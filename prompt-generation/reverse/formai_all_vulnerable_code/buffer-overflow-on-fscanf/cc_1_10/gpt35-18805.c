//FormAI DATASET v1.0 Category: System process viewer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

// Struct to hold information of each process
struct process {
    char name[50];
    int pid;
    char status;
    int ppid;
    long unsigned int memory;
};

int main() {
    DIR *proc_dir = opendir("/proc");  // Open the directory containing information about processes
    struct dirent *dir_entry;  // Struct to hold information about directory entry

    printf("%-20s %-10s %-10s %-10s %-10s\n", "Process Name", "PID", "Status", "PPID", "Memory(KB)");

    // Loop through each directory entry and get information about each process
    while ((dir_entry = readdir(proc_dir)) != NULL) {
        if (dir_entry->d_name[0] < '0' || dir_entry->d_name[0] > '9') {
            continue;  // Only process directories with numeric names
        }
        int pid = atoi(dir_entry->d_name);
        char stat_filepath[50];
        sprintf(stat_filepath, "/proc/%d/stat", pid);
        FILE *stat_file = fopen(stat_filepath, "r");
        char name[50];
        char status;
        int ppid;
        fscanf(stat_file, "%d (%[^)]) %c %d", &pid, name, &status, &ppid);
        fclose(stat_file);

        char smaps_filepath[50];
        sprintf(smaps_filepath, "/proc/%d/smaps", pid);
        FILE *smaps_file = fopen(smaps_filepath, "r");
        char line[256];
        long unsigned int memory = 0;
        while (fgets(line, sizeof(line), smaps_file) != NULL) {
            if (strstr(line, "Rss:") != NULL) {
                char *mem_str = strtok(line, " \t");
                mem_str = strtok(NULL, " \t");
                memory += atoi(mem_str);
            }
        }
        fclose(smaps_file);

        printf("%-20s %-10d %-10c %-10d %-10lu\n", name, pid, status, ppid, memory);
    }

    closedir(proc_dir);
    return 0;
}