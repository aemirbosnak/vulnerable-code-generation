//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Appointment {
    int id;
    char name[50];
    char date[20];
    char time[10];
    struct Appointment* next;
} Appointment;

Appointment* head = NULL;
int appointmentCount = 0;

void addAppointment() {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    newAppointment->id = ++appointmentCount;

    printf("Enter name for the appointment: ");
    scanf(" %[^\n]s", newAppointment->name);

    printf("Enter date for the appointment (YYYY-MM-DD): ");
    scanf(" %[^\n]s", newAppointment->date);

    printf("Enter time for the appointment (HH:MM): ");
    scanf(" %[^\n]s", newAppointment->time);

    newAppointment->next = head;
    head = newAppointment;

    printf("Appointment added successfully with ID %d.\n", newAppointment->id);
}

void viewAppointments() {
    if (head == NULL) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    printf("ID\tName\t\tDate\t\tTime\n");
    printf("-------------------------------------------\n");

    Appointment* temp = head;
    while (temp != NULL) {
        printf("%d\t%s\t%s\t%s\n", temp->id, temp->name, temp->date, temp->time);
        temp = temp->next;
    }
}

void cancelAppointment() {
    if (head == NULL) {
        printf("No appointments to cancel.\n");
        return;
    }

    int id;
    printf("Enter appointment ID to cancel: ");
    scanf("%d", &id);

    Appointment* temp = head;
    Appointment* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Appointment with ID %d not found.\n", id);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Appointment with ID %d has been canceled.\n", id);
}

void displayMenu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Cancel Appointment\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an action: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                cancelAppointment();
                break;
            case 4:
                printf("Exiting the Appointment Scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}