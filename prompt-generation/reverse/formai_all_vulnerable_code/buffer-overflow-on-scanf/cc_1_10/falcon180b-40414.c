//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MIN_APPOINTMENT_DURATION 15
#define MAX_APPOINTMENT_DURATION 60

typedef struct {
    char name[50];
    time_t start_time;
    int duration;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void print_appointments() {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s starts at %s and lasts for %d minutes\n", appointments[i].name, ctime(&appointments[i].start_time), appointments[i].duration);
    }
}

int add_appointment() {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    time_t now = time(NULL);
    appointments[num_appointments].start_time = now + (rand() % (24 * 60 * 60)); // Random start time within the next 24 hours

    printf("Enter duration (in minutes): ");
    scanf("%d", &appointments[num_appointments].duration);

    if (appointments[num_appointments].duration < MIN_APPOINTMENT_DURATION || appointments[num_appointments].duration > MAX_APPOINTMENT_DURATION) {
        printf("Invalid duration.\n");
        return 0;
    }

    num_appointments++;
    printf("Appointment added.\n");
    return 1;
}

int main() {
    srand(time(NULL));

    while (1) {
        printf("1. Add appointment\n2. Print appointments\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (add_appointment()) {
                    print_appointments();
                }
                break;
            case 2:
                print_appointments();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}