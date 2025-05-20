//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments that can be scheduled
#define MAX_APPOINTMENTS 100

// Define the maximum length of the appointment name and the doctor's name
#define MAX_NAME_LENGTH 50

// Define the structure for an appointment
typedef struct appointment {
    char name[MAX_NAME_LENGTH];
    char doctor[MAX_NAME_LENGTH];
    int day;
    int month;
    int year;
} Appointment;

// Function to display the main menu and get user input
int displayMenu() {
    int choice;
    printf("\nAppointment Scheduler\n");
    printf("---------------------\n");
    printf("1. Add an appointment\n");
    printf("2. Remove an appointment\n");
    printf("3. View all appointments\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add a new appointment to the list
void addAppointment(Appointment appointments[], int* numAppointments) {
    // Check if the maximum number of appointments have been reached
    if (*numAppointments >= MAX_APPOINTMENTS) {
        printf("\nMaximum number of appointments reached.\n");
        return;
    }
    // Get the details of the appointment from the user
    printf("\nEnter the name of the patient: ");
    scanf("%s", appointments[*numAppointments].name);
    printf("Enter the name of the doctor: ");
    scanf("%s", appointments[*numAppointments].doctor);
    printf("Enter the date of the appointment (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &appointments[*numAppointments].day, 
          &appointments[*numAppointments].month, &appointments[*numAppointments].year);
    // Increment the number of appointments
    (*numAppointments)++;
    printf("\nAppointment added successfully.\n");
}

// Function to remove an appointment from the list
void removeAppointment(Appointment appointments[], int* numAppointments) {
    int i, j;
    char name[MAX_NAME_LENGTH];
    int day, month, year;
    // Get the details of the appointment to be removed from the user
    printf("\nEnter the name of the patient: ");
    scanf("%s", name);
    printf("Enter the date of the appointment (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &day, &month, &year);
    // Search for the appointment in the list
    for (i = 0; i < *numAppointments; i++) {
        if (strcmp(name, appointments[i].name) == 0 &&
            day == appointments[i].day &&
            month == appointments[i].month &&
            year == appointments[i].year) {
            // Shift the remaining appointments one position to the left
            for (j = i + 1; j < *numAppointments; j++) {
                appointments[j - 1] = appointments[j];
            }
            // Decrement the number of appointments
            (*numAppointments)--;
            printf("\nAppointment removed successfully.\n");
            return;
        }
    }
    printf("\nAppointment not found.\n");
}

// Function to view all appointments
void viewAppointments(Appointment appointments[], int numAppointments) {
    int i;
    // Display the appointments in a tabular format
    printf("\nAll Appointments\n");
    printf("-----------------\n");
    printf("%-20s %-20s %-20s\n", "Patient Name", "Doctor Name", "Appointment Date");
    for (i = 0; i < numAppointments; i++) {
        printf("%-20s %-20s %02d-%02d-%04d\n", appointments[i].name, appointments[i].doctor,
               appointments[i].day, appointments[i].month, appointments[i].year);
    }
}

// Main function
int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;
    int choice;
    while (1) {
        choice = displayMenu();
        switch (choice) {
            case 1:
                addAppointment(appointments, &numAppointments);
                break;
            case 2:
                removeAppointment(appointments, &numAppointments);
                break;
            case 3:
                viewAppointments(appointments, numAppointments);
                break;
            case 4:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}