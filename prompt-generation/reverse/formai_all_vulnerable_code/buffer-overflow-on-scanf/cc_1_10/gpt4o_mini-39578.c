//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_TITLE_LENGTH 100
#define MAX_DESC_LENGTH 256
#define FILENAME "appointments.txt"

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESC_LENGTH];
    char date[11]; // YYYY-MM-DD
    char time[6];  // HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int totalAppointments = 0;

// Function prototypes
void loadAppointments();
void saveAppointments();
void addAppointment();
void viewAppointments();
void deleteAppointment();
void displayMenu();

int main() {
    loadAppointments();
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character

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
                printf("Exiting the appointment scheduler.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    saveAppointments();
    return 0;
}

void loadAppointments() {
    FILE *file = fopen(FILENAME, "r");
    if (file != NULL) {
        while (fscanf(file, "%s %s %s %s\n", 
                      appointments[totalAppointments].title, 
                      appointments[totalAppointments].description, 
                      appointments[totalAppointments].date, 
                      appointments[totalAppointments].time) != EOF) {
            totalAppointments++;
        }
        fclose(file);
    }
}

void saveAppointments() {
    FILE *file = fopen(FILENAME, "w");
    if (file != NULL) {
        for (int i = 0; i < totalAppointments; i++) {
            fprintf(file, "%s %s %s %s\n", 
                    appointments[i].title, 
                    appointments[i].description, 
                    appointments[i].date, 
                    appointments[i].time);
        }
        fclose(file);
    }
}

void addAppointment() {
    if (totalAppointments >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments. Maximum limit reached.\n");
        return;
    }

    printf("Enter appointment title: ");
    fgets(appointments[totalAppointments].title, MAX_TITLE_LENGTH, stdin);
    appointments[totalAppointments].title[strcspn(appointments[totalAppointments].title, "\n")] = 0; // Remove newline

    printf("Enter appointment description: ");
    fgets(appointments[totalAppointments].description, MAX_DESC_LENGTH, stdin);
    appointments[totalAppointments].description[strcspn(appointments[totalAppointments].description, "\n")] = 0; // Remove newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(appointments[totalAppointments].date, 11, stdin);
    appointments[totalAppointments].date[strcspn(appointments[totalAppointments].date, "\n")] = 0; // Remove newline

    printf("Enter appointment time (HH:MM): ");
    fgets(appointments[totalAppointments].time, 6, stdin);
    appointments[totalAppointments].time[strcspn(appointments[totalAppointments].time, "\n")] = 0; // Remove newline

    totalAppointments++;
    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (totalAppointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Scheduled Appointments:\n");
    for (int i = 0; i < totalAppointments; i++) {
        printf("%d. %s - %s on %s at %s\n", 
               i + 1, 
               appointments[i].title, 
               appointments[i].description, 
               appointments[i].date, 
               appointments[i].time);
    }
}

void deleteAppointment() {
    if (totalAppointments == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    viewAppointments();
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    getchar();  // Consume newline

    if (index < 1 || index > totalAppointments) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = index - 1; i < totalAppointments - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    totalAppointments--;
    printf("Appointment deleted successfully!\n");
}

void displayMenu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}