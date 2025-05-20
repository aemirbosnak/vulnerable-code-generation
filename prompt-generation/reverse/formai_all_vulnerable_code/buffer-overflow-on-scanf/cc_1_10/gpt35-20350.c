//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 100

// Struct to store information about an appointment
typedef struct {
    char name[MAX_INPUT_LEN];
    char date[MAX_INPUT_LEN];
    char time[MAX_INPUT_LEN];
} Appointment;

// Function to display the menu and get user input
int menu() {
    int choice;
    printf("\n==== APPOINTMENT SCHEDULER ====\n");
    printf("1. View all appointments\n");
    printf("2. Add a new appointment\n");
    printf("3. Delete an appointment\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to display all the appointments
void viewAppointments(Appointment *appointments, int numAppointments) {
    printf("\n==== ALL APPOINTMENTS ====\n");
    if (numAppointments == 0) {
        printf("(No appointments scheduled)\n");
    }
    else {
        for (int i = 0; i < numAppointments; i++) {
            printf("%d. %s on %s at %s\n", i+1, appointments[i].name, appointments[i].date, appointments[i].time);
        }
    }
}

// Function to add a new appointment
void addAppointment(Appointment *appointments, int *numAppointments) {
    printf("\n==== ADD NEW APPOINTMENT ====\n");
    printf("Enter name: ");
    scanf("%s", appointments[*numAppointments].name);
    printf("Enter date (yyyy-mm-dd): ");
    scanf("%s", appointments[*numAppointments].date);
    printf("Enter time (hh:mm): ");
    scanf("%s", appointments[*numAppointments].time);
    (*numAppointments)++;
    printf("Appointment added!\n");
}

// Function to delete an appointment
void deleteAppointment(Appointment *appointments, int *numAppointments) {
    printf("\n==== DELETE AN APPOINTMENT ====\n");
    viewAppointments(appointments, *numAppointments);
    if (*numAppointments == 0) {
        return;
    }
    int choice;
    printf("Enter the number of the appointment to delete: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > *numAppointments) {
        printf("Invalid choice. Please try again.\n");
        return;
    }
    for (int i = choice-1; i < *numAppointments-1; i++) {
        appointments[i] = appointments[i+1];
    }
    (*numAppointments)--;
    printf("Appointment deleted!\n");
}

int main() {
    Appointment appointments[MAX_INPUT_LEN];
    int numAppointments = 0;
    int choice;

    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                viewAppointments(appointments, numAppointments);
                break;
            case 2:
                addAppointment(appointments, &numAppointments);
                break;
            case 3:
                deleteAppointment(appointments, &numAppointments);
                break;
            case 4:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}