//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid; // Child process ID
    int status;
    char *message; 
    
    // Create pipe
    int fd[2];
    if(pipe(fd) == -1) {
        perror("Pipe failed");
        exit(EXIT_FAILURE);
    }
    
    // Fork a child process
    child_pid = fork();
    if(child_pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    
    if(child_pid == 0) { 
        // Child process - Reads from pipe
        close(fd[1]); // Close write end
        while(1) {
            read(fd[0], &message, sizeof(message));
            printf("[Child]: %s", message);
            if (strcmp(message, "I'm done") == 0) {
                break;
            }
        }
        close(fd[0]); // Close read end
        exit(EXIT_SUCCESS);
    } else { 
        // Parent process - Writes to pipe
        close(fd[0]); // Close read end
        while(1) {
            printf("[Parent]: Something witty or funny to say: ");
            gets(message);
            write(fd[1], &message, sizeof(message));
            if (strcmp(message, "I'm done") == 0) {
                break;
            }
        }
        close(fd[1]); // Close write end
        waitpid(child_pid, &status, 0); // Wait for child process to terminate
    }
    
    return 0;
}