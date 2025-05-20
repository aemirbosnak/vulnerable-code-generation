//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdbool.h>

bool schedule[7][24] = {0}; // 2D array to hold the availability for each day and hour

void displayMenu() {
    printf("\n");
    printf("1. Schedule an appointment\n");
    printf("2. Cancel an appointment\n");
    printf("3. View appointments for a day\n");
    printf("4. Exit\n");
}

void scheduleAppointment() {
    int day, start, end;
    printf("Enter the day (0-6): ");
    scanf("%d", &day);
    printf("Enter the start time (0-23): ");
    scanf("%d", &start);
    printf("Enter the end time (0-23): ");
    scanf("%d", &end);
    
    // Check for availability
    bool available = true;
    for (int i = start; i <= end; i++) {
        if (schedule[day][i] == true) {
            available = false;
            break;
        }
    }
    
    // If available, schedule the appointment
    if (available) {
        for (int i = start; i <= end; i++) {
            schedule[day][i] = true;
        }
        printf("Appointment scheduled successfully!\n");
    } else {
        printf("This time slot is already booked. Please choose a different time.\n");
    }
}

void cancelAppointment() {
    int day, start, end;
    printf("Enter the day (0-6): ");
    scanf("%d", &day);
    printf("Enter the start time (0-23): ");
    scanf("%d", &start);
    printf("Enter the end time (0-23): ");
    scanf("%d", &end);
    
    // Make sure the appointment exists
    bool exists = true;
    for (int i = start; i <= end; i++) {
        if (schedule[day][i] == false) {
            exists = false;
            break;
        }
    }
    
    // If it exists, cancel it
    if (exists) {
        for (int i = start; i <= end; i++) {
            schedule[day][i] = false;
        }
        printf("Appointment cancelled successfully!\n");
    } else {
        printf("No appointment was found for this time slot.\n");
    }
}

void viewAppointments() {
    int day;
    printf("Enter the day (0-6): ");
    scanf("%d", &day);
    
    printf("Appointments for day %d:\n", day);
    for (int i = 0; i < 24; i++) {
        if (schedule[day][i] == true) {
            printf("%02d:00 - %02d:00\n", i, i+1);
        }
    }
}

int main() {
    int choice;
    while (true) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                scheduleAppointment();
                break;
            case 2:
                cancelAppointment();
                break;
            case 3:
                viewAppointments();
                break;
            case 4:
                printf("Thank you for using the appointment scheduler!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}