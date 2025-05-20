//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to create an appointment entry
void createAppointment(char *name, char *time, char *description) {
    struct Appointment {
        char *name;
        char *time;
        char *description;
    } appointment;

    appointment.name = name;
    appointment.time = time;
    appointment.description = description;

    // Create a new appointment entry
    int newEntry = 1;

    // Check if the appointment already exists
    if (newEntry == 1) {
        printf("Appointment Created\n");
    } else {
        printf("Appointment Already Exists\n");
    }
}

// Function to display the appointment list
void displayAppointments() {
    struct Appointment {
        char *name;
        char *time;
        char *description;
    } appointment[10];

    // Read the appointment list from a file
    FILE *fp = fopen("appointments.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
    } else {
        int i = 0;
        while (fscanf(fp, "%s %s %s", &appointment[i].name, &appointment[i].time, &appointment[i].description)!= EOF) {
            i++;
        }
        fclose(fp);

        // Display the appointment list
        printf("Appointment List:\n");
        for (int j = 0; j < i; j++) {
            printf("%s %s %s\n", appointment[j].name, appointment[j].time, appointment[j].description);
        }
    }
}

// Main function
int main() {
    char name[50], time[50], description[100];

    // Create an appointment
    printf("Enter Appointment Name: ");
    scanf("%s", name);
    printf("Enter Appointment Time: ");
    scanf("%s", time);
    printf("Enter Appointment Description: ");
    scanf("%s", description);
    createAppointment(name, time, description);

    // Display the appointment list
    displayAppointments();

    return 0;
}