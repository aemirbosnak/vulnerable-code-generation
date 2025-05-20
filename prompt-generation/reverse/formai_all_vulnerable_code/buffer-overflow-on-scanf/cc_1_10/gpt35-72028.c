//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include<stdio.h>
#include<string.h>

// Define the maximum number of appointments the scheduler can handle
#define MAX_APPOINTMENTS 50

// Define a struct for the appointment object
typedef struct {
    int id;
    char date[11];
    char time[6];
    char name[50];
    char email[50];
} Appointment;

// Declare function prototypes
void addAppointment(Appointment [], int *);
void viewAppointments(Appointment [], int);
void updateAppointment(Appointment [], int);
void deleteAppointment(Appointment [], int *);

int main() {
    // Define an array of Appointment objects
    Appointment appointments[MAX_APPOINTMENTS];

    // Initialize the number of appointments to 0
    int numAppointments = 0;

    // Declare a char array for the user input
    char choice[1];

    do {
        // Display the menu options
        printf("\nAppointment Scheduler Menu: \n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Update Appointment\n");
        printf("4. Delete Appointment\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        // Get the user input
        scanf(" %c", choice);

        switch(choice[0]) {
            case '1':
                addAppointment(appointments, &numAppointments);
                break;

            case '2':
                viewAppointments(appointments, numAppointments);
                break;

            case '3':
                updateAppointment(appointments, numAppointments);
                break;

            case '4':
                deleteAppointment(appointments, &numAppointments);
                break;

            case '5':
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    } while (choice[0] != '5');

    return 0;
}

void addAppointment(Appointment appointments[], int *numAppointments) {
    if (*numAppointments < MAX_APPOINTMENTS) {
        // Increment the number of appointments
        (*numAppointments)++;

        // Create an Appointment object and get input values
        Appointment newAppointment;
        newAppointment.id = *numAppointments;
        printf("\nEnter appointment date (YYYY-MM-DD): ");
        scanf("%s", newAppointment.date);
        printf("Enter appointment time (HH:MM): ");
        scanf("%s", newAppointment.time);
        printf("Enter patient name: ");
        scanf(" %[^\n]", newAppointment.name);
        printf("Enter patient email: ");
        scanf("%s", newAppointment.email);

        // Add the new Appointment object to the array
        appointments[*numAppointments - 1] = newAppointment;

        printf("\nAppointment added successfully.\n");
    } else {
        printf("\nThe scheduler is full. No more appointments can be added.\n");
    }
}

void viewAppointments(Appointment appointments[], int numAppointments) {
    if (numAppointments == 0) {
        printf("\nNo appointments found.\n");
    } else {
        // Display the table header
        printf("\nID    DATE          TIME   NAME                     EMAIL\n");
        printf("------------------------------------------------------------------------\n");

        // Loop through all Appointment objects and display values
        for (int i = 0; i < numAppointments; i++) {
            printf("%-5d %-12s %-6s %-24s %-50s\n", appointments[i].id, appointments[i].date, 
            appointments[i].time, appointments[i].name, appointments[i].email);
        }
    }
}

void updateAppointment(Appointment appointments[], int numAppointments) {
    if (numAppointments == 0) {
        printf("\nNo appointments found. Update operation not allowed.\n");
    } else {
        // Get the ID of the appointment to be updated
        int id;
        printf("\nEnter the ID of the appointment to be updated: ");
        scanf("%d", &id);

        // Loop through all Appointment objects
        for (int i = 0; i < numAppointments; i++) {
            if (appointments[i].id == id) {
                // Get new values from the user
                printf("\nEnter new appointment date (YYYY-MM-DD): ");
                scanf("%s", appointments[i].date);
                printf("Enter new appointment time (HH:MM): ");
                scanf("%s", appointments[i].time);
                printf("Enter new patient name: ");
                scanf(" %[^\n]", appointments[i].name);
                printf("Enter new patient email: ");
                scanf("%s", appointments[i].email);

                printf("\nAppointment updated successfully.\n");
                return;
            }
        }

        printf("\nAppointment ID not found. Please enter a valid ID.\n");
    }
}

void deleteAppointment(Appointment appointments[], int *numAppointments) {
    if (*numAppointments == 0) {
        printf("\nNo appointments found. Delete operation not allowed.\n");
    } else {
        // Get the ID of the appointment to be deleted
        int id;
        printf("\nEnter the ID of the appointment to be deleted: ");
        scanf("%d", &id);

        // Loop through all Appointment objects
        for (int i = 0; i < *numAppointments; i++) {
            if (appointments[i].id == id) {
                // Shift all objects after the deleted object back by one position
                for (int j = i + 1; j < *numAppointments; j++) {
                    appointments[j - 1] = appointments[j];
                }

                // Decrement the number of appointments
                (*numAppointments)--;

                printf("\nAppointment deleted successfully.\n");
                return;
            }
        }

        printf("\nAppointment ID not found. Please enter a valid ID.\n");
    }
}