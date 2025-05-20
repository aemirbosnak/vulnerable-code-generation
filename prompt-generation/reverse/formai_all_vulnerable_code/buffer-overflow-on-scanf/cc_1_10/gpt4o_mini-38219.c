//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define TITLE_LENGTH 50
#define DATE_LENGTH 20
#define DESC_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char date[DATE_LENGTH];
    char description[DESC_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment();
void viewAppointments();
void deleteAppointment();
void editAppointment();
void displayMenu();
void clearInputBuffer();

int main() {
    int choice = 0;

    while (choice != 5) {
        displayMenu();
        scanf("%d", &choice);
        clearInputBuffer();

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
                editAppointment();
                break;
            case 5:
                printf("Exiting the Appointment Scheduler. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Edit Appointment\n");
    printf("5. Exit\n");
    printf("Please enter your choice: ");
}

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached! Cannot add more appointments.\n");
        return;
    }

    printf("Enter appointment title: ");
    fgets(appointments[appointmentCount].title, TITLE_LENGTH, stdin);
    appointments[appointmentCount].title[strcspn(appointments[appointmentCount].title, "\n")] = 0; // Remove newline

    printf("Enter appointment date (DD/MM/YYYY): ");
    fgets(appointments[appointmentCount].date, DATE_LENGTH, stdin);
    appointments[appointmentCount].date[strcspn(appointments[appointmentCount].date, "\n")] = 0; // Remove newline

    printf("Enter appointment description: ");
    fgets(appointments[appointmentCount].description, DESC_LENGTH, stdin);
    appointments[appointmentCount].description[strcspn(appointments[appointmentCount].description, "\n")] = 0; // Remove newline

    appointmentCount++;
    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments available.\n");
        return;
    }

    printf("\n--- Appointments ---\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Title: %s\n", appointments[i].title);
        printf("Date: %s\n", appointments[i].date);
        printf("Description: %s\n", appointments[i].description);
        printf("-------------------\n");
    }
}

void deleteAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    printf("Enter appointment number to delete (1-%d): ", appointmentCount);
    scanf("%d", &index);
    clearInputBuffer();

    if (index < 1 || index > appointmentCount) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = index - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointmentCount--;
    printf("Appointment deleted successfully!\n");
}

void editAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to edit.\n");
        return;
    }

    int index;
    printf("Enter appointment number to edit (1-%d): ", appointmentCount);
    scanf("%d", &index);
    clearInputBuffer();

    if (index < 1 || index > appointmentCount) {
        printf("Invalid appointment number!\n");
        return;
    }

    printf("Editing Appointment %d:\n", index);
    printf("Enter new title (or press Enter to keep current \"%s\"): ", appointments[index - 1].title);
    char newTitle[TITLE_LENGTH];
    fgets(newTitle, TITLE_LENGTH, stdin);
    if (strlen(newTitle) > 1) { // Check if we have a new title
        newTitle[strcspn(newTitle, "\n")] = 0; // Remove newline
        strcpy(appointments[index - 1].title, newTitle);
    }

    printf("Enter new date (or press Enter to keep current \"%s\"): ", appointments[index - 1].date);
    char newDate[DATE_LENGTH];
    fgets(newDate, DATE_LENGTH, stdin);
    if (strlen(newDate) > 1) { // Check if we have a new date
        newDate[strcspn(newDate, "\n")] = 0; // Remove newline
        strcpy(appointments[index - 1].date, newDate);
    }

    printf("Enter new description (or press Enter to keep current \"%s\"): ", appointments[index - 1].description);
    char newDesc[DESC_LENGTH];
    fgets(newDesc, DESC_LENGTH, stdin);
    if (strlen(newDesc) > 1) { // Check if we have a new description
        newDesc[strcspn(newDesc, "\n")] = 0; // Remove newline
        strcpy(appointments[index - 1].description, newDesc);
    }

    printf("Appointment edited successfully!\n");
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}