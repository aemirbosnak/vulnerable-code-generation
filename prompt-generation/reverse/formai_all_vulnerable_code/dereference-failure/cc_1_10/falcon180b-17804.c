//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PROCESSES 100

typedef struct {
    char name[20];
    int pid;
} Process;

int num_processes = 0;
Process processes[MAX_PROCESSES];

void read_processes() {
    DIR *dir;
    struct dirent *ent;
    char path[20];

    sprintf(path, "/proc");
    dir = opendir(path);

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (isdigit(ent->d_name[0])) {
                num_processes++;
                if (num_processes > MAX_PROCESSES) {
                    num_processes = MAX_PROCESSES;
                }
                strcpy(processes[num_processes - 1].name, ent->d_name);
                processes[num_processes - 1].pid = atoi(ent->d_name);
            }
        }
        closedir(dir);
    }
}

void print_processes() {
    for (int i = 0; i < num_processes; i++) {
        printf("%s (%d)\n", processes[i].name, processes[i].pid);
    }
}

int main() {
    read_processes();
    print_processes();

    return 0;
}