//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the appointment information
struct Appointment {
    char date[20];
    char time[10];
    char name[50];
    char reason[100];
};

// Function to display the menu options
void displayMenu() {
    printf("\nAppointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. Edit Appointment\n");
    printf("3. Delete Appointment\n");
    printf("4. View Appointments\n");
    printf("5. Exit\n");
}

// Function to add a new appointment
void addAppointment(struct Appointment appointments[], int* count) {
    printf("\nAdd Appointment\n");
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", appointments[*count].date);
    printf("Enter time (hh:mm): ");
    scanf("%s", appointments[*count].time);
    printf("Enter name: ");
    scanf("%s", appointments[*count].name);
    printf("Enter reason: ");
    scanf("%s", appointments[*count].reason);
    (*count)++;
}

// Function to edit an existing appointment
void editAppointment(struct Appointment appointments[], int count) {
    printf("\nEdit Appointment\n");
    printf("Enter date to edit (dd/mm/yyyy): ");
    char date[20];
    scanf("%s", date);

    for (int i = 0; i < count; i++) {
        if (strcmp(appointments[i].date, date) == 0) {
            printf("Enter new time (hh:mm): ");
            scanf("%s", appointments[i].time);
            printf("Enter new name: ");
            scanf("%s", appointments[i].name);
            printf("Enter new reason: ");
            scanf("%s", appointments[i].reason);
            printf("Appointment updated successfully!\n");
            return;
        }
    }

    printf("No appointment found on %s\n", date);
}

// Function to delete an existing appointment
void deleteAppointment(struct Appointment appointments[], int* count) {
    printf("\nDelete Appointment\n");
    printf("Enter date to delete (dd/mm/yyyy): ");
    char date[20];
    scanf("%s", date);

    for (int i = 0; i < *count; i++) {
        if (strcmp(appointments[i].date, date) == 0) {
            for (int j = i; j < *count-1; j++) {
                memcpy(&appointments[j], &appointments[j+1], sizeof(struct Appointment));
            }
            (*count)--;
            printf("Appointment deleted successfully!\n");
            return;
        }
    }

    printf("No appointment found on %s\n", date);
}

// Function to view all appointments
void viewAppointments(struct Appointment appointments[], int count) {
    printf("\nList of Appointments:\n");
    printf("Date\t Time\t Name\t Reason\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t %s\t %s\t %s\n", appointments[i].date, appointments[i].time, appointments[i].name, appointments[i].reason);
    }
}

// Main function
int main() {
    struct Appointment appointments[100];
    int count = 0;

    int choice = 0;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(appointments, &count);
                break;
            case 2:
                editAppointment(appointments, count);
                break;
            case 3:
                deleteAppointment(appointments, &count);
                break;
            case 4:
                viewAppointments(appointments, count);
                break;
            case 5:
                printf("Thank you for using our Appointment Scheduler!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}