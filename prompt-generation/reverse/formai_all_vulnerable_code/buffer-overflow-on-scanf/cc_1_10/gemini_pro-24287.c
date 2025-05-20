//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/syscall.h>

#define BUFSIZE 1024

int main() {
    int fd;
    char buf[BUFSIZE];
    int len;
    int pid;

    printf("Enter the PID of the process you want to inspect: ");
    scanf("%d", &pid);

    // Open the /proc/[pid]/status file
    char filename[256];
    sprintf(filename, "/proc/%d/status", pid);
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Read the entire file into a buffer
    len = read(fd, buf, BUFSIZE);
    if (len == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    // Close the file
    close(fd);

    // Parse the file and print the relevant information
    char *ptr;
    char *name;
    int state;
    int ppid;
    int uid;
    int gid;

    // Process name
    ptr = strstr(buf, "Name:");
    ptr += strlen("Name:");
    name = strtok(ptr, "\n");
    printf("Process name: %s\n", name);

    // Process state
    ptr = strstr(buf, "State:");
    ptr += strlen("State:");
    state = strtok(ptr, "\t\n")[0];
    printf("Process state: %c\n", state);

    // Parent process ID
    ptr = strstr(buf, "PPid:");
    ptr += strlen("PPid:");
    ppid = strtok(ptr, "\t\n");
    printf("Parent process ID: %d\n", ppid);

    // User ID
    ptr = strstr(buf, "Uid:");
    ptr += strlen("Uid:");
    uid = strtok(ptr, "\t\n");
    printf("User ID: %d\n", uid);

    // Group ID
    ptr = strstr(buf, "Gid:");
    ptr += strlen("Gid:");
    gid = strtok(ptr, "\t\n");
    printf("Group ID: %d\n", gid);

    return 0;
}