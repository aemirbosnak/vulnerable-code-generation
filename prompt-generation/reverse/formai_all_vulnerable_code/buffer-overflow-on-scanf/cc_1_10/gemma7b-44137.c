//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
} Appointment;

int main() {
    Appointment appointments[MAX_Appointments];
    int numAppointments = 0;

    // Create a loop to manage appointments
    while (1) {
        // Get the user's input
        char name[50];
        char date[50];
        char time[50];

        printf("Enter your name: ");
        scanf("%s", name);

        printf("Enter the date: ");
        scanf("%s", date);

        printf("Enter the time: ");
        scanf("%s", time);

        // Create a new appointment
        Appointment newAppointment;
        strcpy(newAppointment.name, name);
        strcpy(newAppointment.date, date);
        strcpy(newAppointment.time, time);

        // Add the new appointment to the list
        appointments[numAppointments++] = newAppointment;

        // Check if the user wants to continue
        char continue_char;
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &continue_char);

        // If the user does not want to continue, break out of the loop
        if (continue_char != 'Y') {
            break;
        }
    }

    // Print the appointments
    printf("Your appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("\n");
    }

    return 0;
}