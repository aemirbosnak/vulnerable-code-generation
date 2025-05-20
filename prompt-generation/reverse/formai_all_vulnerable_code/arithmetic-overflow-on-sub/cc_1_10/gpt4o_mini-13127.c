//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRIPS 10
#define TIMESTAMP_SIZE 20

typedef struct {
    int year;
    int month;
    int day;
    char description[100];
} TimeTravelLog;

TimeTravelLog tripLog[MAX_TRIPS];
int tripCount = 0;

void currentTimestamp(char *buffer) {
    time_t now = time(NULL);
    struct tm t = *localtime(&now);
    snprintf(buffer, TIMESTAMP_SIZE, "%d-%02d-%02d %02d:%02d:%02d", 
             t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
             t.tm_hour, t.tm_min, t.tm_sec);
}

void travelToFuture(int years) {
    if (tripCount >= MAX_TRIPS) {
        printf("Maximum number of trips reached. Cannot travel.\n");
        return;
    }
    
    int currentYear = 2023;
    tripLog[tripCount].year = currentYear + years;
    tripLog[tripCount].month = 12; // Lets assume you land in December
    tripLog[tripCount].day = 31; // Last Day of the Year
    snprintf(tripLog[tripCount].description, sizeof(tripLog[tripCount].description),
             "Traveled to year %d, December 31st.", tripLog[tripCount].year);
    
    tripCount++;
    printf("Traveling to the future... %s\n", tripLog[tripCount - 1].description);
}

void travelToPast(int years) {
    if (tripCount >= MAX_TRIPS) {
        printf("Maximum number of trips reached. Cannot travel.\n");
        return;
    }
    
    int currentYear = 2023;
    tripLog[tripCount].year = currentYear - years;
    tripLog[tripCount].month = 1; // Lets assume you land in January
    tripLog[tripCount].day = 1; // First Day of the Year
    snprintf(tripLog[tripCount].description, sizeof(tripLog[tripCount].description),
             "Traveled to year %d, January 1st.", tripLog[tripCount].year);
    
    tripCount++;
    printf("Traveling to the past... %s\n", tripLog[tripCount - 1].description);
}

void displayTrips() {
    printf("\nTime Travel Log:\n");
    for (int i = 0; i < tripCount; i++) {
        printf("[%d] %04d-%02d-%02d: %s\n", 
               i + 1, 
               tripLog[i].year, tripLog[i].month, tripLog[i].day,
               tripLog[i].description);
    }
}

void inputTravelInfo() {
    int choice, years;
    while (1) {
        printf("\nChoose your travel option:\n");
        printf("1. Travel to the future\n");
        printf("2. Travel to the past\n");
        printf("3. Display travel log\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter number of years to travel into the future: ");
                scanf("%d", &years);
                travelToFuture(years);
                break;
            case 2:
                printf("Enter number of years to travel into the past: ");
                scanf("%d", &years);
                travelToPast(years);
                break;
            case 3:
                displayTrips();
                break;
            case 4:
                printf("Exiting the time travel simulator. Safe travels!\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    char timestamp[TIMESTAMP_SIZE];
    currentTimestamp(timestamp);
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Current Date and Time: %s\n", timestamp);
    
    inputTravelInfo();
    
    return 0;
}