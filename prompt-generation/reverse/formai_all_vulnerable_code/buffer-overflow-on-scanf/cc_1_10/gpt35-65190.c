//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of appointments that can be scheduled
#define MAX_APPOINTMENTS 100

// Structure to hold the details of an appointment
typedef struct {
    char name[50];
    char date[20];
    char time[20];
} Appointment;

// Function to print the main menu
void print_menu() {
    printf("\n*** Appointment Scheduler ***\n");
    printf("1. Schedule an appointment\n");
    printf("2. View all appointments\n");
    printf("3. Cancel an appointment\n");
    printf("4. Exit\n");
}

// Function to schedule an appointment
void schedule_appointment(Appointment appointments[], int *num_appointments) {
    if (*num_appointments == MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments can be scheduled.\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", appointments[*num_appointments].name);

    printf("Enter the date (MM/DD/YYYY): ");
    scanf("%s", appointments[*num_appointments].date);

    printf("Enter the time (HH:MM AM/PM): ");
    scanf("%s", appointments[*num_appointments].time);

    printf("Appointment scheduled successfully!\n");

    (*num_appointments)++;
}

// Function to view all appointments
void view_appointments(Appointment appointments[], int num_appointments) {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("All appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%d. %s on %s at %s\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

// Function to cancel an appointment
void cancel_appointment(Appointment appointments[], int *num_appointments) {
    if (*num_appointments == 0) {
        printf("No appointments to cancel.\n");
        return;
    }

    printf("Enter the appointment number to cancel: ");
    int app_num;
    scanf("%d", &app_num);

    if (app_num < 1 || app_num > *num_appointments) {
        printf("Invalid appointment number.\n");
        return;
    }

    // Remove the appointment by shifting all appointments after it to the left
    for (int i = app_num - 1; i < *num_appointments - 1; i++) {
        strcpy(appointments[i].name, appointments[i + 1].name);
        strcpy(appointments[i].date, appointments[i + 1].date);
        strcpy(appointments[i].time, appointments[i + 1].time);
    }

    (*num_appointments)--;
    printf("Appointment cancelled successfully!\n");
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    int choice;
    do {
        print_menu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                schedule_appointment(appointments, &num_appointments);
                break;
            case 2:
                view_appointments(appointments, num_appointments);
                break;
            case 3:
                cancel_appointment(appointments, &num_appointments);
                break;
            case 4:
                printf("Exiting appointment scheduler...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}