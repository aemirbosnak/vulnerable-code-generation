//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store an appointment
typedef struct appointment {
    char name[50];
    char description[100];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} appointment;

// Array to store the appointments
appointment appointments[100];

// Number of appointments
int num_appointments = 0;

// Function to add an appointment
void add_appointment() {
    // Get the appointment details from the user
    printf("Enter the name of the person: ");
    scanf(" %[^\n]", appointments[num_appointments].name);
    printf("Enter the description of the appointment: ");
    scanf(" %[^\n]", appointments[num_appointments].description);
    printf("Enter the day of the appointment (1-31): ");
    scanf("%d", &appointments[num_appointments].day);
    printf("Enter the month of the appointment (1-12): ");
    scanf("%d", &appointments[num_appointments].month);
    printf("Enter the year of the appointment: ");
    scanf("%d", &appointments[num_appointments].year);
    printf("Enter the hour of the appointment (0-23): ");
    scanf("%d", &appointments[num_appointments].hour);
    printf("Enter the minute of the appointment (0-59): ");
    scanf("%d", &appointments[num_appointments].minute);

    // Increment the number of appointments
    num_appointments++;
}

// Function to print the appointments
void print_appointments() {
    // Loop through the appointments and print them
    for (int i = 0; i < num_appointments; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Date: %d/%d/%d\n", appointments[i].day, appointments[i].month, appointments[i].year);
        printf("Time: %d:%d\n\n", appointments[i].hour, appointments[i].minute);
    }
}

// Function to search for an appointment
void search_appointment() {
    // Get the search term from the user
    char search_term[50];
    printf("Enter the search term: ");
    scanf(" %[^\n]", search_term);

    // Loop through the appointments and search for the search term
    for (int i = 0; i < num_appointments; i++) {
        if (strstr(appointments[i].name, search_term) != NULL || strstr(appointments[i].description, search_term) != NULL) {
            // Appointment found
            printf("Appointment %d:\n", i + 1);
            printf("Name: %s\n", appointments[i].name);
            printf("Description: %s\n", appointments[i].description);
            printf("Date: %d/%d/%d\n", appointments[i].day, appointments[i].month, appointments[i].year);
            printf("Time: %d:%d\n\n", appointments[i].hour, appointments[i].minute);
        }
    }
}

// Function to delete an appointment
void delete_appointment() {
    // Get the index of the appointment to delete from the user
    int index;
    printf("Enter the index of the appointment to delete (1-%d): ", num_appointments);
    scanf("%d", &index);

    // Shift the appointments after the deleted appointment to the left
    for (int i = index - 1; i < num_appointments - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    // Decrement the number of appointments
    num_appointments--;
}

// Main function
int main() {
    // Display the menu
    int choice;
    do {
        printf("Appointment Scheduler\n");
        printf("1. Add an appointment\n");
        printf("2. Print the appointments\n");
        printf("3. Search for an appointment\n");
        printf("4. Delete an appointment\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                print_appointments();
                break;
            case 3:
                search_appointment();
                break;
            case 4:
                delete_appointment();
                break;
        }
    } while (choice != 5);

    return 0;
}