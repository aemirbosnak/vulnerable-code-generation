//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<sys/wait.h>
#include<signal.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_SIZE 50
#define MAX_COMMAND_LINE_SIZE 200

typedef struct process {
    int pid;
    char name[MAX_PROCESS_NAME_SIZE];
    char command_line[MAX_COMMAND_LINE_SIZE];
} Process;

void read_processes(Process* processes) {
    DIR* dir;
    struct dirent* ent;
    int count = 0;
    dir = opendir("/proc");
    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR && count < MAX_PROCESSES) {
                char path[50];
                sprintf(path, "/proc/%s/cmdline", ent->d_name);
                FILE* fp = fopen(path, "r");
                if (fp!= NULL) {
                    fgets(processes[count].command_line, MAX_COMMAND_LINE_SIZE, fp);
                    fclose(fp);
                }
                else {
                    strcpy(processes[count].command_line, "NULL");
                }
                strcpy(processes[count].name, ent->d_name);
                processes[count].pid = atoi(ent->d_name);
                count++;
            }
        }
        closedir(dir);
    }
}

void display_processes(Process* processes, int num_processes) {
    printf("PID\tName\tCommand Line\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%s\n", processes[i].pid, processes[i].name, processes[i].command_line);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;
    read_processes(processes);
    display_processes(processes, num_processes);
    return 0;
}