//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    int duration;
    time_t start_time;
} appointment;

appointment schedule[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    printf("Enter name: ");
    scanf("%s", schedule[num_appointments].name);
    printf("Enter duration (in minutes): ");
    scanf("%d", &schedule[num_appointments].duration);
    time_t now = time(NULL);
    schedule[num_appointments].start_time = now + schedule[num_appointments].duration * 60; // Convert duration to seconds
    num_appointments++;
}

void display_schedule() {
    printf("\nSchedule:\n");
    printf("Name\tDuration (mins)\tStart Time\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t%d\t%s", schedule[i].name, schedule[i].duration, ctime(&schedule[i].start_time));
    }
}

int main() {
    srand(time(NULL));
    int choice;
    do {
        printf("\n1. Add appointment\n2. Display schedule\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                display_schedule();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);
    return 0;
}