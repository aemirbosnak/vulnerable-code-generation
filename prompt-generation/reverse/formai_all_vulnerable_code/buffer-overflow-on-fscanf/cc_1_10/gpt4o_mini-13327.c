//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>

#define BUFFER_SIZE 256
#define PROC_DIR "/proc"

// Global variable to control the refresh thread
volatile int keep_running = 1;

// Function to clean up and exit
void handle_exit(int sig) {
    keep_running = 0;
}

// Function to display the processes
void *display_processes(void *arg) {
    while (keep_running) {
        system("clear");
        printf("----- Process Viewer -----\n");
        DIR *dir;
        struct dirent *entry;

        if ((dir = opendir(PROC_DIR)) == NULL) {
            perror("opendir");
            exit(EXIT_FAILURE);
        }

        // Iterate through the /proc directory
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_type == DT_DIR) {
                // Check if the directory name is a number (indicating a PID)
                if (isdigit(entry->d_name[0])) {
                    char path[BUFFER_SIZE];
                    snprintf(path, sizeof(path), "%s/%s/stat", PROC_DIR, entry->d_name);
                    FILE *fp = fopen(path, "r");
                    if (fp) {
                        int pid;
                        char comm[BUFFER_SIZE];
                        char state;
                        fscanf(fp, "%d %s %c", &pid, comm, &state);
                        fclose(fp);
                        printf("PID: %-6d COMMAND: %-20s STATE: %c\n", pid, comm, state);
                    }
                }
            }
        }
        closedir(dir);
        sleep(2); // Refresh every 2 seconds
    }
    return NULL;
}

int main() {
    signal(SIGINT, handle_exit); // Catch Ctrl+C to exit gracefully

    pthread_t thread_id;

    // Create a thread for displaying processes
    if (pthread_create(&thread_id, NULL, display_processes, NULL) != 0) {
        perror("pthread_create");
        return EXIT_FAILURE;
    }

    // Wait for the display thread to complete
    pthread_join(thread_id, NULL);

    printf("\nExiting Process Viewer...\n");
    return EXIT_SUCCESS;
}