//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 80

typedef struct {
    char name[MAX_APPOINTMENT_LENGTH];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

int numAppointments = 0;
Appointment appointments[MAX_APPOINTMENTS];

void addAppointment() {
    char name[MAX_APPOINTMENT_LENGTH];
    int day, month, year, hour, minute;

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter day (1-31): ");
    scanf("%d", &day);

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printf("Enter year (e.g. 2022): ");
    scanf("%d", &year);

    printf("Enter hour (0-23): ");
    scanf("%d", &hour);

    printf("Enter minute (0-59): ");
    scanf("%d", &minute);

    strcpy(appointments[numAppointments].name, name);
    appointments[numAppointments].day = day;
    appointments[numAppointments].month = month;
    appointments[numAppointments].year = year;
    appointments[numAppointments].hour = hour;
    appointments[numAppointments].minute = minute;

    numAppointments++;

    printf("Appointment added.\n");
}

void viewAppointments() {
    time_t now = time(NULL);
    struct tm *currentTime = localtime(&now);

    printf("Current date and time: %d/%d/%d %d:%d\n", currentTime->tm_mday, currentTime->tm_mon + 1, currentTime->tm_year + 1900, currentTime->tm_hour, currentTime->tm_min);

    for (int i = 0; i < numAppointments; i++) {
        if (appointments[i].day == currentTime->tm_mday && appointments[i].month == currentTime->tm_mon + 1 && appointments[i].year == currentTime->tm_year + 1900) {
            printf("Upcoming appointment: %s at %d:%d\n", appointments[i].name, appointments[i].hour, appointments[i].minute);
        }
    }
}

int main() {
    int choice;

    do {
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}