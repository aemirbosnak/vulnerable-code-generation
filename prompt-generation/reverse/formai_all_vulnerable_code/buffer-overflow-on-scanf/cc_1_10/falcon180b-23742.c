//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CLIENTS 100
#define MAX_APPOINTMENTS 1000

typedef struct {
    char name[100];
    char phone[20];
    int id;
} Client;

typedef struct {
    int date;
    int time;
    int client_id;
    char reason[100];
} Appointment;

Client clients[MAX_CLIENTS];
Appointment appointments[MAX_APPOINTMENTS];
int num_clients = 0;
int num_appointments = 0;

int add_client() {
    printf("Enter client name: ");
    scanf("%s", clients[num_clients].name);
    printf("Enter client phone number: ");
    scanf("%s", clients[num_clients].phone);
    clients[num_clients].id = num_clients + 1;
    num_clients++;
    return 0;
}

int add_appointment() {
    int client_id, date, time;
    char reason[100];

    printf("Enter client ID: ");
    scanf("%d", &client_id);

    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%s", reason);
    appointments[num_appointments].date = strtol(reason, NULL, 10);

    printf("Enter appointment time (HH:MM): ");
    scanf("%s", reason);
    appointments[num_appointments].time = strtol(reason, NULL, 10);

    appointments[num_appointments].client_id = client_id;
    appointments[num_appointments].reason[0] = '\0';
    num_appointments++;

    return 0;
}

int view_appointments() {
    printf("Viewing appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("Date: %d-%02d-%02d\n", appointments[i].date, appointments[i].date % 100, appointments[i].date / 100);
        printf("Time: %02d:%02d\n", appointments[i].time / 100, appointments[i].time % 100);
        printf("Client ID: %d\n", appointments[i].client_id);
        printf("Reason: %s\n", appointments[i].reason);
        printf("\n");
    }

    return 0;
}

int main() {
    int choice;

    do {
        printf("1. Add client\n2. Add appointment\n3. View appointments\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_client();
                break;
            case 2:
                add_appointment();
                break;
            case 3:
                view_appointments();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}