//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    time_t appointment_time;
    int duration;
} appointment;

appointment *appointments = NULL;
int num_appointments = 0;

void add_appointment() {
    printf("Enter your name: ");
    scanf("%s", appointments[num_appointments].name);
    appointments[num_appointments].id = rand();
    printf("Enter the appointment date and time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].appointment_time);
    appointments[num_appointments].duration = rand() % 60;
    num_appointments++;
    printf("Appointment added successfully.\n");
}

void view_appointments() {
    printf("Viewing appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("ID: %d\n", appointments[i].id);
        printf("Name: %s\n", appointments[i].name);
        printf("Appointment Time: %s\n", appointments[i].appointment_time);
        printf("Duration: %d minutes\n", appointments[i].duration);
        printf("\n");
    }
}

void cancel_appointment() {
    printf("Enter the ID of the appointment you want to cancel: ");
    int id;
    scanf("%d", &id);
    for (int i = 0; i < num_appointments; i++) {
        if (appointments[i].id == id) {
            printf("Appointment cancelled successfully.\n");
            num_appointments--;
            return;
        }
    }
    printf("Appointment not found.\n");
}

int main() {
    srand(time(NULL));
    appointments = (appointment *)malloc(MAX_APPOINTMENTS * sizeof(appointment));
    num_appointments = 0;
    int choice;
    do {
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Cancel appointment\n");
        printf("4. Exit\n");
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
                cancel_appointment();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}