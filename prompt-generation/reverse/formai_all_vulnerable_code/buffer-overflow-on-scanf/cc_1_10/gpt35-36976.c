//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define APPOINTMENT_SIZE 10

// Struct to store appointment data
typedef struct {
    char name[20];
    char date[12];
    char time[10];
} Appointment;

// Function to add appointment to schedule
void addAppointment(Appointment *appointments, int *num_appointments) {
    if (*num_appointments == APPOINTMENT_SIZE) {
        printf("Appointment schedule is full. Cannot add more appointments.\n");
        return;
    }

    // Get new appointment data from user
    printf("Enter customer name:\n");
    scanf(" %[^\n]", appointments[*num_appointments].name);
    printf("Enter date (dd/mm/yyyy):\n");
    scanf("%s", appointments[*num_appointments].date);
    printf("Enter time (hh:mm):\n");
    scanf("%s", appointments[*num_appointments].time);

    (*num_appointments)++;  // Increase number of appointments counter
    printf("Appointment added successfully!\n");
}

// Function to delete appointment from schedule
void deleteAppointment(Appointment *appointments, int *num_appointments) {
    if (*num_appointments == 0) {
        printf("There are no appointments to delete.\n");
        return;
    }

    // Get appointment name to delete from user
    char name[20];
    printf("Enter customer name of the appointment to be deleted:\n");
    scanf(" %[^\n]", name);

    // Find appointment index to delete
    int index_to_delete = -1;
    for (int i=0; i<*num_appointments; i++) {
        if (strcmp(name, appointments[i].name) == 0) {
            index_to_delete = i;
            break;
        }
    }

    if (index_to_delete == -1) {
        printf("Appointment not found.\n");
        return;
    }

    // Shift appointments to fill gap of deleted appointment
    for (int i=index_to_delete+1; i<*num_appointments; i++) {
        appointments[i-1] = appointments[i];
    }

    (*num_appointments)--;  // Decrease number of appointments counter
    printf("Appointment deleted successfully!\n");
}

// Function to display all appointments in schedule
void displayAppointments(Appointment *appointments, int num_appointments) {
    if (num_appointments == 0) {
        printf("There are no appointments to display.\n");
        return;
    }

    printf("Appointment schedule:\n");
    for (int i=0; i<num_appointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n\n", appointments[i].time);
    }
}

int main() {
    Appointment appointments[APPOINTMENT_SIZE];
    int num_appointments = 0;
    int choice;

    do {
        printf("Appointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. Delete appointment\n");
        printf("3. Display all appointments\n");
        printf("4. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(appointments, &num_appointments);
                break;
            case 2:
                deleteAppointment(appointments, &num_appointments);
                break;
            case 3:
                displayAppointments(appointments, num_appointments);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}