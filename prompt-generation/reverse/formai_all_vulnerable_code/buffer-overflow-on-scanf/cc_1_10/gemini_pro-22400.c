//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of appointments that can be scheduled
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct appointment {
    char name[50];
    char date[11];
    char time[6];
    char description[100];
} appointment;

// Define the array of appointments
appointment appointments[MAX_APPOINTMENTS];

// Initialize the number of appointments to 0
int num_appointments = 0;

// Function to add an appointment to the array
void add_appointment() {
    // Get the appointment details from the user
    printf("Enter the name of the person you are scheduling an appointment for: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter the date of the appointment (YYYY-MM-DD): ");
    scanf("%s", appointments[num_appointments].date);

    printf("Enter the time of the appointment (HH:MM): ");
    scanf("%s", appointments[num_appointments].time);

    printf("Enter a brief description of the appointment: ");
    scanf(" %[^\n]s", appointments[num_appointments].description);

    // Increment the number of appointments
    num_appointments++;
}

// Function to print the appointments in the array
void print_appointments() {
    // Iterate over the appointments and print the details
    for (int i = 0; i < num_appointments; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("Description: %s\n\n", appointments[i].description);
    }
}

// Function to search for an appointment by name
void search_appointment() {
    // Get the name of the person to search for
    char name[50];
    printf("Enter the name of the person you are searching for: ");
    scanf("%s", name);

    // Iterate over the appointments and search for the name
    int found = 0;
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            // Print the appointment details
            printf("Appointment found:\n");
            printf("Name: %s\n", appointments[i].name);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("Description: %s\n\n", appointments[i].description);
            found = 1;
            break;
        }
    }

    // If the name was not found, print an error message
    if (!found) {
        printf("No appointment found for %s.\n", name);
    }
}

// Function to delete an appointment by name
void delete_appointment() {
    // Get the name of the person to delete
    char name[50];
    printf("Enter the name of the person whose appointment you want to delete: ");
    scanf("%s", name);

    // Iterate over the appointments and search for the name
    int found = 0;
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            // Delete the appointment
            for (int j = i + 1; j < num_appointments; j++) {
                appointments[j - 1] = appointments[j];
            }
            num_appointments--;
            found = 1;
            break;
        }
    }

    // If the name was not found, print an error message
    if (!found) {
        printf("No appointment found for %s.\n", name);
    }
}

// Function to sort the appointments by date and time
void sort_appointments() {
    // Iterate over the appointments and sort them by date and time
    for (int i = 0; i < num_appointments - 1; i++) {
        for (int j = i + 1; j < num_appointments; j++) {
            if (strcmp(appointments[i].date, appointments[j].date) > 0) {
                appointment temp = appointments[i];
                appointments[i] = appointments[j];
                appointments[j] = temp;
            } else if (strcmp(appointments[i].date, appointments[j].date) == 0) {
                if (strcmp(appointments[i].time, appointments[j].time) > 0) {
                    appointment temp = appointments[i];
                    appointments[i] = appointments[j];
                    appointments[j] = temp;
                }
            }
        }
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Add some sample appointments to the array
    add_appointment("John Smith", "2023-03-08", "10:00", "Meeting with the boss");
    add_appointment("Jane Doe", "2023-03-10", "11:00", "Doctor's appointment");
    add_appointment("Michael Jones", "2023-03-12", "12:00", "Lunch with a friend");

    // Print the appointments
    printf("Current appointments:\n");
    print_appointments();

    // Search for an appointment
    search_appointment();

    // Delete an appointment
    delete_appointment();

    // Sort the appointments
    sort_appointments();

    // Print the sorted appointments
    printf("Sorted appointments:\n");
    print_appointments();

    return 0;
}