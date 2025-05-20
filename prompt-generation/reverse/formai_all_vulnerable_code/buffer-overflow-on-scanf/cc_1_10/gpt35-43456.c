//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// define maximum number of appointments
#define MAX_APPOINTMENTS 50

// define struct for appointments
typedef struct {
    char date[11];
    char time[6];
    char name[50];
} Appointment;

// initialize global array to store appointments
Appointment appointments[MAX_APPOINTMENTS];

// initialize global variable to keep track of total appointments
int totalAppointments = 0;

// function to check if a given date and time is available for appointment
bool isAvailable(char *date, char *time) {
    for (int i = 0; i < totalAppointments; i++) {
        if (strcmp(appointments[i].date, date) == 0 && strcmp(appointments[i].time, time) == 0) {
            return false;
        }
    }
    return true;
}

// function to add a new appointment
void addAppointment() {
    // check if maximum number of appointments is reached
    if (totalAppointments == MAX_APPOINTMENTS) {
        printf("Sorry, maximum number of appointments reached.\n");
        return;
    }
    // get appointment details from user
    char date[11];
    char time[6];
    char name[50];
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", date);
    printf("Enter time (HH:MM): ");
    scanf("%s", time);
    printf("Enter name: ");
    fflush(stdin);
    fgets(name, 50, stdin);
    name[strlen(name)-1] = '\0';
    // check if date and time are available
    if (!isAvailable(date, time)) {
        printf("Sorry, that date and time is already taken.\n");
        return;
    }
    // add appointment to array
    strcpy(appointments[totalAppointments].date, date);
    strcpy(appointments[totalAppointments].time, time);
    strcpy(appointments[totalAppointments].name, name);
    totalAppointments++;
    printf("Appointment added successfully.\n");
}

// function to display a list of all appointments
void listAppointments() {
    // check if there are any appointments
    if (totalAppointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    // display list of appointments
    printf("Date\t\tTime\t\tName\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < totalAppointments; i++) {
        printf("%s\t%s\t%s\n", appointments[i].date, appointments[i].time, appointments[i].name);
    }
}

// main function
int main() {
    // display welcome message
    printf("Welcome to our Appointment Scheduler program!\n");
    while (true) {
        // display options menu
        printf("\nPlease select an option:\n");
        printf("1. Add new appointment\n");
        printf("2. List all appointments\n");
        printf("3. Exit\n");
        // read user input
        int option;
        scanf("%d", &option);
        // perform selected action
        switch (option) {
            case 1:
                addAppointment();
                break;
            case 2:
                listAppointments();
                break;
            case 3:
                printf("Thank you for using our Appointment Scheduler program!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}