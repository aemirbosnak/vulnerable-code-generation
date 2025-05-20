//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: decentralized
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<unistd.h> 
#include<sys/wait.h> 


#define MAX 1000 //Maximum number of commands the user can input
#define LEN 100   //Maximum length of each command


int main() 
{ 
    char inputStr[MAX][LEN];  //2D array to store user input commands 
    char *parameters[MAX];    //Pointer to store each argument after tokenization
    int count, status; 
    pid_t pid; 
  
    while (1) 
    { 
        printf(">> "); 
        fgets(inputStr[count], MAX, stdin);   // Read user input
        
        if (inputStr[count][strlen(inputStr[count]) - 1] == '\n')  // remove trailing newline
            inputStr[count][strlen(inputStr[count]) - 1] = '\0'; 
        
        if (strcmp(inputStr[count], "exit") == 0) // Exit loop if user enters 'exit'
            break; 
  
        count++; 

        pid = fork(); 
        
        if (pid == -1) 
        { 
            printf("Failed forking child\n"); 
            return 1; 
        } 
        else if (pid == 0)  // Child process
        { 
            parameters[0] = strtok(inputStr[count-1], " ");   // Tokenize string
                
            int i = 1; 
            while (parameters[i-1] != NULL) 
            { 
                parameters[i] = strtok(NULL, " "); 
                i++; 
            } 
            parameters[i] = NULL;   // Last argument should be NULL

            execvp(parameters[0], parameters); // execute command using execvp() system call
              
        } 
        else
        { 
            waitpid(pid, &status, 0);  // Wait for child process to finish
        } 
    } 

    return 0; 
}