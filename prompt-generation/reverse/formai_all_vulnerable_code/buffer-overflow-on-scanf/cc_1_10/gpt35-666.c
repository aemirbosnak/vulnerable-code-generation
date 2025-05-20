//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//DEFINING CONSTANTS
#define MAX_APPOINTMENTS 50
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20
#define MAX_TIME_LENGTH 15

//Declaring the structure for appointment
struct appointment {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
};

//Declaring array to store appointments
struct appointment appointments[MAX_APPOINTMENTS];

//Declaring variables for appointment index and count
int appointmentCount = 0;
int currentIndex = 0;

//Function to display main menu
void displayMenu() {
    printf("------Appointment Scheduler-------\n");
    printf("1. Book Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Cancel Appointment\n");
    printf("4. Exit\n");
    printf("----------------------------------\n");
    printf("Enter your choice (1-4): ");
}

//Function to book an appointment
void bookAppointment() {
    //Check if maximum appointments reached
    if (appointmentCount == MAX_APPOINTMENTS) {
        printf("Maximum Appointments Reached. Cannot book an appointment.\n");
        return;
    }
    //Prompt user for name, date and time of appointment
    printf("Enter name for appointment: ");
    scanf("%s", appointments[appointmentCount].name);
    printf("Enter date of appointment (dd/mm/yyyy): ");
    scanf("%s", appointments[appointmentCount].date);
    printf("Enter time of appointment (hh:mm AM/PM): ");
    scanf("%s", appointments[appointmentCount].time);
    printf("Appointment booked successfully!\n");
    //Increment appointment count
    appointmentCount++;
}

//Function to view appointments
void viewAppointments() {
    //Check if there are any appointments booked
    if (appointmentCount == 0) {
        printf("No Appointments booked yet.\n");
        return;
    }
    //Loop through all appointments
    for (int i = 0; i < appointmentCount; i++) {
        printf("%d. Name: %s\tDate: %s\tTime: %s\n", i+1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

//Function to cancel an appointment
void cancelAppointment() {
    //Check if there are any appointments booked
    if (appointmentCount == 0) {
        printf("No Appointments booked yet.\n");
        return;
    }
    //Prompt user for appointment to cancel
    printf("Enter number of the appointment to cancel: ");
    scanf("%d", &currentIndex);
    //Check if appointment index is valid
    if (currentIndex < 1 || currentIndex > appointmentCount) {
        printf("Invalid appointment number. Try Again.\n");
        return;
    }
    //Shift appointments to remove the cancelled appointment
    for (int i = currentIndex-1; i < appointmentCount-1; i++) {
        strcpy(appointments[i].name, appointments[i+1].name);
        strcpy(appointments[i].date, appointments[i+1].date);
        strcpy(appointments[i].time, appointments[i+1].time);
    }
    //Decrement appointment count
    appointmentCount--;
    printf("Appointment cancelled successfully.\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                bookAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                cancelAppointment();
                break;
            case 4:
                printf("Exiting Appointment Scheduler.\n");
                exit(0);
            default:
                printf("Invalid choice. Try Again!\n");
        }
    }
    return 0;
}