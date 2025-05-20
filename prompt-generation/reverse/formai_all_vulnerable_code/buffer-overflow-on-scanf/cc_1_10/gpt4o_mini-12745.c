//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_STRING_LENGTH 100

typedef struct {
    char name[MAX_STRING_LENGTH];
    char date[MAX_STRING_LENGTH]; // Format: YYYY-MM-DD
    char time[MAX_STRING_LENGTH]; // Format: HH:MM
    char description[MAX_STRING_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void displayMenu() {
    printf("\nAppointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Search Appointment\n");
    printf("5. Exit\n");
}

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Unable to add appointment. Maximum limit reached.\n");
        return;
    }
    
    Appointment newAppointment;

    printf("Enter name: ");
    getchar(); // to clear the buffer
    fgets(newAppointment.name, MAX_STRING_LENGTH, stdin);
    newAppointment.name[strcspn(newAppointment.name, "\n")] = 0; // Remove newline
    
    printf("Enter date (YYYY-MM-DD): ");
    fgets(newAppointment.date, MAX_STRING_LENGTH, stdin);
    newAppointment.date[strcspn(newAppointment.date, "\n")] = 0; // Remove newline
    
    printf("Enter time (HH:MM): ");
    fgets(newAppointment.time, MAX_STRING_LENGTH, stdin);
    newAppointment.time[strcspn(newAppointment.time, "\n")] = 0; // Remove newline
    
    printf("Enter description: ");
    fgets(newAppointment.description, MAX_STRING_LENGTH, stdin);
    newAppointment.description[strcspn(newAppointment.description, "\n")] = 0; // Remove newline

    appointments[appointmentCount++] = newAppointment;
    printf("Appointment added successfully.\n");
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("%d. %s on %s at %s - %s\n", i + 1,
               appointments[i].name, appointments[i].date,
               appointments[i].time, appointments[i].description);
    }
}

void deleteAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int appointmentIndex;
    printf("Enter appointment number to delete: ");
    scanf("%d", &appointmentIndex);
    
    if (appointmentIndex < 1 || appointmentIndex > appointmentCount) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = appointmentIndex - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointmentCount--;
    printf("Appointment deleted successfully.\n");
}

void searchAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to search.\n");
        return;
    }

    char searchName[MAX_STRING_LENGTH];
    printf("Enter name to search for: ");
    getchar(); // to clear the buffer
    fgets(searchName, MAX_STRING_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline
    
    int found = 0;
    printf("\nSearch Results:\n");
    for (int i = 0; i < appointmentCount; i++) {
        if (strstr(appointments[i].name, searchName) != NULL) {
            printf("%d. %s on %s at %s - %s\n", i + 1,
                   appointments[i].name, appointments[i].date,
                   appointments[i].time, appointments[i].description);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No appointments found for the name: %s\n", searchName);
    }
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                searchAppointment();
                break;
            case 5:
                printf("Exiting... Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}