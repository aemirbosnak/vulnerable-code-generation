//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t appointmentTime;
    int duration;
} Appointment;

void addAppointment(Appointment *appointments, int numAppointments) {
    printf("Enter your name:\n");
    scanf("%s", appointments[numAppointments].name);

    printf("Enter your email:\n");
    scanf("%s", appointments[numAppointments].email);

    printf("Enter the appointment time (YYYY-MM-DD HH:MM:SS):\n");
    scanf("%s", appointments[numAppointments].appointmentTime);

    printf("Enter the appointment duration (in minutes):\n");
    scanf("%d", &appointments[numAppointments].duration);
}

void printAppointments(Appointment *appointments, int numAppointments) {
    for (int i = 0; i < numAppointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Email: %s\n", appointments[i].email);
        printf("Appointment Time: %s\n", appointments[i].appointmentTime);
        printf("Appointment Duration: %d minutes\n\n", appointments[i].duration);
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    while (numAppointments < MAX_APPOINTMENTS) {
        printf("Enter 1 to add an appointment, 0 to exit:\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            addAppointment(appointments, numAppointments);
            numAppointments++;
        } else if (choice!= 0) {
            printf("Invalid choice, please try again.\n");
        }
    }

    printAppointments(appointments, numAppointments);

    return 0;
}