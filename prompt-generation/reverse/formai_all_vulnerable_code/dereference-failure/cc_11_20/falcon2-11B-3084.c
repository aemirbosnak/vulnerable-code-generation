//Falcon2-11B DATASET v1.0 Category: System event logger ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>
#include <sys/time.h>

int main() {
    pid_t pid, wstatus;
    int fd, ret, i, j, count, sum, avg, min, max;
    struct timeval start, end;
    struct tm *ltm;
    char *command[100];
    char buffer[100];
    char logfile[100];

    strcpy(logfile, "event_log.txt");
    if ((fd = open(logfile, O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR)) == -1) {
        perror("Error opening file");
        exit(1);
    }

    while (1) {
        printf("Enter a command: ");
        fgets(command[0], sizeof(command[0]), stdin);
        count = 1;
        for (i = 0; i < sizeof(command); i++) {
            if (strlen(command[i]) == 0) {
                continue;
            }
            else {
                if (i == sizeof(command) - 1) {
                    strcpy(command[i + 1], "&");
                }
                else {
                    strcpy(command[i + 1], " ");
                }
                count++;
            }
        }
        printf("Child process %d executing %s\n", getpid(), command[0]);
        pid = fork();
        if (pid < 0) {
            perror("Error forking");
            exit(1);
        }
        else if (pid == 0) {
            signal(SIGINT, SIG_IGN);
            execvp(command[0], command);
            exit(0);
        }
        else {
            wait(&wstatus);
            ret = read(STDERR_FILENO, buffer, sizeof(buffer));
            if (ret > 0) {
                printf("%s\n", buffer);
            }
            else {
                printf("Error reading from STDERR\n");
            }
            ret = read(STDOUT_FILENO, buffer, sizeof(buffer));
            if (ret > 0) {
                printf("%s\n", buffer);
            }
            else {
                printf("Error reading from STDOUT\n");
            }
            for (i = 0; i < count; i++) {
                if (i == 0) {
                    strcpy(command[i], "echo '");
                }
                else {
                    strcat(command[i], " ");
                }
                strcat(command[i], command[i + 1]);
            }
            for (j = 0; j < count; j++) {
                strcpy(command[j + 1], "\"");
            }
            strcat(command[count], " ");
            strcat(command[count], logfile);
            printf("Child process %d completed with exit status %d\n", getpid(), wstatus);
            execvp(command[0], command);
        }
    }
    return 0;
}