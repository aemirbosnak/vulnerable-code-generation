//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void displayMemoryUsage() {
    FILE *file = fopen("/proc/meminfo", "r");
    if (!file) {
        perror("Could not open meminfo");
        return;
    }

    char line[256];
    printf("\n🌟 Memory Usage Information 🌟\n");
    printf("===============================================\n");
    
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "MemTotal:", 8) == 0 || 
            strncmp(line, "MemFree:", 8) == 0 || 
            strncmp(line, "MemAvailable:", 13) == 0) {
            printf("%s", line);
        }
    }
    
    printf("===============================================\n");
    fclose(file);
}

void displayProcessUsage() {
    FILE *file = popen("ps aux --sort=-%mem", "r");
    if (!file) {
        perror("Could not open process list");
        return;
    }

    char line[256];
    printf("\n🛠️ Top 5 Processes by Memory Usage 🛠️\n");
    printf("===============================================\n");
    printf("%-10s  %-8s  %-10s  %s\n", "USER", "PID", "%MEM", "COMMAND");
    printf("===============================================\n");

    for (int i = 0; i < 5 && fgets(line, sizeof(line), file); i++) {
        char user[16], pid[8], mem[8], command[128];
        sscanf(line, "%15s %7s %7s %127[^\n]", user, pid, mem, command);
        printf("%-10s  %-8s  %-10s  %s\n", user, pid, mem, command);
    }
    
    printf("===============================================\n");
    pclose(file);
}

void showMenu() {
    printf("🌈 Welcome to the Happy RAM Monitor! 🌈\n");
    printf("===============================================\n");
    printf("1. Display Memory Usage\n");
    printf("2. Display Top Processes by Memory Usage\n");
    printf("3. Exit\n");
    printf("===============================================\n");
    printf("🍀 Please enter your choice (1-3): ");
}

int main() {
    int choice;
    
    do {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayMemoryUsage();
                break;
                
            case 2:
                displayProcessUsage();
                break;

            case 3:
                printf("😊 Thank you for using the Happy RAM Monitor! Goodbye! 😊\n");
                break;

            default:
                printf("🚫 Oops! That's not a valid option. Please try again! 🚫\n");
                break;
        }
        
        // A little pause to let the user digest the information before the next menu
        printf("\nPress Enter to continue...");
        while (getchar() != '\n'); // clearing out the input buffer
        getchar();

    } while (choice != 3);

    return 0;
}