//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
} Appointment;

int main() {
    Appointment appointments[MAX_Appointments];
    int numAppointments = 0;

    printf("Welcome to the Retro Appointment Scheduler!\n");
    printf("------------------------\n");

    // Loop to handle appointments
    while (1) {
        char name[50];
        char date[50];
        char time[50];

        printf("Enter your name: ");
        scanf("%s", name);

        printf("Enter the date (dd/mm/yyyy): ");
        scanf("%s", date);

        printf("Enter the time (hh:mm): ");
        scanf("%s", time);

        // Create a new appointment
        Appointment newAppointment;
        strcpy(newAppointment.name, name);
        strcpy(newAppointment.date, date);
        strcpy(newAppointment.time, time);

        // Add the new appointment to the list
        appointments[numAppointments++] = newAppointment;

        // Check if the user wants to schedule another appointment
        char answer;
        printf("Do you want to schedule another appointment? (Y/N): ");
        scanf("%c", &answer);

        // Break out of the loop if the user does not want to schedule another appointment
        if (answer == 'N') {
            break;
        }
    }

    // Print the list of appointments
    printf("Your appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s - %s - %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }

    return 0;
}