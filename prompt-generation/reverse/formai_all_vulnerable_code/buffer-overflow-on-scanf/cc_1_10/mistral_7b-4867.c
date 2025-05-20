//MISTRAL-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PIPE_NAME "/tmp/website_uptime_monitor.pipe"
#define URL_LENGTH 256
#define TIMEOUT 5

int main(void) {
    pid_t child_pid;
    int status;
    char url[URL_LENGTH];
    char result[10];
    int fd[2];

    // Create named pipe
    if (mkfifo(PIPE_NAME, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    // Read URL from user input
    printf("Enter the website URL: ");
    scanf("%s", url);

    // Create pipe for IPC
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    child_pid = fork();

    if (child_pid == 0) { // Child process
        close(fd[0]); // Close reading end
        dup2(fd[1], STDOUT_FILENO); // Redirect stdout to pipe
        execl("/usr/bin/curl", "curl", "-s", "-o /dev/null", "-w '%{http_code}\n'", url, NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    } else { // Parent process
        close(fd[1]); // Close writing end

        // Start child process and wait for result
        if (waitpid(child_pid, &status, 0) == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) { // Child process terminated normally
            read(fd[0], result, sizeof(result)); // Read result from pipe
            close(fd[0]);

            if (atoi(result) >= 400) { // Website is down if status code is greater than or equal to 400
                printf("Website %s is down (status code %s)\n", url, result);

                // Write downtime event to log file
                FILE *log_file = fopen("website_downtime.log", "a");
                fprintf(log_file, "%s - %s\n", url, ctime(time(NULL)));
                fclose(log_file);
            }
        } else { // Child process terminated abnormally
            perror("Child process terminated abnormally");
            exit(EXIT_FAILURE);
        }

        close(fd[0]);
    }

    return 0;
}