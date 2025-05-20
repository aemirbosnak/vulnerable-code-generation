//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUF_SIZE 1024

void print_process_info(struct dirent *dir) {
    char path[BUF_SIZE];
    FILE *fp;
    char line[BUF_SIZE];
    pid_t pid;

    // Get the full path of the process directory
    sprintf(path, "/proc/%s", dir->d_name);

    // Open the process directory
    if ((fp = fopen(path, "r")) == NULL) {
        printf("Error: Cannot open %s\n", path);
        return;
    }

    // Read the first line which contains the process ID
    if (fgets(line, BUF_SIZE, fp) == NULL) {
        printf("Error: Cannot read %s\n", path);
        fclose(fp);
        return;
    }

    // Convert the string to a number
    sscanf(line, "%d", &pid);

    // Print the process name and ID
    printf("%s (PID %d)\n", dir->d_name, pid);

    fclose(fp);
}

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dir;

    if (argc!= 2) {
        printf("Usage: %s <process name>\n", argv[0]);
        return 1;
    }

    // Open the process directory
    if ((dp = opendir("/proc")) == NULL) {
        printf("Error: Cannot open /proc\n");
        return 1;
    }

    // Iterate through the process directories
    while ((dir = readdir(dp))!= NULL) {
        // Check if the process name matches
        if (strcmp(dir->d_name, argv[1]) == 0) {
            print_process_info(dir);
        }
    }

    // Close the process directory
    closedir(dp);

    return 0;
}