//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char clientName[50];
    char appointmentDate[20];
    char startTime[10];
    char endTime[10];
} Appointment;

// Function prototypes
void addAppointment(Appointment appointments[], int *numAppointments);
void viewAppointments(Appointment appointments[], int numAppointments);
void cancelAppointment(Appointment appointments[], int *numAppointments);

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;
    int choice;

    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Cancel Appointment\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(appointments, &numAppointments);
                break;
            case 2:
                viewAppointments(appointments, numAppointments);
                break;
            case 3:
                cancelAppointment(appointments, &numAppointments);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void addAppointment(Appointment appointments[], int *numAppointments) {
    // Check if maximum appointments reached
    if (*numAppointments == MAX_APPOINTMENTS) {
        printf("ERROR: Maximum number of appointments reached.\n");
        return;
    }

    // Get appointment details from user
    printf("\nEnter Client Name: ");
    getchar(); // Clear input buffer
    fgets(appointments[*numAppointments].clientName, sizeof(appointments[*numAppointments].clientName), stdin);
    appointments[*numAppointments].clientName[strcspn(appointments[*numAppointments].clientName, "\n")] = 0; // Remove newline character

    printf("Enter Appointment Date (DD/MM/YYYY): ");
    scanf("%s", appointments[*numAppointments].appointmentDate);

    printf("Enter Start Time (HH:MM AM/PM): ");
    scanf("%s", appointments[*numAppointments].startTime);

    printf("Enter End Time (HH:MM AM/PM): ");
    scanf("%s", appointments[*numAppointments].endTime);

    // Increment number of appointments
    *numAppointments += 1;

    printf("Appointment added successfully.\n");
}

void viewAppointments(Appointment appointments[], int numAppointments) {
    // Check if there are no appointments
    if (numAppointments == 0) {
        printf("There are no appointments.\n");
        return;
    }

    // Print all appointments
    printf("\nAppointments\n");
    printf("Client Name\tDate\t\tStart Time\tEnd Time\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s\t%s\t%s\t%s\n", appointments[i].clientName, appointments[i].appointmentDate, appointments[i].startTime, appointments[i].endTime);
    }
}

void cancelAppointment(Appointment appointments[], int *numAppointments) {
    // Check if there are no appointments
    if (*numAppointments == 0) {
        printf("There are no appointments to cancel.\n");
        return;
    }

    char clientName[50];
    printf("Enter the name of the client whose appointment needs to be cancelled: ");
    getchar(); // Clear input buffer
    fgets(clientName, sizeof(clientName), stdin);
    clientName[strcspn(clientName, "\n")] = 0; // Remove newline character

    // Search for appointment with given client name and delete it
    int found = 0;
    for (int i = 0; i < *numAppointments; i++) {
        if (strcmp(appointments[i].clientName, clientName) == 0) {
            *numAppointments -= 1;
            for (int j = i; j < *numAppointments; j++) {
                appointments[j] = appointments[j + 1];
            }
            printf("Appointment for %s on %s from %s to %s has been cancelled.\n", appointments[i].clientName, appointments[i].appointmentDate, appointments[i].startTime, appointments[i].endTime);
            found = 1;
            break;
        }
    }

    // If appointment not found, display error message
    if (!found) {
        printf("No appointment found for %s.\n", clientName);
    }
}