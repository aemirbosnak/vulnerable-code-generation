//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
} Appointment;

Appointment appointments[MAX_Appointments];

int main() {

    int i = 0;
    int available = MAX_Appointments;

    printf("Welcome to the Decentralized C Appointment Scheduler!\n");

    // List all appointments
    for (i = 0; i < MAX_Appointments; i++) {
        if (appointments[i].name[0] != '\0') {
            printf("Name: %s\n", appointments[i].name);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("\n");
        }
    }

    // Get user input
    printf("Enter your name: ");
    scanf("%s", appointments[i].name);

    printf("Enter the date (DD/MM/YY): ");
    scanf("%s", appointments[i].date);

    printf("Enter the time (HH:MM): ");
    scanf("%s", appointments[i].time);

    // Check for availability
    for (i = 0; i < MAX_Appointments; i++) {
        if (appointments[i].name[0] == '\0' && available) {
            appointments[i] = appointments[i];
            available = 0;
        }
    }

    // Confirmation
    if (available) {
        printf("Error: No available slots.\n");
    } else {
        printf("Your appointment has been scheduled.\n");
    }

    return 0;
}