//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

struct appointment {
    char name[50];
    int month;
    int day;
    int year;
    int hour;
    int minute;
};

void addAppointment(struct appointment *appointments, int numAppointments) {
    printf("Enter name: ");
    scanf("%s", appointments[numAppointments].name);
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%d/%d/%d", &appointments[numAppointments].month, &appointments[numAppointments].day, &appointments[numAppointments].year);
    printf("Enter time (HH:MM): ");
    scanf("%d:%d", &appointments[numAppointments].hour, &appointments[numAppointments].minute);
    numAppointments++;
}

void printAppointments(struct appointment *appointments, int numAppointments) {
    printf("\nAppointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s - %d/%d/%d %d:%d\n", appointments[i].name, appointments[i].month, appointments[i].day, appointments[i].year, appointments[i].hour, appointments[i].minute);
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    while (numAppointments < MAX_APPOINTMENTS) {
        printf("\nAdd an appointment? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y') {
            addAppointment(appointments, numAppointments);
        } else if (choice == 'n') {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    printf("\nAppointments:\n");
    printAppointments(appointments, numAppointments);

    return 0;
}