//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
} appointment_t;

appointment_t appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    num_appointments++;
}

void remove_appointment(int index) {
    num_appointments--;
}

void display_appointments() {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s\n", appointments[i].name, appointments[i].description);
        printf("Start time: %s\n", ctime(&appointments[i].start_time));
        printf("End time: %s\n\n", ctime(&appointments[i].end_time));
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time, end_time;

    do {
        printf("1. Add appointment\n");
        printf("2. Remove appointment\n");
        printf("3. Display appointments\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter description: ");
            scanf("%s", description);
            printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", description);
            start_time = strptime(description, "%Y-%m-%d %H:%M:%S", NULL);
            printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", description);
            end_time = strptime(description, "%Y-%m-%d %H:%M:%S", NULL);
            add_appointment();
            break;
        case 2:
            printf("Enter index of appointment to remove: ");
            scanf("%d", &choice);
            remove_appointment(choice - 1);
            break;
        case 3:
            display_appointments();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }

    } while (1);

    return 0;
}