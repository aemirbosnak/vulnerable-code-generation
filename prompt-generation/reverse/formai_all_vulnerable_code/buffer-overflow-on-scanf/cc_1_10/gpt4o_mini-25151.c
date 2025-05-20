//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 30
#define DATE_LENGTH 11

typedef struct Appointment {
    char name[NAME_LENGTH];
    char date[DATE_LENGTH];
    char time[6]; // HH:MM format
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void addAppointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Alas! The appointment tome is full.\n");
        return;
    }

    Appointment new_appointment;

    printf("Enter noble name for the appointment: ");
    scanf("%s", new_appointment.name);
    
    printf("Enter the date of meeting (YYYY-MM-DD): ");
    scanf("%s", new_appointment.date);
    
    printf("Enter the time of meeting (HH:MM): ");
    scanf("%s", new_appointment.time);

    appointments[appointment_count] = new_appointment;
    appointment_count++;

    printf("Dear %s, your appointment hath been scheduled for the %s at %s.\n",
           new_appointment.name, new_appointment.date, new_appointment.time);
}

void viewAppointments() {
    if (appointment_count == 0) {
        printf("Oh, sweet adversity! No appointments are recorded in the log.\n");
        return;
    }
    
    printf("List of Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. Forsooth! %s on %s at %s\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void deleteAppointment() {
    if (appointment_count == 0) {
        printf("With heavy hearts, we can find no apt appointment to slay.\n");
        return;
    }
    
    viewAppointments();
    
    int index;
    printf("Enter the number of the appointment to abolish: ");
    scanf("%d", &index);
    
    if (index < 1 || index > appointment_count) {
        printf("Alas! Such a number dost not exist.\n");
        return;
    }
    
    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;

    printf("The appointment hath been banished from the records.\n");
}

void displayMenu() {
    printf("\n--- The Appointment Scheduler of Verona ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("Please make thy choice: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                printf("Farewell! Until we meet again.\n");
                exit(0);
            default:
                printf("In sooth, thy selection is no valid choice!\n");
        }
    }

    return 0;
}