//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

struct appointment {
    char date[11];
    char time[6];
    char notes[100];
};

struct appointment appointments[MAX_APPOINTMENTS];

int num_appointments = 0;

void add_appointment() {
    if(num_appointments >= MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached!\n");
        return;
    }

    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", appointments[num_appointments].date);
    
    printf("Enter time (HH:MM): ");
    scanf("%s", appointments[num_appointments].time);
    
    printf("Enter notes: ");
    scanf(" %[^\n]", appointments[num_appointments].notes);

    num_appointments++;
}

void list_appointments() {
    printf("Appointments:\n");
    for(int i = 0; i < num_appointments; i++) {
        printf("%s %s - %s\n", appointments[i].date, appointments[i].time, appointments[i].notes);
    }
}

int main() {
    int choice = 0;

    while(choice != 3) {
        printf("Appointment Scheduler Menu:\n");
        printf("1. Add Appointment\n");
        printf("2. List Appointments\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                list_appointments();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}