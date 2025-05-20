//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Appointment struct represents a single appointment
struct Appointment {
    char clientName[50];
    char date[20];
    char time[10];
};

// Function to print the appointment details
void printAppointment(struct Appointment appt) {
    printf("Client Name: %s\n", appt.clientName);
    printf("Date: %s\n", appt.date);
    printf("Time: %s\n", appt.time);
}

// Function to add a new appointment to the scheduler
void addAppointment(struct Appointment appointmentList[], int *numAppointments) {
    printf("Enter client name: ");
    scanf("%s", appointmentList[*numAppointments].clientName);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", appointmentList[*numAppointments].date);
    printf("Enter time (hh:mm): ");
    scanf("%s", appointmentList[*numAppointments].time);
    (*numAppointments)++;
}

// Function to cancel an appointment from the scheduler
void cancelAppointment(struct Appointment appointmentList[], int *numAppointments) {
    char name[50];
    printf("Enter client name: ");
    scanf("%s", name);

    int i;
    bool found = false;
    for (i = 0; i < *numAppointments; i++) {
        if (strcmp(name, appointmentList[i].clientName) == 0) {
            found = true;
            *numAppointments -= 1;
            printf("Appointment cancelled:\n");
            printAppointment(appointmentList[i]);

            // Shift all the appointments after the cancelled one
            // to the left to fill the gap
            int j;
            for (j = i; j < *numAppointments; j++) {
                appointmentList[j] = appointmentList[j+1];
            }
            break;
        }
    }

    if (!found) {
        printf("Appointment not found.\n");
    }
}

int main() {
    struct Appointment appointmentList[100];
    int numAppointments = 0;
    
    printf("Welcome to the Appointment Scheduler!\n");

    while (true) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an appointment\n");
        printf("2. Cancel an appointment\n");
        printf("3. View all appointments\n");
        printf("4. Exit scheduler\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(appointmentList, &numAppointments);
                break;
            case 2:
                cancelAppointment(appointmentList, &numAppointments);
                break;
            case 3:
                printf("All Appointments:\n");
                int i;
                for (i = 0; i < numAppointments; i++) {
                    printf("Appointment %d:\n", i+1);
                    printAppointment(appointmentList[i]);
                    printf("\n");
                }
                break;
            case 4:
                printf("Exiting scheduler. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}