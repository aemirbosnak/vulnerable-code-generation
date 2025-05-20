//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TRIPS 10
#define MAX_YEARS 3000
#define MAX_TIME_UNITS 10

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date travel_date;
    char destination[50];
} TimeTravelTrip;

typedef struct {
    TimeTravelTrip trips[MAX_TRIPS];
    int trip_count;
} TimeMachine;

void initialize_time_machine(TimeMachine *tm) {
    tm->trip_count = 0;
}

void display_travel_destination(TimeTravelTrip trip) {
    printf("Traveling to %02d/%02d/%04d to %s\n", 
           trip.travel_date.day,
           trip.travel_date.month,
           trip.travel_date.year,
           trip.destination);
}

int is_valid_date(Date d) {
    if (d.year < 0 || d.year > MAX_YEARS) return 0;
    if (d.month < 1 || d.month > 12) return 0;
    
    // Days in months
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Leap year adjustment
    if ((d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0))
        days_in_month[2] = 29;

    if (d.day < 1 || d.day > days_in_month[d.month]) return 0;
    return 1;
}

void add_trip(TimeMachine *tm, Date travel_date, const char *destination) {
    if (tm->trip_count >= MAX_TRIPS) {
        printf("Maximum number of trips reached!\n");
        return;
    }

    if (!is_valid_date(travel_date)) {
        printf("Invalid travel date!\n");
        return;
    }

    tm->trips[tm->trip_count].travel_date = travel_date;
    strncpy(tm->trips[tm->trip_count].destination, destination, sizeof(tm->trips[tm->trip_count].destination) - 1);
    tm->trips[tm->trip_count].destination[sizeof(tm->trips[tm->trip_count].destination) - 1] = '\0'; // Ensure null termination
    tm->trip_count++;
    printf("Trip added to %s on %02d/%02d/%04d!\n", destination, travel_date.day, travel_date.month, travel_date.year);
}

void display_all_trips(TimeMachine *tm) {
    if (tm->trip_count == 0) {
        printf("No trips recorded.\n");
        return;
    }
    
    printf("All Time Travel Trips:\n");
    for (int i = 0; i < tm->trip_count; i++) {
        display_travel_destination(tm->trips[i]);
    }
}

void clear_trip_history(TimeMachine *tm) {
    tm->trip_count = 0;
    printf("Trip history cleared!\n");
}

Date random_time() {
    Date d;
    d.year = rand() % (MAX_YEARS + 1);
    d.month = rand() % 12 + 1;
    d.day = rand() % 28 + 1; // 1 to 28 for the sake of simplicity
    return d;
}

void time_travel(TimeMachine *tm) {
    if (tm->trip_count == 0) {
        printf("No trips available to travel!\n");
        return;
    }

    int trip_index = rand() % tm->trip_count;
    display_travel_destination(tm->trips[trip_index]);
    printf("Traveling through time...\n");
}

int main() {
    srand(time(NULL));
    TimeMachine tm;
    initialize_time_machine(&tm);
    
    int choice;
    Date travel_date;
    char destination[50];

    do {
        printf("\nTime Travel Simulator Menu:\n");
        printf("1. Add Trip\n");
        printf("2. View All Trips\n");
        printf("3. Time Travel\n");
        printf("4. Clear Trip History\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter travel date (YYYY MM DD): ");
                scanf("%d %d %d", &travel_date.year, &travel_date.month, &travel_date.day);
                printf("Enter travel destination: ");
                scanf("%s", destination); // Note: this doesn't handle spaces
                add_trip(&tm, travel_date, destination);
                break;
            case 2:
                display_all_trips(&tm);
                break;
            case 3:
                time_travel(&tm);
                break;
            case 4:
                clear_trip_history(&tm);
                break;
            case 5:
                printf("Exiting the simulator. Safe travels!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}