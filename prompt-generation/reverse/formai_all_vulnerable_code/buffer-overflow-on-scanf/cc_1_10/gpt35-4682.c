//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 50
#define TIME_SLOT_SIZE 9 // HH:MM_AM

struct Appointment {
    char time[TIME_SLOT_SIZE];
    char name[20];
    char phone[10];
};

struct Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("\nMaximum appointments reached.\n");
        return;
    }
    
    struct Appointment appointment;
    printf("\nEnter appointment time (HH:MM_AM/PM) : ");
    scanf("%s", appointment.time);
    printf("Enter name : ");
    scanf("%s", appointment.name);
    printf("Enter phone number : ");
    scanf("%s", appointment.phone);
    
    appointments[appointmentCount++] = appointment;
    printf("\nAppointment added successfully!\n");
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("\nNo appointments found.\n");
        return;
    }
    
    printf("\nAppointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("%s - %s - %s\n", appointments[i].time, appointments[i].name, appointments[i].phone);
    }
}

void exitProgram() {
    printf("\nThank you for using the Appointment Scheduler!\n");
    exit(0);
}

int main() {
    printf("*** Ken's Appointment Scheduler ***\n");
    int choice;
    
    while (true) {
        printf("\n1. Add Appointment\n2. View Appointments\n3. Exit\nEnter your choice : ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                exitProgram();
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    }
    
    return 0;
}