//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    int duration;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void print_appointments() {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s: %s - %d minutes\n", appointments[i].name, ctime(&appointments[i].start_time), appointments[i].duration);
    }
}

void add_appointment() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name: ");
    scanf("%s", name);

    time_t start_time;
    printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", ctime(&start_time));

    int duration;
    printf("Enter duration in minutes: ");
    scanf("%d", &duration);

    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, can't add more appointments.\n");
        return;
    }

    strcpy(appointments[num_appointments].name, name);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].duration = duration;
    num_appointments++;

    printf("Appointment added successfully!\n");
}

void delete_appointment() {
    int index;
    printf("Enter appointment index to delete: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_appointments) {
        num_appointments--;
        for (int i = index; i < num_appointments; i++) {
            strcpy(appointments[i].name, appointments[i+1].name);
            appointments[i].start_time = appointments[i+1].start_time;
            appointments[i].duration = appointments[i+1].duration;
        }
        printf("Appointment deleted successfully!\n");
    } else {
        printf("Invalid appointment index.\n");
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < num_appointments; i++) {
        appointments[i].name[0] = '\0';
    }

    int choice;
    do {
        printf("1. Add appointment\n");
        printf("2. Delete appointment\n");
        printf("3. Print appointments\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                delete_appointment();
                break;
            case 3:
                print_appointments();
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