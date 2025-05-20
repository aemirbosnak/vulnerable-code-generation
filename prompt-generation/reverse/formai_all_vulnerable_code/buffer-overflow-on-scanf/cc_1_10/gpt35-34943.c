//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold appointments
typedef struct appointment {
    char time[10];
    char name[50];
    char reason[100];
} Appointment;

// Function to create a new appointment
void createAppointment(Appointment appointment[], int pos) {
    printf("\nEnter appointment details:\n");
    printf("Time: ");
    scanf("%s", appointment[pos].time);
    printf("Name: ");
    scanf(" %[^\n]%*c", appointment[pos].name);
    printf("Reason: ");
    scanf(" %[^\n]%*c", appointment[pos].reason);
    printf("\nAppointment created!\n");
}

// Function to view a specific appointment
void viewAppointment(Appointment appointment[], int pos) {
    printf("\nAppointment Details:\n");
    printf("Time: %s\n", appointment[pos].time);
    printf("Name: %s\n", appointment[pos].name);
    printf("Reason: %s\n", appointment[pos].reason);
}

// Function to delete a specific appointment
void deleteAppointment(Appointment appointment[], int pos) {
    memset(&appointment[pos], 0, sizeof(Appointment));
    printf("\nAppointment deleted!\n");
}

int main() {
    // Initialize array of appointments
    Appointment appointments[10];
    int numAppointments = 0;
    char input[10];

    printf("Welcome to our Appointment Scheduler!\n");

    // Loop until user chooses to quit
    while (1) {
        printf("\nWhat would you like to do? (c = create, v = view, d = delete, q = quit)\n");
        scanf("%s", input);

        // Determine what action to take based on user input
        if (strcmp(input, "c") == 0) {
            if (numAppointments >= 10) {
                printf("\nMaximum number of appointments reached!\n");
            } else {
                createAppointment(appointments, numAppointments);
                numAppointments++;
            }
        } else if (strcmp(input, "v") == 0) {
            if (numAppointments == 0) {
                printf("\nNo appointments scheduled!\n");
            } else {
                printf("\nEnter appointment number: ");
                scanf("%s", input);
                int pos = atoi(input) - 1;
                if (pos >= numAppointments || pos < 0) {
                    printf("\nInvalid appointment number!\n");
                } else {
                    viewAppointment(appointments, pos);
                }
            }
        } else if (strcmp(input, "d") == 0) {
            if (numAppointments == 0) {
                printf("\nNo appointments scheduled!\n");
            } else {
                printf("\nEnter appointment number: ");
                scanf("%s", input);
                int pos = atoi(input) - 1;
                if (pos >= numAppointments || pos < 0) {
                    printf("\nInvalid appointment number!\n");
                } else {
                    deleteAppointment(appointments, pos);
                    numAppointments--;
                }
            }
        } else if (strcmp(input, "q") == 0) {
            printf("\nGoodbye!\n");
            break;
        } else {
            printf("\nInvalid input!\n");
        }
    }

    return 0;
}