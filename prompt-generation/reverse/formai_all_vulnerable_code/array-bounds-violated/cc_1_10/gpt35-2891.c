//FormAI DATASET v1.0 Category: System administration ; Style: single-threaded
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    char command[100];
    char *arg[20];
    int i=0,status;

    printf("Welcome to the Unique System Administration Program!\n");
    printf("Please enter your command:\n");

    while(1)
    {
        printf("> ");
        fgets(command,100,stdin); // read command from user
        command[strlen(command)-1]='\0'; // remove newline character
        
        if(strcmp(command,"exit")==0) // exit program
        {
            printf("Exiting program...\n");
            break;
        }
        
        // tokenize the command string and store in arg array
        char *token=strtok(command," ");
        while(token!=NULL)
        {
            arg[i++]=token;
            token=strtok(NULL," ");
        }
        arg[i]=NULL;

        // fork a child process to execute the command
        int pid=fork();
        if(pid==-1) // error in forking
        {
            printf("Error in forking!\n");
            exit(1);
        }
        else if(pid==0) // child process
        {
            execvp(arg[0],arg); // execute the command
            printf("Command not found!\n"); // this line will only be printed if execvp fails
            exit(1);
        }
        else // parent process
        {
            wait(&status); // wait for child process to finish
        }
        i=0; // reset arg array index
    }
    return 0;
}