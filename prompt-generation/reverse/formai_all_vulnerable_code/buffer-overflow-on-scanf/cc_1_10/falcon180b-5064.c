//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <ctype.h>
#include <dirent.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_PROCESS_NAME_LENGTH 16
#define MAX_PROCESS_ID_LENGTH 6

typedef struct process {
    char name[MAX_PROCESS_NAME_LENGTH];
    char id[MAX_PROCESS_ID_LENGTH];
    int pid;
    int status;
} process_t;

void print_process(process_t *process) {
    printf("Name: %s\n", process->name);
    printf("ID: %s\n", process->id);
    printf("PID: %d\n", process->pid);
    printf("Status: %d\n\n", process->status);
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    DIR *dir;
    struct dirent *ent;
    int num_processes = 0;
    process_t processes[100];

    printf("Enter command to list processes for: ");
    scanf("%s", command);

    dir = opendir("/proc");

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                int pid = atoi(ent->d_name);
                sprintf(command, "cat /proc/%d/cmdline", pid);
                FILE *fp = popen(command, "r");
                char process_name[MAX_PROCESS_NAME_LENGTH] = "";
                char process_id[MAX_PROCESS_ID_LENGTH] = "";

                if (fp!= NULL) {
                    fgets(process_name, MAX_PROCESS_NAME_LENGTH, fp);
                    fgets(process_id, MAX_PROCESS_ID_LENGTH, fp);
                    pclose(fp);
                }

                strncpy(processes[num_processes].name, process_name, MAX_PROCESS_NAME_LENGTH - 1);
                strncpy(processes[num_processes].id, process_id, MAX_PROCESS_ID_LENGTH - 1);
                processes[num_processes].pid = pid;
                processes[num_processes].status = 0;
                num_processes++;
            }
        }

        closedir(dir);

        printf("Processes:\n");

        for (int i = 0; i < num_processes; i++) {
            print_process(&processes[i]);
        }
    } else {
        perror("");
    }

    return 0;
}