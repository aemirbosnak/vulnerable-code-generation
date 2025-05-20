//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the appointment structure
typedef struct appointment {
    char name[50];
    char date[20];
    char time[20];
    int duration;
} appointment;

// Declare the array of appointments
appointment appointments[100];

// Initialize the number of appointments to 0
int numAppointments = 0;

// Function to add an appointment
void addAppointment() {
    // Get the appointment details from the user
    printf("Enter the name of the person you want to schedule an appointment with: ");
    gets(appointments[numAppointments].name);
    printf("Enter the date of the appointment (dd/mm/yyyy): ");
    gets(appointments[numAppointments].date);
    printf("Enter the time of the appointment (hh:mm): ");
    gets(appointments[numAppointments].time);
    printf("Enter the duration of the appointment (in minutes): ");
    scanf("%d", &appointments[numAppointments].duration);

    // Increment the number of appointments
    numAppointments++;
}

// Function to view appointments
void viewAppointments() {
    // Check if there are any appointments
    if (numAppointments == 0) {
        printf("There are no appointments scheduled.\n");
        return;
    }

    // Print the appointments
    printf("Here are the scheduled appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s - %s - %s - %d minutes\n", appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].duration);
    }
}

// Function to search for an appointment
void searchAppointment() {
    // Get the search term from the user
    char searchTerm[50];
    printf("Enter the name of the person you want to search for: ");
    gets(searchTerm);

    // Search for the appointment
    int found = 0;
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].name, searchTerm) == 0) {
            // Print the appointment details
            printf("Appointment found:\n");
            printf("%s - %s - %s - %d minutes\n", appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].duration);
            found = 1;
            break;
        }
    }

    // If the appointment was not found, print an error message
    if (found == 0) {
        printf("No appointment found for %s.\n", searchTerm);
    }
}

// Function to delete an appointment
void deleteAppointment() {
    // Get the name of the person whose appointment you want to delete
    char name[50];
    printf("Enter the name of the person whose appointment you want to delete: ");
    gets(name);

    // Search for the appointment
    int found = 0;
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            // Delete the appointment
            for (int j = i; j < numAppointments - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            numAppointments--;
            found = 1;
            break;
        }
    }

    // If the appointment was not found, print an error message
    if (found == 0) {
        printf("No appointment found for %s.\n", name);
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate some random appointments
    for (int i = 0; i < 10; i++) {
        addAppointment();
    }

    // Print the welcome message
    printf("Welcome to the Appointment Scheduler!\n");

    // Display the menu
    int choice;
    do {
        printf("\nPlease select an option:\n");
        printf("1. Add an appointment\n");
        printf("2. View appointments\n");
        printf("3. Search for an appointment\n");
        printf("4. Delete an appointment\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                searchAppointment();
                break;
            case 4:
                deleteAppointment();
                break;
        }
    } while (choice != 5);

    // Print the goodbye message
    printf("Thank you for using the Appointment Scheduler!\n");

    return 0;
}