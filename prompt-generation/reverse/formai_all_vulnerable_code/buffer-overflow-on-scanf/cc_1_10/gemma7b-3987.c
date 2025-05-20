//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[20];
    char time[20];
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

int main() {
    Appointment* head = NULL;
    char name[50];
    char date[20];
    char time[20];

    // Create a loop to get the user input
    while (1) {
        // Get the user's name, date, and time
        printf("Enter your name: ");
        scanf("%s", name);

        printf("Enter the date (MM/DD/YY): ");
        scanf("%s", date);

        printf("Enter the time (HH:MM): ");
        scanf("%s", time);

        // Create a new appointment
        Appointment* newAppointment = createAppointment(name, date, time);

        // Add the new appointment to the head of the list
        if (head == NULL) {
            head = newAppointment;
        } else {
            newAppointment->next = head;
            head = newAppointment;
        }

        // Ask the user if they want to continue
        char continue_yn;
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &continue_yn);

        // If the user does not want to continue, break out of the loop
        if (continue_yn == 'N') {
            break;
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