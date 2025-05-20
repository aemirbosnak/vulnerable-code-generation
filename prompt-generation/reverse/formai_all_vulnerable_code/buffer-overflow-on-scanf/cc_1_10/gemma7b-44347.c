//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[50];
    char time[50];
    char date[50];
    struct Appointment* next;
} Appointment;

void scheduleAppointment(Appointment* head) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    printf("Enter your name: ");
    scanf("%s", newAppointment->name);
    printf("Enter the time of your appointment: ");
    scanf("%s", newAppointment->time);
    printf("Enter the date of your appointment: ");
    scanf("%s", newAppointment->date);
    newAppointment->next = head;
    head = newAppointment;
}

void printAppointments(Appointment* head) {
    while (head) {
        printf("%s, %s, %s\n", head->name, head->time, head->date);
        head = head->next;
    }
}

int main() {
    Appointment* head = NULL;

    while (1) {
        printf("Enter 'schedule' to schedule an appointment or 'print' to see your appointments: ");
        char command[50];
        scanf("%s", command);

        if (strcmp(command, "schedule") == 0) {
            scheduleAppointment(head);
        } else if (strcmp(command, "print") == 0) {
            printAppointments(head);
        } else {
            printf("Invalid command. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}