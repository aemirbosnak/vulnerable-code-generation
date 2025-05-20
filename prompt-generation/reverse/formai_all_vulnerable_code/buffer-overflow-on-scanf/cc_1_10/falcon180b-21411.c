//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_PROCESSES 1024
#define MAX_LINE_LENGTH 1024

typedef struct process_info{
    int pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
    int exit_code;
    char line[MAX_LINE_LENGTH];
}process_info;

void print_process_info(process_info* process){
    printf("PID: %d\n", process->pid);
    printf("Command: %s\n", process->command);
    printf("Status: %d\n", process->status);
    printf("Exit Code: %d\n", process->exit_code);
    printf("Line: %s\n", process->line);
    printf("\n");
}

void read_process_info(int fd, process_info* process){
    char buffer[MAX_LINE_LENGTH];
    memset(buffer, 0, MAX_LINE_LENGTH);
    read(fd, buffer, MAX_LINE_LENGTH);
    strcpy(process->line, buffer);
    sscanf(process->line, "%d %s %d %d", &process->pid, process->command, &process->status, &process->exit_code);
}

void get_process_info(int pid, process_info* process){
    char filename[20];
    sprintf(filename, "/proc/%d/status", pid);
    int fd = open(filename, O_RDONLY);
    if(fd == -1){
        printf("Error: Could not open file\n");
        exit(1);
    }
    read_process_info(fd, process);
    close(fd);
}

int main(){
    process_info processes[MAX_PROCESSES];
    int num_processes = 0;

    printf("Enter the number of processes you want to view (maximum %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);

    for(int i=0; i<num_processes; i++){
        int pid;
        printf("Enter the PID of process %d: ", i+1);
        scanf("%d", &pid);
        get_process_info(pid, &processes[i]);
    }

    printf("Process Information:\n");
    for(int i=0; i<num_processes; i++){
        print_process_info(&processes[i]);
    }

    return 0;
}