//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: systematic
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
} Appointment;

void addAppointment(Appointment* appointments, int numAppointments) {
    printf("Enter name: ");
    scanf("%s", appointments[numAppointments].name);

    printf("Enter day: ");
    scanf("%d", &appointments[numAppointments].day);

    printf("Enter month: ");
    scanf("%d", &appointments[numAppointments].month);

    printf("Enter year: ");
    scanf("%d", &appointments[numAppointments].year);

    printf("Enter hour (24-hour format): ");
    scanf("%d", &appointments[numAppointments].hour);

    printf("Enter minute: ");
    scanf("%d", &appointments[numAppointments].minute);

    numAppointments++;
}

void displayAppointments(Appointment* appointments, int numAppointments) {
    printf("\nUpcoming Appointments:\n");

    for (int i = 0; i < numAppointments; i++) {
        printf("%s - %d/%d/%d %d:%d\n", appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].hour, appointments[i].minute);
    }
}

void scheduleAppointment(Appointment* appointments, int numAppointments) {
    system("clear");

    printf("\nAppointment Scheduler\n");

    int choice;

    do {
        printf("\nPlease choose an option:\n");
        printf("1. Add appointment\n");
        printf("2. Display appointments\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(appointments, numAppointments);
                break;

            case 2:
                displayAppointments(appointments, numAppointments);
                break;

            case 3:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice!= 3);
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    srand(time(NULL));

    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        addAppointment(appointments, numAppointments);
    }

    scheduleAppointment(appointments, numAppointments);

    return 0;
}