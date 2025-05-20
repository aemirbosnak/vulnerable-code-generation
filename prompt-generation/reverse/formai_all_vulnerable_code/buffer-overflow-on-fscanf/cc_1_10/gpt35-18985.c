//FormAI DATASET v1.0 Category: System process viewer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

// Struct which holds information for each process
typedef struct Process{
    char pid[10];
    char name[255];
    char state[10];
    char memory[10];
} Process;

// Returns true if a string represents an integer, false otherwise
int isInteger(char *str){
    while (*str){
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

// Returns the amount of memory used by a process given its PID
int getMemoryUsage(char *pid){
    char file_path[255];
    snprintf(file_path, sizeof(file_path), "/proc/%s/status", pid);

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(file_path, "r");
    if (fp == NULL){
        perror("Error opening file");
        return 0;
    }

    int memory_usage = 0;

    // Iterate through each line of the status file looking for VmRSS (amount of memory used)
    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "VmRSS:") != NULL){
            char *val = strtok(line, " ");
            val = strtok(NULL, " ");

            // Convert value to integer and return
            memory_usage = atoi(val);
            fclose(fp);
            if (line)
                free(line);
            return memory_usage;
        }
    }

    fclose(fp);
    if (line)
        free(line);
    return memory_usage;
}

// Main program
int main(){
    DIR *d;
    struct dirent *dir;
    d = opendir("/proc");

    if (d){
        // Create an array to hold all processes
        Process processes[1000];
        int num_processes = 0;

        // Iterate through each directory in /proc and check if it represents a process
        while ((dir = readdir(d)) != NULL){
            if (isInteger(dir->d_name)){
                // Get process information and add to array
                char pid[10];
                char name[255];
                char state[10];
                char memory[10];

                strcpy(pid, dir->d_name);

                char file_path[255];
                snprintf(file_path, sizeof(file_path), "/proc/%s/stat", pid);
                FILE *fp = fopen(file_path, "r");
                if (fp == NULL){
                    perror("Error opening file");
                    continue;
                }

                fscanf(fp, "%s %s %s", name, state, memory);

                strcpy(processes[num_processes].pid, pid);
                strcpy(processes[num_processes].name, name);
                strcpy(processes[num_processes].state, state);
                int mem_usage_kb = getMemoryUsage(pid);
                snprintf(memory, sizeof(memory), "%d kB", mem_usage_kb);
                strcpy(processes[num_processes].memory, memory);

                num_processes++;

                fclose(fp);
            }
        }

        closedir(d);

        // Print out all process information
        printf("%-10s %-20s %-10s %-10s\n", "PID", "NAME", "STATE", "MEMORY");

        for (int i = 0; i < num_processes; i++){
            printf("%-10s %-20s %-10s %-10s\n", processes[i].pid, processes[i].name, processes[i].state, processes[i].memory);
        }
    }
    else{
        printf("Could not open directory");
    }

    return 0;
}