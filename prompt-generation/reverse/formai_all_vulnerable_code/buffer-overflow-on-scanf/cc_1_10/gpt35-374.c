//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_NAME_LENGTH 20
#define MAX_APPTS 5

// Define structs
typedef struct {
    int month;
    int day;
    int year;
} Date;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Date date;
} Appointment;

// Define functions
void addAppointment(Appointment[], int*);
void printAppointments(Appointment[], int);
void deleteAppointment(Appointment[], int*);

// Main function
int main() {
    Appointment appts[MAX_APPTS];
    int numAppts = 0;
    char choice;

    do {
        // Print menu
        printf("\nAppointment Scheduler:\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit Program\n");

        // Get choice from user
        printf("\nEnter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addAppointment(appts, &numAppts);
                break;
            case '2':
                printAppointments(appts, numAppts);
                break;
            case '3':
                deleteAppointment(appts, &numAppts);
                break;
            case '4':
                printf("\nProgram exited successfully.\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (1); // Loop forever until user chooses to exit

    return 0;
}

// Add an appointment to the array
void addAppointment(Appointment appts[], int *numAppts) {
    // Check if there is room for more appointments
    if (*numAppts >= MAX_APPTS) {
        printf("\nAppointment limit reached. Please delete an appointment before adding a new one.\n");
        return;
    }

    // Get appointment details from user
    printf("\nEnter name: ");
    scanf("%s", appts[*numAppts].name);
    printf("Enter month (numerical): ");
    scanf("%d", &appts[*numAppts].date.month);
    printf("Enter day: ");
    scanf("%d", &appts[*numAppts].date.day);
    printf("Enter year: ");
    scanf("%d", &appts[*numAppts].date.year);

    // Increment number of appointments
    *numAppts += 1;

    printf("\nAppointment added successfully.\n");
}

// Print all appointments in the array
void printAppointments(Appointment appts[], int numAppts) {
    // Check if there are any appointments
    if (numAppts == 0) {
        printf("\nNo appointments scheduled.\n");
        return;
    }

    // Print all appointments
    printf("\nAppointments:\n");
    for (int i = 0; i < numAppts; i++) {
        printf("%d/%d/%d - %s\n", appts[i].date.month, appts[i].date.day, appts[i].date.year, appts[i].name);
    }
}

// Delete an appointment from the array
void deleteAppointment(Appointment appts[], int *numAppts) {
    // Check if there are any appointments
    if (*numAppts == 0) {
        printf("\nNo appointments scheduled.\n");
        return;
    }

    // Get appointment index from user
    int index;
    printf("\nEnter appointment number to delete (1-%d): ", *numAppts);
    scanf("%d", &index);

    // Check if index is valid
    if (index < 1 || index > *numAppts) {
        printf("\nInvalid appointment number. Please try again.\n");
        return;
    }

    // Shift all appointments after the deleted index down one
    for (int i = index - 1; i < *numAppts - 1; i++) {
        appts[i] = appts[i + 1];
    }

    // Decrement number of appointments
    *numAppts -= 1;

    printf("\nAppointment deleted successfully.\n");
}