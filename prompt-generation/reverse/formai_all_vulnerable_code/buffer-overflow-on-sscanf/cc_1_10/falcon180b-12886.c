//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;
    char name[16];
    int status;
} process_t;

void read_processes(process_t* processes, int count) {
    char path[32] = "/proc";
    int i = 0;

    while (i < count && i < MAX_PROCESSES) {
        sprintf(path + strlen(path), "/%d", i);
        if (access(path, F_OK) == 0) {
            FILE* fp = fopen(path, "r");
            if (fp!= NULL) {
                char line[64];
                fgets(line, sizeof(line), fp);
                sscanf(line, "%d %s %d", &processes[i].pid, processes[i].name, &processes[i].status);
                fclose(fp);
                i++;
            }
        } else {
            break;
        }
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int count = 0;

    read_processes(processes, MAX_PROCESSES);

    printf("PID\tName\tStatus\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }

    return 0;
}