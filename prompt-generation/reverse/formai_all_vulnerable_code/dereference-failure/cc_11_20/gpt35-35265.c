//FormAI DATASET v1.0 Category: System process viewer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/* Define the maximum allowed length of a process name */
#define MAX_PROCESS_NAME_LENGTH 255

/* Define the maximum allowed length of a command-line argument */
#define MAX_ARGUMENT_LENGTH 1024

/* Define the maximum allowed number of arguments per process */
#define MAX_ARGUMENT_COUNT 1024

/* Define the maximum allowed length of a PID string */
#define MAX_PID_LENGTH 16

/* Define the maximum allowed length of a status file path */
#define MAX_STATUS_FILE_PATH_LENGTH 1024

/* The status of a process */
typedef struct process_status_t {
    char name[MAX_PROCESS_NAME_LENGTH];
    pid_t pid;
    uid_t uid;
    int memory;
    int ppid;
    char state;
} process_status_t;

/* Get the process status from the given status file path */
int get_process_status(const char* status_file_path, process_status_t* process_status) {
    FILE* status_file = fopen(status_file_path, "r");
    if (status_file == NULL) {
        return -1;
    }

    char line[MAX_ARGUMENT_LENGTH];
    while (fgets(line, sizeof(line), status_file) != NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            char* name = line + 5;
            while (*name && isspace(*name)) {
                name++;
            }
            strncpy(process_status->name, name, MAX_PROCESS_NAME_LENGTH);
            char* space = strchr(process_status->name, ' ');
            if (space) {
                *space = '\0';
            }
        } else if (strncmp(line, "Pid:", 4) == 0) {
            char* pid = line + 4;
            while (*pid && isspace(*pid)) {
                pid++;
            }
            process_status->pid = atoi(pid);
        } else if (strncmp(line, "Uid:", 4) == 0) {
            char* uid = line + 4;
            while (*uid && isspace(*uid)) {
                uid++;
            }
            process_status->uid = atoi(uid);
        } else if (strncmp(line, "VmSize:", 7) == 0) {
            char* memory = line + 7;
            while (*memory && isspace(*memory)) {
                memory++;
            }
            process_status->memory = atoi(memory);
        } else if (strncmp(line, "PPid:", 5) == 0) {
            char* ppid = line + 5;
            while (*ppid && isspace(*ppid)) {
                ppid++;
            }
            process_status->ppid = atoi(ppid);
        } else if (strncmp(line, "State:", 6) == 0) {
            char* state = line + 6;
            while (*state && isspace(*state)) {
                state++;
            }
            process_status->state = *state;
        }
    }

    fclose(status_file);

    return 0;
}

/* Get the command-line arguments of the process with the given PID */
int get_process_arguments(pid_t pid, char** arguments, int max_argument_count) {
    char status_file_path[MAX_STATUS_FILE_PATH_LENGTH];
    snprintf(status_file_path, MAX_STATUS_FILE_PATH_LENGTH, "/proc/%d/cmdline", pid);
    FILE* status_file = fopen(status_file_path, "r");
    if (status_file == NULL) {
        return -1;
    }

    int argument_index = 0;
    int argument_length = 0;
    int c;
    while ((c = fgetc(status_file)) != EOF && argument_index < max_argument_count - 1) {
        if (c == '\0') {
            if (argument_length > 0) {
                arguments[argument_index] = (char*)malloc(argument_length + 1);
                memcpy(arguments[argument_index], arguments[argument_index - 1] + strlen(arguments[argument_index - 1]) + 1, argument_length);
                arguments[argument_index][argument_length] = '\0';
                argument_length = 0;
            }
            argument_index++;
        } else {
            if (argument_length == 0) {
                arguments[argument_index] = (char*)malloc(MAX_ARGUMENT_LENGTH + 1);
                memset(arguments[argument_index], 0, MAX_ARGUMENT_LENGTH + 1);
            }
            arguments[argument_index][argument_length] = (char)c;
            argument_length++;
        }
    }
    fclose(status_file);

    if (argument_length > 0 && argument_index < max_argument_count - 1) {
        arguments[argument_index] = (char*)malloc(argument_length + 1);
        memcpy(arguments[argument_index], arguments[argument_index - 1] + strlen(arguments[argument_index - 1]) + 1, argument_length);
        arguments[argument_index][argument_length] = '\0';
        argument_index++;
    }
    arguments[argument_index] = NULL;

    return 0;
}

/* Main entry point */
int main(int argc, char** argv) {
    DIR* directory = opendir("/proc");
    if (directory == NULL) {
        fprintf(stderr, "Unable to open /proc.\n");
        return -1;
    }

    struct dirent* ep;
    char pid_str[MAX_PID_LENGTH];
    while ((ep = readdir(directory))) {
        if (ep->d_type == DT_DIR && isdigit(ep->d_name[0])) {
            pid_t pid = atoi(ep->d_name);
            snprintf(pid_str, MAX_PID_LENGTH, "%d", pid);
            char status_file_path[MAX_STATUS_FILE_PATH_LENGTH];
            snprintf(status_file_path, MAX_STATUS_FILE_PATH_LENGTH, "/proc/%s/status", pid_str);
            process_status_t process_status;
            if (get_process_status(status_file_path, &process_status) == 0) {
                printf("%-30s %5s %5d %5d %5d %c ", process_status.name, pid_str, (int)process_status.ppid, (int)process_status.uid, (int)process_status.memory, process_status.state);

                char* arguments[MAX_ARGUMENT_COUNT];
                if (get_process_arguments(process_status.pid, arguments, MAX_ARGUMENT_COUNT) == 0) {
                    for (int i = 0; arguments[i] != NULL; i++) {
                        printf("%s ", arguments[i]);
                    }
                }

                printf("\n");

                for (int i = 0; arguments[i] != NULL; i++) {
                    free(arguments[i]);
                }
            }
        }
    }

    closedir(directory);

    return 0;
}