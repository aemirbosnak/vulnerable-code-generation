//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PATH 256
#define MAX_LINE_LENGTH 256

void print_process_info(const char* pid) {
    char path[MAX_PATH];
    snprintf(path, sizeof(path), "/proc/%s/stat", pid);

    FILE* file = fopen(path, "r");
    if (!file) {
        return;
    }

    char comm[256];
    char state;
    unsigned long min_flt, cmin_flt, maj_flt, cmaj_flt, utime, stime, cutime, cstime, priority, nice, it_real_value, starttime;
    
    fscanf(file, "%*d %s %c %*d %*d %*d %*d %*d %*d %*d %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu",
           comm, &state, &min_flt, &cmin_flt, &maj_flt, &cmaj_flt, &utime, &stime, &priority, &nice, &it_real_value, &starttime);

    fclose(file);
    
    // Calculating memory usage
    snprintf(path, sizeof(path), "/proc/%s/statm", pid);
    file = fopen(path, "r");
    if (!file) {
        return;
    }
    unsigned long size, resident, share, text, lib, data, dt;
    fscanf(file, "%lu %lu %lu %lu %lu %lu %lu", &size, &resident, &share, &text, &lib, &data, &dt);
    fclose(file);
    
    // Displaying the process information
    printf("PID: %s | Command: %s | State: %c | Memory: %lu KB\n", pid, comm, state, resident * (getpagesize() / 1024));
}

void list_processes() {
    DIR* dir = opendir("/proc");
    struct dirent* entry;

    if (!dir) {
        perror("opendir");
        return;
    }

    printf("List of currently running processes:\n");
    printf("------------------------------------------------------------\n");
    
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            print_process_info(entry->d_name);
        }
    }
    
    closedir(dir);
}

int main() {
    printf("System Process Viewer\n");
    printf("Press Ctrl+C to exit...\n\n");
    
    while (1) {
        list_processes();
        sleep(5);  // Refresh every 5 seconds
        printf("\033c"); // Clear console
    }

    return 0;
}