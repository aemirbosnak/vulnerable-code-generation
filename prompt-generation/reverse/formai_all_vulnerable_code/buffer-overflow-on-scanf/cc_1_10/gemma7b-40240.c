//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    struct Appointment* next;
} Appointment;

void addAppointment(Appointment** head) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    printf("Enter your name: ");
    scanf("%s", newAppointment->name);
    printf("Enter the date of your appointment: ");
    scanf("%s", newAppointment->date);
    printf("Enter the time of your appointment: ");
    scanf("%s", newAppointment->time);

    newAppointment->next = NULL;

    if (*head == NULL) {
        *head = newAppointment;
    } else {
        (*head)->next = newAppointment;
    }
}

void viewAppointments(Appointment* head) {
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
        printf("Enter 'add' to add an appointment, 'view' to view appointments, or 'exit' to exit: ");
        char input[20];
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            addAppointment(&head);
        } else if (strcmp(input, "view") == 0) {
            viewAppointments(head);
        } else if (strcmp(input, "exit") == 0) {
            exit(0);
        } else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}