//FormAI DATASET v1.0 Category: System process viewer ; Style: complex
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#define PATH_SIZE 1024
#define MAX_PID 65535

typedef struct {
    char name[50];
    int pid;
    char state;
    int priority;
    char* cmd;
} Process;

int compare_priority(const void* a, const void* b) {
    Process* p1 = (Process*)a;
    Process* p2 = (Process*)b;

    return p2->priority - p1->priority;
}

void print_processes(Process* processes, int num_processes) {
    printf("PID\tSTATE\tPRI\tNAME\t\t\tCOMMAND\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%c\t%d\t%-20s%s\n", processes[i].pid, processes[i].state, processes[i].priority, 
            processes[i].name, processes[i].cmd);
    }
}

void parse_process_info(char* proc, Process* p) {
    char* token = strtok(proc, " ");
    int count = 1;

    while (token) {
        if (count == 2) {
            p->pid = atoi(token);
        } else if (count == 3) {
            p->state = token[0];
        } else if (count == 18) {
            p->priority = atoi(token);
        } else if (count == 22) {
            strncpy(p->name, token, strlen(token));
        }

        token = strtok(NULL, " ");
        count++;
    }
}

void get_command_for_process(Process* p) {
    char cmd_path[PATH_SIZE];
    sprintf(cmd_path, "/proc/%d/cmdline", p->pid);

    FILE* fp = fopen(cmd_path, "r");
    if (fp == NULL) {
        perror("Error opening cmdline file");
        return;
    }

    char cmd[PATH_SIZE];
    fscanf(fp, "%s", cmd);

    p->cmd = (char*)malloc(sizeof(char)*strlen(cmd) + 1);
    if (p->cmd == NULL) {
        perror("Error allocating memory");
        return;
    }

    strncpy(p->cmd, cmd, strlen(cmd) + 1);

    fclose(fp);
}

int main() {
    DIR* dir = opendir("/proc");
    if (dir == NULL) {
        perror("Error opening /proc directory");
        return -1;
    }

    Process processes[MAX_PID];
    int num_processes = 0;

    struct dirent* dp;
    while ((dp = readdir(dir)) != NULL) {
        if (dp->d_type == DT_DIR && strtol(dp->d_name, NULL, 10)) {
            char proc_path[PATH_SIZE];
            sprintf(proc_path, "/proc/%s/stat", dp->d_name);

            FILE* fp = fopen(proc_path, "r");
            if (fp == NULL) {
                perror("Error opening stat file");
                continue;
            }

            char proc_info[PATH_SIZE];
            fgets(proc_info, PATH_SIZE, fp);

            Process p;
            strcpy(p.cmd, "");
            parse_process_info(proc_info, &p);
            get_command_for_process(&p);

            processes[num_processes] = p;
            num_processes++;

            fclose(fp);
        }
    }

    closedir(dir);

    qsort(processes, num_processes, sizeof(Process), compare_priority);
    print_processes(processes, num_processes);

    for (int i = 0; i < num_processes; i++) {
        free(processes[i].cmd);
    }

    return 0;
}