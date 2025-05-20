//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 50
#define MAX_NAME 30

typedef struct {
    char name[MAX_NAME];
    int appointment_id;
    int start_time;
    int end_time;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    printf("Enter the name of the person: ");
    scanf("%s", appointments[num_appointments].name);
    appointments[num_appointments].appointment_id = num_appointments + 1;
    printf("Enter the start time (in minutes from 9am): ");
    scanf("%d", &appointments[num_appointments].start_time);
    printf("Enter the end time (in minutes from 9am): ");
    scanf("%d", &appointments[num_appointments].end_time);
    num_appointments++;
}

void display_appointments() {
    printf("Appointment Schedule:\n");
    printf("ID\tName\tStart Time\tEnd Time\n");
    for(int i=0; i<num_appointments; i++) {
        printf("%d\t%s\t%d\t%d\n", appointments[i].appointment_id, appointments[i].name, appointments[i].start_time, appointments[i].end_time);
    }
}

void sort_appointments() {
    for(int i=0; i<num_appointments-1; i++) {
        for(int j=i+1; j<num_appointments; j++) {
            if(appointments[j].start_time < appointments[i].start_time) {
                appointment temp = appointments[i];
                appointments[i] = appointments[j];
                appointments[j] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int choice;
    do {
        printf("Welcome to the Happy Appointment Scheduler!\n");
        printf("1. Add an appointment\n");
        printf("2. Display appointments\n");
        printf("3. Sort appointments by start time\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                display_appointments();
                break;
            case 3:
                sort_appointments();
                display_appointments();
                break;
            case 4:
                printf("Goodbye! Have a happy day!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice!= 4);
    return 0;
}