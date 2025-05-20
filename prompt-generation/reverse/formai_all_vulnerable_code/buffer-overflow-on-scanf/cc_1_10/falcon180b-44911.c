//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct to hold appointment details
typedef struct {
    char name[50];
    int year, month, day, hour, minute;
} Appointment;

// Function to print a formatted date/time string
void print_datetime(int year, int month, int day, int hour, int minute) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    printf("%04d-%02d-%02d %02d:%02d\n", year, month, day, hour, minute);
}

// Function to schedule an appointment
void schedule_appointment(Appointment *appt) {
    int choice;
    do {
        printf("Enter 1 to schedule a new appointment, 2 to view existing appointments, or 3 to exit:\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name:\n");
                scanf("%s", appt->name);

                printf("Enter year (YYYY):\n");
                scanf("%d", &appt->year);

                printf("Enter month (MM):\n");
                scanf("%d", &appt->month);

                printf("Enter day (DD):\n");
                scanf("%d", &appt->day);

                printf("Enter hour (HH):\n");
                scanf("%d", &appt->hour);

                printf("Enter minute (MM):\n");
                scanf("%d", &appt->minute);

                print_datetime(appt->year, appt->month, appt->day, appt->hour, appt->minute);
                break;

            case 2:
                // TODO: Implement view existing appointments
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 3);
}

int main() {
    Appointment appt;
    schedule_appointment(&appt);
    return 0;
}