//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 10

// Appointment struct
typedef struct {
    int day;
    int month;
    int year;
    int hour;
    int minute;
    char description[100];
} Appointment;

int main() {
    // Initialize appointment array
    Appointment appointments[MAX_APPOINTMENTS];

    // Initialize count variable
    int count = 0;

    // Menu loop variable
    int choice = 0;

    // Loop until user chooses to exit
    while (choice != 4) {
        // Print main menu
        printf("Appointment Scheduler Menu\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");

        // Get user choice
        printf("Choose an option: ");
        scanf("%d", &choice);

        // Perform the chosen action
        switch (choice) {
            case 1:
                // Check for max appointments
                if (count == MAX_APPOINTMENTS) {
                    printf("Appointment list is full.\n");
                    break;
                }

                // Get appointment details
                printf("Enter date (DD/MM/YYYY): ");
                scanf("%d/%d/%d", &appointments[count].day, 
                                   &appointments[count].month, 
                                   &appointments[count].year);
                printf("Enter time (HH:MM): ");
                scanf("%d:%d", &appointments[count].hour, 
                                &appointments[count].minute);
                printf("Enter description: ");
                scanf("%s", appointments[count].description);

                // Increment count
                count++;

                // Confirmation message
                printf("Appointment added successfully.\n");
                break;
            case 2:
                // Check for empty appointment list
                if (count == 0) {
                    printf("No appointments to display.\n");
                    break;
                }

                // Print appointment list header
                printf("Appointments\n");
                printf("==============================\n");
                
                // Loop through appointments and print
                for (int i = 0; i < count; i++) {
                    printf("%02d/%02d/%04d %02d:%02d - %s\n", 
                           appointments[i].day, 
                           appointments[i].month, 
                           appointments[i].year,
                           appointments[i].hour,
                           appointments[i].minute,
                           appointments[i].description);
                }
                break;
            case 3:
                // Check for empty appointment list
                if (count == 0) {
                    printf("No appointments to delete.\n");
                    break;
                }

                // Get appointment to delete
                int index;
                printf("Enter appointment index to delete: ");
                scanf("%d", &index);

                // Check for valid index
                if (index < 0 || index >= count) {
                    printf("Invalid index.\n");
                    break;
                }

                // Loop through appointments and shift array down
                for (int i = index; i < count - 1; i++) {
                    appointments[i] = appointments[i + 1];
                }

                // Decrement count
                count--;

                // Confirmation message
                printf("Appointment deleted successfully.\n");
                break;
            case 4:
                // Exit program
                printf("Goodbye!\n");
                break;
            default:
                // Invalid input
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}