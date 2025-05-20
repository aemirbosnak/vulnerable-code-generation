//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define HOURS_PER_DAY 24
#define MINUTES_PER_HOUR 60
#define SECONDS_PER_MINUTE 60

struct appointment {
    char name[50];
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int second;
};

void schedule_appointment(struct appointment* appointment) {
    printf("Enter the name for the appointment: ");
    scanf("%s", appointment->name);

    printf("Enter the day (1-31): ");
    scanf("%d", &appointment->day);

    printf("Enter the month (1-12): ");
    scanf("%d", &appointment->month);

    printf("Enter the year (YYYY): ");
    scanf("%d", &appointment->year);

    printf("Enter the hour (0-23): ");
    scanf("%d", &appointment->hour);

    printf("Enter the minute (0-59): ");
    scanf("%d", &appointment->minute);

    appointment->second = 0;
}

void print_appointment(struct appointment appointment) {
    printf("%s on %d/%d/%d at %d:%d:%d\n", appointment.name, appointment.day, appointment.month, appointment.year, appointment.hour, appointment.minute, appointment.second);
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    printf("Welcome to the appointment scheduler!\n");

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Would you like to schedule an appointment? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y') {
            schedule_appointment(&appointments[num_appointments]);
            num_appointments++;
        } else if (choice == 'n' || choice == 'N') {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    printf("Your appointments:\n");

    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }

    return 0;
}