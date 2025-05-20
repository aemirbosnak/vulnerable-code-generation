//FormAI DATASET v1.0 Category: System process viewer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX_BUF_SIZE 1024

struct proc_stats {
    char name[MAX_BUF_SIZE];
    int pid;
    char state;
    unsigned int utime;
    unsigned int stime;
    unsigned long long vsize;
};

int parse_process_stat(const char* path, struct proc_stats* stats) {
    FILE* fp;
    char buf[MAX_BUF_SIZE];
    int ret = 0;

    fp = fopen(path, "r");
    if (fp != NULL) {
        fgets(buf, MAX_BUF_SIZE, fp);
        sscanf(buf, "%d %s %c", &stats->pid, stats->name, &stats->state);

        for (int i = 0; i < 13; i++) {
            fgets(buf, MAX_BUF_SIZE, fp);
            switch (i) {
                case 12:
                    sscanf(buf, "voluntary_ctxt_switches: %u", &stats->utime);
                    break;
                case 13:
                    sscanf(buf, "nonvoluntary_ctxt_switches: %u", &stats->stime);
                    break;
                default:
                    break;
            }
        }

        fclose(fp);
        ret = 1;
    }

    return ret;
}

void list_processes() {
    pid_t pid;
    DIR* dir;
    struct dirent* ent;
    char path[MAX_BUF_SIZE];
    struct proc_stats stats;

    printf("%-15s %-7s %-7s %-7s %-7s %-15s\n",
           "Name", "PID", "State", "Utime", "Stime", "Vsize");
    printf("--------------------------------------------------------\n");

    dir = opendir("/proc");
    if (dir != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            pid = strtol(ent->d_name, NULL, 10);
            if (pid > 0) {
                sprintf(path, "/proc/%d/stat", pid);
                if (parse_process_stat(path, &stats)) {
                    printf("%-15s %-7d %-7c %-7u %-7u %-15llu\n",
                           stats.name, stats.pid, stats.state,
                           stats.utime, stats.stime, stats.vsize);
                }
            }
        }
        closedir(dir);
    }
}

int main() {
    list_processes();

    return 0;
}