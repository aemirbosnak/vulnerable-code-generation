//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DESC_LEN 100

typedef struct Appointment {
    char description[MAX_DESC_LEN];
    struct tm dateTime;
    struct Appointment* next;
} Appointment;

Appointment* head = NULL;

void addAppointment() {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    if (!newAppointment) {
        printf("Memory allocation failed! Unable to add appointment.\n");
        return;
    }
    
    printf("Enter appointment description: ");
    getchar(); // consume newline
    fgets(newAppointment->description, MAX_DESC_LEN, stdin);
    newAppointment->description[strcspn(newAppointment->description, "\n")] = 0; // remove newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    int year, month, day;
    scanf("%d-%d-%d", &year, &month, &day);
    newAppointment->dateTime.tm_year = year - 1900;
    newAppointment->dateTime.tm_mon = month - 1;
    newAppointment->dateTime.tm_mday = day;
    newAppointment->dateTime.tm_hour = 0; // default hour
    newAppointment->dateTime.tm_min = 0;  // default minute
    newAppointment->dateTime.tm_sec = 0;  // default seconds
    newAppointment->dateTime.tm_isdst = -1; // Not accounting for DST
    newAppointment->next = head;
    head = newAppointment;

    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (head == NULL) {
        printf("No appointments scheduled.\n");
        return;
    }

    Appointment* current = head;
    printf("\nScheduled Appointments:\n");
    while (current != NULL) {
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", &current->dateTime);
        printf("Description: %s | Date: %s\n", current->description, buffer);
        current = current->next;
    }
}

void deleteAppointment() {
    if (head == NULL) {
        printf("No appointments to delete.\n");
        return;
    }

    viewAppointments();

    printf("Enter the description of the appointment to delete: ");
    getchar(); // consume newline
    char descToDelete[MAX_DESC_LEN];
    fgets(descToDelete, MAX_DESC_LEN, stdin);
    descToDelete[strcspn(descToDelete, "\n")] = 0; // remove newline

    Appointment *current = head, *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->description, descToDelete) == 0) {
            if (previous == NULL) {
                head = current->next; // deleting head
            } else {
                previous->next = current->next; // bypassing current
            }
            free(current);
            printf("Appointment deleted successfully!\n");
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Appointment not found!\n");
}

void menu() {
    int choice;
    while (1) {
        printf("\n--- Appointment Scheduler ---\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
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
                printf("Exiting the scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Appointment Scheduler!\n");
    menu();
    return 0;
}