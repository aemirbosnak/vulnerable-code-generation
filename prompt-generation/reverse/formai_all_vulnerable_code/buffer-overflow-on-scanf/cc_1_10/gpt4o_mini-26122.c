//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printLine(const char *line) {
    printf("%s\n", line);
}

void displaySystemInfo() {
    printLine("----- System Information -----");
    system("uname -a");
    system("uptime");
    printLine("------------------------------");
}

void checkDiskUsage() {
    printLine("----- Disk Usage -----");
    system("df -h");
    printLine("-----------------------");
}

void listLoggedInUsers() {
    printLine("----- Logged In Users -----");
    system("who");
    printLine("----------------------------");
}

void displayMenu() {
    printLine("----- System Admin Tool -----");
    printLine("1. Display System Information");
    printLine("2. Check Disk Usage");
    printLine("3. List Logged In Users");
    printLine("4. Exit");
    printLine("------------------------------");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        printLine("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printLine("Invalid input. Please enter a number between 1 and 4.");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                displaySystemInfo();
                break;
            case 2:
                checkDiskUsage();
                break;
            case 3:
                listLoggedInUsers();
                break;
            case 4:
                printLine("Exiting the program. Goodbye!");
                exit(0);
            default:
                printLine("Invalid choice. Please select an option from 1 to 4.");
                break;
        }
    }

    return 0;
}