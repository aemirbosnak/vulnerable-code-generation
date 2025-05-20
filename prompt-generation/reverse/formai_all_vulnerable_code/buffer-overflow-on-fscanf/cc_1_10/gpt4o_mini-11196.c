//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <pwd.h>
#include <time.h>
#include <limits.h>

#define PROC_DIR "/proc"
#define USERNAME_LENGTH 32

void check_for_suspicious_process(const char *process_name) {
    // List of suspicious process names for demonstration purposes
    const char *suspicious[] = {"malicious_process", "suspicious_app", NULL};
    for (int i = 0; suspicious[i] != NULL; i++) {
        if (strcmp(process_name, suspicious[i]) == 0) {
            printf("Alert: Suspicious process detected - %s\n", process_name);
        }
    }
}

void get_process_info(pid_t pid) {
    char path[PATH_MAX];
    snprintf(path, sizeof(path), "%s/%d/stat", PROC_DIR, pid);

    FILE *file = fopen(path, "r");
    if (!file) {
        fprintf(stderr, "Warning: Unable to open %s\n", path);
        return;
    }

    char state;
    char comm[256];
    unsigned long memory;
    fscanf(file, "%*d %s %c %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %lu", comm, &state, &memory);
    fclose(file);

    printf("PID: %d, Command: %s, State: %c, Memory: %lu\n", pid, comm, state, memory);
    check_for_suspicious_process(comm);
}

void list_processes() {
    DIR *dir = opendir(PROC_DIR);
    if (!dir) {
        fprintf(stderr, "Error: Could not open %s\n", PROC_DIR);
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Check if entry is a number (PID)
        if (entry->d_type == DT_DIR) {
            pid_t pid = atoi(entry->d_name);
            if (pid > 0) {
                get_process_info(pid);
            }
        }
    }
    closedir(dir);
}

void check_current_user() {
    char *username = getlogin();
    if (!username) {
        fprintf(stderr, "Error: Unable to get current user name\n");
        return;
    }
    printf("Current logged in user: %s\n", username);
}

void check_system_time() {
    time_t current_time = time(NULL);
    char *time_str = ctime(&current_time);
    printf("Current system time: %s", time_str);
}

void check_cpu_usage() {
    FILE *cpu_file = fopen("/proc/stat", "r");
    if (!cpu_file) {
        fprintf(stderr, "Error: Unable to open /proc/stat\n");
        return;
    }

    char buffer[256];
    fscanf(cpu_file, "%s", buffer); // Read "cpu" line

    unsigned long user, nice, system, idle, iowait;
    fscanf(cpu_file, "%lu %lu %lu %lu %lu", &user, &nice, &system, &idle, &iowait);
    fclose(cpu_file);

    unsigned long total = user + nice + system + idle + iowait;
    printf("CPU Usage - User: %lu, Nice: %lu, System: %lu, Idle: %lu, Total: %lu\n",
           user, nice, system, idle, total);
}

int main() {
    char continue_viewing = 'y';
    
    printf("=== Paranoid Process Viewer ===\n");
    
    while (continue_viewing == 'y') {
        printf("\n[INFO] Gathering system information...\n");
        check_current_user();
        check_system_time();
        check_cpu_usage();
        printf("\n[INFO] Active Processes:\n");
        list_processes();

        printf("\nDo you wish to continue viewing (y/n)? ");
        scanf(" %c", &continue_viewing);
        if (continue_viewing != 'y' && continue_viewing != 'n') {
            printf("Invalid input. Exiting...\n");
            break;
        }
    }

    printf("Goodbye! Stay vigilant!\n");
    return 0;
}