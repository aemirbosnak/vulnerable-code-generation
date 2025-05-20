//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
} Appointment;

void createAppointment(Appointment** head) {
    *head = malloc(sizeof(Appointment));
    (*head)->next = NULL;
    printf("Enter your name: ");
    scanf("%s", (*head)->name);
    printf("Enter the date: ");
    scanf("%s", (*head)->date);
    printf("Enter the time: ");
    scanf("%s", (*head)->time);
}

void displayAppointments(Appointment* head) {
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

    // Create a menu loop
    while (1) {
        printf("Options:\n");
        printf("1. Create Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Exit\n");

        int choice = 0;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAppointment(&head);
                break;
            case 2:
                displayAppointments(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}