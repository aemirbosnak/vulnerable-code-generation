//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void list_processes() {
    printf("\n✨ Here are the current running processes! ✨\n");
    system("ps -aux");
}

void kill_process() {
    int pid;
    printf("\n🚨 Enter the Process ID (PID) you wish to terminate: ");
    scanf("%d", &pid);
    
    // Attempt to kill the process
    if (kill(pid, SIGTERM) == 0) {
        printf("✅ Successfully terminated the process with PID: %d\n", pid);
    } else {
        perror("❌ Failed to terminate the process");
    }
}

void check_uptime() {
    printf("\n⏳ Checking system uptime...\n");
    system("uptime");
}

void display_menu() {
    printf("\n🎉 Welcome to the Simple Linux System Administration Tool! 🎉\n");
    printf("1. List running processes\n");
    printf("2. Kill a process\n");
    printf("3. Check system uptime\n");
    printf("4. Exit\n");
    printf("Please choose an option (1-4): ");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_processes();
                break;
            case 2:
                kill_process();
                break;
            case 3:
                check_uptime();
                break;
            case 4:
                printf("🚀 Exiting the program. Have a great day! 🌈\n");
                exit(0);
            default:
                printf("❓ Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }
    
    return 0;
}