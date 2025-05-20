//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct patient_info {
    char name[50];
    char email[50];
    char phone[20];
    int age;
} Patient;

typedef struct appointment {
    Patient patient;
    char date[15];
    char time[10];
    bool reserved;
    struct appointment *next;
} Appointment;

Appointment *head = NULL;

void display_menu() {
    printf("Welcome to Dr. Watson's Appointment Scheduler\n");
    printf("Please choose an option:\n");
    printf("\t1. View Appointments\n");
    printf("\t2. Schedule Appointment\n");
    printf("\t3. Remove Appointment\n");
    printf("\t4. Exit\n");
}

void display_appointments() {
    if (head == NULL) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Scheduled Appointments:\n");
    Appointment *temp = head;
    while (temp != NULL) {
        printf("%s   %s   %s   %s   %d   %s\n",
               temp->date, temp->time,
               temp->patient.name, temp->patient.email,
               temp->patient.age, temp->patient.phone);
        temp = temp->next;
    }
}

void add_appointment() {
    Appointment *new_appointment = malloc(sizeof(Appointment));
    new_appointment->reserved = true;
    new_appointment->next = NULL;

    printf("Enter the date of the appointment (MM/DD/YYYY): ");
    scanf("%s", new_appointment->date);

    printf("Enter the time of the appointment (HH:MM AM/PM): ");
    scanf("%s", new_appointment->time);

    printf("Enter the patient's name: ");
    scanf("%s", new_appointment->patient.name);

    printf("Enter the patient's age: ");
    scanf("%d", &new_appointment->patient.age);

    printf("Enter the patient's email: ");
    scanf("%s", new_appointment->patient.email);

    printf("Enter the patient's phone number: ");
    scanf("%s", new_appointment->patient.phone);

    if (head == NULL) {
        head = new_appointment;
    } else {
        Appointment *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_appointment;
    }
    printf("Appointment added successfully.\n");
}

void remove_appointment() {
    if (head == NULL) {
        printf("No appointments scheduled.\n");
        return;
    }

    char date[15];
    char time[10];
    printf("Enter the date of the appointment to remove (MM/DD/YYYY): ");
    scanf("%s", date);

    printf("Enter the time of the appointment to remove (HH:MM AM/PM): ");
    scanf("%s", time);

    Appointment *temp = head;
    Appointment *prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->date, date) == 0 &&
            strcmp(temp->time, time) == 0) {
            if (prev == NULL) {
                head = head->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Appointment removed successfully.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Appointment not found.\n");
}

int main() {
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_appointments();
                break;
            case 2:
                add_appointment();
                break;
            case 3:
                remove_appointment();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}