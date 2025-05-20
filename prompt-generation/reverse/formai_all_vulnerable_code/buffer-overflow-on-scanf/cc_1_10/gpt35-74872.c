//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

// Struct for an appointment
typedef struct {
    char name[50];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

// Function prototypes
void displayMenu();
void addAppointment(Appointment appointments[], int *numAppointments);
void viewAppointments(Appointment appointments[], int numAppointments);
void editAppointment(Appointment appointments[], int numAppointments);
void deleteAppointment(Appointment appointments[], int *numAppointments);

int main() {
    // Array to hold appointments
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    // Loop to display menu and handle user input
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addAppointment(appointments, &numAppointments);
                break;
            case 2:
                viewAppointments(appointments, numAppointments);
                break;
            case 3:
                editAppointment(appointments, numAppointments);
                break;
            case 4:
                deleteAppointment(appointments, &numAppointments);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to display menu options
void displayMenu() {
    printf("\n\n");
    printf("Appointment Scheduler\n");
    printf("---------------------\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Edit Appointment\n");
    printf("4. Delete Appointment\n");
    printf("5. Exit\n");
    printf("---------------------\n");
    printf("Please make a selection: ");
}

// Function to add a new appointment
void addAppointment(Appointment appointments[], int *numAppointments) {
    // Check if max number of appointments has been reached
    if (*numAppointments >= MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached.\n");
        return;
    }

    // Create new appointment and add to array
    Appointment newAppointment;
    printf("Name: ");
    scanf("%s", newAppointment.name);
    printf("Date (DD-MM-YYYY): ");
    scanf("%d-%d-%d", &newAppointment.day, &newAppointment.month, &newAppointment.year);
    printf("Time (HH:MM): ");
    scanf("%d:%d", &newAppointment.hour, &newAppointment.minute);

    appointments[*numAppointments] = newAppointment;
    (*numAppointments)++;

    printf("Appointment added.\n");
}

// Function to view all appointments
void viewAppointments(Appointment appointments[], int numAppointments) {
    // Check if no appointments have been added
    if (numAppointments == 0) {
        printf("No appointments found.\n");
        return;
    }

    // Loop through appointments and display information
    for (int i = 0; i < numAppointments; i++) {
        printf("%d. %s\n", i+1, appointments[i].name);
        printf("   Date: %d-%d-%d\n", appointments[i].day, appointments[i].month, appointments[i].year);
        printf("   Time: %d:%02d\n", appointments[i].hour, appointments[i].minute);
    }
}

// Function to edit an appointment
void editAppointment(Appointment appointments[], int numAppointments) {
    // Check if no appointments have been added
    if (numAppointments == 0) {
        printf("No appointments found.\n");
        return;
    }

    // Display current appointments and ask user which one to edit
    viewAppointments(appointments, numAppointments);

    int choice;
    printf("Please enter the number of the appointment you would like to edit: ");
    scanf("%d", &choice);

    // Check if valid choice was made
    if (choice < 1 || choice > numAppointments) {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    // Get appointment to edit and display current information
    Appointment *appointmentToEdit = &appointments[choice-1];
    printf("Name: %s\n", appointmentToEdit->name);
    printf("Date: %d-%d-%d\n", appointmentToEdit->day, appointmentToEdit->month, appointmentToEdit->year);
    printf("Time: %d:%02d\n", appointmentToEdit->hour, appointmentToEdit->minute);

    // Ask user for new information
    printf("Please enter new information:\n");
    printf("Name: ");
    scanf("%s", appointmentToEdit->name);
    printf("Date (DD-MM-YYYY): ");
    scanf("%d-%d-%d", &appointmentToEdit->day, &appointmentToEdit->month, &appointmentToEdit->year);
    printf("Time (HH:MM): ");
    scanf("%d:%d", &appointmentToEdit->hour, &appointmentToEdit->minute);

    printf("Appointment updated.\n");
}

// Function to delete an appointment
void deleteAppointment(Appointment appointments[], int *numAppointments) {
    // Check if no appointments have been added
    if (*numAppointments == 0) {
        printf("No appointments found.\n");
        return;
    }

    // Display current appointments and ask user which one to delete
    viewAppointments(appointments, *numAppointments);

    int choice;
    printf("Please enter the number of the appointment you would like to delete: ");
    scanf("%d", &choice);

    // Check if valid choice was made
    if (choice < 1 || choice > *numAppointments) {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    // Shift elements to remove appointment from array
    for (int i = choice-1; i < *numAppointments-1; i++) {
        appointments[i] = appointments[i+1];
    }

    (*numAppointments)--;

    printf("Appointment deleted.\n");
}