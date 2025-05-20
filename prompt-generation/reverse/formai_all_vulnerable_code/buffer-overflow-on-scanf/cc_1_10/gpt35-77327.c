//FormAI DATASET v1.0 Category: Task Scheduler ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>
#include<signal.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/types.h>

int main(){
    int pid; 
    printf("Enter the process ID: "); 
    scanf("%d", &pid);
    char command[1000];
    printf("Enter the command to run after specified interval: ");
    scanf("%s", command);
    
    int secs;
    printf("Enter time interval (in seconds) to run the command: ");
    scanf("%d", &secs);
    
    while(1) {
        
        time_t current_time;
        struct tm * time_info;
        
        time(&current_time);
        time_info = localtime(&current_time);
        char *time_str = asctime(time_info);
        int len = strlen(time_str) - 1;
        
        if(time_str[len] == '\n') {
            time_str[len] = '\0';
        }
        
        printf("Current Time: %s\n", time_str);
        
        if(secs == 0) {
            printf("Interval is 0 seconds. Exiting...\n");
            exit(0);
        }
        
        pid_t child_pid;
        child_pid = fork();
        
        if(child_pid < 0) {
            perror("Forking error");
            exit(1);
        }
        
        if(child_pid == 0) {
            printf("Running the specified command...\n");
            char *args[] = {command, NULL}; // NULL is required for the end of the array
            execvp(args[0], args); // Execute the command with arguments
            exit(0);
        }
        else {
            // Wait for child process to finish
            int status;
            wait(&status);
            printf("Command execution finished.\n");
        }
        
        sleep(secs);
    }
    
    return 0;
}