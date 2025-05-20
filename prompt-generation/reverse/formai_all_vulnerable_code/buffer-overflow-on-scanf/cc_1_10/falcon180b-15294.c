//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_PROCESS_NUM 10
#define MAX_COMMAND_LEN 80

char command_list[MAX_PROCESS_NUM][MAX_COMMAND_LEN];
int process_list[MAX_PROCESS_NUM];
int process_num = 0;

void print_process_info(int pid) {
    char filename[20];
    sprintf(filename, "/proc/%d/cmdline", pid);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }
    char cmdline[MAX_COMMAND_LEN];
    fgets(cmdline, MAX_COMMAND_LEN, fp);
    fclose(fp);
    printf("PID: %d\tCommand: %s\n", pid, cmdline);
}

void monitor_processes() {
    printf("Monitoring processes...\n");
    while (1) {
        printf("Current process list:\n");
        for (int i = 0; i < process_num; i++) {
            print_process_info(process_list[i]);
        }
        printf("\n");
        sleep(5);
    }
}

int main() {
    printf("Enter commands to run (up to %d):\n", MAX_PROCESS_NUM);
    for (int i = 0; i < MAX_PROCESS_NUM; i++) {
        printf("Command %d: ", i+1);
        scanf("%s", command_list[i]);
    }

    for (int i = 0; i < MAX_PROCESS_NUM; i++) {
        if (strcmp(command_list[i], "")!= 0) {
            printf("Running command %s...\n", command_list[i]);
            process_list[process_num] = fork();
            if (process_list[process_num] == 0) {
                system(command_list[i]);
                exit(0);
            } else if (process_list[process_num] < 0) {
                printf("Error: Failed to run command %s\n", command_list[i]);
            } else {
                process_num++;
            }
        }
    }

    printf("All commands have been run.\n");
    printf("Do you want to monitor the processes? (y/n): ");
    char choice;
    scanf("%c", &choice);
    if (choice == 'y' || choice == 'Y') {
        monitor_processes();
    }

    return 0;
}