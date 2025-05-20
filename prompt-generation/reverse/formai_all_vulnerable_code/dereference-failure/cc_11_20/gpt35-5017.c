//FormAI DATASET v1.0 Category: System process viewer ; Style: standalone
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>

#define PROC "/proc/"

struct proc_options {
    int user;     /* Option: Only display processes by this user id */
    int fullcmd;  /* Option: Display full command line */
    int threads;  /* Option: Display threads for each process */
};

struct proc_status {
    int pid;
    char cmd[256];
    int ppid;
    char state[16];
    int utime;
    int stime;
    int cutime;
    int cstime;
    int priority;
};

void display_proc_status(struct proc_status* status, struct proc_options* options) {
    char cmd[256];
    if(options->fullcmd) {
        FILE* fp = fopen(status->cmd, "r");
        if(fp != NULL) {
            fgets(cmd, sizeof(cmd), fp);
            fclose(fp);
            printf("%d\t%s\t%d\t%s\t%d\t%d\t%d\t%d\t%d\t%s\n", status->pid, cmd, status->ppid, status->state, 
                status->utime, status->stime, status->cutime, status->cstime, status->priority, PROC);
        } else {
            printf("%d\t%s\t%d\t%s\t%d\t%d\t%d\t%d\t100\t%s\n", status->pid, status->cmd, status->ppid, status->state, 
                status->utime, status->stime, status->cutime, status->cstime, PROC);
        }
    } else {
        printf("%d\t%s\t%d\t%s\t%d\t%d\t%d\t%d\t%d\t%s\n", status->pid, status->cmd, status->ppid, status->state, 
            status->utime, status->stime, status->cutime, status->cstime, status->priority, PROC);
    }
    if(options->threads) {
        DIR* dir;
        struct dirent* entry;
        char path[256];
        char subpath[256];
        int tid, tpid, tstate, tuid = -1, x;
        dir = opendir(PROC);
        printf("\nThreads:\n");
        while((entry = readdir(dir)) != NULL) {
            if(!isdigit(entry->d_name[0]))
                continue;
            tid = atoi(entry->d_name);
            if(tid <= 0)
                continue;
            snprintf(path, sizeof(path), "%s%s/task/%d/status", PROC, entry->d_name, tid);
            FILE* fp = fopen(path, "r");
            if(fp == NULL)
                continue;
            for(x = 0; x < 16; x++) {
                fgets(subpath, sizeof(subpath), fp);
                if(strncmp(subpath, "Pid:\t", 5) == 0) {
                    tpid = atoi(subpath + 5);
                } else if(strncmp(subpath, "State:\t", 7) == 0) {
                    sscanf(subpath + 7, "%s", status->state);
                } else if(strncmp(subpath, "Uid:\t", 4) == 0) {
                    tuid = atoi(subpath + 4);
                }
            }
            fclose(fp);
            if(options->user > 0 && tuid != options->user)
                continue;
            if(tpid == status->pid) {
                printf("%d\t%s\t%d\t%s\t%s", tid, status->cmd, status->pid, status->state, PROC);
                if(options->fullcmd) {
                    fp = fopen(status->cmd, "r");
                    if(fp != NULL) {
                        fgets(cmd, sizeof(cmd), fp);
                        fclose(fp);
                        printf("%s\n", cmd);
                    } else {
                        printf("\n");
                    }
                } else {
                    printf("\n");
                }
            }
        }
        closedir(dir);
    }
}

int main(int argc, char** argv) {
    DIR* dir;
    struct dirent* entry;
    char path[256];
    char subpath[256];
    int pid, uid = -1, x;
    struct proc_status status;
    struct proc_options options;
    options.user = -1;
    options.fullcmd = 0;
    options.threads = 0;
    if(argc > 1) {
        for(x = 1; x < argc; x++) {
            if(strncmp(argv[x], "-u", 2) == 0) {
                options.user = atoi(argv[x] + 2);
            } else if(strncmp(argv[x], "-f", 2) == 0) {
                options.fullcmd = 1;
            } else if(strncmp(argv[x], "-t", 2) == 0) {
                options.threads = 1;
            }
        }
    }
    printf("PID\tCMD\tPPID\tSTATE\tUTIME\tSTIME\tCUTIME\tCSTIME\tPRI\tPATH\n");
    dir = opendir(PROC);
    while((entry = readdir(dir)) != NULL) {
        if(!isdigit(entry->d_name[0]))
            continue;
        pid = atoi(entry->d_name);
        if(pid <= 0)
            continue;
        snprintf(path, sizeof(path), "%s%s/status", PROC, entry->d_name);
        FILE* fp = fopen(path, "r");
        if(fp == NULL)
            continue;
        memset(&status, 0, sizeof(struct proc_status));
        status.pid = pid;
        strncpy(status.cmd, entry->d_name, 256);
        for(x = 0; x < 32; x++) {
            fgets(subpath, sizeof(subpath), fp);
            if(strncmp(subpath, "Name:\t", 6) == 0) {
                sscanf(subpath + 6, "%s", status.cmd);
            } else if(strncmp(subpath, "State:\t", 7) == 0) {
                sscanf(subpath + 7, "%s", status.state);
            } else if(strncmp(subpath, "PPid:\t", 6) == 0) {
                status.ppid = atoi(subpath + 6);
            } else if(strncmp(subpath, "Uid:\t", 5) == 0) {
                uid = atoi(subpath + 5);
            } else if(strncmp(subpath, "Utime:\t", 7) == 0) {
                status.utime = atoi(subpath + 7);
            } else if(strncmp(subpath, "Stime:\t", 7) == 0) {
                status.stime = atoi(subpath + 7);
            } else if(strncmp(subpath, "Cutime:\t", 8) == 0) {
                status.cutime = atoi(subpath + 8);
            } else if(strncmp(subpath, "Cstime:\t", 8) == 0) {
                status.cstime = atoi(subpath + 8);
            } else if(strncmp(subpath, "Priority:\t", 10) == 0) {
                status.priority = atoi(subpath + 10);
            }
        }
        fclose(fp);
        if(options.user > 0 && uid != options.user)
            continue;
        display_proc_status(&status, &options);
    }
    closedir(dir);
    return 0;
}