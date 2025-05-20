//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for Appointment 
typedef struct {
    char date[20];
    char time[10];
    char name[50];
    char email[50];
    char purpose[100];
} Appointment;

void saveAppointment(Appointment *pt, int *count) {
    FILE *fp;
    // Open file for appending
    fp = fopen("appointments.txt", "a");

    if (fp == NULL) {
      printf("Error opening file\n");
      exit(1);
    }

    // Write the appointment data to the file
    fprintf(fp, "%s,%s,%s,%s,%s\n", pt->date, pt->time, pt->name, pt->email, pt->purpose);

    // Close the file
    fclose(fp);

    // Increment count of appointments
    (*count)++;
}

void displayAppointments() {
    FILE *fp;
    char buffer[255];

    // Open file for reading
    fp = fopen("appointments.txt", "r");

    if (fp == NULL) {
      printf("Error opening file\n");
      exit(1);
    }

    // Read the file line-by-line and display appointments
    while (fgets(buffer, 255, fp) != NULL) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(fp);
}

int main() {
    Appointment appointment;
    int count = 0;
    int choice;

    do {
        // Display menu
        printf("\n");
        printf("1. Schedule Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Schedule Appointment
            {
                printf("\nEnter appointment date (dd-mm-yyyy): ");
                scanf("%s", appointment.date);

                printf("Enter appointment time (hh:mm): ");
                scanf("%s", appointment.time);

                printf("Enter your name: ");
                scanf("%s", appointment.name);

                printf("Enter your email: ");
                scanf("%s", appointment.email);

                printf("Enter purpose of appointment: ");
                scanf("%s", appointment.purpose);

                // Save the appointment
                saveAppointment(&appointment, &count);

                printf("\nAppointment added successfully!\n");
                break;
            }
            case 2: // View Appointments
            {
                if (count == 0) {
                    printf("\nNo appointments scheduled yet!\n");
                } else {
                    printf("\nScheduled appointments:\n");
                    displayAppointments();
                }
                break;
            }
            case 3: // Exit
            {
                printf("\nExiting...\n");
                break;
            }
            default:
            {
                printf("\nInvalid choice! Try again.\n");
                break;
            }
        }

    } while (choice != 3);

    return 0;
}