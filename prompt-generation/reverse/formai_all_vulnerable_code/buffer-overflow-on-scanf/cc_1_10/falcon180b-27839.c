//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    time_t start_time;
    time_t end_time;
} appointment;

int num_appointments = 0;
appointment appointments[MAX_APPOINTMENTS];

void add_appointment() {
    char name[MAX_NAME_LENGTH];
    int id;
    time_t start_time, end_time;

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter ID: ");
    scanf("%d", &id);

    printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", name);
    strptime(name, "%Y-%m-%d %H:%M:%S", &start_time);

    printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", name);
    strptime(name, "%Y-%m-%d %H:%M:%S", &end_time);

    appointments[num_appointments].name[0] = '\0';
    strcat(appointments[num_appointments].name, name);
    appointments[num_appointments].id = id;
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;

    num_appointments++;
}

void view_appointments() {
    for (int i = 0; i < num_appointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("ID: %d\n", appointments[i].id);
        printf("Start time: %s\n", ctime(&appointments[i].start_time));
        printf("End time: %s\n", ctime(&appointments[i].end_time));
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
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
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}