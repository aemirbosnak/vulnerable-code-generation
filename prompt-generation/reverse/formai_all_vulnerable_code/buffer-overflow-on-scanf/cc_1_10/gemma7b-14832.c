//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[20];
    char date[20];
    char time[20];
    struct Appointment* next;
} Appointment;

int main() {
    Appointment* head = NULL;
    Appointment* tail = NULL;
    int numAppointments = 0;

    // Loop to get the number of appointments
    printf("Enter the number of appointments: ");
    scanf("%d", &numAppointments);

    // Allocate memory for each appointment
    for (int i = 0; i < numAppointments; i++) {
        head = malloc(sizeof(Appointment));
        tail = head;

        // Get the appointment details
        printf("Enter the name of the appointment: ");
        scanf("%s", tail->name);

        printf("Enter the date of the appointment: ");
        scanf("%s", tail->date);

        printf("Enter the time of the appointment: ");
        scanf("%s", tail->time);

        // Insert the appointment into the list
        if (head == NULL) {
            head = tail;
        } else {
            tail->next = head;
            head = tail;
        }
    }

    // Print the appointments
    printf("Your appointments:\n");
    for (Appointment* current = head; current; current = current->next) {
        printf("Name: %s\n", current->name);
        printf("Date: %s\n", current->date);
        printf("Time: %s\n", current->time);
        printf("\n");
    }

    return 0;
}