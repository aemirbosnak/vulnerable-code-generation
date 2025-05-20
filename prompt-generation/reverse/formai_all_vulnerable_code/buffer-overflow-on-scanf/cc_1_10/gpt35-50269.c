//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define Appointment struct
typedef struct Appointment {
    char date[20];
    char time[20];
    char type[50];
} Appointment;

// Define function to check if a given appointment is available
bool isAvailable(Appointment *appointments, int size, char *date, char *time) {
    for (int i = 0; i < size; i++) {
        if (strcmp(appointments[i].date, date) == 0 && strcmp(appointments[i].time, time) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // Declare variables and arrays
    char name[50], date[20], time[20], type[50];
    int numAppointments, numTaken = 0;
    Appointment *appointments;

    // Get user input for number of appointments and allocate memory for array of appointments
    printf("Greetings and salutations! How many appointments doth thou require? ");
    scanf("%d", &numAppointments);
    appointments = (Appointment*) malloc(numAppointments * sizeof(Appointment));

    // Loop through each appointment to get user input
    for (int i = 0; i < numAppointments; i++) {
        printf("What date does thy appointment #%d fall on? ", i+1);
        scanf("%s", date);
        printf("What time does thy appointment on %s occur? ", date);
        scanf("%s", time);

        // Check if appointment is available and assign values to appointment struct
        if (isAvailable(appointments, numTaken, date, time)) {
            strcpy(appointments[numTaken].date, date);
            strcpy(appointments[numTaken].time, time);
            printf("What type of appointment wouldst thou like at %s on %s? ", time, date);
            scanf("%s", type);
            strcpy(appointments[numTaken].type, type);
            numTaken++;
            printf("Thy appointment hath been scheduled successfully!\n");
        } else {
            printf("Alack, thine appointment for %s at %s is already taken. Canst thou choose another time?\n", date, time);
            i--; // Re-ask for same appointment
        }
    }

    // Print out all scheduled appointments
    printf("\nGoodly sir or lady, here are all of thy scheduled appointments:\n");
    for (int i = 0; i < numTaken; i++) {
        printf("Appointment #%d: %s at %s for %s\n", i+1, appointments[i].date, appointments[i].time, appointments[i].type);
    }

    // Free memory and return
    free(appointments);
    printf("\nFarewell, and may all thy appointments be scheduled with ease!");
    return 0;
}