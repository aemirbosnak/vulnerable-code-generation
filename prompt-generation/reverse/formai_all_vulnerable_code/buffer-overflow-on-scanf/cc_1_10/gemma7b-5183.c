//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_Appointments 10

struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    int id;
};

int main() {
    struct Appointment appointments[MAX_Appointments];
    int numAppointments = 0;

    // Initialize the appointments array
    for (int i = 0; i < MAX_Appointments; i++) {
        appointments[i].id = -1;
    }

    // Get the user input
    char input[50];
    printf("Enter the name of the appointment: ");
    scanf("%s", input);

    // Check if the appointment slot is available
    int available = 1;
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].name, input) == 0) {
            available = 0;
        }
    }

    // If the slot is available, create the appointment
    if (available) {
        numAppointments++;
        appointments[numAppointments - 1].id = numAppointments;
        strcpy(appointments[numAppointments - 1].name, input);

        printf("Enter the date of the appointment: ");
        scanf("%s", appointments[numAppointments - 1].date);

        printf("Enter the time of the appointment: ");
        scanf("%s", appointments[numAppointments - 1].time);

        // Print the confirmation
        printf("Your appointment has been scheduled.\n");
        printf("Name: %s\n", appointments[numAppointments - 1].name);
        printf("Date: %s\n", appointments[numAppointments - 1].date);
        printf("Time: %s\n", appointments[numAppointments - 1].time);
    } else {
        // Print the error message
        printf("Sorry, that slot is not available.\n");
    }

    return 0;
}