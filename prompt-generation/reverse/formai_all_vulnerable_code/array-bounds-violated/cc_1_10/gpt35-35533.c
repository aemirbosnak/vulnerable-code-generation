//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: complex
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

#define BUFF_SIZE 256  //Buffer size

int main(){
    char command[BUFF_SIZE]; //command buffer
    int status; //for exit status 

    while(1){ //continue until user quit
        printf(">>> ");
        fgets(command, BUFF_SIZE, stdin); //read user input
        command[strlen(command)-1] = '\0'; //remove newline character
        
        if(strcmp("quit", command) == 0){ //if user enters quit
            printf("Exiting shell...\n");
            exit(0);
        }
        
        char *arg[BUFF_SIZE]; //argument buffer
        int i = 0; //argument index
        
        //parse arguments
        char *token = strtok(command, " ");
        while(token != NULL){
            arg[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        arg[i] = NULL; //set last argument to NULL
        
        pid_t pid = fork(); //create child process
        
        if(pid == -1){ //if fork fails
            printf("Error: Fork failed!\n");
            exit(1);
        }
        else if(pid == 0){ //if child process
            if(execvp(arg[0], arg) == -1){ //execute entered command
                printf("Error: Failed to execute command!\n");
                exit(1);
            }
        }
        else{ //if parent process
            wait(&status); //wait for child process to exit
            if(WIFEXITED(status)){ //check exit status
                printf("Exited with status: %d\n", WEXITSTATUS(status));
            }
        }
    }
    return 0;
}