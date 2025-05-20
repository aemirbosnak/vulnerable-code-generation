//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#define MAX_PID 1000

struct proc_info {
    int pid;
    char name[256];
    int state;
    int ppid;
    int pgrp;
    long long utime;
    long long stime;
    long long cutime;
    long long cstime;
};

static struct proc_info proc_info[MAX_PID];
static int num_procs;

static void update_proc_info() {
    FILE *f = fopen("/proc", "r");
    if (f == NULL) {
        perror("fopen");
        return;
    }

    num_procs = 0;
    while (fscanf(f, "%d %s %c %d %d %lld %lld %lld %lld", &proc_info[num_procs].pid, proc_info[num_procs].name, &proc_info[num_procs].state, &proc_info[num_procs].ppid, &proc_info[num_procs].pgrp, &proc_info[num_procs].utime, &proc_info[num_procs].stime, &proc_info[num_procs].cutime, &proc_info[num_procs].cstime) == 9) {
        num_procs++;
    }

    fclose(f);
}

static void print_proc_info() {
    printf("PID\tNAME\tSTATE\tPPID\tPGRP\tUTIME\tSTIME\tCUTIME\tCSTIME\n");
    for (int i = 0; i < num_procs; i++) {
        printf("%d\t%s\t%c\t%d\t%d\t%lld\t%lld\t%lld\t%lld\n", proc_info[i].pid, proc_info[i].name, proc_info[i].state, proc_info[i].ppid, proc_info[i].pgrp, proc_info[i].utime, proc_info[i].stime, proc_info[i].cutime, proc_info[i].cstime);
    }
}

int main() {
    while (1) {
        update_proc_info();
        print_proc_info();

        sleep(1);
    }

    return 0;
}