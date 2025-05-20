//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Appointment {
    int day;
    int month;
    int year;
    char name[256];
    char email[256];
};

struct Node {
    struct Appointment data;
    struct Node* next;
};

struct Node* head = NULL;

void addAppointment() {
    struct Appointment appointment;
    printf("Please enter the appointment details:\n");
    printf("Name: ");
    scanf(" %[^\n]s", appointment.name);
    printf("Email: ");
    scanf(" %[^\n]s", appointment.email);
    printf("Year: ");
    scanf("%d", &appointment.year);
    printf("Month: ");
    scanf("%d", &appointment.month);
    printf("Day: ");
    scanf("%d", &appointment.day);

    struct Node* newAppointment = (struct Node*)malloc(sizeof(struct Node));
    newAppointment->data = appointment;
    newAppointment->next = NULL;

    if (head == NULL) {
        head = newAppointment;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newAppointment;
    }

    printf("Appointment added successfully.\n");
}

void displayAppointments() {
    if (head == NULL) {
        printf("No appointments found.\n");
    } else {
        struct Node* current = head;
        int appointmentCount = 0;
        printf("Appointments:\n");
        while (current != NULL) {
            appointmentCount++;
            printf("%d. Name: %s, Email: %s, Date: %d/%d/%d\n", 
                   appointmentCount,
                   current->data.name,
                   current->data.email,
                   current->data.day,
                   current->data.month,
                   current->data.year);
            current = current->next;
        }
    }
}

void removeAppointment() {
    if (head == NULL) {
        printf("No appointments found.\n");
    } else {
        int appointmentNumber;
        printf("Please enter the number of the appointment you want to remove: ");
        scanf("%d", &appointmentNumber);
        if (appointmentNumber < 1) {
            printf("Invalid appointment number.\n");
        } else {
            struct Node* current = head;
            struct Node* previous = NULL;
            int count = 1;
            while (count < appointmentNumber && current != NULL) {
                previous = current;
                current = current->next;
                count++;
            }
            if (current == NULL) {
                printf("Invalid appointment number.\n");
            } else {
                if (previous == NULL) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                free(current);
                printf("Appointment removed successfully.\n");
            }
        }
    }
}

void checkAppointmentsToday() {
    struct tm* today = localtime(&(time_t){ time(NULL) });
    int currentDay = today->tm_mday, currentMonth = today->tm_mon + 1, currentYear = today->tm_year + 1900;

    if (head == NULL) {
        printf("No appointments found.\n");
    } else {
        struct Node* current = head;
        int appointmentCount = 0;
        printf("Appointments Today:\n");
        while (current != NULL) {
            if (current->data.day == currentDay && current->data.month == currentMonth && current->data.year == currentYear) {
                appointmentCount++;
                printf("%d. Name: %s, Email: %s, Date: %d/%d/%d\n", 
                       appointmentCount,
                       current->data.name,
                       current->data.email,
                       current->data.day,
                       current->data.month,
                       current->data.year);
            }
            current = current->next;
        }
        if (appointmentCount == 0) {
            printf("No appointments found.\n");
        }
    }
}

void showMenu() {
    printf("\nMenu:\n");
    printf("1. Add Appointment\n");
    printf("2. Display Appointments\n");
    printf("3. Remove Appointment\n");
    printf("4. Check Appointments Today\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
}

int main() {
    int choice;
    printf("Welcome to the Appointment Scheduler!\n");
    do {
        showMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                displayAppointments();
                break;
            case 3:
                removeAppointment();
                break;
            case 4:
                checkAppointmentsToday();
                break;
            case 5:
                printf("Thank you for using the Appointment Scheduler! Goodbye.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}