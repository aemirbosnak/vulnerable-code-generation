//FormAI DATASET v1.0 Category: System process viewer ; Style: Romeo and Juliet
/* Act I: Introduction */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

int main(void) {
    printf("Enter fair command, and all processes separate in thy view,\n"
           "By name, pid, or memory usage distinguish them true:\n"
           "To list them all, thou canst enter ls,\n"
           "But for specific ones, thou shalt enter with success.\n");
           
    /* Act II: Gathering Information */
    
    DIR *dir;
    struct dirent *entry;
    FILE *f;
    char path[256], cmd[256], buf[1024];
    char name[50], state[10];
    int pid, ppid, pgrp, session, tty_nr, tpgid;
    unsigned int utime, stime, cutime, cstime, starttime;
    unsigned long long int start_time, total_time, seconds, kilobytes, memory, vmsize;
    long int jiffies;
    
    while(1) {
        printf("\nEnter your command: ");
        fflush(stdout);
        fgets(cmd, 256, stdin);
        strtok(cmd, "\n"); // Remove the newline character
        
        if (strcmp(cmd, "ls") == 0) {
            dir = opendir("/proc");
            printf("\n");
            printf("%12s  %5s %10s %8s %5s  %7s  %s\n",
                   "Name", "PID", "Memory", "STATE", "PPID", "SESSION", "TTY_NR");
            while ((entry = readdir(dir)) != NULL) {
                if (atoi(entry->d_name) != 0) {
                    // It is a valid process
                    sprintf(path, "/proc/%s/stat", entry->d_name);
                    f = fopen(path, "r");
                    fscanf(f, "%d %s %s %d %d %d %d %d %u %u %u %u %lu",
                           &pid, name, state, &ppid, &pgrp, &session, &tty_nr,
                           &tpgid, &utime, &stime, &cutime, &cstime, &starttime);
                    fclose(f);
                    kilobytes = 0;
                    sprintf(path, "/proc/%s/statm", entry->d_name);
                    f = fopen(path, "r");
                    fgets(buf, 1024, f);
                    sscanf(buf, "%llu %llu", &vmsize, &memory);
                    kilobytes = memory/1024;
                    printf("%12s  %5d %10llu %8s %5d  %7d  %d\n", name, pid, kilobytes, state, ppid, session, tty_nr);
                    fclose(f);
                }
            }
            closedir(dir);
        } else {
            // Find the process by ID or name
            int is_id = 1;
            for (int i=0; i<strlen(cmd); i++) {
                if (cmd[i] < '0' || cmd[i] > '9') {
                    is_id = 0; // It's not a number, so it must be a process name
                    break;
                }
            }
            if (is_id) {
                // Find the process by ID
                sprintf(path, "/proc/%s/stat", cmd);
                f = fopen(path, "r");
                if (f == NULL) {
                    printf("No such process found.\n");
                    continue;
                }
                fscanf(f, "%d %s %s %d %d %d %d %d %u %u %u %u %lu",
                       &pid, name, state, &ppid, &pgrp, &session, &tty_nr,
                       &tpgid, &utime, &stime, &cutime, &cstime, &starttime);
                fclose(f);
                kilobytes = 0;
                sprintf(path, "/proc/%s/statm", cmd);
                f = fopen(path, "r");
                fgets(buf, 1024, f);
                sscanf(buf, "%llu %llu", &vmsize, &memory);
                kilobytes = memory/1024;
                printf("\nProcess Name: %s\n", name);
                printf("Process ID: %d\n", pid);
                printf("Parent Process ID: %d\n", ppid);
                printf("Virtual Memory Size: %llu KB\n", vmsize);
                printf("Resident Set Size: %llu KB\n", kilobytes);
                fclose(f);
            } else {
                // Find the process by name
                dir = opendir("/proc");
                int found = 0;
                printf("\n");
                printf("%12s  %5s %10s %8s %5s  %7s  %s\n",
                       "Name", "PID", "Memory", "STATE", "PPID", "SESSION", "TTY_NR");
                while ((entry = readdir(dir)) != NULL) {
                    if (atoi(entry->d_name) != 0) {
                        // It is a valid process
                        sprintf(path, "/proc/%s/stat", entry->d_name);
                        f = fopen(path, "r");
                        fscanf(f, "%d %s %s %d %d %d %d %d %u %u %u %u %lu",
                               &pid, name, state, &ppid, &pgrp, &session, &tty_nr,
                               &tpgid, &utime, &stime, &cutime, &cstime, &starttime);
                        fclose(f);
                        if (strcmp(name, cmd) == 0) {
                            found = 1;
                            kilobytes = 0;
                            sprintf(path, "/proc/%s/statm", entry->d_name);
                            f = fopen(path, "r");
                            fgets(buf, 1024, f);
                            sscanf(buf, "%llu %llu", &vmsize, &memory);
                            kilobytes = memory/1024;
                            printf("%12s  %5d %10llu %8s %5d  %7d  %d\n", name, pid, kilobytes, state, ppid, session, tty_nr);
                            fclose(f);
                        }
                    }
                }
                closedir(dir);
                if (!found) printf("No such process found.\n");
            }
        }
    }
    return 0;
}

/* Epilogue: Farewell */