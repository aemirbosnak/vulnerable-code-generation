//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define DESCRIPTION_LENGTH 100

// Structure to represent an appointment
typedef struct {
    int id;
    char description[DESCRIPTION_LENGTH];
    struct tm time;
} Appointment;

// Function declarations
void addAppointment(Appointment appointments[], int *count);
void viewAppointments(Appointment appointments[], int count);
void deleteAppointment(Appointment appointments[], int *count);
void displayMenu();

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(appointments, &count);
                break;
            case 2:
                viewAppointments(appointments, count);
                break;
            case 3:
                deleteAppointment(appointments, &count);
                break;
            case 4:
                printf("Exiting the Appointment Scheduler. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

void addAppointment(Appointment appointments[], int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached.\n");
        return;
    }

    Appointment newAppointment;
    newAppointment.id = *count + 1;

    printf("Enter appointment description: ");
    getchar(); // To consume the newline character left by the previous scanf
    fgets(newAppointment.description, DESCRIPTION_LENGTH, stdin);
    newAppointment.description[strcspn(newAppointment.description, "\n")] = 0; // Strip newline

    printf("Enter appointment date and time (YYYY MM DD HH mm): ");
    scanf("%d %d %d %d %d", &newAppointment.time.tm_year, 
          &newAppointment.time.tm_mon, 
          &newAppointment.time.tm_mday, 
          &newAppointment.time.tm_hour, 
          &newAppointment.time.tm_min);
    
    newAppointment.time.tm_year -= 1900; // Adjusting year
    newAppointment.time.tm_mon -= 1; // tm_mon is zero-based

    appointments[*count] = newAppointment;
    (*count)++;
    
    printf("Appointment added successfully!\n");
}

void viewAppointments(Appointment appointments[], int count) {
    if (count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\n--- List of Appointments ---\n");
    for (int i = 0; i < count; i++) {
        printf("Appointment ID: %d\n", appointments[i].id);
        printf("Description: %s\n", appointments[i].description);
        printf("Date: %d-%02d-%02d Time: %02d:%02d\n", 
                appointments[i].time.tm_year + 1900, 
                appointments[i].time.tm_mon + 1, 
                appointments[i].time.tm_mday, 
                appointments[i].time.tm_hour, 
                appointments[i].time.tm_min);
        printf("------------------------------\n");
    }
}

void deleteAppointment(Appointment appointments[], int *count) {
    if (*count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int idToDelete;
    printf("Enter the appointment ID to delete: ");
    scanf("%d", &idToDelete);

    for (int i = 0; i < *count; i++) {
        if (appointments[i].id == idToDelete) {
            for (int j = i; j < *count - 1; j++) {
                appointments[j] = appointments[j + 1]; // Shift appointments down
            }
            (*count)--;
            printf("Appointment with ID %d deleted successfully!\n", idToDelete);
            return;
        }
    }
    printf("Appointment with ID %d not found.\n", idToDelete);
}