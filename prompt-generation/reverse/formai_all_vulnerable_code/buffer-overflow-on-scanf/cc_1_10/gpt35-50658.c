//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define structure for appointment */
typedef struct appointment {
    char date[20];
    char time[20];
    char name[50];
    char phone[20];
} Appointment;

/* Define structure for schedule */
typedef struct schedule {
    Appointment appointments[100]; // Maximum 100 appointments
    int num_appointments;
} Schedule;

/* Function to add appointment */
void add_appointment(Schedule *schedule) {
    /* Check if max number of appointments reached */
    if (schedule->num_appointments >= 100) {
        printf("Sorry, maximum number of appointments reached.\n");
        return;
    }
    
    /* Get appointment details */
    Appointment appointment;
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%s", appointment.date);
    printf("Enter time (HH:MM): ");
    scanf("%s", appointment.time);
    printf("Enter name: ");
    scanf("%s", appointment.name);
    printf("Enter phone number: ");
    scanf("%s", appointment.phone);
    
    /* Add appointment to schedule */
    schedule->appointments[schedule->num_appointments++] = appointment;
    
    printf("Appointment added successfully!\n");
}

/* Function to display appointments */
void display_appointments(Schedule *schedule) {
    if (schedule->num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("Date\tTime\tName\tPhone\n");
    for (int i = 0; i < schedule->num_appointments; i++) {
        printf("%s\t%s\t%s\t%s\n", schedule->appointments[i].date, 
                                    schedule->appointments[i].time,
                                    schedule->appointments[i].name,
                                    schedule->appointments[i].phone);
    }
}

int main() {
    /* Create empty schedule */
    Schedule schedule;
    schedule.num_appointments = 0;
    
    /* Display menu and get user choice */
    int choice;
    while (choice != 3) {
        printf("Appointment Scheduler\n");
        printf("----------------------\n");
        printf("1. Add Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_appointment(&schedule);
                break;
            case 2:
                display_appointments(&schedule);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}