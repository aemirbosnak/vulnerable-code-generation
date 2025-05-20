//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: creative
// Welcome to the Appointment Scheduler 2000, the most advanced and user-friendly appointment scheduling system in the known universe.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments that can be stored.
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment.
typedef struct {
    char name[50];
    char date[20];
    char time[20];
    char location[50];
    char description[200];
} appointment;

// Declare an array of appointments.
appointment appointments[MAX_APPOINTMENTS];

// Declare the current number of appointments.
int num_appointments = 0;

// Print the main menu.
void print_main_menu() {
    printf("Welcome to the Appointment Scheduler 2000.\n");
    printf("Please select an option:\n");
    printf("1. Add an appointment\n");
    printf("2. View all appointments\n");
    printf("3. Edit an appointment\n");
    printf("4. Delete an appointment\n");
    printf("5. Exit\n");
}

// Get the user's input.
int get_input() {
    int input;
    scanf("%d", &input);
    return input;
}

// Add an appointment to the array.
void add_appointment() {
    // Get the appointment details from the user.
    printf("Enter the name of the appointment: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter the date of the appointment (MM/DD/YYYY): ");
    scanf("%s", appointments[num_appointments].date);
    printf("Enter the time of the appointment (HH:MM AM/PM): ");
    scanf("%s", appointments[num_appointments].time);
    printf("Enter the location of the appointment: ");
    scanf("%s", appointments[num_appointments].location);
    printf("Enter a description of the appointment: ");
    scanf("%s", appointments[num_appointments].description);

    // Increment the number of appointments.
    num_appointments++;
}

// View all appointments in the array.
void view_appointments() {
    // Check if there are any appointments.
    if (num_appointments == 0) {
        printf("There are no appointments scheduled.\n");
        return;
    }

    // Print the header.
    printf("%-20s %-20s %-20s %-20s %-20s\n", "Name", "Date", "Time", "Location", "Description");

    // Print the appointments.
    for (int i = 0; i < num_appointments; i++) {
        printf("%-20s %-20s %-20s %-20s %-20s\n", appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].location, appointments[i].description);
    }
}

// Edit an appointment in the array.
void edit_appointment() {
    // Get the index of the appointment to edit.
    int index;
    printf("Enter the index of the appointment to edit: ");
    scanf("%d", &index);

    // Check if the index is valid.
    if (index < 0 || index >= num_appointments) {
        printf("Invalid index.\n");
        return;
    }

    // Get the new appointment details from the user.
    printf("Enter the new name of the appointment: ");
    scanf("%s", appointments[index].name);
    printf("Enter the new date of the appointment (MM/DD/YYYY): ");
    scanf("%s", appointments[index].date);
    printf("Enter the new time of the appointment (HH:MM AM/PM): ");
    scanf("%s", appointments[index].time);
    printf("Enter the new location of the appointment: ");
    scanf("%s", appointments[index].location);
    printf("Enter a new description of the appointment: ");
    scanf("%s", appointments[index].description);
}

// Delete an appointment from the array.
void delete_appointment() {
    // Get the index of the appointment to delete.
    int index;
    printf("Enter the index of the appointment to delete: ");
    scanf("%d", &index);

    // Check if the index is valid.
    if (index < 0 || index >= num_appointments) {
        printf("Invalid index.\n");
        return;
    }

    // Shift the appointments after the deleted appointment to the left.
    for (int i = index; i < num_appointments - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    // Decrement the number of appointments.
    num_appointments--;
}

// Exit the program.
void exit_program() {
    printf("Thank you for using the Appointment Scheduler 2000. Goodbye!\n");
    exit(0);
}

// Main function.
int main() {
    // Print the main menu.
    print_main_menu();

    // Get the user's input.
    int input = get_input();

    // Handle the user's input.
    while (input != 5) {
        switch (input) {
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
            default:
                printf("Invalid input.\n");
        }

        // Print the main menu.
        print_main_menu();

        // Get the user's input.
        input = get_input();
    }

    // Exit the program.
    exit_program();

    return 0;
}