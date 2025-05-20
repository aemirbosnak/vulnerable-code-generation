//FormAI DATASET v1.0 Category: System administration ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    int pid,status;
    char prompt[50];

    printf("Welcome to the sample system administration program! \n");
    while(1){
        printf("$ ");
        scanf("%s", prompt);

        if(!(strcmp(prompt, "exit"))){
            exit(0);
        }

        pid = fork();

        if(pid == -1){
            printf("Error: Unable to create new process.\n");
        }

        else if(pid == 0){
            if(!(strcmp(prompt, "processes"))){
                system("ps aux");
            }

            else if(!(strcmp(prompt, "memory"))){
                system("free -h");
            }

            else if(!(strcmp(prompt, "disks"))){
                printf("\n");
                system("lsblk");
                printf("\n");
            }

            else if(!(strcmp(prompt, "users"))){
                system("who");
            }

            else{
                printf("Error: Invalid command entered.\n");
            }

            exit(0);
        }

        else{
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}