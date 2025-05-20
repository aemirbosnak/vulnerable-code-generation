//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define STAT_PATH "/proc/stat"
#define PROC_PATH "/proc/"
#define STATUS_FILE "/status"

// Data structure to represent a process.
typedef struct {
    int pid;
    char comm[256];
    char state[16];
} Process;

// Function prototypes
void list_processes(Process *processes, int *count);
void display_processes(Process *processes, int count);
void print_process_info(int pid);
void show_menu();

int main() {
    Process processes[MAX_PROCESSES];
    int process_count = 0;

    while(1) {
        // Refresh and list processes
        list_processes(processes, &process_count);
        display_processes(processes, process_count);

        show_menu();

        char choice;
        printf("Select an option (v = view info, q = quit): ");
        scanf(" %c", &choice);

        if (choice == 'q') {
            break; // Exit the program
        } else if (choice == 'v') {
            int pid;
            printf("Enter PID to view details: ");
            scanf("%d", &pid);
            print_process_info(pid);
            printf("\nPress enter to continue...");
            getchar(); // consume newline
            getchar(); // wait for user to press enter
        }
    }

    return 0;
}

void list_processes(Process *processes, int *count) {
    DIR *dir = opendir(PROC_PATH);
    struct dirent *entry;
    *count = 0;

    if (dir == NULL) {
        perror("Failed to open /proc");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Check if the directory name is a number (PID)
            if (isdigit(entry->d_name[0])) {
                int pid = atoi(entry->d_name);
                char stat_file[256];
                snprintf(stat_file, sizeof(stat_file), "%s%s/stat", PROC_PATH, entry->d_name);
                FILE *file = fopen(stat_file, "r");
                if (file) {
                    fscanf(file, "%d %s %s", &processes[*count].pid, processes[*count].comm, processes[*count].state);
                    fclose(file);
                    (*count)++;
                }
            }
        }
    }
    closedir(dir);
}

void display_processes(Process *processes, int count) {
    printf("\nPID\tCOMMAND\t\tSTATE\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-15s\t%s\n", processes[i].pid, processes[i].comm, processes[i].state);
    }
    printf("\nTotal processes: %d\n", count);
}

void print_process_info(int pid) {
    char status_file[256];
    snprintf(status_file, sizeof(status_file), "%s%d%s", PROC_PATH, pid, STATUS_FILE);

    FILE *file = fopen(status_file, "r");
    if (file != NULL) {
        char line[256];
        printf("\nProcess Information for PID %d:\n", pid);
        printf("------------------------------------------\n");
        while (fgets(line, sizeof(line), file)) {
            if (strstr(line, "Name:") || strstr(line, "State:") ||
                strstr(line, "Pid:") || strstr(line, "Uid:")) {
                printf("%s", line);
            }
        }
        fclose(file);
    } else {
        printf("No information found for PID %d.\n", pid);
    }
}

void show_menu() {
    printf("\nMenu:\n");
    printf("v - View process information\n");
    printf("q - Quit the program\n");
}