//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LOG_ENTRIES 100
#define LOG_FILE "system_log.txt"

typedef struct {
    char timestamp[20];
    char action[50];
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];
int logCount = 0;

void logAction(const char *action) {
    if(logCount < MAX_LOG_ENTRIES) {
        FILE *file = fopen(LOG_FILE, "a");
        if (file == NULL) {
            perror("Could not open log file");
            return;
        }
        
        snprintf(logEntries[logCount].timestamp, 20, "%ld", time(NULL));
        snprintf(logEntries[logCount].action, 50, "%s", action);
        fprintf(file, "%s - %s\n", logEntries[logCount].timestamp, logEntries[logCount].action);
        fclose(file);
        logCount++;
        printf("Logged: %s\n", action);
    } else {
        printf("Log entries are full.\n");
    }
}

void displayLogs() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Could not read log file");
        return;
    }

    char line[100];
    printf("----- System Log -----\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void checkDiskSpace() {
    printf("Checking disk space...\n");
    // Using system call to fetch disk usage
    int result = system("df -h");
    if(result == -1) {
        logAction("Failed to check disk space.");
    } else {
        logAction("Checked disk space successfully.");
    }
}

void listUsers() {
    printf("Listing all users...\n");
    // Using system call to fetch the list of users
    int result = system("cut -d: -f1 /etc/passwd");
    if(result == -1) {
        logAction("Failed to list users.");
    } else {
        logAction("Listed users successfully.");
    }
}

void monitorProcesses() {
    printf("Monitoring current processes...\n");
    // Using system call to fetch current processes
    int result = system("ps aux");
    if(result == -1) {
        logAction("Failed to monitor processes.");
    } else {
        logAction("Monitored processes successfully.");
    }
}

void displayMenu() {
    printf("----- Sherlock Holmes System Administration -----\n");
    printf("1. Check Disk Space\n");
    printf("2. List Users\n");
    printf("3. Monitor Processes\n");
    printf("4. Display Logs\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                checkDiskSpace();
                break;
            case 2:
                listUsers();
                break;
            case 3:
                monitorProcesses();
                break;
            case 4:
                displayLogs();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                logAction("Exited the program.");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                logAction("Invalid choice attempted.");
        }
    }
    
    return 0;
}