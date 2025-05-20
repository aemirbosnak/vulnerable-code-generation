//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

struct appointment {
    char name[50];
    char date[20];
    char time[20];
    char duration[20];
    char doctor[50];
};

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    // Ask the user for the number of appointments they want to schedule
    printf("How many appointments do you want to schedule? ");
    scanf("%d", &num_appointments);

    // Loop through each appointment and ask for the details
    for (int i = 0; i < num_appointments; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", appointments[i].name);
        printf("Date: ");
        scanf("%s", appointments[i].date);
        printf("Time: ");
        scanf("%s", appointments[i].time);
        printf("Duration: ");
        scanf("%s", appointments[i].duration);
        printf("Doctor: ");
        scanf("%s", appointments[i].doctor);
    }

    // Print the appointments
    printf("\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("Duration: %s\n", appointments[i].duration);
        printf("Doctor: %s\n", appointments[i].doctor);
    }

    return 0;
}