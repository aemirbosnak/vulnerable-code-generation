//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_CLIENTS 100

struct appointment {
    char client_name[50];
    time_t appointment_time;
    int appointment_duration;
};

struct client {
    char name[50];
    int client_id;
};

int num_appointments = 0;
int num_clients = 0;

struct appointment appointments[MAX_APPOINTMENTS];
struct client clients[MAX_CLIENTS];

void add_appointment() {
    printf("Enter client name: ");
    scanf("%s", appointments[num_appointments].client_name);

    printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].client_name);

    printf("Enter appointment duration (in minutes): ");
    scanf("%d", &appointments[num_appointments].appointment_duration);

    num_appointments++;
}

void view_appointments() {
    for (int i = 0; i < num_appointments; i++) {
        printf("Client name: %s\n", appointments[i].client_name);
        printf("Appointment time: %s\n", ctime(&appointments[i].appointment_time));
        printf("Appointment duration: %d minutes\n\n", appointments[i].appointment_duration);
    }
}

void main() {
    int choice;

    do {
        printf("\nAppointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
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
}