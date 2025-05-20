//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 50
#define MAX_NAME_LENGTH 50

struct appointment {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
};

struct appointment schedule[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    printf("Enter name: ");
    scanf("%s", schedule[num_appointments].name);

    time_t start_time;
    printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", &start_time);
    schedule[num_appointments].start_time = start_time;

    time_t end_time;
    printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", &end_time);
    schedule[num_appointments].end_time = end_time;

    num_appointments++;
}

void view_appointments() {
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s to %s\n", schedule[i].name, ctime(&schedule[i].start_time), ctime(&schedule[i].end_time));
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Appointment Scheduler\n");
    printf("-------------------------------------\n");

    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice!= 3);

    return 0;
}