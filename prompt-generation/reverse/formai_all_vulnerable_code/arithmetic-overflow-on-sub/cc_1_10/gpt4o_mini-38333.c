//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HISTORY 100

typedef struct {
    int year;
    int month;
    int day;
    char event[256];
} TimeTravelHistory;

void displayMenu() {
    printf("Time Travel Simulator Menu\n");
    printf("1. Time Travel\n");
    printf("2. View Travel History\n");
    printf("3. Exit\n");
}

void travelToDate(TimeTravelHistory *history, int *historyCount) {
    int year, month, day;
    printf("Enter the destination year: ");
    scanf("%d", &year);
    printf("Enter the destination month (1-12): ");
    scanf("%d", &month);
    printf("Enter the destination day (1-31): ");
    scanf("%d", &day);

    // Basic validation of date
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        printf("Invalid date entered. Please try again.\n");
        return;
    }

    // Simulate time travel
    printf("Time traveling to %4d-%02d-%02d...\n", year, month, day);
    time_t t;
    struct tm *tm_info;

    // Set time structure
    tm_info = malloc(sizeof(struct tm));
    if (!tm_info) {
        printf("Memory allocation failed.\n");
        return;
    }
    tm_info->tm_year = year - 1900;  // tm_year is  years since 1900
    tm_info->tm_mon = month - 1;     // tm_mon is 0-11
    tm_info->tm_mday = day;
    tm_info->tm_hour = 0;
    tm_info->tm_min = 0;
    tm_info->tm_sec = 0;

    // Convert to time_t
    t = mktime(tm_info);
    if (t == -1) {
        printf("Error in time conversion.\n");
        free(tm_info);
        return;
    }

    // Store in history
    if (*historyCount < MAX_HISTORY) {
        history[*historyCount].year = year;
        history[*historyCount].month = month;
        history[*historyCount].day = day;
        snprintf(history[*historyCount].event, sizeof(history[*historyCount].event), "Time traveled to %4d-%02d-%02d", year, month, day);
        (*historyCount)++;
    } else {
        printf("Travel history is full! Unable to store this travel.\n");
    }

    free(tm_info);
}

void viewTravelHistory(TimeTravelHistory *history, int historyCount) {
    if (historyCount == 0) {
        printf("No travel history available.\n");
        return;
    }
    printf("Travel History:\n");
    for (int i = 0; i < historyCount; i++) {
        printf("%d: %s\n", i + 1, history[i].event);
    }
}

int main() {
    TimeTravelHistory travelHistory[MAX_HISTORY];
    int historyCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                travelToDate(travelHistory, &historyCount);
                break;
            case 2:
                viewTravelHistory(travelHistory, historyCount);
                break;
            case 3:
                printf("Exiting Time Travel Simulator. Safe travels!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}