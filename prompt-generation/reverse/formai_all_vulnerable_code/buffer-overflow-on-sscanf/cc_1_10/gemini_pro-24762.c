//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <math.h>

// Declare global variables
pid_t pid;
int proc_count = 0;
struct dirent *dp;
DIR *dir;
char buf[1024];

// Define function prototypes
void print_process_info(pid_t pid);
void print_directory_tree(DIR *dir, int level);
void calculate_total_procs(DIR *dir);

int main(int argc, char *argv[]) {

    // Check if the user has provided a valid directory path
    if (argc != 2) {
        printf("Usage: %s <directory path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the specified directory
    dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Calculate the total number of processes in the system
    calculate_total_procs(dir);

    // Iterate through the directory and print the information about each process
    while ((dp = readdir(dir)) != NULL) {

        // Check if the current entry is a directory
        if (dp->d_type != DT_DIR) {
            continue;
        }

        // Check if the current entry is the current working directory
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }

        // Parse the process ID from the directory name
        sscanf(dp->d_name, "%d", &pid);

        // Print the process information
        print_process_info(pid);

        // Recursively print the directory tree for the current process
        print_directory_tree(dir, 1);
    }

    // Close the directory
    closedir(dir);

    // Print the total number of processes
    printf("Total number of processes: %d\n", proc_count);

    return EXIT_SUCCESS;
}

// Define function to print the process information
void print_process_info(pid_t pid) {

    // Read the file /proc/[pid]/stat
    sprintf(buf, "/proc/%d/stat", pid);
    int fd = open(buf, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    ssize_t bytes_read = read(fd, buf, sizeof(buf) - 1);
    if (bytes_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    close(fd);

    // Parse the process information from the stat file
    char name[256];
    int state;
    unsigned long int utime, stime;
    sscanf(buf, "%*d %s %*c %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %lu %lu", name, &state, &utime, &stime);

    // Print the process information
    printf("PID: %d\n", pid);
    printf("Name: %s\n", name);
    printf("State: %c\n", state);
    printf("User time: %lu\n", utime);
    printf("System time: %lu\n", stime);
}

// Define function to print the directory tree for a process
void print_directory_tree(DIR *dir, int level) {

    // Iterate through the directory and print the information about each entry
    while ((dp = readdir(dir)) != NULL) {

        // Check if the current entry is a directory
        if (dp->d_type != DT_DIR) {
            continue;
        }

        // Check if the current entry is the current working directory
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }

        // Print the directory entry
        for (int i = 0; i < level; i++) {
            printf("    ");
        }
        printf("%s\n", dp->d_name);

        // Recursively print the directory tree for the current entry
        print_directory_tree(dir, level + 1);
    }

    // Rewind the directory stream
    rewinddir(dir);
}

// Define function to calculate the total number of processes in the system
void calculate_total_procs(DIR *dir) {

    // Iterate through the directory and count the number of directories
    while ((dp = readdir(dir)) != NULL) {

        // Check if the current entry is a directory
        if (dp->d_type != DT_DIR) {
            continue;
        }

        // Check if the current entry is the current working directory
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }

        // Increment the process count
        proc_count++;
    }

    // Rewind the directory stream
    rewinddir(dir);
}