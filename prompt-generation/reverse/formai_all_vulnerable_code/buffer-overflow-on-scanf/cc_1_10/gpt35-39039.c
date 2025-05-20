//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Data Structure to hold an appointment information
typedef struct appointment {
    char patient_name[50];
    char doctor_name[50];
    char date[12];
} Appointment;

// Function to get appointment details from the user
void createAppointment(Appointment *new_appointment) {
    printf("\nEnter Patient Name: ");
    scanf("%[^\n]%*c", new_appointment->patient_name);
    printf("Enter Doctor Name: ");
    scanf("%[^\n]%*c", new_appointment->doctor_name);
    printf("Enter Appointment Date (dd-mm-yyyy): ");
    scanf("%s", new_appointment->date);
}

// Function to display appointment details
void displayAppointment(Appointment appointment) {
    printf("\n===================================\n");
    printf("Patient Name: %s\n", appointment.patient_name);
    printf("Doctor Name: %s\n", appointment.doctor_name);
    printf("Appointment Date: %s\n", appointment.date);
    printf("===================================\n");
}

int main() {
    int max_appointments;
    printf("Enter Maximum Number of Appointments: ");
    scanf("%d", &max_appointments);
    
    Appointment *appointments = (Appointment *) malloc(max_appointments * sizeof(Appointment));
    int num_appointments = 0;
    
    int option;
    do {
        printf("\n\n===== Appointment Scheduler =====\n");
        printf("1. Schedule an Appointment\n");
        printf("2. View All Appointments\n");
        printf("3. Exit\n");
        printf("Select Option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                if (num_appointments >= max_appointments) {
                    printf("\nMaximum Appointments Reached!\n");
                }
                else {
                    createAppointment(&appointments[num_appointments]);
                    num_appointments++;
                    printf("\nAppointment Scheduled Successfully.\n");
                }
                break;
            case 2:
                if (num_appointments == 0) {
                    printf("\nNo Appointments Scheduled Yet!\n");
                }
                else {
                    printf("\nAll Appointments:\n");
                    for (int i = 0; i < num_appointments; i++) {
                        displayAppointment(appointments[i]);
                    }
                }
                break;
            case 3:
                printf("\nExiting Program...\n");
                break;
            default:
                printf("\nInvalid Option Selected!\n");
                break;
        }
    } while (option != 3);
    
    // Free Memory Allocated
    free(appointments);
    
    return 0;
}