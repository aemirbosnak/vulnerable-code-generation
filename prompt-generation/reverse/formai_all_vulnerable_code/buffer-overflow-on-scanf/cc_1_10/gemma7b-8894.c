//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char time[50];
    char date[50];
} Appointment;

void displayAppointments(Appointment *appointments) {
    int i;
    for (i = 0; i < MAX_Appointments; i++) {
        if (appointments[i].name[0] != '\0') {
            printf("%s, %s, %s\n", appointments[i].name, appointments[i].time, appointments[i].date);
        }
    }
}

void addAppointment(Appointment *appointments) {
    int i;
    for (i = 0; i < MAX_Appointments; i++) {
        if (appointments[i].name[0] == '\0') {
            printf("Enter your name: ");
            scanf("%s", appointments[i].name);
            printf("Enter the time: ");
            scanf("%s", appointments[i].time);
            printf("Enter the date: ");
            scanf("%s", appointments[i].date);
            return;
        }
    }
    printf("Error: No available appointments.\n");
}

int main() {
    Appointment appointments[MAX_Appointments];
    int choice;

    displayAppointments(appointments);

    printf("Enter 1 to add an appointment, 2 to display appointments: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addAppointment(appointments);
            break;
        case 2:
            displayAppointments(appointments);
            break;
        default:
            printf("Invalid input.\n");
    }

    return 0;
}