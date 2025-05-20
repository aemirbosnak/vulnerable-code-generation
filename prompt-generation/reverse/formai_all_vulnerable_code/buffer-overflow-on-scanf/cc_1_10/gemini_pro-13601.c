//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct {
    char name[50];
    char date[20];
    char time[20];
    char description[100];
} appointment_t;

// Define the array of appointments
appointment_t appointments[MAX_APPOINTMENTS];

// Initialize the array of appointments
int num_appointments = 0;

// Function to add an appointment
void add_appointment() {
    // Get the appointment details from the user
    printf("Enter the name of the person you want to schedule an appointment with: ");
    scanf(" %s", appointments[num_appointments].name);
    printf("Enter the date of the appointment (YYYY-MM-DD): ");
    scanf(" %s", appointments[num_appointments].date);
    printf("Enter the time of the appointment (HH:MM): ");
    scanf(" %s", appointments[num_appointments].time);
    printf("Enter a brief description of the appointment: ");
    scanf(" %[^\n]%*c", appointments[num_appointments].description);

    // Increment the number of appointments
    num_appointments++;
}

// Function to view all appointments
void view_appointments() {
    // Print the header
    printf("%-20s %-20s %-20s %-20s\n", "Name", "Date", "Time", "Description");

    // Print the appointments
    for (int i = 0; i < num_appointments; i++) {
        printf("%-20s %-20s %-20s %-20s\n", appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].description);
    }
}

// Function to search for an appointment
void search_appointment() {
    // Get the search term from the user
    char search_term[50];
    printf("Enter the name of the person you want to search for: ");
    scanf(" %s", search_term);

    // Search for the appointment
    int found = 0;
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, search_term) == 0) {
            // Print the appointment
            printf("%-20s %-20s %-20s %-20s\n", appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].description);
            found = 1;
        }
    }

    // If the appointment was not found, print an error message
    if (!found) {
        printf("No appointment found for the given name.\n");
    }
}

// Function to delete an appointment
void delete_appointment() {
    // Get the name of the person whose appointment you want to delete
    char name[50];
    printf("Enter the name of the person whose appointment you want to delete: ");
    scanf(" %s", name);

    // Search for the appointment
    int found = 0;
    int index = -1;
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            found = 1;
            index = i;
        }
    }

    // If the appointment was found, delete it
    if (found) {
        for (int i = index; i < num_appointments - 1; i++) {
            appointments[i] = appointments[i + 1];
        }
        num_appointments--;
        printf("Appointment deleted successfully.\n");
    } else {
        // If the appointment was not found, print an error message
        printf("No appointment found for the given name.\n");
    }
}

// Function to print the main menu
void print_menu() {
    printf("\n");
    printf("1. Add an appointment\n");
    printf("2. View all appointments\n");
    printf("3. Search for an appointment\n");
    printf("4. Delete an appointment\n");
    printf("5. Quit\n");
    printf("\n");
}

// Main function
int main() {
    // Print the welcome message
    printf("Welcome to the Appointment Scheduler!\n");

    // Loop until the user quits
    int choice = 0;
    while (choice != 5) {
        // Print the main menu
        print_menu();

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                search_appointment();
                break;
            case 4:
                delete_appointment();
                break;
            case 5:
                printf("Thank you for using the Appointment Scheduler!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}