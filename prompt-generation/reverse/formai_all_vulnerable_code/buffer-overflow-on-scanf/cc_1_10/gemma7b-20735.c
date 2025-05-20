//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Appointment {
    char name[50];
    char date[10];
    char time[10];
    int id;
} Appointment;

int main() {
    Appointment appointments[MAX];
    int i = 0;

    // Create a loop to add appointments
    while (1) {
        // Get the appointment details
        printf("Enter your name: ");
        scanf("%s", appointments[i].name);

        printf("Enter the date (dd/mm/yyyy): ");
        scanf("%s", appointments[i].date);

        printf("Enter the time (hh:mm): ");
        scanf("%s", appointments[i].time);

        // Assign an ID to the appointment
        appointments[i].id = i;

        // Increment the number of appointments
        i++;

        // Check if the user wants to continue
        printf("Do you want to add another appointment? (Y/N): ");
        char answer;
        scanf("%c", &answer);

        if (answer == 'N') {
            break;
        }
    }

    // Print the appointments
    printf("Your appointments:\n");
    for (i = 0; i < MAX; i++) {
        if (appointments[i].name[0] != '\0') {
            printf("Name: %s\n", appointments[i].name);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("ID: %d\n", appointments[i].id);
            printf("\n");
        }
    }

    return 0;
}