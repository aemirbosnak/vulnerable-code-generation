//FormAI DATASET v1.0 Category: System administration ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

// Signal handler function
void sigHandler(int signum){
    if(signum == SIGINT){
        printf("\nInterrupt signal received...\nCleaning up and exiting...\n");
    }
    exit(signum);
}

int main(){
    // Registering signal handler for SIGINT
    signal(SIGINT, sigHandler);

    // Initializing variables
    char username[20], password[20], data[20];
    int attempts = 0;

    // Prompting user for login credentials
    printf("Enter your username: ");
    fflush(stdout); // flushing stdout buffer
    scanf("%s", username);
    printf("Enter your password: ");
    fflush(stdout); // flushing stdout buffer
    scanf("%s", password);

    // Checking if login credentials are correct
    while(attempts < 3){
        if(strcmp(username, "admin") == 0 && strcmp(password, "password") == 0){
            printf("\nHello, admin.\nYou have successfully logged in.\n");
            break;
        }
        else{
            printf("\nIncorrect username or password.\n");
            attempts++;
            if(attempts < 3){
                printf("Please try again.\n");
            }
        }
        // Prompting user for login credentials again
        printf("\nEnter your username: ");
        fflush(stdout); // flushing stdout buffer
        scanf("%s", username);
        printf("Enter your password: ");
        fflush(stdout); // flushing stdout buffer
        scanf("%s", password);
    }

    if(attempts == 3){
        printf("\nYou have entered incorrect login credentials 3 times.\nExiting...\n");
        exit(0);
    }

    while(1){
        printf("\nEnter a command (or 'exit' to quit):\n");
        fflush(stdout); // flushing stdout buffer
        scanf("%s", data);

        if(strcmp(data, "exit") == 0){
            printf("\nExiting...\n");
            exit(0);
        }
        else{
            // Using fork() to create a child process to execute the command
            pid_t pid = fork();
            if(pid == -1){
                perror("fork() failed");
                exit(1);
            }
            else if(pid == 0){
                char* args[] = {data, NULL};
                int execStatus = execvp(args[0], args);
                if(execStatus == -1){
                    perror("execvp() failed");
                    _exit(1);
                }
            }
            else{
                // Parent process waiting for child process to complete
                int childStatus;
                waitpid(pid, &childStatus, 0);
                if(WIFEXITED(childStatus) != 0){
                    printf("\nCommand exited with status %d\n", WEXITSTATUS(childStatus));
                }
                else{
                    printf("\nCommand terminated by signal %d\n", WTERMSIG(childStatus));
                }
            }
        }
    }

    return 0;
}