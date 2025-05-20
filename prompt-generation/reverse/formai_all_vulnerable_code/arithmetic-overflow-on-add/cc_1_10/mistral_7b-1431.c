//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Appointment structure definition
typedef struct Appointment {
    char title[50];
    time_t startTime;
    time_t endTime;
    struct Appointment *next;
} Appointment;

// Initialize headAppointment to NULL
Appointment *headAppointment = NULL;

// Function to create a new appointment node
Appointment *createAppointment(const char *title, time_t startTime, time_t endTime) {
    Appointment *newAppointment = (Appointment *)malloc(sizeof(Appointment));
    strcpy(newAppointment->title, title);
    newAppointment->startTime = startTime;
    newAppointment->endTime = endTime;
    newAppointment->next = NULL;
    return newAppointment;
}

// Function to add an appointment to the list
void addAppointment(const char *title, time_t startTime, time_t endTime) {
    Appointment *newAppointment = createAppointment(title, startTime, endTime);
    if (headAppointment == NULL) {
        headAppointment = newAppointment;
    } else {
        Appointment *current = headAppointment;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newAppointment;
    }
}

// Function to print all appointments in the list
void printAppointments() {
    printf("Appointments:\n");
    Appointment *current = headAppointment;
    while (current != NULL) {
        printf("%s from %s to %s\n", current->title, ctime(&current->startTime), ctime(&current->endTime));
        current = current->next;
    }
}

// Function to search for an appointment by title
time_t searchAppointments(const char *title) {
    Appointment *current = headAppointment;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            return current->startTime;
        }
        current = current->next;
    }
    return -1;
}

// Main function to demonstrate the usage of the above functions
int main() {
    // Add some initial appointments
    addAppointment("Doctor's appointment", mktime(NULL) + 3600, mktime(NULL) + 7200);
    addAppointment("Interview", mktime(NULL) + 5400, mktime(NULL) + 7200);

    // Print all appointments
    printAppointments();

    // Search for an appointment by title
    time_t startTime = searchAppointments("Interview");
    if (startTime != -1) {
        printf("Interview starts at %s", ctime(&startTime));
    } else {
        printf("No appointment with that title found.\n");
    }

    return 0;
}