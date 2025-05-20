//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(void)
{
    char buffer[MAX_BUFFER_SIZE];
    char *cmd;
    pid_t pid;
    
    while (1) {
        printf(">> ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        
        // Replace newline with null-terminator
        buffer[strlen(buffer)-1] = '\0';
        
        // If user enters exit, quit the shell
        if (strcmp(buffer, "exit") == 0) break;
        
        // Create child process to execute command
        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // In child process
            cmd = strtok(buffer, " ");
            char *args[10];
            args[0] = cmd;
            int i = 1;
            while ((cmd = strtok(NULL, " ")) != NULL) {
                args[i] = cmd;
                i++;
            }
            // Set last argument to NULL per execvp requirements
            args[i] = NULL;
            // Execute command
            execvp(args[0], args);
            // Print error if execvp fails
            perror(args[0]);
            exit(EXIT_FAILURE);
        } else {
            // In parent process
            int status;
            if (waitpid(pid, &status, 0) == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
        }
    }
    
    return 0;
}