//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TRIPS 100

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date date;
    char destination[100];
} TimeTrip;

void display_menu() {
    printf("\n=== Time Travel Simulator ===\n");
    printf("1. Travel to the Past\n");
    printf("2. Travel to the Future\n");
    printf("3. View Past Trips\n");
    printf("4. View Future Trips\n");
    printf("5. Exit\n");
    printf("=============================\n");
    printf("Enter your choice: ");
}

void get_current_date(Date *current_date) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    current_date->year = tm.tm_year + 1900;
    current_date->month = tm.tm_mon + 1;
    current_date->day = tm.tm_mday;
}

void travel_to_past(TimeTrip *trips, int *trip_count) {
    Date travel_date;
    char destination[100];

    printf("Enter year to travel to: ");
    scanf("%d", &travel_date.year);
    
    printf("Enter month to travel to (1-12): ");
    scanf("%d", &travel_date.month);
    
    printf("Enter day to travel to (1-31): ");
    scanf("%d", &travel_date.day);

    printf("Enter the place you want to visit: ");
    scanf(" %[^\n]s", destination);

    trips[*trip_count].date = travel_date;
    strcpy(trips[*trip_count].destination, destination);
    (*trip_count)++;

    printf("You traveled to %s on %02d-%02d-%d!\n", destination, 
           travel_date.day, travel_date.month, travel_date.year);
}

void travel_to_future(TimeTrip *trips, int *trip_count) {
    Date travel_date;
    char destination[100];

    printf("Enter year to travel to: ");
    scanf("%d", &travel_date.year);

    printf("Enter month to travel to (1-12): ");
    scanf("%d", &travel_date.month);

    printf("Enter day to travel to (1-31): ");
    scanf("%d", &travel_date.day);

    printf("Enter the place you want to visit: ");
    scanf(" %[^\n]s", destination);

    trips[*trip_count].date = travel_date;
    strcpy(trips[*trip_count].destination, destination);
    (*trip_count)++;

    printf("You traveled to %s on %02d-%02d-%d!\n", destination, 
           travel_date.day, travel_date.month, travel_date.year);
}

void view_trips(TimeTrip *trips, int trip_count, const char* type) {
    if (trip_count == 0) {
        printf("No %s trips recorded yet.\n", type);
        return;
    }
    printf("\n=== %s Trips ===\n", type);
    for (int i = 0; i < trip_count; i++) {
        printf("Trip %d: %s on %02d-%02d-%d\n", 
               i + 1, trips[i].destination, 
               trips[i].date.day, trips[i].date.month, trips[i].date.year);
    }
}

int main() {
    TimeTrip trips[MAX_TRIPS];
    int trip_count = 0;
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                travel_to_past(trips, &trip_count);
                break;
            case 2:
                travel_to_future(trips, &trip_count);
                break;
            case 3:
                view_trips(trips, trip_count, "Past");
                break;
            case 4:
                view_trips(trips, trip_count, "Future");
                break;
            case 5:
                printf("Exiting Time Travel Simulator. Safe travels!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}