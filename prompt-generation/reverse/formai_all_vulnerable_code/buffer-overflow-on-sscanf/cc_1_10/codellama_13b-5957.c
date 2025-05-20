//Code Llama-13B DATASET v1.0 Category: RAM usage monitor ; Style: Cryptic
/*
 * RAM usage monitor example program
 *
 * (Cryptic style)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 256
#define MAX_PROCS 10

struct proc_info {
    char name[BUFSIZE];
    int pid;
    int ppid;
    int status;
    int uid;
    int gid;
    int priority;
    int nice;
    int cpu_time;
    int mem_usage;
};

int main() {
    struct proc_info procs[MAX_PROCS];
    int i, nprocs;
    char buf[BUFSIZE];
    FILE *f;

    f = fopen("/proc/stat", "r");
    if (f == NULL) {
        perror("fopen");
        exit(1);
    }

    while (fgets(buf, BUFSIZE, f)) {
        if (buf[0] == 'c') {
            break;
        }
    }

    fclose(f);

    nprocs = 0;
    f = fopen("/proc/stat", "r");
    if (f == NULL) {
        perror("fopen");
        exit(1);
    }

    while (fgets(buf, BUFSIZE, f)) {
        if (buf[0] == 'c') {
            break;
        }

        sscanf(buf, "%d %s %d %d %d %d %d %d %d %d",
               &procs[nprocs].pid,
               procs[nprocs].name,
               &procs[nprocs].ppid,
               &procs[nprocs].status,
               &procs[nprocs].uid,
               &procs[nprocs].gid,
               &procs[nprocs].priority,
               &procs[nprocs].nice,
               &procs[nprocs].cpu_time,
               &procs[nprocs].mem_usage);
        nprocs++;
    }

    fclose(f);

    for (i = 0; i < nprocs; i++) {
        printf("PID: %d, Name: %s, PPID: %d, Status: %d, UID: %d, GID: %d, Priority: %d, Nice: %d, CPU Time: %d, Mem Usage: %d\n",
               procs[i].pid,
               procs[i].name,
               procs[i].ppid,
               procs[i].status,
               procs[i].uid,
               procs[i].gid,
               procs[i].priority,
               procs[i].nice,
               procs[i].cpu_time,
               procs[i].mem_usage);
    }

    return 0;
}