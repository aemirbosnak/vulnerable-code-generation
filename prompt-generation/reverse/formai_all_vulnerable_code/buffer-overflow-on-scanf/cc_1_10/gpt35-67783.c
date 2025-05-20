//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define structs and constants
#define MAX_APPOINTMENTS 50
#define MAX_NAME_LENGTH 20

typedef struct {
    int hour;
    int minute;
} Time;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Time time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

// Function declarations
bool add_appointment(char name[], int hour, int minute);
bool remove_appointment(char name[]);
bool list_appointments();
bool search_appointment(char name[], Time time);

// Main function
int main() {
    char choice;
    char name[MAX_NAME_LENGTH];
    int hour, minute;
    
    // Seed random number generator for generating appointments
    srand(time(NULL));
    
    // Print welcome message
    printf("Welcome to the Appointment Scheduler!\n\n");
    
    // Loop until user chooses to exit
    while (true) {
        // Prompt user for action
        printf("What would you like to do?\n");
        printf("\ta) Add an appointment\n");
        printf("\tr) Remove an appointment\n");
        printf("\tl) List all appointments\n");
        printf("\ts) Search for an appointment\n");
        printf("\tq) Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        // Process user's choice
        switch (choice) {
            case 'a':
                // Prompt user for appointment details
                printf("\nEnter the name for the appointment: ");
                scanf("%s", name);
                printf("Enter the hour for the appointment (0-23): ");
                scanf("%d", &hour);
                printf("Enter the minute for the appointment (0-59): ");
                scanf("%d", &minute);
                
                // Add appointment to schedule
                if (add_appointment(name, hour, minute)) {
                    printf("\nAppointment added!\n");
                } else {
                    printf("\nError: Appointment could not be added.\n");
                }
                break;
            case 'r':
                // Prompt user for appointment name to remove
                printf("\nEnter the name of the appointment to remove: ");
                scanf("%s", name);
                
                // Remove appointment from schedule
                if (remove_appointment(name)) {
                    printf("\nAppointment removed!\n");
                } else {
                    printf("\nError: Appointment not found.\n");
                }
                break;
            case 'l':
                // List all appointments
                list_appointments();
                break;
            case 's':
                // Prompt user for appointment details to search for
                printf("\nEnter the name for the appointment: ");
                scanf("%s", name);
                printf("Enter the hour for the appointment (0-23): ");
                scanf("%d", &hour);
                printf("Enter the minute for the appointment (0-59): ");
                scanf("%d", &minute);
                
                // Search for appointment
                if (search_appointment(name, (Time){hour, minute})) {
                    printf("\nAppointment found!\n");
                } else {
                    printf("\nAppointment not found.\n");
                }
                break;
            case 'q':
                // Quit the program
                printf("\nGoodbye!\n");
                return 0;
            default:
                // Invalid input, ask again
                printf("\nInvalid choice, please try again.\n");
        }
        
        // Print a random appointment advertisement
        printf("\nHere is a random appointment you can schedule: %s at %02d:%02d.\n\n", 
                appointments[rand() % num_appointments].name, 
                appointments[rand() % num_appointments].time.hour, 
                appointments[rand() % num_appointments].time.minute);
    }
}

// Function implementations
bool add_appointment(char name[], int hour, int minute) {
    // Check if there is space for the appointment
    if (num_appointments >= MAX_APPOINTMENTS) {
        return false;
    }
    
    // Create the appointment
    Appointment appointment = {
        .time = {hour, minute}
    };
    strncpy(appointment.name, name, MAX_NAME_LENGTH);
    appointment.name[MAX_NAME_LENGTH - 1] = '\0';
    
    // Insert the appointment into the schedule in order of time
    int i;
    for (i = num_appointments - 1; i >= 0; i--) {
        if (appointment.time.hour < appointments[i].time.hour ||
            (appointment.time.hour == appointments[i].time.hour && appointment.time.minute < appointments[i].time.minute)) {
            appointments[i + 1] = appointments[i];
        } else {
            break;
        }
    }
    appointments[i + 1] = appointment;
    num_appointments++;
    
    return true;
}

bool remove_appointment(char name[]) {
    int i;
    for (i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            // Remove appointment by shifting subsequent appointments left
            for (int j = i; j < num_appointments - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            num_appointments--;
            return true;
        }
    }
    return false;
}

bool list_appointments() {
    if (num_appointments == 0) {
        printf("\nNo appointments scheduled.\n");
    } else {
        printf("\nAppointments:\n");
        for (int i = 0; i < num_appointments; i++) {
            printf("%s at %02d:%02d\n", appointments[i].name, appointments[i].time.hour, appointments[i].time.minute);
        }
    }
    return true;
}

bool search_appointment(char name[], Time time) {
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0 && appointments[i].time.hour == time.hour && appointments[i].time.minute == time.minute) {
            return true;
        }
    }
    return false;
}