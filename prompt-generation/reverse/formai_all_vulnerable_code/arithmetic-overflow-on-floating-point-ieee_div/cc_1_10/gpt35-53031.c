//FormAI DATASET v1.0 Category: System process viewer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// This is the function to check if a string is a number
int is_number(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// This is the function to calculate the CPU utilization
float calculate_cpu_utilization(unsigned long process_time, unsigned long uptime, unsigned long hertz) {
    float total_time = (float) process_time / (float) hertz;
    float seconds = (float) uptime / (float) hertz;
    return (total_time / seconds) * 100;
}

int main() {
    // Constants
    const char* PROC_DIRECTORY = "/proc";
    const int BUFFER_SIZE = 1024;
    const int HERTZ_PER_SECOND = (int) sysconf(_SC_CLK_TCK);

    // Variables
    DIR* dir;
    struct dirent* entry;
    char path[BUFFER_SIZE];
    char buf[BUFFER_SIZE];
    char* token;
    char* endptr;
    int pid;
    char* pname;
    char state;
    unsigned long uptime;
    unsigned long process_time;
    unsigned long hertz;
    float cpu_utilization;

    // Print header
    printf("%-8s %-40s %8s\n", "PID", "COMMAND", "%CPU");

    // Open /proc directory
    dir = opendir(PROC_DIRECTORY);
    if (dir == NULL) {
        perror("Failed to open /proc directory");
        exit(EXIT_FAILURE);
    }

    // Read /proc directory
    while ((entry = readdir(dir)) != NULL) {
        // Check if the entry is a PID directory
        if (is_number(entry->d_name)) {
            // Construct path to process directory
            sprintf(path, "%s/%s/stat", PROC_DIRECTORY, entry->d_name);
            
            // Open process stat file
            FILE* fp = fopen(path, "r");
            if (fp == NULL) {
                perror("Failed to open process stat file");
                continue;
            }

            // Read process stat file
            if (fgets(buf, BUFFER_SIZE, fp) == NULL) {
                perror("Failed to read process stat file");
                fclose(fp);
                continue;
            }

            // Extract PID, pname, state, uptime, and process_time from process stat file
            token = strtok(buf, " ");
            pid = atoi(token);
            token = strtok(NULL, " ");
            pname = token;
            token = strtok(NULL, " ");
            state = token[0];
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            uptime = strtoul(token, &endptr, 10);
            token = strtok(NULL, " ");
            process_time = strtoul(token, &endptr, 10);
            hertz = HERTZ_PER_SECOND;

            // Calculate CPU utilization
            cpu_utilization = calculate_cpu_utilization(process_time, uptime, hertz);

            // Print PID, pname, and %CPU
            printf("%-8d %-40s %8.2f\n", pid, pname, cpu_utilization);

            // Close process stat file
            fclose(fp);
        }
    }

    // Close /proc directory
    closedir(dir);

    return 0;
}