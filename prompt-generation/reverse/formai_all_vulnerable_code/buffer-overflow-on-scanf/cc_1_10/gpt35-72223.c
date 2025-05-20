//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold appointment data
typedef struct appointment {
    char name[50];
    char date[15];
    char time[15];
} Appointment;

// Function to display menu options
void displayMenu() {
    printf("Appointment Scheduler\n");
    printf("---------------------\n");
    printf("1. Add appointment\n");
    printf("2. Cancel appointment\n");
    printf("3. View appointments\n");
    printf("4. Exit\n");
    printf("\n");
}

// Function to add an appointment
void addAppointment(Appointment *appointments[], int *count) {
    printf("Add Appointment\n");
    printf("---------------\n");

    // Allocate memory for new appointment
    appointments[*count] = malloc(sizeof(Appointment));

    // Get appointment name
    printf("Enter appointment name: ");
    scanf("%s", appointments[*count]->name);

    // Get appointment date
    printf("Enter appointment date (dd/mm/yyyy): ");
    scanf("%s", appointments[*count]->date);

    // Get appointment time
    printf("Enter appointment time (hh:mm am/pm): ");
    scanf("%s", appointments[*count]->time);

    // Increment appointment count
    (*count)++;
}

// Function to cancel an appointment
void cancelAppointment(Appointment *appointments[], int *count) {
    printf("Cancel Appointment\n");
    printf("------------------\n");

    // Get appointment name to cancel
    char name[50];
    printf("Enter appointment name to cancel: ");
    scanf("%s", name);

    // Loop through appointments and find appointment to cancel
    int i;
    for (i = 0; i < *count; i++) {
        if (strcmp(appointments[i]->name, name) == 0) {
            // Free memory for cancelled appointment
            free(appointments[i]);

            // Shift appointments to fill cancelled position
            int j;
            for (j = i; j < *count - 1; j++) {
                appointments[j] = appointments[j+1];
            }

            // Decrement appointment count
            (*count)--;
            printf("Appointment cancelled.\n");
            return;
        }
    }

    printf("Appointment not found.\n");
}

// Function to display all appointments
void viewAppointments(Appointment *appointments[], int count) {
    printf("View Appointments\n");
    printf("-----------------\n");

    // Loop through appointments and display appointment data
    int i;
    for (i = 0; i < count; i++) {
        printf("%s on %s at %s\n", appointments[i]->name, appointments[i]->date, appointments[i]->time);
    }
}

int main() {
    // Create appointment array
    Appointment *appointments[100];
    int count = 0;

    int choice;
    do {
        displayMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(appointments, &count);
                break;
            case 2:
                cancelAppointment(appointments, &count);
                break;
            case 3:
                viewAppointments(appointments, count);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    } while (choice != 4);

    // Free memory for all appointments
    int i;
    for (i = 0; i < count; i++) {
        free(appointments[i]);
    }

    return 0;
}