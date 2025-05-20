//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char time[50];
    char date[50];
} Appointment;

int main() {
    Appointment appointments[MAX_Appointments];
    int numAppointments = 0;

    // Initialize the appointments array
    for (int i = 0; i < MAX_Appointments; i++) {
        appointments[i].name[0] = '\0';
        appointments[i].time[0] = '\0';
        appointments[i].date[0] = '\0';
    }

    // Get the number of appointments from the user
    printf("How many appointments do you want to make? ");
    scanf("%d", &numAppointments);

    // Create the appointments
    for (int i = 0; i < numAppointments; i++) {
        // Get the appointment name, time, and date
        printf("Enter the name of the appointment: ");
        scanf("%s", appointments[i].name);

        printf("Enter the time of the appointment: ");
        scanf("%s", appointments[i].time);

        printf("Enter the date of the appointment: ");
        scanf("%s", appointments[i].date);
    }

    // Print the appointments
    printf("Your appointments are:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Time: %s\n", appointments[i].time);
        printf("Date: %s\n", appointments[i].date);
        printf("\n");
    }

    return 0;
}