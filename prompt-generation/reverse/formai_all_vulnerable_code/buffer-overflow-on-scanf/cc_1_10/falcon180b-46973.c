//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MINUTES_IN_A_DAY (24 * 60)

typedef struct {
    char name[MAX_NAME_LENGTH];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

void add_appointment(Appointment* appointments, int num_appointments, const char* name, int day, int month, int year, int hour, int minute) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, the appointment book is full!\n");
        return;
    }

    strcpy(appointments[num_appointments].name, name);
    appointments[num_appointments].day = day;
    appointments[num_appointments].month = month;
    appointments[num_appointments].year = year;
    appointments[num_appointments].hour = hour;
    appointments[num_appointments].minute = minute;

    num_appointments++;
}

void display_appointments(const Appointment* appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s on %d/%d/%d at %d:%d\n", appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].hour, appointments[i].minute);
    }
}

int main() {
    srand(time(NULL));

    int num_appointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];

    char name[MAX_NAME_LENGTH];
    printf("Welcome to the appointment scheduler!\n");
    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter your name (or type 'done' to finish): ");
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        int day, month, year, hour, minute;
        printf("Enter the appointment details:\n");
        printf("Day (1-31): ");
        scanf("%d", &day);
        printf("Month (1-12): ");
        scanf("%d", &month);
        printf("Year (e.g. 2022): ");
        scanf("%d", &year);
        printf("Hour (0-23): ");
        scanf("%d", &hour);
        printf("Minute (0-59): ");
        scanf("%d", &minute);

        add_appointment(appointments, num_appointments, name, day, month, year, hour, minute);
    }

    printf("Your appointments:\n");
    display_appointments(appointments, num_appointments);

    return 0;
}