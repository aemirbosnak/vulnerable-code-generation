//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

void displayMenu() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Choose an option:\n");
    printf("1. Travel to the Past\n");
    printf("2. Travel to the Future\n");
    printf("3. Exit\n");
}

Date travelToPast(Date currentDate) {
    unsigned int randomDays = rand() % 365 * 3; // Random travel up to 3 years back
    Date newDate = currentDate;
    
    newDate.year -= (randomDays / 365);
    newDate.day -= (randomDays % 365);
    if (newDate.day <= 0) {
        newDate.month--;
        newDate.day += 30; // For simplicity, we assume each month has 30 days
        if (newDate.month <= 0) {
            newDate.year--;
            newDate.month = 12;
        }
    }
    printf("==== You have traveled to the past! ====\n");
    printf("New Date: %d-%02d-%02d\n", newDate.year, newDate.month, newDate.day);
    return newDate;
}

Date travelToFuture(Date currentDate) {
    unsigned int randomDays = rand() % 365 * 3; // Random travel up to 3 years forward
    Date newDate = currentDate;
    
    newDate.year += (randomDays / 365);
    newDate.day += (randomDays % 365);
    if (newDate.day > 30) {
        newDate.month++;
        newDate.day -= 30; // For simplicity, we assume each month has 30 days
        if (newDate.month > 12) {
            newDate.year++;
            newDate.month = 1;
        }
    }
    printf("==== You have traveled to the future! ====\n");
    printf("New Date: %d-%02d-%02d\n", newDate.year, newDate.month, newDate.day);
    return newDate;
}

int main() {
    srand(time(NULL));
    Date currentDate;
    
    printf("Enter the current date (YYYY MM DD): ");
    scanf("%d %d %d", &currentDate.year, &currentDate.month, &currentDate.day);

    while (1) {
        displayMenu();
        
        int choice;
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                currentDate = travelToPast(currentDate);
                break;
            case 2:
                currentDate = travelToFuture(currentDate);
                break;
            case 3:
                printf("Thank you for using the Time Travel Simulator! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }

        printf("\n---- Current Date is: %d-%02d-%02d ----\n\n", currentDate.year, currentDate.month, currentDate.day);
    }

    return 0;
}