//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: ultraprecise
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
    char description[200];
} appointment;

// Function to add an appointment to the schedule
void add_appointment(appointment *schedule, int *num_appointments) {
    // Get the appointment details from the user
    printf("Enter the name of the person you are scheduling an appointment for: ");
    scanf("%s", schedule[*num_appointments].name);

    printf("Enter the date of the appointment (YYYY-MM-DD): ");
    scanf("%s", schedule[*num_appointments].date);

    printf("Enter the time of the appointment (HH:MM): ");
    scanf("%s", schedule[*num_appointments].time);

    printf("Enter a brief description of the appointment: ");
    scanf(" %[^\n]%*c", schedule[*num_appointments].description);

    // Increment the number of appointments
    (*num_appointments)++;
}

// Function to print the schedule
void print_schedule(appointment *schedule, int num_appointments) {
    // Print the header
    printf("%-20s %-11s %-6s %s\n", "Name", "Date", "Time", "Description");

    // Print each appointment
    for (int i = 0; i < num_appointments; i++) {
        printf("%-20s %-11s %-6s %s\n", schedule[i].name, schedule[i].date, schedule[i].time, schedule[i].description);
    }
}

// Main function
int main() {
    // Create the schedule
    appointment schedule[MAX_APPOINTMENTS];

    // Initialize the number of appointments
    int num_appointments = 0;

    // Add appointments to the schedule
    while (1) {
        // Get the user's choice
        int choice;
        printf("1. Add an appointment\n2. Print the schedule\n3. Quit\n");
        scanf("%d", &choice);

        // Add an appointment
        if (choice == 1) {
            add_appointment(schedule, &num_appointments);
        }
        // Print the schedule
        else if (choice == 2) {
            print_schedule(schedule, num_appointments);
        }
        // Quit the program
        else if (choice == 3) {
            break;
        }
        // Invalid choice
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}