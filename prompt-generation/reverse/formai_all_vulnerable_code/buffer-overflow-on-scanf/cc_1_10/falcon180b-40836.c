//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int duration;
} appointment;

void addAppointment(appointment *appointments, int numAppointments) {
    printf("Enter name: ");
    scanf("%s", appointments[numAppointments].name);

    printf("Enter day (1-31): ");
    scanf("%d", &appointments[numAppointments].day);

    printf("Enter month (1-12): ");
    scanf("%d", &appointments[numAppointments].month);

    printf("Enter year (YYYY): ");
    scanf("%d", &appointments[numAppointments].year);

    printf("Enter hour (0-23): ");
    scanf("%d", &appointments[numAppointments].hour);

    printf("Enter minute (0-59): ");
    scanf("%d", &appointments[numAppointments].minute);

    printf("Enter duration in minutes: ");
    scanf("%d", &appointments[numAppointments].duration);

    numAppointments++;
}

void displayAppointments(appointment *appointments, int numAppointments) {
    printf("\nAppointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s - %d/%d/%d %d:%d - %d minutes\n", appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].hour, appointments[i].minute, appointments[i].duration);
    }
}

void scheduleAppointment(appointment *appointments, int numAppointments) {
    time_t now = time(NULL);
    struct tm *currentTime = localtime(&now);

    printf("\nSchedule an appointment:\n");
    printf("1. Add appointment\n");
    printf("2. Display appointments\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addAppointment(appointments, numAppointments);
            break;
        case 2:
            displayAppointments(appointments, numAppointments);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    while (1) {
        system("clear");
        scheduleAppointment(appointments, numAppointments);
    }

    return 0;
}