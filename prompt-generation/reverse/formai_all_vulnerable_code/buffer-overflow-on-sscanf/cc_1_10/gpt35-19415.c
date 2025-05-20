//FormAI DATASET v1.0 Category: System process viewer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 25
#define MAX_PROC_FILES 1024

struct proc_info {
    int pid;
    char name[MAX_NAME_LENGTH];
    char status;
    int mem;
};

int get_proc_info(struct proc_info *proc_list) {
    DIR* proc_dir = opendir("/proc");
    struct dirent* proc_entry;
    int num_procs = 0;

    while ((proc_entry = readdir(proc_dir))) {
        char path[100];
        sprintf(path, "/proc/%s/status", proc_entry->d_name);
        FILE* proc_file = fopen(path, "r");
        char line[256];

        if (proc_file == NULL) {
            continue;
        }

        int pid;
        char name[MAX_NAME_LENGTH];
        char status;
        int mem;

        while (fgets(line, sizeof(line), proc_file)) {
            if (sscanf(line, "Pid: %d", &pid) == 1) {
                proc_list[num_procs].pid = pid;
            } else if (sscanf(line, "Name: %s", name) == 1) {
                strncpy(proc_list[num_procs].name, name, MAX_NAME_LENGTH - 1);
            } else if (sscanf(line, "State: %c", &status) == 1) {
                proc_list[num_procs].status = status;
            } else if (sscanf(line, "VmRSS: %d", &mem) == 1) {
                proc_list[num_procs].mem = mem;
                num_procs++;
            }
        }

        fclose(proc_file);
    }

    closedir(proc_dir);
    return num_procs;
}

void print_proc_info(struct proc_info *proc_list, int num_procs) {
    printf("PID\t\tNAME\t\tSTATUS\t\tMEM\n");

    for (int i = 0; i < num_procs; i++) {
        printf("%d\t\t%s\t\t%c\t\t%d\n", proc_list[i].pid, proc_list[i].name, proc_list[i].status, proc_list[i].mem);
    }
}

int main() {
    struct proc_info proc_list[MAX_PROC_FILES];
    int num_procs = get_proc_info(proc_list);
    print_proc_info(proc_list, num_procs);

    return 0;
}