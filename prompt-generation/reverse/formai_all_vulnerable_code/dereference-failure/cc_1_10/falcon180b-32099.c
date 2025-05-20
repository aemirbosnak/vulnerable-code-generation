//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/prctl.h>

#define MAX_PROCESSES 1000

typedef struct process {
    pid_t pid;
    char name[16];
    int status;
    struct rusage rusage;
} process_t;

void get_processes(process_t *processes, int count) {
    DIR *dir;
    struct dirent *ent;
    int i = 0;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR && isdigit(ent->d_name[0])) {
                snprintf(processes[i].name, sizeof(processes[i].name), "%s", ent->d_name);
                processes[i].pid = atoi(ent->d_name);
                if (getrusage(processes[i].pid, &processes[i].rusage) == -1) {
                    processes[i].status = -1;
                } else {
                    processes[i].status = 0;
                }
                i++;
            }
        }
        closedir(dir);
    }
}

int main() {
    struct utsname uname_data;
    uname(&uname_data);

    printf("System Information:\n");
    printf("Hostname: %s\n", uname_data.nodename);
    printf("Kernel version: %s\n", uname_data.release);
    printf("CPU family: %d\n", uname_data.machine);

    process_t processes[MAX_PROCESSES];
    int count = 0;

    get_processes(processes, count);

    printf("\nProcess Information:\n");
    printf("PID\tName\tStatus\n");

    for (int i = 0; i < count; i++) {
        if (processes[i].status == 0) {
            printf("%d\t%s\tOK\n", processes[i].pid, processes[i].name);
        } else {
            printf("%d\t%s\tERROR\n", processes[i].pid, processes[i].name);
        }
    }

    return 0;
}