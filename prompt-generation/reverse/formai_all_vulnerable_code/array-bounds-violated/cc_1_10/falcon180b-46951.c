//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    int appointment_time;
    int status;
} appointment;

void main() {

    int num_appointments, i, j, choice;
    appointment appointments[100];

    printf("Welcome to the Cyberpunk Appointment Scheduler\n");
    printf("How many appointments would you like to schedule? ");
    scanf("%d", &num_appointments);

    for(i=0;i<num_appointments;i++) {
        printf("Enter name for appointment %d: ", i+1);
        scanf("%s", appointments[i].name);
        appointments[i].age = rand() % 100;
        appointments[i].appointment_time = rand() % 24 + 1;
        appointments[i].status = 0;
    }

    while(1) {
        system("clear");
        printf("Current appointments:\n");
        for(i=0;i<num_appointments;i++) {
            printf("%s (%d years old) - %d:%02d\n", appointments[i].name, appointments[i].age, appointments[i].appointment_time/60, appointments[i].appointment_time%60);
        }
        printf("\nWhat would you like to do?\n1. Schedule an appointment\n2. Cancel an appointment\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name of person to schedule appointment for: ");
                scanf("%s", appointments[num_appointments-1].name);
                appointments[num_appointments-1].appointment_time = rand() % 24 + 1;
                appointments[num_appointments-1].status = 1;
                num_appointments++;
                break;
            case 2:
                printf("Enter name of person to cancel appointment for: ");
                scanf("%s", appointments[i].name);
                appointments[i].status = 0;
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}