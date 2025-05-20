//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_APPOINTMENTS 1000

// Define structure for each appointment
typedef struct appointment {
    char name[50];
    char date[15];
    char time[10];
} appointment;

// Define array of appointments
appointment appointments[MAX_APPOINTMENTS];

// Define variables to keep track of number of appointments and appointment index
int num_appointments = 0;
int curr_appointment_idx = -1;

// Function to display menu options
void display_menu() {
    printf("\n\n");
    printf("Appointment Scheduler\n");
    printf("---------------------\n");
    printf("1. Schedule new appointment\n");
    printf("2. View next appointment\n");
    printf("3. Cancel current appointment\n");
    printf("4. Exit\n");
}

// Function to schedule a new appointment
void schedule_appointment() {
    char name[50];
    char date[15];
    char time[10];
    
    // Prompt user for appointment details
    printf("Enter name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0; // remove newline character
    
    printf("Enter date (mm/dd/yyyy): ");
    fgets(date, 15, stdin);
    date[strcspn(date, "\n")] = 0; // remove newline character
    
    printf("Enter time (hh:mm): ");
    fgets(time, 10, stdin);
    time[strcspn(time, "\n")] = 0; // remove newline character
    
    // Add appointment to array
    appointment new_appointment;
    strcpy(new_appointment.name, name);
    strcpy(new_appointment.date, date);
    strcpy(new_appointment.time, time);
    
    appointments[num_appointments++] = new_appointment;
    
    printf("Appointment scheduled successfully!\n");
}

// Function to view next appointment
void view_next_appointment() {
    if (num_appointments == 0) {
        printf("There are no appointments scheduled.\n");
        return;
    }
    
    curr_appointment_idx = (curr_appointment_idx + 1) % num_appointments;
    
    printf("Name: %s\n", appointments[curr_appointment_idx].name);
    printf("Date: %s\n", appointments[curr_appointment_idx].date);
    printf("Time: %s\n", appointments[curr_appointment_idx].time);
}

// Function to cancel current appointment
void cancel_appointment() {
    if (num_appointments == 0) {
        printf("There are no appointments scheduled.\n");
        return;
    }
    
    // Shift appointments in array to fill gap
    for (int i = curr_appointment_idx; i < num_appointments - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    
    num_appointments--;
    curr_appointment_idx = -1;
    
    printf("Appointment cancelled successfully!\n");
}

int main() {
    int choice;
    
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // catch newline character
        
        switch(choice) {
            case 1:
                schedule_appointment();
                break;
            case 2:
                view_next_appointment();
                break;
            case 3:
                cancel_appointment();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);
    
    return 0;
}