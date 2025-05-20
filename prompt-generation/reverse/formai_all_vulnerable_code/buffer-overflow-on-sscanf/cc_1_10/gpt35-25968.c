//FormAI DATASET v1.0 Category: System process viewer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PID 5000
#define MAX_NAME 100

typedef struct process {
    int pid;
    char name[MAX_NAME];
    char status;
} process;

int get_process_info(process *p, int pid) {
    char cmd[MAX_NAME];
    snprintf(cmd, sizeof(cmd), "ps -p %d -o pid,comm,state", pid);
    
    FILE *fp = popen(cmd, "r");
    if(fp == NULL)
        return -1;
    
    char output[MAX_NAME];
    fgets(output, MAX_NAME, fp);
    if(strlen(output) == 0)
        return -1;
    
    int n = sscanf(output, "%d %s %c", &p->pid, p->name, &p->status);
    if(n != 3)
        return -1;
    
    pclose(fp);
    return 0;
}

void print_process_info(process *p) {
    printf("%5d %20s %5c\n", p->pid, p->name, p->status);
}

int main() {
    printf("%5s %20s %5s\n", "PID", "NAME", "STAT");
    
    for(int pid = 1; pid < MAX_PID; pid++) {
        process p;
        if(get_process_info(&p, pid) == 0) {
            print_process_info(&p);
        }
    }
    
    return 0;
}