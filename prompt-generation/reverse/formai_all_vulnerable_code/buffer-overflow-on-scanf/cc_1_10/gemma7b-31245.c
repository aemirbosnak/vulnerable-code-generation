//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: creative
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

void scheduleAppointment(Appointment* head) {
    Appointment* newAppt = (Appointment*)malloc(sizeof(Appointment));
    printf("Enter your name: ");
    scanf("%s", newAppt->name);
    printf("Enter the date of your appointment: ");
    scanf("%s", newAppt->date);
    printf("Enter the time of your appointment: ");
    scanf("%s", newAppt->time);

    newAppt->next = NULL;

    if (head == NULL) {
        head = newAppt;
    } else {
        head->next = newAppt;
    }
}

void printAppointments(Appointment* head) {
    printf("Your appointments:\n");
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
        printf("Enter 'schedule' to schedule an appointment or 'print' to see your appointments: ");
        char command[50];
        scanf("%s", command);

        if (strcmp(command, "schedule") == 0) {
            scheduleAppointment(head);
        } else if (strcmp(command, "print") == 0) {
            printAppointments(head);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}