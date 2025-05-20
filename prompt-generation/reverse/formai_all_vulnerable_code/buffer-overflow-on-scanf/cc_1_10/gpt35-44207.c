//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold appointment details
struct Appointment {
    char name[50];
    char date[20];
    char time[20];
};

// Function to add new appointment
void addAppointment(struct Appointment *appointments, int *count) {
    struct Appointment appointment;
    printf("Enter name: ");
    scanf("%s", appointment.name);
    printf("Enter date: ");
    scanf("%s", appointment.date);
    printf("Enter time: ");
    scanf("%s", appointment.time);
    appointments[*count] = appointment;
    (*count)++;
    printf("\nAppointment added successfully!\n\n");
}

// Function to display all appointments
void displayAppointments(struct Appointment *appointments, int count) {
    if(count == 0) {
        printf("\nNo appointments found!\n\n");
        return;
    }
    printf("%-20s%-20s%s\n", "Name", "Date", "Time");
    for(int i=0; i<count; i++) {
        printf("%-20s%-20s%s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
    printf("\n");
}

int main() {
    struct Appointment appointments[50];
    int count = 0;
    int choice = 0;
    while(choice != 3) {
        printf("1. Add Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addAppointment(appointments, &count); break;
            case 2: displayAppointments(appointments, count); break;
            case 3: printf("\nExiting...\n"); break;
            default: printf("\nInvalid choice, please try again!\n\n"); break;
        }
    }
    return 0;
}