//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

#define BUF_SIZE 1024

void prompt(); // function to display shell prompt
void handle_sigint(int sig); // function to handle SIGINT signal

int main() {
    char *args[BUF_SIZE]; // array of char pointers to store user input
    char buffer[BUF_SIZE]; // array of chars to store user input
    char *path = "/usr/bin/"; // path for executables
    char progpath[20];
    pid_t pid;
    int status;
    int redirect = 0;
    int fd;
    
    signal(SIGINT, handle_sigint); // handle SIGINT signal
    
    while(1) {
        prompt(); // display shell prompt
        
        fgets(buffer, BUF_SIZE, stdin); // read user input
        
        // replace newline character in user input with null character
        if(buffer[strlen(buffer)-1] == '\n') {
            buffer[strlen(buffer)-1] = '\0';
        }
        
        // exit if user inputs "exit"
        if(strcmp(buffer, "exit") == 0) {
            fprintf(stdout, "Goodbye!\n");
            exit(EXIT_SUCCESS);
        }
        
        // check if user wants to redirect output to a file
        if(strchr(buffer, '>')) {
            redirect = 1;
            char *temp = strtok(buffer, ">");
            strcpy(buffer, temp);
            fd = open(strtok(NULL, " "), O_WRONLY | O_CREAT | O_TRUNC, 0644);
        }
        
        // split user input into array of char pointers
        char *token = strtok(buffer, " ");
        int i = 0;
        while(token != NULL) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;
        
        // search for executable file in path
        strcpy(progpath, path);
        strcat(progpath, args[0]);
        int executable_found = access(progpath, X_OK);
        if(executable_found == 0) { // if executable is found
            pid = fork(); // create child process
            if(pid == 0) { // if child process
                if(redirect) { // redirect output, if necessary
                    dup2(fd, STDOUT_FILENO);
                    close(fd);
                }
                execv(progpath, args); // execute command
                exit(EXIT_SUCCESS);
            } else if(pid > 0) { // if parent process
                waitpid(pid, &status, 0); // wait for child process to finish
                redirect = 0;
            } else { // if error
                fprintf(stderr, "Error: Failed to fork\n");
            }
        } else { // if executable is not found
            fprintf(stderr, "Error: Command not found\n");
        }
    }
    return 0;
}

void prompt() {
    char *username = getenv("USER");
    char hostname[BUF_SIZE];
    gethostname(hostname, BUF_SIZE);
    fprintf(stdout, "\033[1;31m%s\033[0;0m@\033[1;34m%s\033[0;0m$ ", username, hostname);
}

void handle_sigint(int sig) {
    fprintf(stdout, "\n"); // print new line character
    prompt(); // display shell prompt
    fflush(stdout); // flush stdout
    signal(SIGINT, handle_sigint); // restore signal handler
}