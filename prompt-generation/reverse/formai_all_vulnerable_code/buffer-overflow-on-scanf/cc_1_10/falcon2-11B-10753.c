//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    // Create a pipe
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }
    
    // Create child process
    pid_t childpid = fork();
    if (childpid == -1) {
        perror("fork");
        return 1;
    }
    
    // Child process
    if (childpid == 0) {
        // Close read end of pipe
        close(pipefd[0]);
        
        // Read input from pipe
        char input[1024];
        read(pipefd[1], input, sizeof(input));
        
        // Print input
        printf("%s\n", input);
        
        // Close write end of pipe
        close(pipefd[1]);
        
        // Exit child process
        exit(0);
    }
    
    // Parent process
    else {
        // Close write end of pipe
        close(pipefd[1]);
        
        // Read input from stdin
        char input[1024];
        scanf("%s", input);
        
        // Write input to pipe
        write(pipefd[0], input, sizeof(input));
        
        // Close read end of pipe
        close(pipefd[0]);
        
        // Wait for child process to finish
        wait(NULL);
        
        // Print output
        printf("%s\n", input);
    }
    
    // Close pipe
    close(pipefd[1]);
    
    return 0;
}