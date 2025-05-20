//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define a structure to store appointment details
typedef struct {
    char name[50];
    int day;
    int month;
    int year;
    float time;
} appointment;

// Declare global variables
appointment appointments[100];
int count = 0;

// Function to print the list of appointments
void print_appointments() {
    if(count == 0) {
        printf("No appointments scheduled!\n");
    } else {
        printf("Scheduled Appointments:\n");
        printf("%-30s %-15s %-15s %-15s %-15s\n", "Name", "Date(YYYY/MM/DD)", "Time(HH.MM)");
        for(int i=0; i<count; i++) {
            printf("%-30s %04d/%02d/%02d\t\t %.2f\n", appointments[i].name, appointments[i].year, 
                appointments[i].month, appointments[i].day, appointments[i].time);
        }
    }
}

// Function to check if a particular date and time is available
bool is_available(int day, int month, int year, float time) {
    for(int i=0; i<count; i++) {
        if(appointments[i].day == day && appointments[i].month == month && appointments[i].year == year && 
            appointments[i].time == time) {
            return false;
        }
    }
    return true;
}

// Function to schedule an appointment
void schedule_appointment() {
    appointment new_appointment;
    printf("Enter your full name: ");
    fgets(new_appointment.name, sizeof(new_appointment.name), stdin);
    new_appointment.name[strcspn(new_appointment.name, "\n")] = 0;
    printf("Enter the date (YYYY/MM/DD): ");
    scanf("%d/%d/%d", &new_appointment.year, &new_appointment.month, &new_appointment.day);
    printf("Enter the time (HH.MM): ");
    scanf("%f", &new_appointment.time);
    getchar(); // to clear the newline character left in the input stream
    if(is_available(new_appointment.day, new_appointment.month, new_appointment.year, new_appointment.time)) {
        appointments[count] = new_appointment;
        count++;
        printf("Appointment scheduled successfully!\n");
    } else {
        printf("The selected date and time is already booked! Please try again with another slot.\n");
    }
}

// Main function
int main() {
    int option;
    printf("Welcome to Appointment Scheduler!\n\n");
    do {
        printf("Please choose an option:\n");
        printf("1. Schedule an appointment\n");
        printf("2. View scheduled appointments\n");
        printf("3. Exit\n");
        printf("Option: ");
        scanf("%d", &option);
        getchar(); // to clear the newline character left in the input stream
        printf("\n");
        switch(option) {
            case 1:
                schedule_appointment();
                break;
            case 2:
                print_appointments();
                break;
            case 3:
                printf("Thank you for using Appointment Scheduler!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n\n");
        }
    } while(option != 3);
    return 0;
}