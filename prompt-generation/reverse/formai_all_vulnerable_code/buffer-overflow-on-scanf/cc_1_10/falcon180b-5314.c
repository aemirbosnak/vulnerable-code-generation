//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_USER_NAME_LENGTH 50
#define MAX_DATE_TIME_LENGTH 20
#define MAX_NOTES_LENGTH 100

typedef struct {
    char userName[MAX_USER_NAME_LENGTH];
    char dateTime[MAX_DATE_TIME_LENGTH];
    char notes[MAX_NOTES_LENGTH];
} appointment;

int numAppointments = 0;
appointment appointments[MAX_APPOINTMENTS];

void addAppointment() {
    if (numAppointments >= MAX_APPOINTMENTS) {
        printf("Sorry, cannot add more appointments. ");
        return;
    }

    printf("Enter user name: ");
    scanf("%s", appointments[numAppointments].userName);

    printf("Enter date and time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[numAppointments].dateTime);

    printf("Enter notes: ");
    scanf("%s", appointments[numAppointments].notes);

    numAppointments++;
    printf("Appointment added successfully. ");
}

void viewAppointments() {
    if (numAppointments == 0) {
        printf("No appointments yet. ");
        return;
    }

    printf("Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%d. %s - %s - %s\n", i+1, appointments[i].userName, appointments[i].dateTime, appointments[i].notes);
    }
}

void main() {
    srand(time(NULL));

    int choice;
    while (1) {
        printf("\nAppointment Scheduler\n1. Add appointment\n2. View appointments\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addAppointment();
            break;
        case 2:
            viewAppointments();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice. ");
        }
    }
}