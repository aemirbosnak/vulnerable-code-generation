//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store appointment details
typedef struct {
    char name[100];
    int startTime;
    int endTime;
} Appointment;

// Function to add a new appointment to the schedule
void addAppointment(Appointment *appointments, int capacity) {
    if (capacity == 0) {
        printf("The schedule is full!\n");
        return;
    }

    char name[100];
    int startTime, endTime;

    // Prompt user to enter appointment details
    printf("Enter the name of the appointment: ");
    fgets(name, 100, stdin);

    // Convert input to integer
    sscanf(name, "%d %d", &startTime, &endTime);

    if (startTime < 0 || endTime < 0) {
        printf("Invalid time entered.\n");
        return;
    }

    // Check if the appointment overlaps with existing appointments
    int i;
    for (i = 0; i < capacity; i++) {
        if (appointments[i].startTime >= startTime && appointments[i].endTime <= endTime) {
            printf("Appointment already exists.\n");
            return;
        }
    }

    // Allocate memory for new appointment
    Appointment *newAppointment = malloc(sizeof(Appointment));
    if (newAppointment == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    // Copy appointment details to new appointment
    strcpy(newAppointment->name, name);
    newAppointment->startTime = startTime;
    newAppointment->endTime = endTime;

    // Shift existing appointments to make room for new appointment
    int j;
    for (j = capacity; j > i; j--) {
        appointments[j] = appointments[j - 1];
    }

    // Insert new appointment at the beginning of the schedule
    appointments[i] = *newAppointment;

    printf("Appointment added successfully.\n");
}

// Function to print the schedule
void printSchedule(Appointment *appointments, int capacity) {
    int i;
    printf("Schedule:\n");
    for (i = 0; i < capacity; i++) {
        if (appointments[i].startTime == 0 && appointments[i].endTime == 0) {
            printf(" %s\n", appointments[i].name);
        } else {
            printf(" %s %d:%d\n", appointments[i].name, appointments[i].startTime, appointments[i].endTime);
        }
    }
}

// Main function
int main() {
    Appointment appointments[10];
    int capacity = 10;

    // Initialize appointments array
    int i;
    for (i = 0; i < capacity; i++) {
        appointments[i].name[0] = '\0';
        appointments[i].startTime = 0;
        appointments[i].endTime = 0;
    }

    // Add appointments to the schedule
    printf("Enter appointments:\n");
    addAppointment(appointments, capacity);
    printSchedule(appointments, capacity);

    return 0;
}