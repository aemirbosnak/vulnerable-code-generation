//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length for appointment notes
#define MAX_LENGTH 100

// Define structure for appointment scheduler
typedef struct {
    char date[11];
    char time[6];
    char name[50];
    char notes[MAX_LENGTH];
} Appointment;

// Initialize function to create an appointment
Appointment create_appointment() {
    Appointment new_appt;
    printf("Enter date of appointment (dd-mm-yyyy): ");
    scanf("%s", new_appt.date);
    printf("Enter time of appointment (hh:mm): ");
    scanf("%s", new_appt.time);
    printf("Enter name of person for appointment: ");
    scanf("%s", new_appt.name);
    printf("Enter any notes for the appointment (maximum %d characters): ", MAX_LENGTH);
    scanf(" %[^\n]%*c", new_appt.notes); // read input with spaces
    return new_appt;
}

// Initialize function to display an appointment
void display_appointment(Appointment appt) {
    printf("\nDate: %s\nTime: %s\nName: %s\nNotes: %s\n", appt.date, appt.time, appt.name, appt.notes);
}

// Define main function
int main() {
    Appointment appts[10];
    int num_appts = 0;
    int choice = 0;

    printf("Welcome to the Appointment Scheduler!\n");

    // Start the scheduler loop
    while (choice != 4) {
        printf("\nPlease choose an option:\n");
        printf("1. Add an appointment\n");
        printf("2. View all appointments\n");
        printf("3. View upcoming appointments\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_appts < 10) {
                    appts[num_appts] = create_appointment();
                    num_appts++;
                } else {
                    printf("Sorry, you have reached the maximum number of appointments (10)!\n");
                }
                break;
            case 2:
                if (num_appts > 0) {
                    printf("\nAll Appointments:\n");
                    for (int i=0; i<num_appts; i++) {
                        display_appointment(appts[i]);
                        printf("\n");
                    }
                } else {
                    printf("You have no appointments yet!\n");
                }
                break;
            case 3:
                if (num_appts > 0) {
                    printf("\nUpcoming Appointments:\n");
                    for (int i=0; i<num_appts; i++) {
                        if (strcmp(appts[i].date, "today") == 0 || strcmp(appts[i].date, "tomorrow") == 0) {
                            display_appointment(appts[i]);
                            printf("\n");
                        }
                    }
                } else {
                    printf("You have no appointments yet!\n");
                }
                break;
            case 4:
                printf("Thank you for using the Appointment Scheduler!\n");
                break;
            default:
                printf("Sorry, that is not a valid choice!\n");
        }
    }

    return 0;
}