//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    time_t start_time;
    time_t end_time;
} appointment_t;

appointment_t appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(char* name, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: cannot add more appointments.\n");
        return;
    }
    strcpy(appointments[num_appointments].name, name);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;
    num_appointments++;
}

void print_appointments() {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s to %s\n", appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }
}

int main() {
    srand(time(NULL));
    int choice;
    while (1) {
        printf("1. Add appointment\n2. Print appointments\n3. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            char name[MAX_NAME_LEN];
            time_t start_time, end_time;
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", ctime(&start_time));
            printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", ctime(&end_time));
            add_appointment(name, start_time, end_time);
        } else if (choice == 2) {
            print_appointments();
        } else if (choice == 3) {
            exit(0);
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}