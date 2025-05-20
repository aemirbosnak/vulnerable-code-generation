//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: genious
#include <stdio.h>
#include <string.h>

/**
 * An Appointment scheduler program that allows users to set up appointments with a doctor.
 * Users can view, add, and cancel appointments.
 * The program is limited to one doctor and allows only one appointment per time slot.
 */

// Define global constants
#define MAX_APPOINTMENTS 10
#define TIME_SLOT_SIZE 50

// Define custom data types
typedef struct {
    char time_slot[TIME_SLOT_SIZE];
    char patient_name[50];
    int is_available; // to indicate whether the appointment slot is available or not
} Appointment;

// Function prototypes
void view_appointments(Appointment schedule[]);
void add_appointment(Appointment schedule[]);
void cancel_appointment(Appointment schedule[]);

int main() {

    // Define the schedule array of Appointments
    Appointment schedule[MAX_APPOINTMENTS] = {
        {"9:00 AM - 10:00 AM", "", 1},
        {"10:00 AM - 11:00 AM", "", 1},
        {"11:00 AM - 12:00 PM", "", 1},
        {"12:00 PM - 1:00 PM", "", 1},
        {"1:00 PM - 2:00 PM", "", 1},
        {"2:00 PM - 3:00 PM", "", 1},
        {"3:00 PM - 4:00 PM", "", 1},
        {"4:00 PM - 5:00 PM", "", 1},
        {"5:00 PM - 6:00 PM", "", 1},
        {"6:00 PM - 7:00 PM", "", 1},
    };

    int choice;

    printf("Welcome to the Appointment Scheduler!\n");

    do {
        printf("\nPlease choose an option:\n");
        printf("1. View appointments\n");
        printf("2. Add appointment\n");
        printf("3. Cancel appointment\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                view_appointments(schedule);
                break;
            case 2:
                add_appointment(schedule);
                break;
            case 3:
                cancel_appointment(schedule);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

// Function to display the schedule of appointments
void view_appointments(Appointment schedule[]) {
    printf("\nSCHEDULE\n");

    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        printf("%s\t%s\n", schedule[i].time_slot, schedule[i].patient_name);
    }
}

// Function to add an appointment
void add_appointment(Appointment schedule[]) {
    char input[10];
    int time_slot_found = 0;
    int i;

    printf("\nADD APPOINTMENT\n");
    printf("Please enter the desired time slot (e.g. 9:00 AM - 10:00 AM): ");
    scanf("%s", input);

    // Check if the time slot is available
    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        if (strcmp(schedule[i].time_slot, input) == 0) {
            if (schedule[i].is_available) {
                time_slot_found = 1;
                break;
            } else {
                printf("Sorry, this time slot is already taken.\n");
                return;
            }
        }
    }

    if (!time_slot_found) {
        printf("Invalid time slot. Please try again.\n");
        return;
    }

    printf("Please enter the patient's name: ");
    scanf("%s", schedule[i].patient_name);
    schedule[i].is_available = 0;
    printf("Appointment added successfully!\n");
}

// Function to cancel an appointment
void cancel_appointment(Appointment schedule[]) {
    char input[10];
    int time_slot_found = 0;
    int i;

    printf("\nCANCEL APPOINTMENT\n");
    printf("Please enter the time slot of the appointment you want to cancel (e.g. 9:00 AM - 10:00 AM): ");
    scanf("%s", input);

    // Check if the time slot exists and is not available
    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        if (strcmp(schedule[i].time_slot, input) == 0) {
            if (!schedule[i].is_available) {
                time_slot_found = 1;
                break;
            } else {
                printf("There is no appointment scheduled for this time slot.\n");
                return;
            }
        }
    }

    if (!time_slot_found) {
        printf("Invalid time slot. Please try again.\n");
        return;
    }

    printf("Are you sure you want to cancel the following appointment?\n");
    printf("%s\t%s\n", schedule[i].time_slot, schedule[i].patient_name);
    printf("Enter 'Y' for Yes or 'N' for No: ");

    char answer;
    scanf(" %c", &answer);
    
    if (answer == 'Y') {
        strcpy(schedule[i].patient_name, "");
        schedule[i].is_available = 1;
        printf("Appointment cancelled successfully!\n");
    } else {
        printf("Operation cancelled.\n");
    }
}