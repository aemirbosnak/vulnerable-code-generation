//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define NAME_SIZE 50
#define DATE_SIZE 15
#define TIME_SIZE 10

typedef struct {
    char name[NAME_SIZE];
    char date[DATE_SIZE];
    char time[TIME_SIZE];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void addAppointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments. Maximum limit reached!\n");
        return;
    }
    Appointment new_appointment;
    
    printf("Enter the name for the appointment: ");
    scanf("%s", new_appointment.name);
    
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", new_appointment.date);
    
    printf("Enter the time (HH:MM): ");
    scanf("%s", new_appointment.time);
    
    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled!\n");
        return;
    }
    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. %s on %s at %s\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void cancelAppointment() {
    if (appointment_count == 0) {
        printf("No appointments to cancel!\n");
        return;
    }
    
    int index;
    printf("Enter the appointment number to cancel: ");
    scanf("%d", &index);
    
    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number!\n");
        return;
    }
    
    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    
    appointment_count--;
    printf("Appointment cancelled successfully!\n");
}

void displayMenu() {
    printf("\nAppointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Cancel Appointment\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                cancelAppointment();
                break;
            case 4:
                printf("Exiting the scheduler. Have a great day!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 4);
    
    return 0;
}