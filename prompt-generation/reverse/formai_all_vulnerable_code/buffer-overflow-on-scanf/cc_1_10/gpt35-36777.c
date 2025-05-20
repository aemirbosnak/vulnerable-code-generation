//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Constants
#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20
#define MAX_TIME_LENGTH 10

// Structs
typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
} Appointment;

// Function prototypes
void printMenu();
void addAppointment(Appointment[], int*);
void viewAppointments(Appointment[], int);
void deleteAppointment(Appointment[], int*);
bool dateExists(Appointment[], int, char[]);
bool timeExists(Appointment[], int, char[]);

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;
    int choice = 0;

    printf("Welcome to the Appointment Scheduler\n");

    while (choice != 4) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(appointments, &numAppointments);
                break;
            case 2:
                viewAppointments(appointments, numAppointments);
                break;
            case 3:
                deleteAppointment(appointments, &numAppointments);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Prints the menu options
void printMenu() {
    printf("Menu:\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

// Adds an appointment to the array
void addAppointment(Appointment appointments[], int *numAppointments) {
    if (*numAppointments == MAX_APPOINTMENTS) {
        printf("Unable to add appointment. Maximum number of appointments reached.\n");
        return;
    }

    Appointment newAppointment;

    // Get name
    printf("Enter name: ");
    scanf("%s", newAppointment.name);

    // Get date
    char date[MAX_DATE_LENGTH];
    bool dateExistsFlag = true;

    while (dateExistsFlag) {
        printf("Enter date (MM/DD/YYYY): ");
        scanf("%s", date);

        if (dateExists(appointments, *numAppointments, date)) {
            printf("A conflicting appointment already exists on that date. Please try again.\n");
        } else {
            dateExistsFlag = false;
            strcpy(newAppointment.date, date);
        }
    }

    // Get time
    char time[MAX_TIME_LENGTH];
    bool timeExistsFlag = true;

    while (timeExistsFlag) {
        printf("Enter time (HH:MM AM/PM): ");
        scanf("%s", time);

        if (timeExists(appointments, *numAppointments, time)) {
            printf("A conflicting appointment already exists at that time. Please try again.\n");
        } else {
            timeExistsFlag = false;
            strcpy(newAppointment.time, time);
        }
    }

    // Add appointment to array
    appointments[*numAppointments] = newAppointment;
    (*numAppointments)++;
    printf("Appointment added successfully!\n");
}

// Views all appointments in the array
void viewAppointments(Appointment appointments[], int numAppointments) {
    if (numAppointments == 0) {
        printf("No appointments found.\n");
        return;
    }

    printf("Appointments:\n");
    printf("%-20s| %-20s| %-20s\n", "Date", "Time", "Name");

    for (int i = 0; i < numAppointments; i++) {
        printf("%-20s| %-20s| %-20s\n", appointments[i].date, appointments[i].time, appointments[i].name);
    }
}

// Deletes an appointment from the array
void deleteAppointment(Appointment appointments[], int *numAppointments) {
    if (*numAppointments == 0) {
        printf("No appointments found.\n");
        return;
    }

    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
    bool foundFlag = false;

    // Get date and time of appointment to delete
    printf("Enter the date of the appointment to delete (MM/DD/YYYY): ");
    scanf("%s", date);
    printf("Enter the time of the appointment to delete (HH:MM AM/PM): ");
    scanf("%s", time);

    // Find appointment and delete it
    for (int i = 0; i < *numAppointments; i++) {
        if (strcmp(appointments[i].date, date) == 0 && strcmp(appointments[i].time, time) == 0) {
            foundFlag = true;

            // Shift elements to the left to remove appointment
            for (int j = i; j < *numAppointments - 1; j++) {
                appointments[j] = appointments[j + 1];
            }

            (*numAppointments)--;
            printf("Appointment deleted successfully!\n");
            break;
        }
    }

    if (!foundFlag) {
        printf("Appointment not found.\n");
    }
}

// Checks if a given date already exists in the array
bool dateExists(Appointment appointments[], int numAppointments, char date[]) {
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].date, date) == 0) {
            return true;
        }
    }

    return false;
}

// Checks if a given time already exists in the array
bool timeExists(Appointment appointments[], int numAppointments, char time[]) {
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].time, time) == 0) {
            return true;
        }
    }

    return false;
}