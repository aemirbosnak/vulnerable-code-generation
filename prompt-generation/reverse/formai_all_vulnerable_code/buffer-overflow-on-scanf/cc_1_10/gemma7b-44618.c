//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    struct Appointment* next;
} Appointment;

void insertAppointment(Appointment** head) {
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

void printAppointments(Appointment* head) {
    while (head) {
        printf("%s, %s, %s\n", head->name, head->date, head->time);
        head = head->next;
    }
}

int main() {
    Appointment* head = NULL;

    printf("Enter 'insert' to insert an appointment, 'print' to print all appointments, or 'exit' to exit: ");
    char command;
    scanf("%c", &command);

    switch (command) {
        case 'i':
            insertAppointment(&head);
            break;
        case 'p':
            printAppointments(head);
            break;
        case 'e':
            exit(0);
            break;
        default:
            printf("Invalid command.\n");
    }

    return 0;
}