//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_APPOINTMENTS 100

// Struct to hold appointment data
typedef struct {
    char name[MAX_NAME_LENGTH];
    int day;
    int time;
} Appointment;

// Global variables
Appointment appointments[MAX_APPOINTMENTS];
int numAppointments = 0;

// Function to add appointment
void addAppointment() {
    if (numAppointments == MAX_APPOINTMENTS) {
        printf("Error: Maximum number of appointments reached\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    int day, time;
    printf("Name: ");
    scanf("%s", name);
    printf("Day: ");
    scanf("%d", &day);
    printf("Time: ");
    scanf("%d", &time);

    Appointment appt;
    strcpy(appt.name, name);
    appt.day = day;
    appt.time = time;

    appointments[numAppointments++] = appt;
    printf("Appointment added successfully!\n");
}

// Function to remove appointment
void removeAppointment() {
    char name[MAX_NAME_LENGTH];
    int day, time;
    printf("Name: ");
    scanf("%s", name);
    printf("Day: ");
    scanf("%d", &day);
    printf("Time: ");
    scanf("%d", &time);

    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].name, name) == 0 &&
            appointments[i].day == day &&
            appointments[i].time == time) {
            for (int j = i; j < numAppointments - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            numAppointments--;
            printf("Appointment removed successfully!\n");
            return;
        }
    }

    printf("Error: Appointment not found\n");
}

// Function to show all appointments
void showAppointments() {
    if (numAppointments == 0) {
        printf("No appointments found.\n");
        return;
    }

    printf("Name\tDay\tTime\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s\t%d\t%d\n", appointments[i].name, appointments[i].day, appointments[i].time);
    }
}

// Main function
int main() {
    int choice;
    bool running = true;
    while (running) {
        printf("\n");
        printf("1. Add Appointment\n");
        printf("2. Remove Appointment\n");
        printf("3. Show Appointments\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                removeAppointment();
                break;
            case 3:
                showAppointments();
                break;
            case 4:
                running = false;
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}