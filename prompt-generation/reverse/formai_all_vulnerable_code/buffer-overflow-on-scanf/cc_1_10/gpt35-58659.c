//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
// AppointmentScheduler.c - A program that manages appointments using C language
// Written in a Dennis Ritchie style by [YourNameHere]

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Appointment structure
typedef struct {
    int month, day, year;
    char description[100];
} Appointment;

// Function signatures
void show_menu();
void add_appointment(Appointment *appointments, int *num_appointments);
void print_appointments(Appointment *appointments, int num_appointments);
void exit_program();

int main() {
    int choice, num_appointments = 0;
    Appointment appointments[100];

    do {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_appointment(appointments, &num_appointments);
                break;
            case 2:
                print_appointments(appointments, num_appointments);
                break;
            case 3:
                exit_program();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}

// Display the menu options
void show_menu() {
    printf("--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. Print Appointments\n");
    printf("3. Exit\n");
}

// Add an appointment to the list
void add_appointment(Appointment *appointments, int *num_appointments) {
    printf("--- Add Appointment ---\n");

    if(*num_appointments < 100) {
        printf("Enter the month: ");
        scanf("%d", &appointments[*num_appointments].month);

        printf("Enter the day: ");
        scanf("%d", &appointments[*num_appointments].day);

        printf("Enter the year: ");
        scanf("%d", &appointments[*num_appointments].year);

        printf("Enter the appointment description: ");
        scanf("%s", appointments[*num_appointments].description);

        printf("Appointment added.\n");
        (*num_appointments)++;
    } else {
        printf("The appointment list is full.\n");
    }
}

// Print the list of appointments
void print_appointments(Appointment *appointments, int num_appointments) {
    printf("--- List of Appointments ---\n");

    if(num_appointments == 0) {
        printf("There are no appointments scheduled.\n");
    } else {
        for(int i = 0; i < num_appointments; i++) {
            printf("%d/%d/%d: %s\n", appointments[i].month, appointments[i].day, appointments[i].year, appointments[i].description);
        }
    }
}

// Exit the program
void exit_program() {
    printf("Thank you for using the Appointment Scheduler.\n");
    exit(0);
}