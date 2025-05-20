//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Appointment structure
typedef struct Appointment {
    char name[50];
    char date[11];
    char time[6];
    char reason[100];
} Appointment;

// Appointment list
Appointment appointments[100];

// Appointment count
int appointment_count = 0;

// Function to add an appointment
void add_appointment() {
    // Get appointment details
    printf("Yay! Let's schedule an appointment!\n");
    printf("Name: ");
    scanf("%s", appointments[appointment_count].name);
    printf("Date (YYYY-MM-DD): ");
    scanf("%s", appointments[appointment_count].date);
    printf("Time (HH:MM): ");
    scanf("%s", appointments[appointment_count].time);
    printf("Reason: ");
    scanf(" %[^\n]%*c", appointments[appointment_count].reason);

    // Increment appointment count
    appointment_count++;
}

// Function to view appointments
void view_appointments() {
    // Check if there are any appointments
    if (appointment_count == 0) {
        printf("Oops! No appointments to show. Let's schedule one!\n");
        return;
    }

    // Print appointment details
    printf("Here's your list of appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. Name: %s\n", i + 1, appointments[i].name);
        printf("    Date: %s\n", appointments[i].date);
        printf("    Time: %s\n", appointments[i].time);
        printf("    Reason: %s\n\n", appointments[i].reason);
    }
}

// Function to edit an appointment
void edit_appointment() {
    // Get appointment number
    int appointment_number;
    printf("Which appointment do you want to edit? (Enter its number): ");
    scanf("%d", &appointment_number);

    // Check if appointment number is valid
    if (appointment_number < 1 || appointment_number > appointment_count) {
        printf("Oops! Invalid appointment number. Try again!\n");
        return;
    }

    // Get updated appointment details
    printf("Name: ");
    scanf("%s", appointments[appointment_number - 1].name);
    printf("Date (YYYY-MM-DD): ");
    scanf("%s", appointments[appointment_number - 1].date);
    printf("Time (HH:MM): ");
    scanf("%s", appointments[appointment_number - 1].time);
    printf("Reason: ");
    scanf(" %[^\n]%*c", appointments[appointment_number - 1].reason);
}

// Function to delete an appointment
void delete_appointment() {
    // Get appointment number
    int appointment_number;
    printf("Which appointment do you want to delete? (Enter its number): ");
    scanf("%d", &appointment_number);

    // Check if appointment number is valid
    if (appointment_number < 1 || appointment_number > appointment_count) {
        printf("Oops! Invalid appointment number. Try again!\n");
        return;
    }

    // Shift appointments after the deleted appointment
    for (int i = appointment_number - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    // Decrement appointment count
    appointment_count--;
}

// Main function
int main() {
    // Welcome message
    printf("Welcome to the Appointment Scheduler! Let's get you organized!\n\n");

    // Menu options
    int choice;
    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add an appointment\n");
        printf("2. View appointments\n");
        printf("3. Edit an appointment\n");
        printf("4. Delete an appointment\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle menu options
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                edit_appointment();
                break;
            case 4:
                delete_appointment();
                break;
            case 5:
                printf("Thanks for using the Appointment Scheduler! See you soon!\n");
                return 0;
            default:
                printf("Oops! Invalid choice. Please try again.\n");
        }
    }

    return 0;
}