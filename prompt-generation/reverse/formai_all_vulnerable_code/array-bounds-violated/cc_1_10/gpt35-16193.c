//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Sherlock Holmes
/* In the case of the curious incident of the Unix-like Shell */
/* Program written in the style of Sherlock Holmes */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

#define MAX_INPUT_LEN 1024
#define MAX_ARG_NUM 64
#define MAX_CMD_NUM 16

void printPrompt(){
    printf("Sherlock>");
}

int getCmd(char* cmd[], char* inputStr){

    int i = 0; 
    cmd[i] = strtok(inputStr," ");

    while(cmd[i] && i < MAX_ARG_NUM - 1){
        i++;
        cmd[i] = strtok(NULL, " ");
    }

    return i;
}

int main(){

    char input[MAX_INPUT_LEN];
    char *cmd[MAX_ARG_NUM];
    char *cmdList[MAX_CMD_NUM][MAX_ARG_NUM];
    int cmdNum, i, j;

    while(1){

        printPrompt();
        fgets(input, MAX_INPUT_LEN, stdin);

        if(input[0] == '\n') continue;

        input[strlen(input) - 1] = '\0';
        printf("The curious incident of the Unix-like Shell is that the input was: %s\n", input);

        cmdNum = 0;

        char* cmdLine = strtok(input,"|");

        while(cmdLine && cmdNum < MAX_CMD_NUM){

            j = getCmd(cmdList[cmdNum], cmdLine);
            cmdList[cmdNum][j] = NULL;

            cmdLine = strtok(NULL,"|");
            cmdNum++;
        }

        pid_t pid, wpid;
        int status;
        int fd[2];
        int fd_in = 0;

        for(i = 0; i < cmdNum; i++){
            pipe(fd);
            pid=fork();

            if(pid == 0){

                dup2(fd_in, STDIN_FILENO);

                if(i != cmdNum - 1){
                    dup2(fd[1], STDOUT_FILENO);
                }

                close(fd[0]);
                close(fd[1]);

                if(execvp(cmdList[i][0], cmdList[i]) == -1){
                    perror("execvp");
                    exit(-1);
                }
            }
            else if(pid < 0){

                perror("Sherlock: unable to fork");
                exit(1);
            }
            else{

                do{
                    wpid = waitpid(pid, &status, WUNTRACED);
                } while(!WIFEXITED(status) && !WIFSIGNALED(status));

                close(fd[1]);
                fd_in = fd[0];
            }
        }
    }

    return 0;
}