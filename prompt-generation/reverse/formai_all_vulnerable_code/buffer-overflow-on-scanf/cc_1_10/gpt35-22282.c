//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for appointment details
struct Appointment {
    char name[20];
    char date[11];
    char time[6];
    char location[50];
    char notes[100];
};

// Function to add appointment
void addAppointment(struct Appointment app[], int size) {
    struct Appointment new_app;
    printf("\nEnter name: ");
    scanf("%s", new_app.name);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", new_app.date);
    printf("Enter time (hh:mm): ");
    scanf("%s", new_app.time);
    printf("Enter location: ");
    scanf("%s", new_app.location);
    printf("Enter notes: ");
    scanf("%s", new_app.notes);

    app[size] = new_app; // Adding to the end of the array
    printf("\nAdded appointment successfully.\n");
}

// Function to display all appointments
void displayAppointments(struct Appointment app[], int size) {
    printf("\nDisplaying all appointments:\n");
    for(int i=0; i<size; i++) {
        printf("\nAppointment %d:\n", i+1);
        printf("Name: %s\n", app[i].name);
        printf("Date: %s\n", app[i].date);
        printf("Time: %s\n", app[i].time);
        printf("Location: %s\n", app[i].location);
        printf("Notes: %s\n", app[i].notes);
    }
}

int main() {
    int size = 0;
    struct Appointment appointments[50]; // Initialize array with maximum size of 50

    int choice;
    do {
        printf("\nAppointment Scheduler");
        printf("\n1. Add Appointment");
        printf("\n2. Display All Appointments");
        printf("\n3. Exit");
        printf("\nEnter your choice (1/2/3): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addAppointment(appointments, size);
                size++; // Increase size of array after adding appointment
                break;
            case 2:
                displayAppointments(appointments, size);
                break;
            case 3:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while(choice != 3);

    return 0;
}