//FormAI DATASET v1.0 Category: System administration ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

int main(){

    printf("Welcome to RetroSys\n");

    while(1){

        char input[100];
        printf("RetroSys~$ ");
        fgets(input, 100, stdin);

        char *token = strtok(input, " ");
        char *args[10];
        int i=0;

        while(token != NULL){
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }

        args[i-1][strlen(args[i-1])-1] = '\0';

        if(strcmp(args[0], "exit") == 0){
            printf("Shutting down RetroSys\n");
            exit(0);
        }

        pid_t pid = fork();

        if(pid == 0){
            execvp(args[0], args);
            printf("Command not found\n");
            exit(1);
        }
        else if(pid < 0){
            printf("Error: Fork failed\n");
            exit(1);
        }
        else{
            wait(NULL);
        }

    }

    return 0;
}