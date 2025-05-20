//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    int id;
    time_t start_time;
    time_t end_time;
} Appointment;

int main() {
    int choice;
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    do {
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Delete appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_appointments >= MAX_APPOINTMENTS) {
                printf("Cannot add more appointments.\n");
            } else {
                printf("Enter appointment name: ");
                scanf("%s", appointments[num_appointments].name);
                appointments[num_appointments].id = num_appointments + 1;
                printf("Enter appointment start time (YYYY-MM-DD HH:MM:SS): ");
                scanf("%s", appointments[num_appointments].start_time);
                printf("Enter appointment end time (YYYY-MM-DD HH:MM:SS): ");
                scanf("%s", appointments[num_appointments].end_time);
                num_appointments++;
            }
            break;

        case 2:
            printf("Appointment ID\tName\tStart Time\tEnd Time\n");
            for (int i = 0; i < num_appointments; i++) {
                printf("%d\t%s\t%s\t%s\n", appointments[i].id, appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
            }
            break;

        case 3:
            printf("Enter appointment ID to delete: ");
            scanf("%d", &appointments[0].id);
            for (int i = 0; i < num_appointments; i++) {
                if (appointments[i].id == appointments[0].id) {
                    for (int j = i; j < num_appointments - 1; j++) {
                        appointments[j] = appointments[j + 1];
                    }
                    num_appointments--;
                }
            }
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