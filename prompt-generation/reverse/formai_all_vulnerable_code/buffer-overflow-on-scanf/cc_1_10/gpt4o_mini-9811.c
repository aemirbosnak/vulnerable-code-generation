//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRIPS 10
#define MAX_YEARS 9999

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date departure;
    Date arrival;
    char destination[50];
} TimeTravelTrip;

typedef struct {
    TimeTravelTrip trips[MAX_TRIPS];
    int tripCount;
} TimeTraveler;

void displayMenu() {
    printf("\n*** Time Travel Simulator Menu ***\n");
    printf("1. Plan a Time Travel Trip\n");
    printf("2. View Planned Trips\n");
    printf("3. Execute Time Travel\n");
    printf("4. Exit\n");
    printf("Please choose an option: ");
}

int isValidDate(Date date) {
    if (date.year < 0 || date.year > MAX_YEARS) return 0;
    if (date.month < 1 || date.month > 12) return 0;
    
    int daysInMonth[] = {0, 31, (date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0) ? 29 : 28, 31, 30, 
                          31, 30, 31, 31, 30, 31, 30};

    return date.day > 0 && date.day <= daysInMonth[date.month];
}

void addTrip(TimeTraveler *traveler) {
    if (traveler->tripCount >= MAX_TRIPS) {
        printf("You have reached the maximum number of planned trips.\n");
        return;
    }
    
    TimeTravelTrip trip;
    printf("Enter departure date (YYYY MM DD): ");
    scanf("%d %d %d", &trip.departure.year, &trip.departure.month, &trip.departure.day);
    
    if (!isValidDate(trip.departure)) {
        printf("Invalid departure date.\n");
        return;
    }
    
    printf("Enter arrival date (YYYY MM DD): ");
    scanf("%d %d %d", &trip.arrival.year, &trip.arrival.month, &trip.arrival.day);
    
    if (!isValidDate(trip.arrival)) {
        printf("Invalid arrival date.\n");
        return;
    }
    
    printf("Enter your destination: ");
    getchar(); // Clear newline character
    fgets(trip.destination, sizeof(trip.destination), stdin);
    trip.destination[strcspn(trip.destination, "\n")] = 0; // Remove newline
    
    traveler->trips[traveler->tripCount] = trip;
    traveler->tripCount++;
    printf("Trip planned successfully!\n");
}

void viewTrips(TimeTraveler traveler) {
    if (traveler.tripCount == 0) {
        printf("No trips planned.\n");
        return;
    }
    
    for (int i = 0; i < traveler.tripCount; i++) {
        printf("Trip %d: From %04d-%02d-%02d to %04d-%02d-%02d, Destination: %s\n", 
               i + 1,
               traveler.trips[i].departure.year,
               traveler.trips[i].departure.month,
               traveler.trips[i].departure.day,
               traveler.trips[i].arrival.year,
               traveler.trips[i].arrival.month,
               traveler.trips[i].arrival.day,
               traveler.trips[i].destination);
    }
}

void executeTravel(TimeTraveler traveler) {
    if (traveler.tripCount == 0) {
        printf("No trips planned to execute.\n");
        return;
    }
    
    for (int i = 0; i < traveler.tripCount; i++) {
        printf("Traveling to %s...\n", traveler.trips[i].destination);
        printf("Departing on: %04d-%02d-%02d\n", 
               traveler.trips[i].departure.year,
               traveler.trips[i].departure.month,
               traveler.trips[i].departure.day);
        printf("Arriving on: %04d-%02d-%02d\n",
               traveler.trips[i].arrival.year,
               traveler.trips[i].arrival.month,
               traveler.trips[i].arrival.day);
        printf("You have successfully traveled to %s!\n", traveler.trips[i].destination);
        printf("------------------------------------------------------------------\n");
    }
}

int main() {
    TimeTraveler traveler = {0};
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTrip(&traveler);
                break;
            case 2:
                viewTrips(traveler);
                break;
            case 3:
                executeTravel(traveler);
                break;
            case 4:
                printf("Exiting Time Travel Simulator. Safe travels!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}