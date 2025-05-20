//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define NAME_LEN 50
#define DATE_LEN 11 // Format: YYYY-MM-DD
#define TIME_LEN 6  // Format: HH:MM

typedef struct Appointment {
    char clientName[NAME_LEN];
    char date[DATE_LEN];
    char time[TIME_LEN];
    char description[100];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("There are too many appointments scheduled. Cannot add more.\n");
        return;
    }

    printf("Enter client name: ");
    scanf("%s", appointments[appointmentCount].clientName);

    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%s", appointments[appointmentCount].date);

    printf("Enter appointment time (HH:MM): ");
    scanf("%s", appointments[appointmentCount].time);

    printf("Enter description: ");
    getchar(); // to consume newline leftover
    fgets(appointments[appointmentCount].description, sizeof(appointments[appointmentCount].description), stdin);
    appointments[appointmentCount].description[strcspn(appointments[appointmentCount].description, "\n")] = 0; // remove newline

    appointmentCount++;
    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\n--- Scheduled Appointments ---\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Client Name: %s\n", appointments[i].clientName);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("Description: %s\n\n", appointments[i].description);
    }
}

void searchAppointment() {
    char clientName[NAME_LEN];
    printf("Enter client name to search: ");
    scanf("%s", clientName);

    int found = 0;
    for (int i = 0; i < appointmentCount; i++) {
        if (strcmp(appointments[i].clientName, clientName) == 0) {
            found = 1;
            printf("Found Appointment:\n");
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("Description: %s\n\n", appointments[i].description);
        }
    }
    if (!found) {
        printf("No appointments found for the client '%s'.\n", clientName);
    }
}

void deleteAppointment() {
    char clientName[NAME_LEN];
    printf("Enter client name to delete appointment: ");
    scanf("%s", clientName);

    int foundIndex = -1;
    for (int i = 0; i < appointmentCount; i++) {
        if (strcmp(appointments[i].clientName, clientName) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        for (int i = foundIndex; i < appointmentCount - 1; i++) {
            appointments[i] = appointments[i + 1];
        }
        appointmentCount--;
        printf("Appointment for '%s' deleted successfully.\n", clientName);
    } else {
        printf("No appointment found for '%s'.\n", clientName);
    }
}

void displayMenu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Search Appointment\n");
    printf("4. Delete Appointment\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                searchAppointment();
                break;
            case 4:
                deleteAppointment();
                break;
            case 5:
                printf("Exiting the appointment scheduler. Farewell!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}