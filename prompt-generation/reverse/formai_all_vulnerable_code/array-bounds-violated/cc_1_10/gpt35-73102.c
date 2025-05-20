//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: creative
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){

    char buffer[1024];
    char* args[64];
    pid_t pid;

    printf("Welcome to MyShell!\n");
    while(1){

        printf(">>> ");
        fgets(buffer,1024,stdin);
        buffer[strlen(buffer) - 1] = '\0';

        if(strcmp(buffer,"exit") == 0){
            exit(0);
        }

        int count = 0;
        char* token = strtok(buffer," ");
        while(token != NULL){
            args[count] = token;
            count++;
            token = strtok(NULL," ");
        }
        args[count] = NULL;

        pid = fork();
        if(pid < 0){
            fprintf(stderr,"Fork Failure\n");
            exit(-1);
        }
        else if(pid == 0){
            execvp(args[0],args);
            fprintf(stderr,"Command Not Found\n");
            exit(1);
        }
        else{
            wait(NULL);
        }

    }

    return 0;
}