//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include <stdio.h>

// Define the maximum number of appointments possible
#define MAX_APPOINTMENTS 10

// Define the data type for an appointment
typedef struct {
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

// Define a function to display an appointment
void displayAppointment(Appointment appointment) {
    printf("\nAppointment Details\n");
    printf("Date: %d/%d/%d\n", appointment.day, appointment.month, appointment.year);
    printf("Time: %02d:%02d\n", appointment.hour, appointment.minute);
}

int main() {
    // Declare an array to store appointments
    Appointment appointments[MAX_APPOINTMENTS];
    
    // Define variables to store user input
    int day, month, year, hour, minute;
    int numAppointments = 0;
    
    // Ask the user to enter appointments until the maximum is reached
    while (numAppointments < MAX_APPOINTMENTS) {
        printf("Enter appointment details: \n");
        printf("Day (1-31): ");
        scanf("%d", &day);
        
        printf("Month (1-12): ");
        scanf("%d", &month);
        
        printf("Year: ");
        scanf("%d", &year);
        
        printf("Hour (0-23): ");
        scanf("%d", &hour);
        
        printf("Minute (0-59): ");
        scanf("%d", &minute);
        
        // Create a new appointment and add it to the array
        Appointment appointment = {day, month, year, hour, minute};
        appointments[numAppointments] = appointment;
        numAppointments++;
        
        printf("Appointment added successfully!\n");
        displayAppointment(appointment);
        
        // Ask the user if they want to add another appointment
        char response;
        printf("Do you want to add another appointment? (y/n)\n");
        scanf(" %c", &response);
        
        // End the loop if the user says no
        if (response == 'n' || response == 'N') {
            break;
        }
    }
    
    // Display all of the appointments that were entered
    printf("\nAll Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        displayAppointment(appointments[i]);
    }
    
    return 0;
}