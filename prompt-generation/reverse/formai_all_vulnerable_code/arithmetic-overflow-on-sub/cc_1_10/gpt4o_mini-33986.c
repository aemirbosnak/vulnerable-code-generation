//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <pthread.h>
#include <time.h>

#define EXIT_COMMAND "exit"
#define UPDATE_INTERVAL 2  // Time interval for updating memory usage in seconds

// Function to fetch memory usage statistics
void getMemoryUsage(long *total, long *free, long *used) {
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        *total = info.totalram;
        *free = info.freeram;
        *used = *total - *free;
    } else {
        perror("sysinfo");
        exit(EXIT_FAILURE);
    }
}

// Function to convert bytes to a human-readable format
void formatMemorySize(long size, char *output, size_t len) {
    const char *units[] = {"B", "KB", "MB", "GB"};
    int unit = 0;
    double sizeDouble = size;
    
    while (sizeDouble >= 1024.0 && unit < 3) {
        sizeDouble /= 1024.0;
        unit++;
    }
    
    snprintf(output, len, "%.2f %s", sizeDouble, units[unit]);
}

// Thread function to continuously monitor memory usage
void *memoryMonitor(void *arg) {
    while (1) {
        long total, free, used;
        getMemoryUsage(&total, &free, &used);

        char totalStr[20], freeStr[20], usedStr[20];
        formatMemorySize(total, totalStr, sizeof(totalStr));
        formatMemorySize(free, freeStr, sizeof(freeStr));
        formatMemorySize(used, usedStr, sizeof(usedStr));
        
        printf("\rTotal Memory: %s | Free Memory: %s | Used Memory: %s", totalStr, freeStr, usedStr);
        fflush(stdout);
        
        sleep(UPDATE_INTERVAL);
    }
    return NULL;
}

// Function to handle user input for exiting the program
void handleUserInput() {
    char command[100];

    while (1) {
        printf("\nType '%s' to exit: ", EXIT_COMMAND);
        fgets(command, sizeof(command), stdin);
        
        command[strcspn(command, "\n")] = 0;  // Remove newline
        if (strcmp(command, EXIT_COMMAND) == 0) {
            printf("Exiting memory monitor program.\n");
            exit(EXIT_SUCCESS);
        }
    }
}

int main() {
    pthread_t monitorThread;

    // Create a thread to monitor memory usage
    if (pthread_create(&monitorThread, NULL, memoryMonitor, NULL) != 0) {
        perror("Failed to create thread");
        return EXIT_FAILURE;
    }

    // Handle user input in the main thread
    handleUserInput();

    // Clean up before exit (though in this case, we won't reach here)
    pthread_cancel(monitorThread);
    pthread_join(monitorThread, NULL);
    return EXIT_SUCCESS;
}