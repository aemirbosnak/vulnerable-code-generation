//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 20

typedef struct Appointment {
    char name[50];
    char date[10];
    char time[10];
    struct Appointment* next;
} Appointment;

Appointment* createAppointment(char* name, char* date, char* time) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);
    newAppointment->next = NULL;
    return newAppointment;
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

void scheduleAppointment(Appointment** head) {
    char name[50];
    char date[10];
    char time[10];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%s", date);

    printf("Enter the time (hh:mm): ");
    scanf("%s", time);

    Appointment* newAppointment = createAppointment(name, date, time);
    if (*head == NULL) {
        *head = newAppointment;
    } else {
        (*head)->next = newAppointment;
    }
}

int main() {
    Appointment* head = NULL;

    printf("Welcome to the C Appointment Scheduler!\n");
    printf("------------------------\n");

    char choice;

    do {
        printf("Enter 's' to schedule an appointment, 'd' to display appointments, or 'q' to quit: ");
        scanf("%c", &choice);

        switch (choice) {
            case 's':
                scheduleAppointment(&head);
                break;
            case 'd':
                displayAppointments(head);
                break;
            case 'q':
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    } while (choice != 'q');

    printf("Thank you for using the C Appointment Scheduler!\n");
    return 0;
}