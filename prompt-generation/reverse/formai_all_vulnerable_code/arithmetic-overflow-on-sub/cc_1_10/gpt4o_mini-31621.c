//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printWelcomeMessage() {
    printf("========================================\n");
    printf("       Welcome to Time Travel Simulator  \n");
    printf("========================================\n");
}

void printCurrentDate() {
    time_t t;
    struct tm *tm_info;
    char buffer[26];

    time(&t);
    tm_info = localtime(&t);

    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Current date and time: %s\n", buffer);
}

int getUserChoice() {
    int choice;
    printf("Choose an option:\n");
    printf("1. Travel to the Past\n");
    printf("2. Travel to the Future\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void travelToPast(int years) {
    time_t t;
    struct tm *tm_info;
    char buffer[26];

    time(&t);
    tm_info = localtime(&t);

    tm_info->tm_year -= years;  // Subtract years from current year
    mktime(tm_info); // Normalize the time
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    
    printf("You've traveled %d years to the past!\n", years);
    printf("New date and time: %s\n", buffer);
}

void travelToFuture(int years) {
    time_t t;
    struct tm *tm_info;
    char buffer[26];

    time(&t);
    tm_info = localtime(&t);

    tm_info->tm_year += years;  // Add years to current year
    mktime(tm_info); // Normalize the time
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    
    printf("You've traveled %d years into the future!\n", years);
    printf("New date and time: %s\n", buffer);
}

int main() {
    printWelcomeMessage();
    printCurrentDate();
    
    int choice, years;
    while (1) {
        choice = getUserChoice();
        
        if (choice == 3) {
            printf("Exiting Time Travel Simulator. Safe travels!\n");
            break;
        }
        
        printf("Enter the number of years to travel: ");
        scanf("%d", &years);

        if (choice == 1) {
            if (years <= 0) {
                printf("You cannot travel to the past by less than or equal to zero years!\n");
            } else {
                travelToPast(years);
            }
        } else if (choice == 2) {
            if (years <= 0) {
                printf("You cannot travel to the future by less than or equal to zero years!\n");
            } else {
                travelToFuture(years);
            }
        } else {
            printf("Invalid choice! Please try again.\n");
        }
        
        printf("\n");
    }
    
    return 0;
}