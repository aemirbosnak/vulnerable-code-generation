//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_TRAVEL_POINTS 10

typedef struct {
    int year;
    int month;
    int day;
    char description[100];
} TimePoint;

typedef struct {
    TimePoint points[MAX_TRAVEL_POINTS];
    int count;
} TimeTravelLog;

void initTravelLog(TimeTravelLog *log) {
    log->count = 0;
}

void addTimePoint(TimeTravelLog *log, int year, int month, int day, const char *description) {
    if (log->count < MAX_TRAVEL_POINTS) {
        log->points[log->count].year = year;
        log->points[log->count].month = month;
        log->points[log->count].day = day;
        strncpy(log->points[log->count].description, description, 99);
        log->points[log->count].description[99] = '\0'; // Ensuring null termination
        log->count++;
    } else {
        printf("Travel log is full! Cannot add more time points.\n");
    }
}

void showTravelLog(const TimeTravelLog *log) {
    printf("\nTime Travel Log:\n");
    for (int i = 0; i < log->count; i++) {
        printf("%d-%02d-%02d: %s\n", log->points[i].year, log->points[i].month, log->points[i].day, log->points[i].description);
    }
}

void timeTravel(int year, int month, int day) {
    printf("\n*** Time Traveling to %d-%02d-%02d... ***\n", year, month, day);
    sleep(2); // Simulated travel time
    printf("*** Welcome to %d-%02d-%02d! Step out and explore.\n\n", year, month, day);
}

void timeMachineMenu(TimeTravelLog *log) {
    int choice;
    do {
        printf("Time Machine Menu:\n");
        printf("1. Add Time Point\n");
        printf("2. Show Travel Log\n");
        printf("3. Travel in Time\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        scanf("%d", &choice);
        
        int year, month, day;
        char description[100];
        
        switch (choice) {
            case 1:
                printf("Enter year: ");
                scanf("%d", &year);
                printf("Enter month (1-12): ");
                scanf("%d", &month);
                printf("Enter day (1-31): ");
                scanf("%d", &day);
                printf("Enter description: ");
                getchar(); // Clear newline from buffer
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0'; // Remove newline character
                addTimePoint(log, year, month, day, description);
                break;
            case 2:
                showTravelLog(log);
                break;
            case 3:
                if (log->count == 0) {
                    printf("Your travel log is empty! Please add some time points first.\n");
                } else {
                    printf("Select a time point (1-%d): ", log->count);
                    int travelTo;
                    scanf("%d", &travelTo);
                    if (travelTo >= 1 && travelTo <= log->count) {
                        TimePoint tp = log->points[travelTo - 1];
                        timeTravel(tp.year, tp.month, tp.day);
                    } else {
                        printf("Invalid selection.\n");
                    }
                }
                break;
            case 4:
                printf("Exiting the time machine. Don't forget your time-keeping devices!\n");
                break;
            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
    } while (choice != 4);
}

int main() {
    srand(time(NULL)); // Seed for randomness in the travel experience
    TimeTravelLog log;
    initTravelLog(&log);
    
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Prepare your time machines. Adventure awaits!\n\n");
    
    timeMachineMenu(&log);
    
    printf("Thank you for using the Time Travel Simulator!\n");
    return 0;
}