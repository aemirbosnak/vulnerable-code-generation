//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define structure to hold appointment information
struct Appointment {
    char name[50];
    char description[100];
    int year;
    int month;
    int day;
    int hour;
    int minute;
};

// Declare array to hold appointments
struct Appointment appointments[MAX_APPOINTMENTS];

// Keep track of number of appointments in array
int num_appointments = 0;

// Function prototypes
void add_appointment();
void view_appointments();
void search_appointments();

// Main function
int main() {
    int option;

    printf("Welcome to the Peaceful Appointment Scheduler\n\n");

    do {
        // Present menu to user
        printf("Please select an option:\n");
        printf("1. Add an appointment\n");
        printf("2. View all appointments\n");
        printf("3. Search for an appointment\n");
        printf("4. Exit\n\n");

        // Get user input
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                search_appointments();
                break;
            case 4:
                printf("Thank you for using the Peaceful Appointment Scheduler. Have a peaceful day!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }

        printf("\n");

    } while (option != 4);

    return 0;
}

// Function to add an appointment
void add_appointment() {
    struct Appointment new_appointment;

    // Get appointment information from user
    printf("Enter the name of the appointment: ");
    scanf("%s", new_appointment.name);

    printf("Enter a description of the appointment: ");
    scanf("%s", new_appointment.description);

    printf("Enter the year of the appointment (YYYY): ");
    scanf("%d", &new_appointment.year);

    printf("Enter the month of the appointment (MM): ");
    scanf("%d", &new_appointment.month);

    printf("Enter the day of the appointment (DD): ");
    scanf("%d", &new_appointment.day);

    printf("Enter the hour of the appointment (HH): ");
    scanf("%d", &new_appointment.hour);

    printf("Enter the minute of the appointment (MM): ");
    scanf("%d", &new_appointment.minute);

    // Add appointment to array
    if (num_appointments < MAX_APPOINTMENTS) {
        appointments[num_appointments] = new_appointment;
        num_appointments++;
        printf("Appointment successfully added.\n");
    } else {
        printf("Cannot add appointment: maximum number of appointments reached.\n");
    }
}

// Function to view all appointments
void view_appointments() {
    if (num_appointments == 0) {
        printf("There are no appointments to view.\n");
    } else {
        printf("All Appointments:\n");
        for (int i = 0; i < num_appointments; i++) {
            printf("%d. %s - %s on %d/%d/%d at %02d:%02d\n", i+1,
            appointments[i].name, appointments[i].description,
            appointments[i].day, appointments[i].month, appointments[i].year,
            appointments[i].hour, appointments[i].minute);
        }
    }
}

// Function to search for an appointment
void search_appointments() {
    char search_name[50];
    int found = 0;

    printf("Enter the name of the appointment to search for: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, search_name) == 0) {
            printf("%d. %s - %s on %d/%d/%d at %02d:%02d\n", i+1,
            appointments[i].name, appointments[i].description,
            appointments[i].day, appointments[i].month, appointments[i].year,
            appointments[i].hour, appointments[i].minute);
            found = 1;
        }
    }

    if (!found) {
        printf("No appointments found with that name.\n");
    }
}