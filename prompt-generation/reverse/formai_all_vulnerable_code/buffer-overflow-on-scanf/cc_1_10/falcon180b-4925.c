//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int year, month, day, hour, minute;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter year: ");
    scanf("%d", &appointments[num_appointments].year);

    printf("Enter month: ");
    scanf("%d", &appointments[num_appointments].month);

    printf("Enter day: ");
    scanf("%d", &appointments[num_appointments].day);

    printf("Enter hour: ");
    scanf("%d", &appointments[num_appointments].hour);

    printf("Enter minute: ");
    scanf("%d", &appointments[num_appointments].minute);

    num_appointments++;
}

void view_appointments() {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %d/%d/%d %d:%d\n", appointments[i].name, appointments[i].year, appointments[i].month, appointments[i].day, appointments[i].hour, appointments[i].minute);
    }
}

void remove_appointment() {
    printf("Enter name of appointment to remove: ");
    scanf("%s", appointments[num_appointments - 1].name);

    num_appointments--;
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("1. Add appointment\n2. View appointments\n3. Remove appointment\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                remove_appointment();
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