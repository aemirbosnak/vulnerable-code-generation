//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int appointment_time;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments;

void add_appointment() {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter appointment time (in minutes): ");
    scanf("%d", &appointments[num_appointments].appointment_time);
    num_appointments++;
}

void display_schedule() {
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    int current_minute = current_time->tm_min;

    printf("\nSchedule for %s:\n", ctime(&now));
    for (int i = 0; i < num_appointments; i++) {
        int appointment_minute = appointments[i].appointment_time * 60 + current_minute;
        if (appointment_minute > 1439) {
            appointment_minute -= 1440;
        }
        printf("%s at %02d:%02d\n", appointments[i].name, appointment_minute / 60, appointment_minute % 60);
    }
}

int main() {
    num_appointments = 0;

    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. Display schedule\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_appointment();
            break;
        case 2:
            display_schedule();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}