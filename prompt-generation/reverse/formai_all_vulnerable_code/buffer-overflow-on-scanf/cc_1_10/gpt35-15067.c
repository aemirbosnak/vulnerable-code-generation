//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Structure to hold appointment information
struct Appointment {
    char name[50];
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int duration;
};

// Function declarations
void scheduleAppointment();
void viewAppointments();
int getAppointmentCount();
void displayMenu();

// Global variable for appointment count
int appointmentCount = 0;

int main() {
    int choice;
    srand(time(0)); // Setting seed for random number generation
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                scheduleAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                printf("Exiting program. Thank you for using the Appointment Scheduler.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 3);
    
    return 0;
}

void displayMenu() {
    printf("-------- Appointment Scheduler --------\n");
    printf("1. Schedule Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Exit\n");
}

void scheduleAppointment() {
    struct Appointment newApp;
    printf("Enter name: ");
    scanf("%s", &newApp.name);
    printf("Enter date (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &newApp.day, &newApp.month, &newApp.year);
    printf("Enter time (hh:mm): ");
    scanf("%d:%d", &newApp.hour, &newApp.minute);
    printf("Enter duration (in minutes): ");
    scanf("%d", &newApp.duration);
    appointmentCount++;
    printf("Appointment successfully scheduled!\n");
}

void viewAppointments() {
    if(getAppointmentCount() == 0) {
        printf("You have no appointments scheduled.\n");
        return;
    }
    int i;
    printf("-------- Scheduled Appointments --------\n");
    for(i=0; i<appointmentCount; i++) {
        struct Appointment currApp;
        // Randomly generating appointment date and time
        currApp.day = rand() % 30 + 1;
        currApp.month = rand() % 12 + 1;
        currApp.year = 2022;
        currApp.hour = rand() % 24;
        currApp.minute = rand() % 60;
        currApp.duration = rand() % 120 + 30;
        printf("Appointment %d:\n", i+1);
        printf("Name: %s\n", currApp.name);
        printf("Date: %d-%d-%d\n", currApp.day, currApp.month, currApp.year);
        printf("Time: %d:%d\n", currApp.hour, currApp.minute);
        printf("Duration: %d minutes\n", currApp.duration);
        printf("\n");
    }
}

int getAppointmentCount() {
    return appointmentCount;
}