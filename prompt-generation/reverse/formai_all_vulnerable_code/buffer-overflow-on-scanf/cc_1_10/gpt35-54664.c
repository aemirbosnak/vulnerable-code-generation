//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_BUFF_SIZE 100

int main()
{
    int pid;
    char cmd[MAX_BUFF_SIZE];
    
    while(true)
    {
        printf("Enter the command to check the RAM usage:\n");
        scanf("%s", cmd);
        
        if(strcmp(cmd, "exit") == 0)
        {
            printf("Exiting the monitor program.\n");
            break;
        }
        
        pid = fork();
        
        if(pid < 0)
        {
            printf("Fork creation failed. Please try again.\n");
            continue;
        }
        else if(pid == 0)
        {
            char* args[] = {"ps", "-o", "rss=RAM", "-p", "1234", NULL};
            int ret = execvp("ps", args);
            
            if(ret == -1)
            {
                printf("Invalid command. Please try again.\n");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(NULL);
        }
    }
    
    return EXIT_SUCCESS;
}