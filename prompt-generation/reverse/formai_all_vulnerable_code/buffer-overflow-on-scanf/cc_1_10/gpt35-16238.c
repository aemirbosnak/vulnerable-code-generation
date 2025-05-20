//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Define Constants
#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 15
#define MAX_TIME_LENGTH 10

// Appointment struct
typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
} Appointment;

// Function prototypes
int menu();
void makeAppointment(Appointment* appointments, int* numAppointments);
void displayAppointments(Appointment* appointments, int numAppointments);

int main() {
    int choice, numAppointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];

    do {
        // Display menu and get user choice
        choice = menu();

        // Handle choice
        switch(choice) {
            case 1:
                makeAppointment(appointments, &numAppointments);
                break;
            case 2:
                displayAppointments(appointments, numAppointments);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n\n");
        }
    } while(choice != 3);

    return 0;
}

// Function: menu
// Displays the menu and gets the user's choice
int menu() {
    int choice;

    printf("Appointment Scheduler\n");
    printf("----------------------------\n");
    printf("1. Make Appointment\n");
    printf("2. Display Appointments\n");
    printf("3. Exit\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    return choice;
}

// Function: makeAppointment
// Gets user input to make a new appointment and adds it to the appointments array
void makeAppointment(Appointment* appointments, int* numAppointments) {
    // Check if there is space for a new appointment
    if(*numAppointments >= MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments can be made.\n\n");
        return;
    }

    // Get user input for appointment details
    printf("Enter name: ");
    scanf(" %[^\n]s", appointments[*numAppointments].name);

    printf("Enter date (MM/DD/YYYY): ");
    scanf(" %[^\n]s", appointments[*numAppointments].date);

    printf("Enter time (HH:MM AM/PM): ");
    scanf(" %[^\n]s", appointments[*numAppointments].time);

    // Increase appointment count
    *numAppointments += 1;

    printf("Appointment added successfully.\n\n");
}

// Function: displayAppointments
// Prints out all the appointments in the appointments array
void displayAppointments(Appointment* appointments, int numAppointments) {
    // Check if there are any appointments
    if(numAppointments <= 0) {
        printf("No appointments found.\n\n");
        return;
    }

    printf("Appointments\n");
    printf("----------------------------\n");

    // Print out each appointment
    for(int i = 0; i < numAppointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n\n", appointments[i].time);
    }
}