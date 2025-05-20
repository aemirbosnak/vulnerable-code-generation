//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 11

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[6]; // HH:MM format
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void addAppointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Oops! Can't schedule more appointments at this moment!\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter your name: ");
    scanf("%s", new_appointment.name);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", new_appointment.date);
    printf("Enter time (HH:MM): ");
    scanf("%s", new_appointment.time);
    
    appointments[appointment_count] = new_appointment;
    appointment_count++;
    
    printf("🎉 Appointment added successfully! 🎉\n");
}

void viewAppointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled! Let's add some! 🚀\n");
        return;
    }
    
    printf("\n🌟 Your Appointments 🌟\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment #%d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n\n", appointments[i].time);
    }
}

void cancelAppointment() {
    viewAppointments();
    if (appointment_count == 0) return;

    int index;
    printf("Enter the appointment number to cancel: ");
    scanf("%d", &index);
    
    if (index < 1 || index > appointment_count) {
        printf("🚫 Invalid appointment number! Please try again.\n");
        return;
    }

    // Shift appointments to fill the cancelled appointment slot
    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    
    printf("🎉 Appointment #%d cancelled successfully! 🎉\n", index);
}

void displayMenu() {
    printf("\n🌈 Welcome to the Appointment Scheduler! 🌈\n");
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
                printf("✨ Thank you for using the Appointment Scheduler! ✨\n");
                exit(0);
            default:
                printf("🚀 Invalid choice! Please choose again.\n");
        }
    } while (1);

    return 0;
}