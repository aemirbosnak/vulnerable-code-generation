//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold appointment information
typedef struct Appointment {
    char day[10];
    char time[10];
    char name[50];
} Appointment;

// Function to print out a single appointment
void printAppointment(Appointment apt) {
    printf("Appointment on %s at %s with %s\n", apt.day, apt.time, apt.name);
}

// Function to add a new appointment to the scheduler
void addAppointment(Appointment *scheduler, int size) {
    // Get appointment details from user input
    char day[10];
    char time[10];
    char name[50];
    printf("Enter the day of the appointment (MM/DD/YYYY): ");
    scanf("%s", day);
    printf("Enter the time of the appointment (HH:MM): ");
    scanf("%s", time);
    printf("Enter the name of the person for this appointment: ");
    scanf("%s", name);

    // Add the appointment to the scheduler
    strcpy(scheduler[size].day, day);
    strcpy(scheduler[size].time, time);
    strcpy(scheduler[size].name, name);
    printf("Appointment added!\n");
}

// Function to display all appointments on a given day
void viewAppointments(Appointment *scheduler, int size) {
    // Get the day to view appointments for
    char day[10];
    printf("Enter the day to view appointments (MM/DD/YYYY): ");
    scanf("%s", day);

    // Loop through all appointments and print those on the given day
    for (int i = 0; i < size; i++) {
        if (strcmp(scheduler[i].day, day) == 0) {
            printAppointment(scheduler[i]);
        }
    }
}

int main() {
    // Create a dynamic array to hold appointments (initial size of 5)
    int capacity = 5;
    Appointment *scheduler = malloc(capacity * sizeof(Appointment));
    int size = 0;

    // Display menu to user
    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add an appointment\n");
        printf("2. View appointments on a given day\n");
        printf("3. Exit\n");
        int selection;
        printf("Enter selection (1-3): ");
        scanf("%d", &selection);
        if (selection == 1) {
            // If the array is full, double the capacity
            if (size == capacity) {
                capacity *= 2;
                scheduler = realloc(scheduler, capacity * sizeof(Appointment));
            }
            addAppointment(&scheduler[size], size);
            size++;
        } else if (selection == 2) {
            viewAppointments(scheduler, size);
        } else if (selection == 3) {
            break;
        } else {
            printf("Invalid selection!\n");
        }
    }

    // Free memory used by the dynamic array
    free(scheduler);

    return 0;
}