//FormAI DATASET v1.0 Category: System process viewer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define MAX_PID 32768
#define MAX_PATH 1024

struct proc_info {
    int pid;
    char name[MAX_PATH];
    char state;
    char cmdline[MAX_PATH];
};

int count_chars(const char *str, char ch) {
    int count = 0;
    const char *p = str;
    while (*p != '\0') {
        if (*p == ch) {
            count++;
        }
        p++;
    }
    return count;
}

void parse_cmdline(const char *cmdline, char *out) {
    const char *p = cmdline;
    while (*p != '\0' && !isspace(*p)) {
        *out++ = *p++;
    }
    *out = '\0';
}

void print_proc_info(struct proc_info *info) {
    printf("%5d %c %-20s %s\n", info->pid, info->state, info->name, info->cmdline);
}

int main() {
    DIR *dirp = opendir("/proc");
    if (dirp == NULL) {
        perror("opendir failed");
        exit(EXIT_FAILURE);
    }

    struct proc_info processes[MAX_PID];
    int num_processes = 0;

    struct dirent *direntp;
    while ((direntp = readdir(dirp))) {
        if (!isdigit(direntp->d_name[0])) {
            continue;
        }
        int pid = atoi(direntp->d_name);

        char stat_path[MAX_PATH];
        sprintf(stat_path, "/proc/%d/stat", pid);

        FILE *f = fopen(stat_path, "r");
        if (f == NULL) {
            continue;
        }

        int n = fscanf(f, "%d %s %c", &pid, processes[num_processes].name, &processes[num_processes].state);
        fclose(f);
        if (n != 3) {
            continue;
        }

        char cmdline_path[MAX_PATH];
        sprintf(cmdline_path, "/proc/%d/cmdline", pid);
        f = fopen(cmdline_path, "r");
        if (f == NULL) {
            continue;
        }

        char cmdline[MAX_PATH];
        fgets(cmdline, MAX_PATH, f);
        fclose(f);

        parse_cmdline(cmdline, processes[num_processes].cmdline);
        processes[num_processes].pid = pid;
        num_processes++;
    }

    closedir(dirp);

    printf("%5s %1s %-20s %s\n", "PID", "S", "COMMAND", "CMDLINE");
    for (int i = 0; i < num_processes; i++) {
        print_proc_info(&processes[i]);
    }

    return 0;
}