//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct appointment {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
} appointment_t;

appointment_t appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    char name[MAX_NAME_LENGTH], description[MAX_DESCRIPTION_LENGTH];
    time_t start_time, end_time;

    printf("Enter appointment name: ");
    scanf("%s", name);

    printf("Enter appointment description: ");
    scanf("%s", description);

    printf("Enter appointment start time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", &start_time);

    printf("Enter appointment end time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", &end_time);

    strptime(start_time, "%Y-%m-%d %H:%M:%S", &appointments[num_appointments].start_time);
    strptime(end_time, "%Y-%m-%d %H:%M:%S", &appointments[num_appointments].end_time);

    strncpy(appointments[num_appointments].name, name, MAX_NAME_LENGTH);
    strncpy(appointments[num_appointments].description, description, MAX_DESCRIPTION_LENGTH);

    num_appointments++;
}

void view_appointments() {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Start time: %s\n", ctime(&appointments[i].start_time));
        printf("End time: %s\n", ctime(&appointments[i].end_time));
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add appointment\n2. View appointments\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}