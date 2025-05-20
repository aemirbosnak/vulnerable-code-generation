//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the appointment structure
typedef struct Appointment {
    char date[11];
    char startTime[6];
    char endTime[6];
    char description[50];
    struct Appointment *next;
} Appointment;

// Prototype declarations
void addAppointment(Appointment **head);
void printAppointments(Appointment *head);
void deleteAppointment(Appointment **head, char *date);
void searchAppointment(Appointment *head, char *date);
void updateAppointment(Appointment **head, char *date);

// Main function
int main() {
    Appointment *head = NULL;
    int choice;
    char date[11];

    do {
        printf("Appointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. Delete Appointment\n");
        printf("3. Search Appointment\n");
        printf("4. Update Appointment\n");
        printf("5. Print Appointments\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(&head);
                break;
            case 2:
                printf("Enter date of appointment to delete: ");
                scanf("%s", date);
                deleteAppointment(&head, date);
                break;
            case 3:
                printf("Enter date of appointment to search: ");
                scanf("%s", date);
                searchAppointment(head, date);
                break;
            case 4:
                printf("Enter date of appointment to update: ");
                scanf("%s", date);
                updateAppointment(&head, date);
                break;
            case 5:
                printAppointments(head);
                break;
            case 6:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid choice.");
        }
    } while (choice != 6);

    return 0;
}

// Function to add an appointment
void addAppointment(Appointment **head) {
    Appointment *newAppointment = (Appointment*)malloc(sizeof(Appointment));

    printf("Enter date of appointment (MM/DD/YYYY): ");
    scanf("%s", newAppointment->date);
    printf("Enter start time of appointment (HH:MM): ");
    scanf("%s", newAppointment->startTime);
    printf("Enter end time of appointment (HH:MM): ");
    scanf("%s", newAppointment->endTime);
    printf("Enter appointment description (Max 50 characters): ");
    scanf("%s", newAppointment->description);

    if (*head == NULL || strcmp(newAppointment->date, (*head)->date) < 0) {
        newAppointment->next = *head;
        *head = newAppointment;
    } else {
        Appointment *current = *head;
        while (current->next != NULL && strcmp(newAppointment->date, current->next->date) > 0)
            current = current->next;
        newAppointment->next = current->next;
        current->next = newAppointment;
    }

    printf("Appointment added successfully!\n");
}

// Function to print all appointments
void printAppointments(Appointment *head) {
    if (head == NULL)
        printf("No appointments to print.\n");
    else {
        printf("Date\tStart Time\tEnd Time\tDescription\n");
        printf("------------------------------------------------\n");
        while (head != NULL) {
            printf("%s\t%s\t\t%s\t\t%s\n", head->date, head->startTime, head->endTime, head->description);
            head = head->next;
        }
    }
}

// Function to delete an appointment
void deleteAppointment(Appointment **head, char *date) {
    if (*head == NULL)
        printf("No appointments to delete.\n");
    else {
        Appointment *temp = *head;
        if (strcmp(temp->date, date) == 0) {
            *head = (*head)->next;
            free(temp);
            printf("Appointment deleted successfully!\n");
            return;
        }
        while (temp->next != NULL) {
            if (strcmp(temp->next->date, date) == 0) {
                Appointment *deleteTemp = temp->next;
                temp->next = temp->next->next;
                free(deleteTemp);
                printf("Appointment deleted successfully!\n");
                return;
            }
            temp = temp->next;
        }
        printf("Appointment not found.\n");
    }
}

// Function to search for an appointment
void searchAppointment(Appointment *head, char *date) {
    if (head == NULL)
        printf("No appointments found.\n");
    else {
        while (head != NULL) {
            if (strcmp(head->date, date) == 0) {
                printf("Appointment found:\n");
                printf("Date\tStart Time\tEnd Time\tDescription\n");
                printf("------------------------------------------------\n");
                printf("%s\t%s\t\t%s\t%s\n", head->date, head->startTime, head->endTime, head->description);
                return;
            }
            head = head->next;
        }
        printf("Appointment not found.\n");
    }
}

// Function to update an appointment
void updateAppointment(Appointment **head, char *date) {
    if (*head == NULL)
        printf("No appointments to update.\n");
    else {
        Appointment *temp = *head;
        while (temp != NULL) {
            if (strcmp(temp->date, date) == 0) {
                printf("Enter new date of appointment (MM/DD/YYYY): ");
                scanf("%s", temp->date);
                printf("Enter new start time of appointment (HH:MM): ");
                scanf("%s", temp->startTime);
                printf("Enter new end time of appointment (HH:MM): ");
                scanf("%s", temp->endTime);
                printf("Enter new appointment description (Max 50 characters): ");
                scanf("%s", temp->description);
                printf("Appointment updated successfully!\n");
                return;
            }
            temp = temp->next;
        }
        printf("Appointment not found.\n");
    }
}