//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 10 // maximum number of appointments that can be scheduled
#define MAX_NAME_LENGTH 50 // maximum length of a name for an appointment
#define MAX_TIME_LENGTH 10 // maximum length of time input for an appointment

// struct to hold each appointment's information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char time[MAX_TIME_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS]; // array to hold all scheduled appointments
int numAppointments = 0; // counter to keep track of number of scheduled appointments

// function to show menu and get user input
int showMenu() {
    int choice;
    printf("\n\nAppointment Scheduler\n");
    printf("1 - Schedule Appointment\n");
    printf("2 - List Appointments\n");
    printf("3 - Cancel Appointment\n");
    printf("4 - Quit\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    return choice;
}

// function to schedule a new appointment
void scheduleAppointment() {
    if (numAppointments < MAX_APPOINTMENTS) {
        printf("\nEnter Name: ");
        scanf("%s", appointments[numAppointments].name);
        printf("Enter Time (hh:mm am/pm): ");
        scanf("%s", appointments[numAppointments].time);
        numAppointments++;
        printf("\nAppointment Scheduled!\n");
    }
    else {
        printf("\nCannot Schedule More Appointments!\n");
    }
}

// function to print list of all scheduled appointments
void listAppointments() {
    if (numAppointments == 0) {
        printf("\nNo Appointments Scheduled!\n");
    }
    else {
        printf("\nList of Appointments:\n");
        for (int i = 0; i < numAppointments; i++) {
            printf("%d) Name: %s, Time: %s\n", i+1, appointments[i].name, appointments[i].time);
        }
    }
}

// function to cancel a scheduled appointment
void cancelAppointment() {
    if (numAppointments == 0) {
        printf("\nNo Appointments Scheduled!\n");
        return;
    }
    char name[MAX_NAME_LENGTH];
    printf("\nEnter Name: ");
    scanf("%s", name);
    bool found = false;
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            found = true;
            printf("\nCanceling Appointment for %s at %s\n", appointments[i].name, appointments[i].time);
            for (int j = i; j < numAppointments-1; j++) {
                appointments[j] = appointments[j+1];
            }
            numAppointments--;
            printf("\nAppointment Canceled!\n");
            break;
        }
    }
    if (!found) {
        printf("\nAppointment Not Found!\n");
    }
}

// main function to run the appointment scheduler
int main() {
    int choice;
    while(true) {
        choice = showMenu();
        switch(choice) {
            case 1: // schedule appointment
                scheduleAppointment();
                break;
            case 2: // list appointments
                listAppointments();
                break;
            case 3: // cancel appointment
                cancelAppointment();
                break;
            case 4: // quit
                printf("\nGoodbye!\n");
                return 0;
                break;
            default: // invalid choice
                printf("\nInvalid Choice!\n");
                break;
        }
    }
    return 0;
}