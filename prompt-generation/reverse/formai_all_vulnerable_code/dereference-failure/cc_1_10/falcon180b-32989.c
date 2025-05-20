//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LEN 1024

// Structure to store process information
typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LEN];
    int status;
} process_t;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [process_id]\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    char proc_file[20];
    sprintf(proc_file, "/proc/%d", pid);

    // Check if process exists
    if (access(proc_file, F_OK) == -1) {
        printf("Process not found.\n");
        return 1;
    }

    // Open process status file
    char status_file[30];
    sprintf(status_file, "/proc/%d/status", pid);
    int fd = open(status_file, O_RDONLY);
    if (fd == -1) {
        printf("Failed to open process status file.\n");
        return 1;
    }

    // Read process information
    process_t process;
    memset(&process, 0, sizeof(process_t));
    ssize_t bytes_read = read(fd, &process, sizeof(process_t));
    if (bytes_read!= sizeof(process_t)) {
        printf("Failed to read process information.\n");
        close(fd);
        return 1;
    }
    close(fd);

    // Print process information
    printf("Process ID: %d\n", process.pid);
    printf("Command: %s\n", process.command);
    printf("Status: %d\n", process.status);

    return 0;
}