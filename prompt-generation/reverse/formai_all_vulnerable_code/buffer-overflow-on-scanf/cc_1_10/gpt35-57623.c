//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

struct Appointment {
    char name[50];
    char date[20];
    char time[10];
};

struct Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void print_menu() {
    printf("--------------------\n");
    printf("Appointment Scheduler\n");
    printf("--------------------\n");
    printf("1. Schedule an Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Cancel an Appointment\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void schedule_appointment() {
    struct Appointment appt;
    printf("Enter name: ");
    fgets(appt.name, 50, stdin);
    printf("Enter date (MM/DD/YYYY): ");
    fgets(appt.date, 20, stdin);
    printf("Enter time (HH:MM): ");
    fgets(appt.time, 10, stdin);

    appointments[num_appointments] = appt;
    num_appointments++;
    printf("Appointment scheduled!\n");
}

void view_appointments() {
    printf("Name\tDate\tTime\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t%s\t%s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void cancel_appointment() {
    char name[50];
    printf("Enter name: ");
    fgets(name, 50, stdin);

    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            // found appointment
            for (int j = i; j < num_appointments-1; j++) {
                appointments[j] = appointments[j+1];
            }
            num_appointments--;
            printf("Appointment cancelled!\n");
            return;
        }
    }

    printf("No appointment found with that name.\n");
}

int main() {
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        getchar(); // clear newline from input buffer

        switch(choice) {
            case 1:
                schedule_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                cancel_appointment();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}