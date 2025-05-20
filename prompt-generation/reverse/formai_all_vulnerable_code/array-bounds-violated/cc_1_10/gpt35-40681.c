//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<signal.h>

#define MAX_CMD_ARGS 20
#define MAX_INPUT_LEN 512

int cd(char **tokens);
void handler(int signum);
void process_command(char *input);

int main(){
    char input[MAX_INPUT_LEN];

    signal(SIGINT, handler);

    while(1){
        printf("myshell>>");
        fgets(input, MAX_INPUT_LEN, stdin);
        process_command(input);
    }
    return 0;
}

void process_command(char *input){
    input[strlen(input)-1] = '\0';
    pid_t pid;
    char *tokens[MAX_CMD_ARGS];
    char *ptr = strtok(input, " ");
    int bg_flag = 0, i = 0;

    while(ptr != NULL){
        tokens[i++] = ptr;
        ptr = strtok(NULL, " ");
    }

    tokens[i] = NULL;

    if(strcmp(tokens[0], "exit") == 0){
        printf("Exiting shell...\n");
        exit(0);
    }
    else if(strcmp(tokens[0], "cd") == 0){
        if(cd(tokens) == -1){
            printf("Error: cd failed.\n");
        }
    }
    else{
        if(tokens[i-1][0] == '&'){
            tokens[i-1] = NULL;
            bg_flag = 1;
        }
        pid = fork();

        if(pid == -1){
            printf("Error: fork failed.\n");
        }
        else if(pid == 0){
            int input_fd, output_fd;
            for(i=0;tokens[i]!=NULL;i++){
                if(strcmp(tokens[i], "<") == 0){
                    input_fd = open(tokens[i+1], O_RDONLY);
                    if(input_fd == -1){
                        printf("Error: Cannot open file.\n");
                        exit(0);
                    }
                    dup2(input_fd, STDIN_FILENO);
                    close(input_fd);
                    tokens[i] = NULL;
                }
                else if(strcmp(tokens[i], ">") == 0){
                    output_fd = open(tokens[i+1], O_WRONLY|O_CREAT|O_TRUNC, 0644);
                    if(output_fd == -1){
                        printf("Error: Cannot open file.\n");
                        exit(0);
                    }
                    dup2(output_fd, STDOUT_FILENO);
                    close(output_fd);
                    tokens[i] = NULL;
                }
            }
            if(execvp(tokens[0], tokens) == -1){
                printf("Error: execvp failed.\n");
            }
            exit(0);
        }
        else{
            if(bg_flag == 0){
                waitpid(pid, NULL, 0);
            }
        }
    }
}

int cd(char **tokens){
    if(tokens[1] == NULL){
        printf("Error: No argument passed.\n");
        return -1;
    }
    else{
        if(chdir(tokens[1]) == -1){
            return -1;
        }
        else{
            return 0;
        }
    }
}

void handler(int signum){
    printf("\nSignal No. : %d\n", signum);
    printf("Cannot be exited using Ctrl-C!\n");
    fflush(stdout);
}