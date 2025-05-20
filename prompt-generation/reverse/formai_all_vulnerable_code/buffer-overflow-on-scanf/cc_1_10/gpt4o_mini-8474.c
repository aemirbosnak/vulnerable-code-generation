//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define DESCRIPTION_LENGTH 256

typedef struct {
    char description[DESCRIPTION_LENGTH];
    int day;
    int month;
    int year;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment();
void viewAppointments();
void clearBuffer();
void showMenu();
void handleMenuChoice(int choice);

int main() {
    int choice;

    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear the input buffer before reading strings
        handleMenuChoice(choice);
    } while (choice != 3);

    return 0;
}

void showMenu() {
    printf("\nAppointment Scheduler Menu:\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Exit\n");
}

void handleMenuChoice(int choice) {
    switch (choice) {
        case 1:
            addAppointment();
            break;
        case 2:
            viewAppointments();
            break;
        case 3:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
    }
}

void clearBuffer() {
    while (getchar() != '\n');
}

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment list is full! Cannot add more appointments.\n");
        return;
    }

    Appointment newAppointment;

    printf("Enter appointment description: ");
    fgets(newAppointment.description, DESCRIPTION_LENGTH, stdin);
    newAppointment.description[strcspn(newAppointment.description, "\n")] = '\0'; // Remove newline

    printf("Enter day, month, year (DD MM YYYY): ");
    scanf("%d %d %d", &newAppointment.day, &newAppointment.month, &newAppointment.year);
    clearBuffer(); // Clear buffer for next input

    appointments[appointmentCount] = newAppointment;
    appointmentCount++;

    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("%d. %s on %02d/%02d/%04d\n", i + 1, appointments[i].description, 
               appointments[i].day, appointments[i].month, appointments[i].year);
    }

    // Recursively ask if the user wants to view appointments again
    char choice;
    printf("\nDo you want to view appointments again? (y/n): ");
    choice = getchar();
    clearBuffer(); // Clear buffer before returning

    if (choice == 'y' || choice == 'Y') {
        viewAppointments(); // Recursive call
    } else {
        printf("Returning to main menu...\n");
    }
}