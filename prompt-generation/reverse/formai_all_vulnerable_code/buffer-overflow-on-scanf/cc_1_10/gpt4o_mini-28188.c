//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 11

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[6]; // HH:MM format
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void clearScreen() {
    printf("\033[H\033[J");
}

void printMenu() {
    printf("===================================\n");
    printf("          Appointment Scheduler     \n");
    printf("===================================\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Remove Appointment\n");
    printf("4. Exit\n");
    printf("Please choose an option: ");
}

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Oops! The schedule is full. Can't add more appointments.\n");
        return;
    }

    Appointment newAppointment;
    printf("Enter the name of the person: ");
    scanf(" %[^\n]s", newAppointment.name);
    printf("Enter the appointment date (YYYY-MM-DD): ");
    scanf(" %[^\n]s", newAppointment.date);
    printf("Enter the appointment time (HH:MM): ");
    scanf(" %[^\n]s", newAppointment.time);

    appointments[appointmentCount] = newAppointment;
    appointmentCount++;

    printf("Yay! Appointment added successfully!\n");
}

void viewAppointments() {
    printf("You have %d appointment(s):\n", appointmentCount);
    if (appointmentCount == 0) {
        printf("No appointments scheduled. Add some joy to your calendar!\n");
        return;
    }

    for (int i = 0; i < appointmentCount; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("----------------------------\n");
    }
}

void removeAppointment() {
    if (appointmentCount == 0) {
        printf("There are no appointments to remove. Let's add some happiness first!\n");
        return;
    }

    int index;
    printf("Enter the appointment number to remove (1 - %d): ", appointmentCount);
    scanf("%d", &index);

    if (index < 1 || index > appointmentCount) {
        printf("Oops! That's not a valid appointment number.\n");
        return;
    }

    for (int i = index - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointmentCount--;

    printf("Hooray! Appointment removed successfully!\n");
}

int main() {
    int choice;

    while (1) {
        clearScreen();
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                removeAppointment();
                break;
            case 4:
                printf("Thank you for using the Appointment Scheduler! Have a great day!\n");
                exit(0);
            default:
                printf("Oops! That's not a valid choice. Please try again!\n");
        }

        printf("Press Enter to continue...");
        getchar();  // Clear the newline character left by scanf
        getchar(); // Wait for user to press Enter
    }

    return 0;
}