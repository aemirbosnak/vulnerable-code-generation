//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define BUFFER_SIZE 256

typedef struct {
    pid_t pid;
    uid_t uid;
    char command[BUFFER_SIZE];
} Process;

void trim_whitespace(char *str) {
    char *end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    *(end+1) = '\0';
}

int is_number(const char *s) {
    while (*s) {
        if (!isdigit(*s)) return 0;
        s++;
    }
    return 1;
}

void get_process_info(pid_t pid, Process *p) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "/proc/%d/status", pid);
    
    FILE *file = fopen(path, "r");
    if (!file) {
        return; // Process may have terminated
    }
    
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        if (sscanf(buffer, "Pid:\t%d", &p->pid) == 1)
            ;
        else if (sscanf(buffer, "Uid:\t%d", &p->uid) == 1)
            ;
        else if (strncmp(buffer, "Name:", 5) == 0) {
            strcpy(p->command, buffer + 6);
            trim_whitespace(p->command);
        }
    }
    fclose(file);
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");
    if (!dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    Process processes[1024];
    int count = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (is_number(entry->d_name)) {
            pid_t pid = atoi(entry->d_name);
            get_process_info(pid, &processes[count]);
            count++;
        }
    }
    closedir(dir);

    printf("%-10s %-10s %-50s\n", "PID", "UID", "COMMAND");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-10d %-50s\n", processes[i].pid, processes[i].uid, processes[i].command);
    }
}

int main() {
    printf("Process Viewer\n");
    printf("=============================\n");
    list_processes();
    return 0;
}