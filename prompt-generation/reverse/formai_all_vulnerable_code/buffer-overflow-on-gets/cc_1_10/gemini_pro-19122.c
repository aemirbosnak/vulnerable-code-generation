//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct appointment {
    char name[50];
    char date[11];
    char time[11];
    char reason[50];
} appointment_t;

// Define the function to add an appointment
void add_appointment(appointment_t *appointments, int *num_appointments) {
    // Get the appointment details from the user
    printf("Enter the name of the person you want to schedule an appointment with: ");
    gets(appointments[*num_appointments].name);
    printf("Enter the date of the appointment (YYYY-MM-DD): ");
    gets(appointments[*num_appointments].date);
    printf("Enter the time of the appointment (HH:MM): ");
    gets(appointments[*num_appointments].time);
    printf("Enter the reason for the appointment: ");
    gets(appointments[*num_appointments].reason);

    // Increment the number of appointments
    (*num_appointments)++;
}

// Define the function to view appointments
void view_appointments(appointment_t *appointments, int num_appointments) {
    // Print the header
    printf("%-20s %-11s %-11s %-50s\n", "Name", "Date", "Time", "Reason");

    // Print the appointments
    for (int i = 0; i < num_appointments; i++) {
        printf("%-20s %-11s %-11s %-50s\n", appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].reason);
    }
}

// Define the function to delete an appointment
void delete_appointment(appointment_t *appointments, int *num_appointments) {
    // Get the name of the person whose appointment you want to delete
    char name[50];
    printf("Enter the name of the person whose appointment you want to delete: ");
    gets(name);

    // Find the appointment
    int index = -1;
    for (int i = 0; i < *num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // If the appointment was found, delete it
    if (index != -1) {
        for (int i = index; i < *num_appointments - 1; i++) {
            appointments[i] = appointments[i + 1];
        }
        (*num_appointments)--;
    } else {
        printf("No appointment found for the given name.\n");
    }
}

// Define the main function
int main() {
    // Create an array of appointments
    appointment_t appointments[MAX_APPOINTMENTS];

    // Initialize the number of appointments to 0
    int num_appointments = 0;

    // Display the menu
    int choice;
    do {
        printf("\n1. Add an appointment\n");
        printf("2. View appointments\n");
        printf("3. Delete an appointment\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                add_appointment(appointments, &num_appointments);
                break;
            case 2:
                view_appointments(appointments, num_appointments);
                break;
            case 3:
                delete_appointment(appointments, &num_appointments);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}