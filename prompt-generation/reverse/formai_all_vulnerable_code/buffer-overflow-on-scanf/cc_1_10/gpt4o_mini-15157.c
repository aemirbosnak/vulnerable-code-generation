//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date date;
    int destination;
} TimeTravelRequest;

void displayCurrentDate(Date *date) {
    printf("Current Date: %04d-%02d-%02d\n", date->year, date->month, date->day);
}

void promptTravelDestination() {
    printf("Select Destination:\n");
    printf("1. 2025 - Future\n");
    printf("2. 1980 - Past\n");
    printf("3. 1776 - Historic Event\n");
    printf("4. 3000 - Sci-Fi\n");
    printf("5. Back to Present\n");
}

void setTimeTravelDestination(TimeTravelRequest *request) {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            request->date.year = 2025;
            request->date.month = 1;
            request->date.day = 1;
            request->destination = 1;
            break;
        case 2:
            request->date.year = 1980;
            request->date.month = 1;
            request->date.day = 1;
            request->destination = 2;
            break;
        case 3:
            request->date.year = 1776;
            request->date.month = 7;
            request->date.day = 4;
            request->destination = 3;
            break;
        case 4:
            request->date.year = 3000;
            request->date.month = 1;
            request->date.day = 1;
            request->destination = 4;
            break;
        case 5:
            request->date.year = 2023;
            request->date.month = 10;
            request->date.day = 1; // Assume today's date
            request->destination = 0;
            break;
        default:
            printf("Invalid choice. Staying in the present.\n");
            request->date.year = 2023;
            request->date.month = 10;
            request->date.day = 1; // Assume today's date
            request->destination = 0;
            break;
    }
}

void simulateTimeTravel(TimeTravelRequest *request) {
    printf("Time traveling to %04d-%02d-%02d...\n", request->date.year, request->date.month, request->date.day);
    // Simulated time travel effect
    for (int i = 0; i < 3; i++) {
        printf(". ");
        fflush(stdout);
        sleep(1); // Delay for effect
    }
    printf("\nArrived at destination!\n");
}

int main() {
    TimeTravelRequest request;
    request.date.year = 2023;
    request.date.month = 10;
    request.date.day = 1;

    while (1) {
        displayCurrentDate(&request.date);
        promptTravelDestination();
        setTimeTravelDestination(&request);
        if (request.destination == 0) {
            printf("You have returned to the present. Thank you for time traveling!\n");
            break;
        }
        simulateTimeTravel(&request);
    }

    return 0;
}