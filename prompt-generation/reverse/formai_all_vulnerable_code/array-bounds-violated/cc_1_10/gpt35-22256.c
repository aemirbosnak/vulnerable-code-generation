//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for appointment
struct Appointment {
    char name[30];
    char phone[15];
    int month;
    int day;
    int hour;
};

// Define function to check if input month is valid
int is_valid_month(int month) {
    return (month >= 1 && month <= 12);
}

// Define function to check if input day is valid
int is_valid_day(int day, int month) {
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && (day >= 1 && day <= 29)) {
        return 1;
    } else if (day >= 1 && day <= days_in_month[month - 1]) {
        return 1;
    } else {
        return 0;
    }
}

// Define function to check if input hour is valid
int is_valid_hour(int hour) {
    return (hour >= 9 && hour <= 17);
}

int main(void)
{
    // Initialize array of appointments
    struct Appointment appointments[10];
    int num_appointments = 0;
    
    while (1) {
        // Menu options
        printf("\nEnter 'q' to quit the program.\n");
        printf("Enter 'a' to add an appointment.\n");
        printf("Enter 'v' to view all appointments.\n");
        printf("Enter your choice: ");
    
        char choice;
        scanf(" %c", &choice);
        
        // Quit program if 'q' is entered
        if (choice == 'q') {
            printf("Goodbye!\n");
            break;
        }
        
        // Add appointment if 'a' is entered
        else if (choice == 'a') {
            // Check if there is space for another appointment
            if (num_appointments >= 10) {
                printf("Sorry, there is no space for another appointment.\n");
                continue;
            }
            
            // Get appointment details from user input
            struct Appointment new_appointment;
            printf("Enter name: ");
            scanf("%s", new_appointment.name);
            
            printf("Enter phone number: ");
            scanf("%s", new_appointment.phone);
            
            printf("Enter month (1-12): ");
            scanf("%d", &new_appointment.month);
            if (!is_valid_month(new_appointment.month)) {
                printf("Invalid month entered.\n");
                continue;
            }
            
            printf("Enter day: ");
            scanf("%d", &new_appointment.day);
            if (!is_valid_day(new_appointment.day, new_appointment.month)) {
                printf("Invalid day entered.\n");
                continue;
            }
            
            printf("Enter hour (9-17): ");
            scanf("%d", &new_appointment.hour);
            if (!is_valid_hour(new_appointment.hour)) {
                printf("Invalid hour entered.\n");
                continue;
            }
            
            // Add new appointment to array and update number of appointments
            appointments[num_appointments++] = new_appointment;
    
            printf("Appointment added.\n");
        }
        
        // View all appointments if 'v' is entered
        else if (choice == 'v') {
            printf("\nAppointments:\n");
            for (int i = 0; i < num_appointments; i++) {
                printf("- %s (%s) on %d/%d at %d:00\n", appointments[i].name, appointments[i].phone, appointments[i].month, appointments[i].day, appointments[i].hour);
            }
            if (num_appointments == 0) {
                printf("There are no appointments.\n");
            }
        }
        
        // Invalid input
        else {
            printf("Invalid choice entered.\n");
        }
    }

    return 0;
}