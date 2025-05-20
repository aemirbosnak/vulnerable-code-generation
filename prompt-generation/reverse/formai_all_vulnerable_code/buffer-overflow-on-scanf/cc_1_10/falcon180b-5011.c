//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Sherlock Holmes
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
} Appointment;

void addAppointment(Appointment* appointments, int numAppointments) {
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

    printf("Enter duration (in minutes): ");
    scanf("%d", &appointments[numAppointments].duration);

    numAppointments++;
}

void displayAppointments(Appointment* appointments, int numAppointments) {
    printf("\nAppointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s - %02d/%02d/%04d %02d:%02d - %d minutes\n", appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].hour, appointments[i].minute, appointments[i].duration);
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    addAppointment(appointments, numAppointments);

    while (numAppointments < MAX_APPOINTMENTS) {
        printf("\nDo you want to add another appointment? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            addAppointment(appointments, numAppointments);
        } else if (choice!= 'n' && choice!= 'N') {
            printf("Invalid choice. Please try again.\n");
        } else {
            break;
        }
    }

    displayAppointments(appointments, numAppointments);

    return 0;
}