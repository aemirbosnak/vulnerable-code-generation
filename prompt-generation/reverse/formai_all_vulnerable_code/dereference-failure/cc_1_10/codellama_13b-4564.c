//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: Ken Thompson
// A unique C Appointment Scheduler example program in a Ken Thompson style
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 25
#define MAX_APPOINTMENTS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
} Appointment;

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    char command[MAX_NAME_LENGTH];

    printf("Welcome to the appointment scheduler!\n");

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add an appointment\n");
        printf("2. Delete an appointment\n");
        printf("3. Show all appointments\n");
        printf("4. Exit\n");
        printf("Enter a command: ");

        fgets(command, MAX_NAME_LENGTH, stdin);

        if (strcmp(command, "1") == 0) {
            printf("Enter the name of the appointment: ");
            fgets(appointments[num_appointments].name, MAX_NAME_LENGTH, stdin);

            printf("Enter the start time of the appointment (format: HH:MM:SS): ");
            fgets(appointments[num_appointments].start_time, MAX_NAME_LENGTH, stdin);

            printf("Enter the end time of the appointment (format: HH:MM:SS): ");
            fgets(appointments[num_appointments].end_time, MAX_NAME_LENGTH, stdin);

            num_appointments++;
        } else if (strcmp(command, "2") == 0) {
            printf("Enter the name of the appointment you want to delete: ");
            fgets(appointments[num_appointments].name, MAX_NAME_LENGTH, stdin);

            for (int i = 0; i < num_appointments; i++) {
                if (strcmp(appointments[i].name, appointments[num_appointments].name) == 0) {
                    for (int j = i; j < num_appointments - 1; j++) {
                        appointments[j] = appointments[j + 1];
                    }
                    num_appointments--;
                    break;
                }
            }
        } else if (strcmp(command, "3") == 0) {
            printf("Current appointments:\n");
            for (int i = 0; i < num_appointments; i++) {
                printf("%s: %s - %s\n", appointments[i].name, appointments[i].start_time, appointments[i].end_time);
            }
        } else if (strcmp(command, "4") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}