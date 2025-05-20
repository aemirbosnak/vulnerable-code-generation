//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define maximum number of appointments
#define MAX_APPOINTMENTS 50

// Define appointment structure
struct Appointment {
    char name[50];
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

// Declare global array of Appointments
struct Appointment appointments[MAX_APPOINTMENTS];

// Declare global counter for number of Appointments
int numAppointments = 0;

// Function to display main menu
void displayMenu() {
    printf("\n----------------------------------------------\n");
    printf("      Welcome to Appointment Scheduler\n");
    printf("----------------------------------------------\n");
    printf("1. Add Appointment\n");
    printf("2. View All Appointments\n");
    printf("3. Search for an Appointment\n");
    printf("4. Delete an Appointment\n");
    printf("5. Exit\n");
}

// Function to add new appointment
void addAppointment() {
    // Check if maximum number of appointments has been reached
    if (numAppointments == MAX_APPOINTMENTS) {
        printf("Maximum appointments reached!\n");
        return;
    }
    
    // Prompt user to enter appointment details
    printf("Enter appointment details:\n");
    printf("Name: ");
    fgets(appointments[numAppointments].name, 50, stdin);
    appointments[numAppointments].name[strcspn(appointments[numAppointments].name, "\n")] = 0; // Remove newline character
    printf("Date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &appointments[numAppointments].day, &appointments[numAppointments].month, &appointments[numAppointments].year);
    printf("Time (hh:mm): ");
    scanf("%d:%d", &appointments[numAppointments].hour, &appointments[numAppointments].minute);
    getchar(); // Consume newline character
    
    // Increment number of appointments
    numAppointments++;
    
    printf("Appointment added successfully!\n");
}

// Function to view all appointments
void viewAllAppointments() {
    // Check if there are no appointments
    if (numAppointments == 0) {
        printf("No appointments found!\n");
        return;
    }
    
    // Print table header
    printf("\n%-20s %-15s %-12s %s\n", "Name", "Date", "Time", "ID");
    
    // Loop through appointments and print details
    for (int i = 0; i < numAppointments; i++) {
        printf("%-20s %02d/%02d/%d %02d:%02d %02d\n", appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].hour, appointments[i].minute, i);
    }
}

// Function to search for an appointment
void searchAppointment() {
    // Check if there are no appointments
    if (numAppointments == 0) {
        printf("No appointments found!\n");
        return;
    }
    
    // Prompt user to enter search term
    char searchTerm[50];
    printf("Enter search term: ");
    fgets(searchTerm, 50, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline character
    
    // Print table header
    printf("\n%-20s %-15s %-12s %s\n", "Name", "Date", "Time", "ID");
    
    // Loop through appointments and print details if search term is found
    bool found = false;
    for (int i = 0; i < numAppointments; i++) {
        if (strstr(appointments[i].name, searchTerm) != NULL) {
            printf("%-20s %02d/%02d/%d %02d:%02d %02d\n", appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].hour, appointments[i].minute, i);
            found = true;
        }
    }
    
    // If search term was not found, display message
    if (!found) {
        printf("No matching appointments found!\n");
    }
}

// Function to delete an appointment
void deleteAppointment() {
    // Check if there are no appointments
    if (numAppointments == 0) {
        printf("No appointments found!\n");
        return;
    }
    
    // Prompt user to enter appointment ID to delete
    int id;
    printf("Enter ID of appointment to delete: ");
    scanf("%d", &id);
    getchar(); // Consume newline character
    
    // Check if appointment ID is valid
    if (id < 0 || id >= numAppointments) {
        printf("Invalid appointment ID!\n");
        return;
    }
    
    // Shift appointments to left to fill deleted appointment
    for (int i = id; i < numAppointments - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    
    // Decrement number of appointments
    numAppointments--;
    
    printf("Appointment deleted successfully!\n");
}

int main() {
    // Declare variables for menu selection and program loop
    int selection;
    bool running = true;
    
    // Display menu and prompt user for selection until they choose to exit
    while (running) {
        displayMenu();
        printf("Enter selection: ");
        scanf("%d", &selection);
        getchar(); // Consume newline character
        
        switch (selection) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAllAppointments();
                break;
            case 3:
                searchAppointment();
                break;
            case 4:
                deleteAppointment();
                break;
            case 5:
                running = false;
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid selection!\n");
                break;
        }
    }
    
    return 0;
}