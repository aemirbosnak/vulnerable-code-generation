//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

struct Appointment {
    char name[50];
    char description[100];
    int start_time;
    int end_time;
};

struct Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, the appointment book is full.\n");
        return;
    }

    printf("Enter the name of the person you are scheduling an appointment for: ");
    scanf(" %[^\n]%*c", appointments[num_appointments].name);

    printf("Enter a description of the appointment: ");
    scanf(" %[^\n]%*c", appointments[num_appointments].description);

    printf("Enter the start time of the appointment (in hours): ");
    scanf("%d", &appointments[num_appointments].start_time);

    printf("Enter the end time of the appointment (in hours): ");
    scanf("%d", &appointments[num_appointments].end_time);

    num_appointments++;
}

void print_appointments() {
    if (num_appointments == 0) {
        printf("There are no appointments scheduled.\n");
        return;
    }

    printf("Here is a list of your appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf(" - %s from %d to %d: %s\n",
            appointments[i].name,
            appointments[i].start_time,
            appointments[i].end_time,
            appointments[i].description);
    }
}

void delete_appointment() {
    char name[50];
    printf("Enter the name of the person whose appointment you want to delete: ");
    scanf(" %[^\n]%*c", name);

    int found = 0;
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < num_appointments - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            num_appointments--;
            break;
        }
    }

    if (!found) {
        printf("Sorry, I couldn't find an appointment for that person.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nAppointment Scheduler\n");
        printf("1. Add an appointment\n");
        printf("2. Print appointments\n");
        printf("3. Delete an appointment\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                print_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}