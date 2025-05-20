//Falcon2-11B DATASET v1.0 Category: Basic Unix-like Shell ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int status;
    int child_pid;
    char *command[5];
    char input_string[100];
    char output_string[100];
    char *current_directory = (char*)malloc(100);

    printf("Enter command: ");
    fgets(input_string, sizeof(input_string), stdin);
    sscanf(input_string, "%s %s %s %s %s", command[0], command[1], command[2], command[3], command[4]);

    child_pid = fork();

    if (child_pid == 0) {
        // Child process
        execvp(command[0], command);
    } else if (child_pid > 0) {
        // Parent process
        waitpid(child_pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child process terminated by signal %d\n", WTERMSIG(status));
        } else {
            printf("Child process terminated abnormally\n");
        }
    } else {
        printf("Fork failed\n");
    }

    // Change directory
    chdir(".");

    // Read input from user
    printf("Enter input string: ");
    fgets(input_string, sizeof(input_string), stdin);

    // Write output to file
    FILE *fp = fopen("output.txt", "w");
    fprintf(fp, "%s", output_string);
    fclose(fp);

    // Free allocated memory
    free(current_directory);

    return 0;
}