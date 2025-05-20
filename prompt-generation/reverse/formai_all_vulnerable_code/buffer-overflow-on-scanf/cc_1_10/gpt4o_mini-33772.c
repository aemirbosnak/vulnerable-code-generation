//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_TITLE_LENGTH 50
#define MAX_DATE_LENGTH 20
#define FILENAME "appointments.txt"

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char date[MAX_DATE_LENGTH];
} Appointment;

void addAppointment();
void viewAppointments();
void deleteAppointment();
void clearScreen();
void pause();

int main() {
    int choice;

    do {
        clearScreen();
        printf("=== Appointment Scheduler ===\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("=============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

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
                printf("Exiting the scheduler. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                pause();
        }
    } while (choice != 4);

    return 0;
}

void addAppointment() {
    FILE *file;
    Appointment appt;

    printf("Enter appointment title: ");
    fgets(appt.title, MAX_TITLE_LENGTH, stdin);
    strtok(appt.title, "\n"); // Remove trailing newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(appt.date, MAX_DATE_LENGTH, stdin);
    strtok(appt.date, "\n"); // Remove trailing newline

    file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        pause();
        return;
    }

    fprintf(file, "%s,%s\n", appt.title, appt.date);
    fclose(file);

    printf("Appointment added successfully!\n");
    pause();
}

void viewAppointments() {
    FILE *file;
    Appointment appt;
    int count = 0;

    file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No appointments found!\n");
        pause();
        return;
    }

    printf("\n=== List of Appointments ===\n");
    while (fscanf(file, "%49[^,],%19[^\n]\n", appt.title, appt.date) != EOF) {
        printf("Appointment #%d: %s on %s\n", ++count, appt.title, appt.date);
    }
    fclose(file);

    if (count == 0) {
        printf("No appointments to display.\n");
    } else {
        printf("=============================\n");
    }
    pause();
}

void deleteAppointment() {
    FILE *file, *tempFile;
    Appointment appt;
    char titleToDelete[MAX_TITLE_LENGTH];
    int found = 0;

    printf("Enter the title of the appointment to delete: ");
    fgets(titleToDelete, MAX_TITLE_LENGTH, stdin);
    strtok(titleToDelete, "\n"); // Remove trailing newline

    file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No appointments found!\n");
        pause();
        return;
    }

    tempFile = fopen("temp.txt", "w");
    while (fscanf(file, "%49[^,],%19[^\n]\n", appt.title, appt.date) != EOF) {
        if (strcmp(appt.title, titleToDelete) != 0) {
            fprintf(tempFile, "%s,%s\n", appt.title, appt.date);
        } else {
            found = 1;
        }
    }
    fclose(file);
    fclose(tempFile);
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found) {
        printf("Appointment '%s' deleted successfully!\n", titleToDelete);
    } else {
        printf("No appointment found with the title '%s'.\n", titleToDelete);
    }
    pause();
}

void clearScreen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void pause() {
    printf("\nPress Enter to continue...");
    getchar();
}