//FormAI DATASET v1.0 Category: System administration ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {

    pid_t pid;

    char* command = malloc(sizeof(char) * 100);
    char* output = malloc(sizeof(char) * 1000);

    printf("Enter a system command: ");
    scanf("%s", command);

    pid = fork();

    if (pid < 0) {
        printf("Error: Failed to create child process.\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {

        int status = system(command);

        if (status == 0) {
            printf("\nCommand executed successfully!\n");

            char* new_command = malloc(sizeof(char) * 100);
            strcpy(new_command, command);
            strcat(new_command, " --help");

            printf("Do you want to see the help page for this command? (y/n): ");
            char c;
            scanf("%c", &c);

            if (c == 'y') {
                system(new_command);
            }
        }
        else {
            printf("\nCommand execution failed!\n");
        }

        exit(EXIT_SUCCESS);
    }
    else {
        wait(NULL);
        printf("\nThe output of the command is:\n");
        FILE* file = popen(command, "r");
        fgets(output, 1000, file);
        fclose(file);
        printf("%s\n", output);
    }

    free(command);
    free(output);

    return 0;
}