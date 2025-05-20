//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HISTORY 10
#define YEAR_START 1900
#define YEAR_END 2100

typedef struct {
    int year;
    int month;
    int day;
    char destination[50];
} TimeTravelEntry;

TimeTravelEntry travelHistory[MAX_HISTORY];
int travelCount = 0;

void displayMenu() {
    printf("\n--- Time Travel Simulator ---\n");
    printf("1. Travel to a specific date\n");
    printf("2. Display travel history\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

void travelToDate(int year, int month, int day, const char* destination) {
    if (travelCount < MAX_HISTORY) {
        travelHistory[travelCount].year = year;
        travelHistory[travelCount].month = month;
        travelHistory[travelCount].day = day;
        snprintf(travelHistory[travelCount].destination, sizeof(travelHistory[travelCount].destination), "%s", destination);
        travelCount++;
        
        printf("You have successfully traveled to %s on %02d/%02d/%d!\n", destination, day, month, year);
    } else {
        printf("Travel history is full. You cannot travel to another date!\n");
    }
}

void displayTravelHistory() {
    if (travelCount == 0) {
        printf("No travel history available.\n");
        return;
    }

    printf("\n--- Travel History ---\n");
    for (int i = 0; i < travelCount; i++) {
        printf("Travel %d: %s on %02d/%02d/%d\n", i + 1, travelHistory[i].destination, travelHistory[i].day, travelHistory[i].month, travelHistory[i].year);
    }
}

int isValidDate(int year, int month, int day) {
    if (year < YEAR_START || year > YEAR_END) return 0;
    if (month < 1 || month > 12) return 0;

    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
        return (day >= 1 && day <= 29);
    }
    
    return (day >= 1 && day <= daysInMonth[month - 1]);
}

int main() {
    int choice;
    int year, month, day;
    char destination[50];

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter year (1900-2100): ");
                scanf("%d", &year);
                printf("Enter month (1-12): ");
                scanf("%d", &month);
                printf("Enter day (1-31): ");
                scanf("%d", &day);
                printf("Enter destination: ");
                scanf("%s", destination);

                if (isValidDate(year, month, day)) {
                    travelToDate(year, month, day, destination);
                } else {
                    printf("Invalid date. Please try again.\n");
                }
                break;
            case 2:
                displayTravelHistory();
                break;
            case 3:
                printf("Exiting... Thank you for using the Time Travel Simulator!\n");
                break;
            default:
                printf("Invalid option! Please select again.\n");
        }
    } while (choice != 3);

    return 0;
}