//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define a struct for appointments
typedef struct {
    char name[50];
    char date[20];
    char time[20];
    char location[50];
} Appointment;

// Function for displaying appointment details
void displayAppointment(Appointment appt) {
    printf("Name: %s\n", appt.name);
    printf("Date: %s\n", appt.date);
    printf("Time: %s\n", appt.time);
    printf("Location: %s\n", appt.location);
}

// Function for adding a new appointment
void addAppointment(Appointment *appts, int *numAppts) {
    // Ensure there is space for a new appointment
    if (*numAppts >= MAX_APPOINTMENTS) {
        printf("Sorry, the maximum number of appointments has been reached.\n");
        return;
    }

    // Get input from user for new appointment
    printf("Enter the name: ");
    scanf("%s", appts[*numAppts].name);
    printf("Enter the date (mm/dd/yyyy): ");
    scanf("%s", appts[*numAppts].date);
    printf("Enter the time (hh:mm AM/PM): ");
    scanf("%s", appts[*numAppts].time);
    printf("Enter the location: ");
    scanf("%s", appts[*numAppts].location);

    // Increment the number of appointments
    (*numAppts)++;

    printf("Appointment added successfully!\n");
}

// Function for searching for an appointment by date
void searchByDate(Appointment *appts, int numAppts) {
    // Get input from user for date to search for
    char searchDate[20];
    printf("Enter the date to search for (mm/dd/yyyy): ");
    scanf("%s", searchDate);

    // Loop through appointments and display matches
    int foundCount = 0;
    for (int i = 0; i < numAppts; i++) {
        if (strcmp(appts[i].date, searchDate) == 0) {
            displayAppointment(appts[i]);
            foundCount++;
        }
    }

    // Display message if no matches were found
    if (foundCount == 0) {
        printf("Sorry, no appointments found for that date.\n");
    }
}

// Function for deleting an appointment by name
void deleteByName(Appointment *appts, int *numAppts) {
    // Get input from user for name to search for
    char searchName[50];
    printf("Enter the name of the appointment to delete: ");
    scanf("%s", searchName);

    // Loop through appointments and delete matches
    int numDeleted = 0;
    for (int i = 0; i < *numAppts; i++) {
        if (strcmp(appts[i].name, searchName) == 0) {
            // Move all subsequent appointments back by one index
            for (int j = i; j < *numAppts - 1; j++) {
                appts[j] = appts[j + 1];
            }
            numDeleted++;
        }
    }

    // Decrement the number of appointments by the number that were deleted
    *numAppts -= numDeleted;

    // Display message if no matches were found
    if (numDeleted == 0) {
        printf("Sorry, no appointments found with that name.\n");
    } else {
        printf("Appointment(s) deleted successfully!\n");
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize array of appointments
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    // Loop for user input
    char userInput[20];
    while (1) {
        // Display menu and get user input
        printf("--------------------\n");
        printf("Appointment Scheduler\n");
        printf("--------------------\n");
        printf("1. Add Appointment\n");
        printf("2. Search by Date\n");
        printf("3. Delete by Name\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%s", userInput);

        // Handle user input
        if (strcmp(userInput, "1") == 0) {
            addAppointment(appointments, &numAppointments);
        } else if (strcmp(userInput, "2") == 0) {
            searchByDate(appointments, numAppointments);
        } else if (strcmp(userInput, "3") == 0) {
            deleteByName(appointments, &numAppointments);
        } else if (strcmp(userInput, "4") == 0) {
            break;
        } else {
            printf("Invalid choice. Please enter a number 1-4.\n");
        }
    }

    return 0;
}