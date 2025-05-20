//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10
#define MAX_NAME_LENGTH 20

typedef struct Appointment {
    char name[MAX_NAME_LENGTH];
    char time[MAX_NAME_LENGTH];
    struct Appointment* next;
} Appointment;

Appointment* createAppointment(char* name, char* time) {
    Appointment* newAppt = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppt->name, name);
    strcpy(newAppt->time, time);
    newAppt->next = NULL;
    return newAppt;
}

void displayAppointments(Appointment* appt) {
    while (appt) {
        printf("%s (%s)\n", appt->name, appt->time);
        appt = appt->next;
    }
}

int main() {
    Appointment* head = NULL;

    // Multiplayer part:
    // Assume two players, Player 1 and Player 2, are connected to the same server

    // Player 1 makes an appointment
    printf("Player 1, enter your name: ");
    char* name1 = malloc(MAX_NAME_LENGTH);
    scanf("%s", name1);

    printf("Player 1, enter the time of your appointment: ");
    char* time1 = malloc(MAX_NAME_LENGTH);
    scanf("%s", time1);

    Appointment* newAppt1 = createAppointment(name1, time1);
    if (head == NULL) {
        head = newAppt1;
    } else {
        newAppt1->next = head;
        head = newAppt1;
    }

    // Player 2 makes an appointment
    printf("Player 2, enter your name: ");
    char* name2 = malloc(MAX_NAME_LENGTH);
    scanf("%s", name2);

    printf("Player 2, enter the time of your appointment: ");
    char* time2 = malloc(MAX_NAME_LENGTH);
    scanf("%s", time2);

    Appointment* newAppt2 = createAppointment(name2, time2);
    if (head == NULL) {
        head = newAppt2;
    } else {
        newAppt2->next = head;
        head = newAppt2;
    }

    // Display all appointments
    printf("All appointments:\n");
    displayAppointments(head);

    return 0;
}