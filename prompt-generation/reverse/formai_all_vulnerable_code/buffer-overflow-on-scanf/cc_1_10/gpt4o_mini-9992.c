//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DESC_LEN 100
#define MAX_DATE_LEN 11

typedef struct Appointment {
    char description[MAX_DESC_LEN];
    char date[MAX_DATE_LEN]; // Format: YYYY-MM-DD
    struct Appointment *next;
} Appointment;

Appointment *head = NULL;

void addAppointment() {
    Appointment *newAppointment = (Appointment *)malloc(sizeof(Appointment));
    if (!newAppointment) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter appointment description: ");
    getchar(); // consume newline character
    fgets(newAppointment->description, MAX_DESC_LEN, stdin);
    newAppointment->description[strcspn(newAppointment->description, "\n")] = 0; // remove trailing newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%s", newAppointment->date);

    newAppointment->next = head;
    head = newAppointment;

    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (!head) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    Appointment *current = head;
    while (current != NULL) {
        printf("Description: %s, Date: %s\n", current->description, current->date);
        current = current->next;
    }
}

void deleteAppointments() {
    Appointment *current = head;
    Appointment *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    printf("All appointments deleted.\n");
}

void displayMenu() {
    printf("\n=== Appointment Scheduler ===\n");
    printf("1. Add an Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete All Appointments\n");
    printf("4. Exit\n");
    printf("============================\n");
    printf("Choose an option: ");
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
                deleteAppointments();
                break;
            case 4:
                printf("Exiting the Appointment Scheduler. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    deleteAppointments(); // Clean up before exit
    return 0;
}