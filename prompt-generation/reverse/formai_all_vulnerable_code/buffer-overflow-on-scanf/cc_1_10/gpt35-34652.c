//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size of name and appointment time
#define MAX_NAME_SIZE 50
#define MAX_TIME_SIZE 10

// Define struct for appointments
typedef struct {
    char name[MAX_NAME_SIZE];
    char time[MAX_TIME_SIZE];
} Appointment;

// Define function to print menu options
void print_menu() {
    printf("\nMenu Options:\n");
    printf("1. Schedule Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Cancel Appointment\n");
    printf("4. Exit\n");
}

// Define function to schedule new appointment
void schedule(Appointment *appts, int *num_appts) {
    // Check if there are already maximum number of appointments
    if (*num_appts == 10) {
        printf("\nSorry, there are no available appointment slots.\n");
    } else {
        printf("\nEnter patient name: ");
        char name[MAX_NAME_SIZE];
        scanf("%s", name);
        
        printf("Enter appointment time: ");
        char time[MAX_TIME_SIZE];
        scanf("%s", time);
        
        // Create new appointment and add to appointment array
        Appointment new_appt = {0};
        strcpy(new_appt.name, name);
        strcpy(new_appt.time, time);
        appts[*num_appts] = new_appt;
        (*num_appts)++;
        
        printf("\nAppointment scheduled for %s at %s.\n", name, time);
    }
}

// Define function to view all appointments
void view_appts(Appointment *appts, int num_appts) {
    // Check if there are any appointments
    if (num_appts == 0) {
        printf("\nThere are no appointments scheduled.\n");
    } else {
        printf("\nAppointments:\n");
        for (int i = 0; i < num_appts; i++) {
            printf("%s - %s\n", appts[i].name, appts[i].time);
        }
    }
}

// Define function to cancel appointment
void cancel_appt(Appointment *appts, int *num_appts) {
    // Check if there are any appointments
    if (*num_appts == 0) {
        printf("\nThere are no appointments scheduled to cancel.\n");
    } else {
        printf("\nEnter appointment time to cancel: ");
        char time[MAX_TIME_SIZE];
        scanf("%s", time);
        
        int found_appt = 0;
        for (int i = 0; i < *num_appts; i++) {
            if (strcmp(appts[i].time, time) == 0) {
                found_appt = 1;
                
                printf("\nAppointment for %s at %s has been cancelled.\n", appts[i].name, appts[i].time);
                
                // Remove appointment from array
                for (int j = i; j < *num_appts - 1; j++) {
                    appts[j] = appts[j + 1];
                }
                (*num_appts)--;
                
                break;
            }
        }
        
        if (!found_appt) {
            printf("\nAppointment not found.\n");
        }
    }
}

int main() {
    // Define array to store appointments and number of appointments
    Appointment appts[10] = {0};
    int num_appts = 0;
    
    // Print welcome message and menu
    printf("Welcome to the Appointment Scheduler!\n");
    print_menu();
    
    // Loop for user input until exit
    int choice = 0;
    while (choice != 4) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                schedule(appts, &num_appts);
                break;
            case 2:
                view_appts(appts, num_appts);
                break;
            case 3:
                cancel_appt(appts, &num_appts);
                break;
            case 4:
                printf("\nThank you for using the Appointment Scheduler!\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
                break;
        }
        
        // Print menu after each option
        if (choice != 4) {
            print_menu();
        }
    }
    
    return 0;
}