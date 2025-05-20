//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

// Structure for appointment date and time
struct appointment {
    int day;
    int month;
    int year;
    int hour; // 24 hour format
    int minute;
};

// Function to display the appointment details
void displayAppointment(struct appointment apt) {
    printf("\nYour appointment is scheduled on:\nDate: %d/%d/%d\nTime: %d:%d", apt.day, apt.month, apt.year, apt.hour, apt.minute);
}

// Recursive function to book an appointment
void bookAppointment() {
    // Initialize appointment details
    struct appointment apt;
    apt.day = 0;
    apt.month = 0;
    apt.year = 0;
    apt.hour = 0;
    apt.minute = 0;

    // Get appointment details from user
    printf("\nEnter date in DD/MM/YYYY format: ");
    scanf("%d/%d/%d", &apt.day, &apt.month, &apt.year);
    printf("Enter time in HH:MM format (24-hour): ");
    scanf("%d:%d", &apt.hour, &apt.minute);

    // Check if the appointment date is valid
    if ((apt.month == 4 || apt.month == 6 || apt.month == 9 || apt.month == 11) && apt.day > 30) {
        printf("\nInvalid date! Please enter a valid date.\n");
        bookAppointment(); // Recursive call to bookAppointment function
    }
    else if (apt.month == 2) {
        // Check for leap year
        if ((apt.year % 4 == 0 && apt.year % 100 != 0) || apt.year % 400 == 0) {
            if (apt.day > 29) {
                printf("\nInvalid date! Please enter a valid date.\n");
                bookAppointment(); // Recursive call to bookAppointment function
            }
        }
        else {
            if (apt.day > 28) {
                printf("\nInvalid date! Please enter a valid date.\n");
                bookAppointment(); // Recursive call to bookAppointment function
            }
        }
    }
    else if (apt.day > 31) {
        printf("\nInvalid date! Please enter a valid date.\n");
        bookAppointment(); // Recursive call to bookAppointment function
    }

    // Check if the appointment time is valid
    if (apt.hour < 0 || apt.hour > 23 || apt.minute < 0 || apt.minute > 59) {
        printf("\nInvalid time! Please enter a valid time.\n");
        bookAppointment(); // Recursive call to bookAppointment function
    }

    // Display the appointment details
    displayAppointment(apt);
}

// Main function
int main() {
    printf("Welcome to the appointment scheduler!\n");

    // Book an appointment recursively
    bookAppointment();
    
    return 0;
}