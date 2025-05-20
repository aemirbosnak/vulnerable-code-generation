//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: happy
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 1024

int main() {
    while(1) {
        char input[MAX_LENGTH];
        char* args[MAX_LENGTH/2 + 1];
        int bg = 0, n = 0;

        printf("\n Let's be happy! Enter your command: ");
        fgets(input, MAX_LENGTH, stdin);

        if(input[0] == '\n')
            continue;

        input[strlen(input) - 1] = '\0';

        if(strcmp(input, "exit") == 0) 
            break;

        for(int i=0; i<strlen(input); i++) {
            if(input[i] == '&') {
                bg = 1;
                break;
            }
        }
        
        char* token = strtok(input, " ");
        
        while(token != NULL) {
            args[n++] = token;
            token = strtok(NULL, " ");
        }

        args[n] = NULL;

        pid_t pid = fork();

        if(pid < 0) {
            printf("Error! Forking failed.");
            exit(1);
        }

        if(pid == 0) {
            execvp(args[0], args);
            printf("%s is not a valid command", args[0]);
            exit(1);
        }
        else {
            if(bg == 0)
                waitpid(pid, NULL, 0);
        }
    }

    printf("\n Goodbye! Have a happy day! :)\n");
    return 0;
}