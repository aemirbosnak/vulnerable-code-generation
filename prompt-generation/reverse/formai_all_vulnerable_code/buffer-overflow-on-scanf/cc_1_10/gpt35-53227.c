//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// define struct for appointment
typedef struct appointment {
    char* name;
    char* day;
    char* time;
} Appointment;

// declare global variables
int count = 0;
int MAX_APPTS = 10;

// declare functions
void addAppointment(Appointment appts[]);
void viewAppointments(Appointment appts[]);
void removeAppointment(Appointment appts[]);
void clearInput();

// main function
int main() {
    // declare array of appointments
    Appointment appts[MAX_APPTS];
    
    // declare variable for menu choice
    int choice;
    
    do {
        // print menu
        printf("\nAppointment Scheduler Menu\n");
        printf("==========================\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Remove Appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        // get user input for menu choice
        scanf("%d", &choice);
        clearInput();
        
        switch(choice) {
            case 1:
                // add appointment
                addAppointment(appts);
                break;
            case 2:
                // view appointments
                viewAppointments(appts);
                break;
            case 3:
                // remove appointment
                removeAppointment(appts);
                break;
            case 4:
                // exit
                printf("\nExiting program.");
                break;
            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }
    } while (choice != 4);
    
    // return success
    return 0;
}

// function to add appointment
void addAppointment(Appointment appts[]) {
    // check if max appointments have been reached
    if (count == MAX_APPTS) {
        printf("\nMaximum number of appointments reached.");
        return;
    }
    
    // allocate memory for new appointment
    Appointment* newAppt = (Appointment*) malloc(sizeof(Appointment));
    
    // get name
    printf("\nEnter name for appointment: ");
    char buffer[100];
    fgets(buffer, 100, stdin);
    newAppt->name = (char*) malloc(strlen(buffer) + 1);
    strcpy(newAppt->name, buffer);
    
    // get day
    printf("Enter day of appointment (e.g. Monday, Tuesday, etc.): ");
    fgets(buffer, 100, stdin);
    newAppt->day = (char*) malloc(strlen(buffer) + 1);
    strcpy(newAppt->day, buffer);
    
    // get time
    printf("Enter time of appointment (e.g. 10:30 AM): ");
    fgets(buffer, 100, stdin);
    newAppt->time = (char*) malloc(strlen(buffer) + 1);
    strcpy(newAppt->time, buffer);
    
    // add appointment to array and increment count
    appts[count++] = *newAppt;
    
    // print message
    printf("\nAppointment added successfully.");
}

// function to view appointments
void viewAppointments(Appointment appts[]) {
    // check if there are any appointments
    if (count == 0) {
        printf("\nNo appointments to display.");
        return;
    }
    
    // print header
    printf("\nAPPOINTMENTS\n");
    printf("============\n");
    
    // print appointments
    for (int i = 0; i < count; i++) {
        printf("\nAppointment %d:\n", i + 1);
        printf("Name: %s", appts[i].name);
        printf("Day: %s", appts[i].day);
        printf("Time: %s", appts[i].time);
    }
}

// function to remove appointment
void removeAppointment(Appointment appts[]) {
    // check if there are any appointments
    if (count == 0) {
        printf("\nNo appointments to remove.");
        return;
    }
    
    // get appointment number to remove
    int apptNum;
    printf("\nEnter appointment number to remove: ");
    scanf("%d", &apptNum);
    clearInput();
    
    // remove appointment
    if (apptNum < 1 || apptNum > count) {
        printf("\nInvalid appointment number. Please try again.");
    } else {
        for (int i = apptNum - 1; i < count - 1; i++) {
            appts[i] = appts[i+1];
        }
        count--;
        printf("\nAppointment removed successfully.");
    }
}

// function to clear input buffer
void clearInput() {
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}