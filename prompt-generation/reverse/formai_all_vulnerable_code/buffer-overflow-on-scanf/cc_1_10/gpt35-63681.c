//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 50 // Maximum number of appointments that can be stored

struct appointment {
    char name[20];
    char date[10];
    char time[5];
};

struct appointment scheduler[MAX_APPOINTMENTS]; // Array of appointments

int num_appointments = 0; // Counter of currently scheduled appointments

void schedule_appointment() {
    if(num_appointments < MAX_APPOINTMENTS) { // Check if there is space for new appointments
        struct appointment new_appointment;
        printf("Enter name: ");
        scanf("%s", new_appointment.name);
        printf("Enter date (dd/mm): ");
        scanf("%s", new_appointment.date);
        printf("Enter time (hh:mm): ");
        scanf("%s", new_appointment.time);
        scheduler[num_appointments] = new_appointment;
        num_appointments++;
        printf("Appointment scheduled successfully!\n");
    } else {
        printf("Cannot schedule appointment. Maximum number of appointments reached.\n");
    }
}

void cancel_appointment() {
    if(num_appointments > 0) { // Check if there are appointments to cancel
        char name_to_cancel[20];
        printf("Enter name of appointment to cancel: ");
        scanf("%s", name_to_cancel);
        int i;
        for(i = 0; i < num_appointments; i++) {
            if(strcmp(name_to_cancel, scheduler[i].name) == 0) { // Check if names match
                scheduler[i] = scheduler[num_appointments-1];
                num_appointments--;
                printf("Appointment cancelled successfully!\n");
                return;
            }
        }
        printf("Appointment not found.\n");
    } else {
        printf("Cannot cancel appointment. No appointments scheduled.\n");
    }
}

void list_appointments() {
    if(num_appointments > 0) { // Check if there are appointments to list
        printf("Scheduled Appointments:\n");
        int i;
        for(i = 0; i < num_appointments; i++) {
            printf("%d. %s - %s %s\n", i+1, scheduler[i].name, scheduler[i].date, scheduler[i].time);
        }
    } else {
        printf("No appointments scheduled.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nAppointment Scheduler\n");
        printf("1. Schedule Appointment\n");
        printf("2. Cancel Appointment\n");
        printf("3. List Appointments\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                schedule_appointment();
                break;
            case 2:
                cancel_appointment();
                break;
            case 3:
                list_appointments();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while(1);
    return 0;
}