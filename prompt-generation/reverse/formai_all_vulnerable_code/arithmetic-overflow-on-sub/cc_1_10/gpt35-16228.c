//FormAI DATASET v1.0 Category: System process viewer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_PID_LENGTH 6
#define MAX_NAME_LENGTH 255

// Function to check if a string is a number
int is_number(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

// Function to convert a string to int
int to_int(char *str) {
    int result = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        result = result * 10 + (str[i] - '0');
    }
    return result;
}

// Function to get the process name from the pid
char* get_process_name(int pid) {
    char *path = (char*) malloc(sizeof(char) * (strlen("/proc/") + MAX_PID_LENGTH + strlen("/comm")));
    sprintf(path, "/proc/%d/comm", pid);
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        free(path);
        return NULL;
    }
    char *buffer = (char*) malloc(sizeof(char) * (MAX_NAME_LENGTH + 1));
    int read_count = read(fd, buffer, MAX_NAME_LENGTH);
    if (read_count <= 0) {
        free(path);
        free(buffer);
        return NULL;
    }
    close(fd);
    buffer[read_count - 1] = '\0';
    return buffer;
}

// Function to display the process info
void display_process_info(int pid) {
    char *name = get_process_name(pid);
    printf("%-6d%-25s\n", pid, name == NULL ? "Unknown" : name);
    if (name != NULL) {
        free(name);
    }
}

// Function to display the process table header
void display_table_header() {
    printf("%-6s%-25s\n", "PID", "PROCESS NAME");
    printf("---------------------------------\n");
}

int main() {
    DIR *dir;
    struct dirent *entry;
    char *end_ptr;
    char pid_str[MAX_PID_LENGTH];
    int pid;

    display_table_header();

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Unable to open directory [/proc]");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        // Check if the entry is a directory and is numeric
        if (entry->d_type == DT_DIR && is_number(entry->d_name)) {
            pid = strtol(entry->d_name, &end_ptr, 10);
            if (*end_ptr == '\0') {
                display_process_info(pid);
            }
        }
    }

    closedir(dir);

    return 0;
}