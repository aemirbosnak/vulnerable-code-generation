//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: scientific
#include <stdio.h>
#define APPOINTMENT_LIMIT 10
#define MAX_NAME_LENGTH 50

struct Appointment {
    char name[MAX_NAME_LENGTH];
    int day, month, year, hours, minutes;
};

int num_appointments = 0;
struct Appointment appointments[APPOINTMENT_LIMIT];

void get_initial_input() {
    printf("Welcome to the appointment scheduler. Please enter:\n");
    printf("the number of appointments you wish to schedule (up to %d): ", APPOINTMENT_LIMIT);
    scanf("%d", &num_appointments);

    for (int i = 0; i < num_appointments; i++) {
        printf("Enter the details for appointment %d.\n", i + 1);
        printf("Name: ");
        scanf("%s", appointments[i].name);
        printf("Date (dd-mm-yyyy): ");
        scanf("%d-%d-%d", &appointments[i].day, &appointments[i].month, &appointments[i].year);
        printf("Time (hh:mm): ");
        scanf("%d:%d", &appointments[i].hours, &appointments[i].minutes);
    }
}

void print_appointments() {
    printf("Here are your scheduled appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("- %s on %d-%d-%d at %02d:%02d", appointments[i].name, appointments[i].day, 
               appointments[i].month, appointments[i].year, appointments[i].hours, appointments[i].minutes);
    }
}

void get_time_range(int* start_day, int* start_month, int* start_year, int* end_day, int* end_month, int* end_year) {
    printf("Please enter the start date for the range you want to see (dd-mm-yyyy): ");
    scanf("%d-%d-%d", start_day, start_month, start_year);
    printf("Please enter the end date for the range you want to see (dd-mm-yyyy): ");
    scanf("%d-%d-%d", end_day, end_month, end_year);
}

void print_appointments_in_range(int start_day, int start_month, int start_year, int end_day, int end_month, int end_year) {
    printf("Here are your scheduled appointments from %d-%d-%d to %d-%d-%d:\n", start_day, start_month, start_year, end_day, end_month, end_year);
    for (int i = 0; i < num_appointments; i++) {
        if (appointments[i].year > start_year && appointments[i].year < end_year ||
            appointments[i].year == start_year && appointments[i].month > start_month ||
            appointments[i].year == end_year && appointments[i].month < end_month ||
            appointments[i].year == start_year && appointments[i].month == start_month && appointments[i].day >= start_day ||
            appointments[i].year == end_year && appointments[i].month == end_month && appointments[i].day <= end_day) {
            printf("- %s on %d-%d-%d at %02d:%02d\n", appointments[i].name, appointments[i].day, 
                   appointments[i].month, appointments[i].year, appointments[i].hours, appointments[i].minutes);
        }
    }
}

int main() {
    get_initial_input();

    printf("\n");

    print_appointments();

    printf("\n");

    int start_day, start_month, start_year, end_day, end_month, end_year;
    get_time_range(&start_day, &start_month, &start_year, &end_day, &end_month, &end_year);

    printf("\n");

    print_appointments_in_range(start_day, start_month, start_year, end_day, end_month, end_year);

    return 0;
}