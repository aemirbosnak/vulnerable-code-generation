//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// struct for storing appointment details
struct appointment {
    char name[50];
    char date[20];
    char time[10];
};

// function to add appointment
void addAppointment(struct appointment app[], int *count) {
    printf("Enter patient name: ");
    scanf("%s", &app[*count].name);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", &app[*count].date);
    printf("Enter time (hh:mm): ");
    scanf("%s", &app[*count].time);
    printf("Appointment added successfully!\n");
    *count = *count + 1;
}

// function to display all appointments
void displayAppointments(struct appointment app[], int count) {
    printf("Appointments\n");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Patient: %s\nDate: %s\nTime: %s\n", app[i].name, app[i].date, app[i].time);
        printf("-------------------------------------------------------\n");
    }
}

int main() {
    int option, count = 0;
    struct appointment appointments[50];

    while (1) {
        printf("\nWelcome to Happy Appointment Scheduler!\n");
        printf("1. Add an appointment\n");
        printf("2. Display all appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1: addAppointment(appointments, &count);
                    break;
            case 2: displayAppointments(appointments, count);
                    break;
            case 3: printf("Thank you for using Happy Appointment Scheduler. Goodbye!\n");
                    exit(0);
            default: printf("Invalid option. Please enter a valid option.\n");
                     break;
        }
    }
    return 0;
}