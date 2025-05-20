//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    struct Appointment* next;
} Appointment;

Appointment* insertAppointment(Appointment* head) {
    Appointment* newApp = (Appointment*)malloc(sizeof(Appointment));
    printf("Enter your name: ");
    scanf("%s", newApp->name);
    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%s", newApp->date);
    printf("Enter the time (hh:mm): ");
    scanf("%s", newApp->time);
    newApp->next = NULL;

    if (head == NULL) {
        head = newApp;
    } else {
        head->next = newApp;
    }

    return head;
}

void displayAppointments(Appointment* head) {
    printf("Appointments:\n");
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Date: %s\n", head->date);
        printf("Time: %s\n", head->time);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Appointment* head = NULL;

    while (1) {
        int choice;
        printf("1. Insert Appointment\n");
        printf("2. Display Appointments\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertAppointment(head);
                break;
            case 2:
                displayAppointments(head);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Press any key to continue...");
        getchar();
    }

    return 0;
}