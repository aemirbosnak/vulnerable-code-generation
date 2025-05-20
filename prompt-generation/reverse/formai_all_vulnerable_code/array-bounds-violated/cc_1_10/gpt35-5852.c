//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 64

void parse_input(char* input, char** args){
    int i = 0;

    args[i] = strtok(input, " \t\n");

    while(args[i] != NULL){
        i++;
        args[i] = strtok(NULL, " \t\n");
    }
}

int main(){
    char input[MAX_CMD_LEN];
    char* args[MAX_ARGS];
    pid_t pid;
    int status;

    while(1){
        printf("$ > ");
        fgets(input, MAX_CMD_LEN , stdin);

        if(input[strlen(input)-1] == '\n'){
            input[strlen(input)-1] = '\0';
        }

        parse_input(input, args);

        if(strcmp(args[0], "exit") == 0){
            printf("Goodbye!\n");
            return 0;
        }

        pid = fork();

        if(pid == -1){
            printf("Fork Error!\n");
            return 1;
        }

        if(pid == 0){
            if(execvp(args[0], args) == -1){
                printf("Invalid Command\n");
            }
            exit(0);
        }

        else{
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}