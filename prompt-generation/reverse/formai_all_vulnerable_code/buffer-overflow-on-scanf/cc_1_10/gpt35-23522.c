//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for appointment
struct Appointment {
    char date[20];
    char time[10];
    char name[50];
    char description[100];
};

// Define function to create new appointment
void createAppointment(struct Appointment *apt) {
    printf("Enter date of appointment (MM/DD/YYYY): ");
    scanf("%s", apt->date);
    printf("Enter time of appointment (HH:MM AM/PM): ");
    scanf("%s", apt->time);
    printf("Enter name of appointment: ");
    scanf(" %[^\n]", apt->name);
    printf("Enter description of appointment: ");
    scanf(" %[^\n]", apt->description);
}

// Define function to view appointment
void viewAppointment(struct Appointment apt) {
    printf("Appointment Date: %s\n", apt.date);
    printf("Appointment Time: %s\n", apt.time);
    printf("Appointment Name: %s\n", apt.name);
    printf("Appointment Description: %s\n", apt.description);
}

// Define function to delete appointment
void deleteAppointment(struct Appointment *apt) {
    strcpy(apt->date, "");
    strcpy(apt->time, "");
    strcpy(apt->name, "");
    strcpy(apt->description, "");
}

int main() {
    // Declare variables
    int choice = 0;
    struct Appointment apt;
    
    // Loop through menu until user exits
    while(choice != 4) {
        // Display menu
        printf("\n----------------------------------\n");
        printf("Appointment Scheduler Program\n");
        printf("----------------------------------\n");
        printf("1. Create Appointment\n");
        printf("2. View Appointment\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("----------------------------------\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        // Clear screen
        system("cls");
        
        // Perform action based on user choice
        switch(choice) {
            // Create new appointment
            case 1:
                createAppointment(&apt);
                printf("\nAppointment Created!\n");
                break;
            // View appointment
            case 2:
                if(strcmp(apt.date, "") != 0) {
                    printf("\nAppointment Details\n");
                    printf("----------------------------------\n");
                    viewAppointment(apt);
                }
                else {
                    printf("\nNo Appointment Found!\n");
                }
                break;
            // Delete appointment
            case 3:
                if(strcmp(apt.date, "") != 0) {
                    deleteAppointment(&apt);
                    printf("\nAppointment Deleted!\n");
                }
                else {
                    printf("\nNo Appointment Found!\n");
                }
                break;
            // Exit program
            case 4:
                printf("\nExiting Program!\n");
                break;
            // Invalid choice entered
            default:
                printf("\nInvalid Choice! Please Enter Again.\n");
                break;
        }
    }
    
    return 0;
}