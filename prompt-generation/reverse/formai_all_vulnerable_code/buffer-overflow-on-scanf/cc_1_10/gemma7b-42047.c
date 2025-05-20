//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
} Appointment;

Appointment* createAppointment(char* name, char* date, char* time) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);
    newAppointment->next = NULL;
    return newAppointment;
}

void displayAppointments(Appointment* appointments) {
    while (appointments) {
        printf("%s - %s - %s\n", appointments->name, appointments->date, appointments->time);
        appointments = appointments->next;
    }
}

void scheduleAppointment(Appointment* appointments) {
    char name[50];
    char date[50];
    char time[50];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the date: ");
    scanf("%s", date);

    printf("Enter the time: ");
    scanf("%s", time);

    Appointment* newAppointment = createAppointment(name, date, time);
    appointments = newAppointment;
}

int main() {
    Appointment* appointments = NULL;

    printf("Welcome to the C Appointment Scheduler!\n");

    while (1) {
        printf("1. Schedule an appointment\n");
        printf("2. Display appointments\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scheduleAppointment(appointments);
                break;
            case 2:
                displayAppointments(appointments);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}