//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of appointments
#define MAX_APPOINTMENTS 50

// Define an appointment structure
typedef struct {
    char name[50];
    char date[20];
    char time[20];
} Appointment;

// Define a function to create a new appointment
Appointment createAppointment() {
    Appointment apt;
    printf("Enter name: ");
    scanf("%s", &apt.name);
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", &apt.date);
    printf("Enter time (HH:MM AM/PM): ");
    scanf("%s", &apt.time);
    return apt;
}

// Define a function to print an appointment
void printAppointment(Appointment apt) {
    printf("Name: %s\n", apt.name);
    printf("Date: %s\n", apt.date);
    printf("Time: %s\n", apt.time);
}

int main() {
    // Create an array of appointments
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    // Display the menu and get the user's choice
    int choice = 0;
    while (choice != 4) {
        printf("=================\n");
        printf(" Appointment Menu\n");
        printf("=================\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        // Handle the user's choice
        switch (choice) {
            case 1: // Add appointment
                if (numAppointments >= MAX_APPOINTMENTS) {
                    printf("Sorry, you have reached the maximum number of appointments.\n");
                }
                else {
                    Appointment newApt = createAppointment();
                    appointments[numAppointments] = newApt;
                    numAppointments++;
                    printf("Appointment added successfully.\n");
                }
                break;

            case 2: // View appointments
                if (numAppointments == 0) {
                    printf("You have no appointments.\n");
                }
                else {
                    for (int i = 0; i < numAppointments; i++) {
                        printf("Appointment #%d:\n", i+1);
                        printAppointment(appointments[i]);
                    }
                }
                break;

            case 3: // Delete appointment
                if (numAppointments == 0) {
                    printf("You have no appointments to delete.\n");
                } 
                else {
                    printf("Enter the number of the appointment you wish to delete: ");
                    int aptNum;
                    scanf("%d", &aptNum);
                    if (aptNum < 1 || aptNum > numAppointments) {
                        printf("Invalid appointment number.\n");
                    }
                    else {
                        aptNum--; // Adjust index to account for user input
                        for (int i = aptNum; i < numAppointments - 1; i++) {
                            appointments[i] = appointments[i+1];
                        }
                        numAppointments--;
                        printf("Appointment deleted successfully.\n");
                    }
                }
                break;

            case 4: // Exit
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}