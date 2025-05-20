//FormAI DATASET v1.0 Category: System administration ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
  pid_t pid;
  int status;

  printf("Welcome to Remote Server Management System\n\n");

  while(1){
    printf("\nEnter the command you want to execute: ");
    char cmd[50];
    scanf("%[^\n]",cmd);
    getchar();

    if(strcmp(cmd, "exit")==0){
      printf("\nTerminating Remote Server Management System\n");
      break;
    }

    pid=fork();

    if(pid==0){
      //Child process
      system(cmd);
      exit(EXIT_SUCCESS);
    }
    else if(pid>0){
      //Parent process
      waitpid(pid,&status,0);

      if(WIFEXITED(status)){
        printf("\nThe command successfully executed.\n");
      }
      else{
        printf("\nError while executing the command.\n");
      }
    }
    else {
      //Error in creating child process
      printf("\nError in creating child process.\n");
      exit(EXIT_FAILURE);
    }
  }

  return 0;
}