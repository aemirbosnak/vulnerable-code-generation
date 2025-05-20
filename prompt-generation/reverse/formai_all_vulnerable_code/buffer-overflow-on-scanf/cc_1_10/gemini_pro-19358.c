//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct appointment {
    char name[50];
    char date[11];
    char time[6];
    char description[255];
} appointment_t;

// Declare the array of appointments
appointment_t appointments[MAX_APPOINTMENTS];

// Initialize the number of appointments to 0
int num_appointments = 0;

// Display the main menu
void display_main_menu() {
    printf("\nAppointment Scheduler\n");
    printf("--------------------\n");
    printf("1. Add an appointment\n");
    printf("2. View appointments\n");
    printf("3. Delete an appointment\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
}

// Add an appointment
void add_appointment() {
    // Get the appointment details from the user
    printf("Enter your name: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", appointments[num_appointments].date);
    printf("Enter the time (HH:MM): ");
    scanf("%s", appointments[num_appointments].time);
    printf("Enter a description: ");
    scanf(" %[^\n]", appointments[num_appointments].description);

    // Increment the number of appointments
    num_appointments++;
}

// View appointments
void view_appointments() {
    // Display the header
    printf("\nAppointments\n");
    printf("----------\n");
    printf("%-20s %-10s %-6s %-25s\n", "Name", "Date", "Time", "Description");

    // Loop through the appointments and display the details
    for (int i = 0; i < num_appointments; i++) {
        printf("%-20s %-10s %-6s %-25s\n", appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].description);
    }
}

// Delete an appointment
void delete_appointment() {
    // Get the index of the appointment to delete
    int index;
    printf("Enter the index of the appointment to delete: ");
    scanf("%d", &index);

    // Check if the index is valid
    if (index < 0 || index >= num_appointments) {
        printf("Invalid index\n");
        return;
    }

    // Shift the appointments after the one to be deleted to the left
    for (int i = index; i < num_appointments - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    // Decrement the number of appointments
    num_appointments--;
}

// Quit the program
void quit() {
    printf("Thank you for using the Appointment Scheduler.\n");
    exit(0);
}

// Main function
int main() {
    // Display the main menu
    display_main_menu();

    // Get the user's choice
    int choice;
    scanf("%d", &choice);

    // Loop until the user quits
    while (choice != 4) {
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            default:
                printf("Invalid choice\n");
        }

        // Display the main menu again
        display_main_menu();

        // Get the user's choice again
        scanf("%d", &choice);
    }

    // Quit the program
    quit();

    return 0;
}