//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TIME_TRAVELS 10

typedef struct {
    int year;
    int month;
    int day;
    char historical_event[100];
} TimeTravel;

typedef struct {
    TimeTravel travels[MAX_TIME_TRAVELS];
    int count;
} TimeTravelLog;

void initializeLog(TimeTravelLog *log) {
    log->count = 0;
}

void addTravel(TimeTravelLog *log, int year, int month, int day, const char *event) {
    if (log->count < MAX_TIME_TRAVELS) {
        log->travels[log->count].year = year;
        log->travels[log->count].month = month;
        log->travels[log->count].day = day;
        strncpy(log->travels[log->count].historical_event, event, sizeof(log->travels[log->count].historical_event) - 1);
        log->travels[log->count].historical_event[sizeof(log->travels[log->count].historical_event) - 1] = '\0';
        log->count++;
    } else {
        printf("Travel log is full! Cannot add more travels.\n");
    }
}

void displayTravels(const TimeTravelLog *log) {
    printf("\n------ Time Travel Log ------\n");
    for (int i = 0; i < log->count; i++) {
        printf("Travel #%d: %04d-%02d-%02d - Event: %s\n", 
               i + 1, 
               log->travels[i].year, 
               log->travels[i].month, 
               log->travels[i].day, 
               log->travels[i].historical_event);
    }
    printf("-----------------------------\n");
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int year, int month) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return isLeapYear(year) ? 29 : 28;
        default: return 0; // Invalid month
    }
}

int validateDate(int year, int month, int day) {
    if (month < 1 || month > 12 || day < 1)
        return 0;
    if (day > daysInMonth(year, month))
        return 0;
    return 1;
}

void simulateTimeTravel() {
    TimeTravelLog log;
    initializeLog(&log);

    while (1) {
        int year, month, day;
        char event[100];
        char continueChoice;

        printf("\nEnter travel date (YYYY MM DD): ");
        scanf("%d %d %d", &year, &month, &day);

        if (!validateDate(year, month, day)) {
            printf("Invalid date! Please try again.\n");
            continue;
        }

        printf("Enter the historical event you want to witness: ");
        getchar(); // consumes newline left in the buffer
        fgets(event, sizeof(event), stdin);
        event[strcspn(event, "\n")] = 0;  // Remove newline character

        addTravel(&log, year, month, day, event);

        printf("Do you want to add another time travel record? (Y/N): ");
        scanf(" %c", &continueChoice);
        if (continueChoice == 'N' || continueChoice == 'n') {
            break;
        }
    }

    displayTravels(&log);
}

int main() {
    printf("Welcome to the Time Travel Simulator!\n\n");
    
    simulateTimeTravel();
    
    printf("Thank you for using the Time Travel Simulator! Safe travels through time!\n");
    return 0;
}