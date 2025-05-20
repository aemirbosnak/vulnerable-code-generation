//FormAI DATASET v1.0 Category: System administration ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// function to check if a process is running
bool is_process_running(char *process_name){
    FILE *fp;
    char output[1024];

    // run the command "ps -ef | grep <process_name>" and store output in a buffer
    char command[128];
    sprintf(command, "ps -ef | grep %s", process_name);
    fp = popen(command, "r");
    if(fp == NULL){
        printf("Error: Failed to run command\n");
        exit(1);
    }

    // check if there is any output to determine if process is running
    while(fgets(output, sizeof(output), fp) != NULL){
        if(strstr(output, process_name) != NULL){
            pclose(fp);
            return true;
        }
    }

    pclose(fp);
    return false;
}

// function to kill a process by name
void kill_process(char *process_name){
    FILE *fp;
    char command[128];

    // run the command "pkill <process_name>" to kill the process
    sprintf(command, "pkill %s", process_name);
    fp = popen(command, "r");
    if(fp == NULL){
        printf("Error: Failed to run command\n");
        exit(1);
    }

    pclose(fp);
}

int main(){
    char process_name[128];
    printf("Enter the name of the process to check for: ");
    scanf("%s", process_name);

    // check if process is running and print result
    if(is_process_running(process_name)){
        printf("Process %s is running\n", process_name);
    } else {
        printf("Process %s is not running\n", process_name);
    }

    // ask user if they want to kill the process if it is running
    char response[10];
    printf("Do you want to kill the process? (y/n) ");
    scanf("%s", response);
    if(strcmp(response, "y") == 0){
        kill_process(process_name);
        printf("Process %s has been killed\n", process_name);
    }

    return 0;
}