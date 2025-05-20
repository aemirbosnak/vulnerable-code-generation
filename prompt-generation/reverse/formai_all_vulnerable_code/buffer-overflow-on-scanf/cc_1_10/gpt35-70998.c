//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for appointments
struct Appointment {
    char date[11];
    char time[6];
    char name[50];
    char description[100];
};

// Define the array of possible appointment times
char *times[11] = {"09:00", "09:30", "10:00", "10:30", "11:00", "11:30", "12:00", "12:30", "01:00", "01:30", "02:00"};

// Define the function for getting appointment details from user
void getAppointmentDetails(struct Appointment *appt) {
    printf("Enter date (in mm/dd/yyyy format): ");
    scanf("%s", appt->date);
    printf("Enter time (in hh:mm format): ");
    scanf("%s", appt->time);
    printf("Enter name: ");
    scanf("%s", appt->name);
    printf("Enter description: ");
    scanf("%s", appt->description);
}

// Define the function for displaying appointment details
void displayAppointmentDetails(struct Appointment appt) {
    printf("Appointment Details:\n");
    printf("Date: %s\n", appt.date);
    printf("Time: %s\n", appt.time);
    printf("Name: %s\n", appt.name);
    printf("Description: %s\n", appt.description);
}

int main() {
    struct Appointment appointments[10]; // Array of appointments
    int appointmentIndex = 0; // Index of the next available appointment slot
    char selectedTime[6]; // Variable to hold the user selected time slot
    
    // Loop through each time and display it to the user
    for (int i = 0; i < sizeof(times) / sizeof(times[0]); i++) { 
        printf("%d. %s\n", i+1, times[i]);
    }
    
    // Get the user to select a time slot
    printf("Enter the number for the desired time slot: ");
    int selection;
    scanf("%d", &selection);

    // Verify the selection is valid
    if (selection < 1 || selection > sizeof(times) / sizeof(times[0])) {
        printf("Invalid selection\n");
        return 0;
    }
    
    // Copy the selected time slot into the selectedTime variable
    strcpy(selectedTime, times[selection-1]);
    
    // Get details for the appointment at the selected time slot
    struct Appointment newAppointment;
    getAppointmentDetails(&newAppointment);
    strcpy(newAppointment.time, selectedTime);
    
    // Add the appointment to the appointments array
    appointments[appointmentIndex] = newAppointment;
    appointmentIndex++;
    
    // Display the appointment details to the user
    displayAppointmentDetails(newAppointment);
    
    return 0;
}