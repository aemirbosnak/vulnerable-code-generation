//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declaring global variables
int day = 0, hour = 0;

// declaring function to schedule an appointment
void scheduleAppointment(char* name, int chosenDay, int chosenHour) {
    // if day and hour is already taken, display error message
    if (chosenDay == day && chosenHour == hour) {
        printf("Sorry, that appointment slot has already been taken. Please select a different day and time.\n");
    } 
    else {
        // update global variables
        day = chosenDay;
        hour = chosenHour;
        // display success message
        printf("%s, your appointment has been scheduled for day %d at hour %d.\n", name, day, hour);
    }
}

int main() {
    // declaring variables
    char name[50], choice[10];
    int chosenDay, chosenHour;
    // loop until user decides to quit
    while (1) {
        // display menu options
        printf("\nAppointment Scheduler Menu:\n");
        printf("1. Schedule Appointment\n");
        printf("2. View Appointment\n");
        printf("3. Quit\n");
        printf("Enter your choice (1, 2 or 3): ");
        // read user's choice
        scanf("%s", choice);
        // perform corresponding action based on user's choice
        if (strcmp(choice, "1") == 0) {
            // read user's name, day and hour to schedule an appointment
            printf("Enter your name: ");
            scanf("%s", name);
            printf("Enter the day you want to schedule the appointment (1-7): ");
            scanf("%d", &chosenDay);
            printf("Enter the hour you want to schedule the appointment (8-17): ");
            scanf("%d", &chosenHour);
            // schedule the appointment
            scheduleAppointment(name, chosenDay, chosenHour);
        } 
        else if (strcmp(choice, "2") == 0) {
            // if no appointment has been scheduled yet, display message
            if (day == 0 && hour == 0) {
                printf("No appointment has been scheduled yet.\n");
            } 
            else {
                // display appointment details
                printf("Appointment for day %d at hour %d has been scheduled.\n", day, hour);
            }
        }
        else if (strcmp(choice, "3") == 0) {
            // quit the program
            printf("Thank you for using the Appointment Scheduler. Goodbye.\n");
            exit(0);
        } 
        else {
            // if user enters an invalid choice, display error message
            printf("Invalid choice. Please enter 1, 2 or 3.\n");
        }
    }
    return 0;
}