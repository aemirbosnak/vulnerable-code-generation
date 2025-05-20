//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 30
#define MAX_APPOINTMENTS 10
#define MAX_APPOINTMENT_LENGTH 50

typedef struct Appointment {
    char name[MAX_NAME_LENGTH];
    char description[MAX_APPOINTMENT_LENGTH];
    time_t date;
    struct Appointment *next;
} Appointment;

Appointment *appointments = NULL;

void addAppointment(char *name, char *description, time_t date) {
    Appointment *newAppointment = (Appointment *)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->description, description);
    newAppointment->date = date;
    newAppointment->next = appointments;
    appointments = newAppointment;
}

void printAppointments() {
    Appointment *current = appointments;
    while (current != NULL) {
        printf("\nAppointment for %s:\n", current->name);
        printf("Description: %s\n", current->description);
        printf("Date: %s\n", ctime(&(current->date)));
        current = current->next;
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH], description[MAX_APPOINTMENT_LENGTH];
    time_t date;

    while (1) {
        printf("\nRoses are red,\nViolets are blue,\nWelcome to my scheduler,\nLet's plan something new!\n\n");
        printf("Please enter your name: ");
        scanf("%s", name);

        printf("\nEnter appointment description: ");
        scanf("%s", description);

        printf("\nEnter appointment date (YYYY-MM-DD): ");
        scanf("%ld", &date);

        addAppointment(name, description, date);

        printf("\nAppointment added successfully!\nDo you want to add another appointment?\n1. Yes\n2. No\n");
        scanf("%d", &choice);

        if (choice == 2) {
            break;
        }
    }

    printf("\nAppointments for %s:\n", name);
    printAppointments();

    return 0;
}