//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(){
    printf("Welcome to Grateful Shell!\n");
    printf("Type 'help' for a list of commands.\n");
    while(1){
        printf(">> ");
        char input[100];
        fgets(input, 100, stdin);

        char *command = strtok(input, " \n");
        char *args[10];
        int i = 0;
        while(command != NULL){
            args[i] = command;
            i++;
            command = strtok(NULL, " \n");
        }
        args[i] = NULL;

        if(strcmp(args[0], "help") == 0){
            printf("cd <directory> - change the current directory\n");
            printf("ls <directory> - list the contents of the directory\n");
            printf("mkdir <directory> - create a new directory\n");
            printf("rm <file> - remove a file\n");
            printf("cp <file1> <file2> - copy a file\n");
            printf("exit - exit the shell\n");
        }
        else if(strcmp(args[0], "cd") == 0){
            chdir(args[1]);
        }
        else if(strcmp(args[0], "ls") == 0){
            pid_t pid = fork();
            if(pid == 0){
                if(args[1] == NULL){
                    execl("/bin/ls", "ls", NULL);
                }
                else{
                    execl("/bin/ls", "ls", args[1], NULL);
                }
            }
            else{
                wait(NULL);
            }
        }
        else if(strcmp(args[0], "mkdir") == 0){
            pid_t pid = fork();
            if(pid == 0){
                execl("/bin/mkdir", "mkdir", args[1], NULL);
            }
            else{
                wait(NULL);
            }
        }
        else if(strcmp(args[0], "rm") == 0){
            pid_t pid = fork();
            if(pid == 0){
                execl("/bin/rm", "rm", args[1], NULL);
            }
            else{
                wait(NULL);
            }
        }
        else if(strcmp(args[0], "cp") == 0){
            pid_t pid = fork();
            if(pid == 0){
                int fd1 = open(args[1], O_RDONLY);
                int fd2 = open(args[2], O_CREAT | O_WRONLY, 0644);

                char buffer[1000];
                int n;
                while((n = read(fd1, buffer, 1000)) > 0){
                    write(fd2, buffer, n);
                }

                close(fd1);
                close(fd2);
            }
            else{
                wait(NULL);
            }
        }
        else if(strcmp(args[0], "exit") == 0){
            printf("Thank you for using Grateful Shell!\n");
            return 0;
        }
        else{
            printf("Command not found!\n");
        }
    }
    return 0;
}