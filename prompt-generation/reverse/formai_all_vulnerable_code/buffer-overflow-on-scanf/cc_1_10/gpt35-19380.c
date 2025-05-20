//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum number of appointments that can be scheduled per day
#define MAX_APPOINTMENTS 10

// Define the structure of an appointment
struct Appointment {
    char name[50];
    char date[20];
    char time[20];
};

// Define an array to store appointments for the day
struct Appointment appointments[MAX_APPOINTMENTS];

// Define the function to add a new appointment
void addAppointment() {
    // Check if there is room for another appointment
    if (sizeof(appointments)/sizeof(appointments[0]) < MAX_APPOINTMENTS) {
        // Prompt the user to input the appointment details
        printf("Enter name: ");
        scanf("%s", &appointments[sizeof(appointments)/sizeof(appointments[0])].name);
        printf("Enter date (MM/DD/YYYY): ");
        scanf("%s", &appointments[sizeof(appointments)/sizeof(appointments[0])].date);
        printf("Enter time (HH:MM AM/PM): ");
        scanf("%s", &appointments[sizeof(appointments)/sizeof(appointments[0])].time);
        // Confirm the appointment has been added
        printf("Appointment added!\n");
    } else {
        printf("Sorry, there is no room for another appointment.\n");
    }
}

// Define the function to display appointments for the day
void showAppointments() {
    // Check if there are any appointments scheduled for the day
    if (sizeof(appointments)/sizeof(appointments[0]) > 0) {
        // Print the appointments
        for (int i = 0; i < sizeof(appointments)/sizeof(appointments[0]); i++) {
            printf("Appointment %d:\n", i+1);
            printf("Name: %s\n", appointments[i].name);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("\n");
        }
    } else {
        printf("No appointments scheduled for the day.\n");
    }
}

// Define the function to delete an appointment
void deleteAppointment() {
    // Prompt the user to input the appointment name to delete
    char nameToDelete[50];
    printf("Enter name of appointment to delete: ");
    scanf("%s", &nameToDelete);
    // Search for the appointment and delete it if found
    bool appointmentFound = false;
    for (int i = 0; i < sizeof(appointments)/sizeof(appointments[0]); i++) {
        if (strcmp(appointments[i].name, nameToDelete) == 0) {
            // Move all appointments after the deleted one up one position in the array
            for (int j = i; j < sizeof(appointments)/sizeof(appointments[0])-1; j++) {
                appointments[j] = appointments[j+1];
            }
            // Clear the last appointment in the array
            memset(&appointments[sizeof(appointments)/sizeof(appointments[0])-1], 0, sizeof(struct Appointment));
            // Confirm the appointment has been deleted
            printf("Appointment deleted!\n");
            appointmentFound = true;
            break;
        }
    }
    if (!appointmentFound) {
        printf("Could not find appointment with name %s.\n", nameToDelete);
    }
}

// Define the main function
int main() {
    // Display the options menu and prompt the user to select an option
    int option = 0;
    while (option != 4) {
        printf("Options:\n");
        printf("1. Add appointment\n");
        printf("2. Show appointments\n");
        printf("3. Delete appointment\n");
        printf("4. Exit\n");
        printf("\nEnter option: ");
        scanf("%d", &option);
        // Call the appropriate function based on the user's selection
        switch (option) {
            case 1:
                addAppointment();
                break;
            case 2:
                showAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option selected. Try again.\n");
                break;
        }
    }
    return 0;
}