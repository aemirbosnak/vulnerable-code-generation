//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <libgen.h>
#include <dirent.h>
#include <sys/wait.h>

#define MAX_LINE_SIZE 1024
#define MAX_PROCESS_NAME_SIZE 64

// Function to read a line from a file and store it in a buffer
int read_line(FILE* file, char* buffer) {
    int bytes_read = 0;
    char c;
    while ((c = fgetc(file))!= EOF && bytes_read < MAX_LINE_SIZE - 1) {
        buffer[bytes_read++] = c;
    }
    buffer[bytes_read] = '\0';
    return bytes_read;
}

// Function to get the process name from a pid
char* get_process_name(int pid) {
    char path[MAX_PROCESS_NAME_SIZE];
    snprintf(path, MAX_PROCESS_NAME_SIZE, "/proc/%d/cmdline", pid);
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        return NULL;
    }
    char buffer[MAX_PROCESS_NAME_SIZE];
    int bytes_read = read_line(file, buffer);
    fclose(file);
    return strndup(buffer, bytes_read);
}

// Function to print process information
void print_process_info(int pid, char* name, int ppid, int state) {
    printf("PID: %d\n", pid);
    printf("Parent PID: %d\n", ppid);
    printf("Process name: %s\n", name);
    printf("Process state: %s\n", (state == 0)? "Zombie" : (state == 1)? "Sleeping" : (state == 2)? "Running" : (state == 3)? "Stopped" : "Unknown");
}

// Function to print all running processes
void print_processes() {
    DIR* dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        return;
    }
    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        int pid = atoi(entry->d_name);
        char* name = get_process_name(pid);
        int ppid = -1;
        int state = -1;
        if (name!= NULL) {
            char path[MAX_PROCESS_NAME_SIZE];
            snprintf(path, MAX_PROCESS_NAME_SIZE, "/proc/%d/status", pid);
            FILE* file = fopen(path, "r");
            if (file!= NULL) {
                char buffer[MAX_LINE_SIZE];
                while (fgets(buffer, MAX_LINE_SIZE, file)!= NULL) {
                    if (strncmp(buffer, "PPid:", 5) == 0) {
                        ppid = atoi(&buffer[5]);
                    } else if (strncmp(buffer, "State:", 6) == 0) {
                        state = atoi(&buffer[6]);
                    }
                }
                fclose(file);
            }
        }
        if (name!= NULL && ppid!= -1 && state!= -1) {
            print_process_info(pid, name, ppid, state);
        }
        free(name);
    }
    closedir(dir);
}

int main() {
    print_processes();
    return 0;
}