//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Appointment {
    char name[50];
    char date[10];
    char time[10];
    struct Appointment* next;
} Appointment;

void schedule_appointment(Appointment* head) {
    // Allocate memory for a new appointment
    Appointment* new_app = (Appointment*)malloc(sizeof(Appointment));

    // Get the user's name, date, and time
    printf("Enter your name: ");
    scanf("%s", new_app->name);

    printf("Enter the date of your appointment (MM/DD/YY): ");
    scanf("%s", new_app->date);

    printf("Enter the time of your appointment (HH:MM): ");
    scanf("%s", new_app->time);

    // Link the new appointment to the head of the list
    if (head == NULL) {
        head = new_app;
    } else {
        new_app->next = head;
        head = new_app;
    }
}

void print_appointments(Appointment* head) {
    // Traverse the list of appointments
    while (head) {
        // Print the appointment details
        printf("Name: %s\n", head->name);
        printf("Date: %s\n", head->date);
        printf("Time: %s\n", head->time);
        printf("\n");
        head = head->next;
    }
}

int main() {
    // Create a head of the appointment list
    Appointment* head = NULL;

    // Schedule an appointment
    schedule_appointment(head);

    // Print the appointments
    print_appointments(head);

    return 0;
}