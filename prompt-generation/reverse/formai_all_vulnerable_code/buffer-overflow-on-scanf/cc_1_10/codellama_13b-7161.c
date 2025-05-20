//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: sophisticated
/*
 * Appointment Scheduler
 *
 * An example program to demonstrate a sophisticated appointment scheduling system in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an appointment
typedef struct {
    char name[50];
    char date[10];
    char time[10];
} Appointment;

// Function to display a list of appointments
void displayAppointments(Appointment appointments[], int numAppointments) {
    int i;
    for (i = 0; i < numAppointments; i++) {
        printf("Appointment %d: %s on %s at %s\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

// Function to add a new appointment
void addAppointment(Appointment appointments[], int *numAppointments) {
    printf("Enter the name of the appointment: ");
    scanf("%s", appointments[*numAppointments].name);
    printf("Enter the date of the appointment: ");
    scanf("%s", appointments[*numAppointments].date);
    printf("Enter the time of the appointment: ");
    scanf("%s", appointments[*numAppointments].time);
    *numAppointments = *numAppointments + 1;
}

// Function to delete an appointment
void deleteAppointment(Appointment appointments[], int *numAppointments) {
    int index;
    printf("Enter the index of the appointment to delete: ");
    scanf("%d", &index);
    if (index >= 0 && index < *numAppointments) {
        for (int i = index; i < *numAppointments - 1; i++) {
            appointments[i] = appointments[i + 1];
        }
        *numAppointments = *numAppointments - 1;
    } else {
        printf("Invalid index\n");
    }
}

// Function to modify an appointment
void modifyAppointment(Appointment appointments[], int *numAppointments) {
    int index;
    printf("Enter the index of the appointment to modify: ");
    scanf("%d", &index);
    if (index >= 0 && index < *numAppointments) {
        printf("Enter the new name of the appointment: ");
        scanf("%s", appointments[index].name);
        printf("Enter the new date of the appointment: ");
        scanf("%s", appointments[index].date);
        printf("Enter the new time of the appointment: ");
        scanf("%s", appointments[index].time);
    } else {
        printf("Invalid index\n");
    }
}

int main() {
    // Initialize the appointments array
    Appointment appointments[100];
    int numAppointments = 0;

    // Display the menu
    printf("1. Display appointments\n");
    printf("2. Add appointment\n");
    printf("3. Delete appointment\n");
    printf("4. Modify appointment\n");
    printf("5. Exit\n");

    // Loop until the user exits
    int choice;
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                displayAppointments(appointments, numAppointments);
                break;
            case 2:
                addAppointment(appointments, &numAppointments);
                break;
            case 3:
                deleteAppointment(appointments, &numAppointments);
                break;
            case 4:
                modifyAppointment(appointments, &numAppointments);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);

    return 0;
}