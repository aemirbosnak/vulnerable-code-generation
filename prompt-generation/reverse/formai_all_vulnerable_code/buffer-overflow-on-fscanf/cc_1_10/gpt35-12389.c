//FormAI DATASET v1.0 Category: System process viewer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>

#define PROC "/proc"
#define STATE_FILE  "/stat"

typedef struct process {
    char name[50];
    char state;
    int ppid;
    int pid;
} Process;

bool is_numeric(char *pid) {
    for(int i = 0; pid[i] != '\0'; i++) {
        if(pid[i] < '0' || pid[i] > '9') {
            return false;
        }
    }
    return true;
}

void print_process_info(Process *p) {
    printf("%d   %d   %s    %c\n", p->pid, p->ppid, p->name, p->state);
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;

    printf("%s\n", "PID   PPID   NAME   STATE");

    if((dir = opendir(PROC)) == NULL) {
        perror("Could not open " PROC);
        return;
    }

    while((entry = readdir(dir))) {
        if(is_numeric(entry->d_name)) {
            char path[100];
            snprintf(path, sizeof(path), "%s/%s%s", PROC, entry->d_name, STATE_FILE);

            FILE *file;
            if((file = fopen(path, "r")) == NULL) {
                perror(path);
                continue;
            }

            Process p;
            fscanf(file, "%d %s %c %d", &p.pid, p.name, &p.state, &p.ppid);
            print_process_info(&p);
            fclose(file);            
        }
    }

    closedir(dir);
}

int main() {
    list_processes();
    return 0;
}