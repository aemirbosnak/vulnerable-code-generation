//FormAI DATASET v1.0 Category: System process viewer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 256

struct process {
    char p_name[MAX_LEN];
    char p_state[MAX_LEN];
    int p_pid, p_ppid;
    long p_vmsize, p_vmpeak;
};

void show_processes() {
    DIR *dp;
    struct dirent *ep;

    printf("Processes:\n");
    printf("--------------------------------------------------\n");
    printf("|  PID  |  PPID  |   STATE   |   NAME   | VMSIZE |\n");
    printf("--------------------------------------------------\n");

    dp = opendir("/proc");
    if (dp != NULL) {
        while ((ep = readdir(dp))) {
            int pid = atoi(ep->d_name);
            if (pid != 0) {
                char status_file[MAX_LEN];
                char cmdline_file[MAX_LEN];
                snprintf(status_file, sizeof(status_file), "/proc/%d/status", pid);
                snprintf(cmdline_file, sizeof(cmdline_file), "/proc/%d/cmdline", pid);

                FILE *fp = fopen(status_file, "r");
                FILE *fp_cmd = fopen(cmdline_file, "r");
                if (!fp || !fp_cmd) {
                    continue;
                }

                struct process p = { "", "", pid, 0, 0, 0 };
                char line[MAX_LEN];
                while (fgets(line, MAX_LEN, fp)) {
                    char key[MAX_LEN], value[MAX_LEN];
                    sscanf(line, "%s %s", key, value);

                    if (strcmp(key, "Name:") == 0) {
                        strcpy(p.p_name, value);
                    } else if (strcmp(key, "State:") == 0) {
                        strcpy(p.p_state, value);
                    } else if (strcmp(key, "Pid:") == 0) {
                        p.p_pid = atoi(value);
                    } else if (strcmp(key, "PPid:") == 0) {
                        p.p_ppid = atoi(value);
                    } else if (strcmp(key, "VmSize:") == 0) {
                        p.p_vmsize = atol(value);
                    } else if (strcmp(key, "VmPeak:") == 0) {
                        p.p_vmpeak = atol(value);
                    }
                }

                char cmd_line[MAX_LEN];
                fgets(cmd_line, sizeof(cmd_line), fp_cmd);
                fclose(fp);
                fclose(fp_cmd);

                printf("| %5d | %5d  | %-9s | %-8s | %6ld |\n", p.p_pid, p.p_ppid, p.p_state, p.p_name, p.p_vmsize);
            }
        }
        closedir(dp);
    } else {
        perror("Could not open process directory");
    }

    printf("--------------------------------------------------\n");
}

int main() {
    printf("Welcome to the Medieval Process Viewer!\n");
    printf("Thou shall view thy processes, thy lord.\n");

    while (1) {
        printf("\nEnter thy command:\n");
        printf("[1] Show running processes\n");
        printf("[2] Seed the peasants (Exit the program)\n");

        int cmd;
        scanf("%d", &cmd);

        switch (cmd) {
            case 1:
                show_processes();
                break;
            case 2:
                printf("Farewell, thy lord!\n");
                exit(0);
            default:
                printf("I don't understand thy command.\n");
                break;
        }
    }

    return 0;
}