//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: shocked
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

    // Shocked style:

    printf("HELLO, MORTAL! Prepare for a mind-blowing appointment scheduler!\n");

    // Loop until the user wants to quit
    while (1) {
        // Get the user's name, date, and time
        printf("Enter your name: ");
        scanf("%s", appointments[numAppointments].name);

        printf("Enter the date (MM/DD/YY): ");
        scanf("%s", appointments[numAppointments].date);

        printf("Enter the time (HH:MM): ");
        scanf("%s", appointments[numAppointments].time);

        // Increment the number of appointments
        numAppointments++;

        // Check if the user wants to continue or quit
        printf("Do you want to schedule another appointment? (Y/N): ");
        char answer;
        scanf("%c", &answer);

        // If the user wants to quit, break out of the loop
        if (answer == 'N') {
            break;
        }
    }

    // Print a list of appointments
    printf("Here is a list of your appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("\n");
    }

    // Thank the user for using the appointment scheduler
    printf("Thank you for using the most shocking appointment scheduler in the world!\n");

    return 0;
}