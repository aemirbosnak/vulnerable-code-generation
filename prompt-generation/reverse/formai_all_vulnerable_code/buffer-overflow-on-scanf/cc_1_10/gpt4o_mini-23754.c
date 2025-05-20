//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FUTURE 1
#define PAST 2

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date date;
    char timeline[100];
} TimeTravelEvent;

void displayWelcomeMessage() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("You can visit the past or the future.\n");
}

void setCurrentDate(Date *date) {
    time_t t = time(NULL);
    struct tm *current = localtime(&t);
    
    date->year = current->tm_year + 1900;
    date->month = current->tm_mon + 1;
    date->day = current->tm_mday;
}

void convertToString(Date *date, char *dateStr) {
    sprintf(dateStr, "%04d-%02d-%02d", date->year, date->month, date->day);
}

void travelToPast(Date *currentDate, int years) {
    currentDate->year -= years;
}

void travelToFuture(Date *currentDate, int years) {
    currentDate->year += years;
}

int getTravelOption() {
    int option;
    printf("Choose your time travel destination:\n");
    printf("1. Travel to the Past\n");
    printf("2. Travel to the Future\n");
    printf("Select (1 or 2): ");
    scanf("%d", &option);
    
    while (option != PAST && option != FUTURE) {
        printf("Invalid option! Please select (1 or 2): ");
        scanf("%d", &option);
    }
    
    return option;
}

int getYearsToTravel() {
    int years;
    printf("How many years would you like to travel? ");
    scanf("%d", &years);
    
    return years;
}

TimeTravelEvent createTimeTravelEvent(Date *date, const char *timeline) {
    TimeTravelEvent event;
    event.date = *date;
    strcpy(event.timeline, timeline);
    return event;
}

void logTravelEvent(TimeTravelEvent *event) {
    FILE *file = fopen("time_travel_log.txt", "a");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char dateStr[11];
    convertToString(&event->date, dateStr);

    fprintf(file, "Timeline: %s - Date: %s\n", event->timeline, dateStr);
    fclose(file);
}

void displayTravelHistory() {
    char ch;
    FILE *file = fopen("time_travel_log.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("\nTravel History:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

int main() {
    displayWelcomeMessage();
    
    Date currentDate;
    setCurrentDate(&currentDate);
    
    int travelOption = getTravelOption();
    int years = getYearsToTravel();
    
    TimeTravelEvent event;
    if (travelOption == PAST) {
        travelToPast(&currentDate, years);
        event = createTimeTravelEvent(&currentDate, "Past");
        printf("Traveling to the past year: %d\n", currentDate.year);
    } else {
        travelToFuture(&currentDate, years);
        event = createTimeTravelEvent(&currentDate, "Future");
        printf("Traveling to the future year: %d\n", currentDate.year);
    }
    
    logTravelEvent(&event);
    displayTravelHistory();

    return 0;
}