//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ada Lovelace style Appointment Scheduler

#define MAX_APPOINTMENTS 100

struct appointment {
    char name[50];
    char date[10];
    char time[10];
};

void addAppointment(struct appointment *appointments, int numAppointments) {
    printf("Enter name: ");
    scanf("%s", appointments[numAppointments].name);

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", appointments[numAppointments].date);

    printf("Enter time (HH:MM): ");
    scanf("%s", appointments[numAppointments].time);

    numAppointments++;
}

void displayAppointments(struct appointment *appointments, int numAppointments) {
    printf("Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s - %s - %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    while (numAppointments < MAX_APPOINTMENTS) {
        printf("1. Add appointment\n2. Display appointments\n3. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(appointments, numAppointments);
                break;
            case 2:
                displayAppointments(appointments, numAppointments);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}