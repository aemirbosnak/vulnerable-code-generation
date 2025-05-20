//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTS 100
#define MAX_APPTS 10

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int hour;
    int minute;
} Time;

typedef struct {
    char name[50];
    char phone[15];
} Client;

typedef struct {
    Client client;
    Date date;
    Time time;
} Appointment;

int total_clients = 0;
int total_appts = 0;
Client clients[MAX_CLIENTS];
Appointment appts[MAX_APPTS];

void add_client() {
    printf("\nEnter client name: ");
    scanf("%s", clients[total_clients].name);
    printf("Enter client phone number: ");
    scanf("%s", clients[total_clients].phone);
    printf("Client added successfully!\n\n");
    total_clients++;
}

void add_appt() {
    if (total_clients == 0) {
        printf("No clients available. Please add a client first.\n\n");
        return;
    }
    printf("Enter client name: ");
    char name[50];
    scanf("%s", name);
    int client_index = -1;
    for (int i = 0; i < total_clients; i++) {
        if (strcmp(clients[i].name, name) == 0) {
            client_index = i;
            break;
        }
    }
    if (client_index == -1) {
        printf("Client not found. Please check the name spelling.\n\n");
        return;
    }
    printf("Enter appointment date (dd mm yyyy): ");
    scanf("%d %d %d", &appts[total_appts].date.day, &appts[total_appts].date.month, &appts[total_appts].date.year);
    printf("Enter appointment time (hh:mm): ");
    scanf("%d:%d", &appts[total_appts].time.hour, &appts[total_appts].time.minute);
    appts[total_appts].client = clients[client_index];
    total_appts++;
    printf("Appointment added successfully!\n\n");
}

void print_appts() {
    printf("\nAppointments:\n");
    for (int i = 0; i < total_appts; i++) {
        printf("%d. %s - %d/%d/%d - %d:%02d\n", i+1, appts[i].client.name, appts[i].date.day, appts[i].date.month, appts[i].date.year, appts[i].time.hour, appts[i].time.minute);
    }
    printf("\n");
}

int main() {
    int option;
    do {
        printf("Menu:\n");
        printf("1. Add client\n");
        printf("2. Add appointment\n");
        printf("3. View appointments\n");
        printf("4. Exit\n\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch (option) {
            case 1: add_client(); break;
            case 2: add_appt(); break;
            case 3: print_appts(); break;
            case 4: printf("\nGoodbye!\n"); break;
            default: printf("\nInvalid option. Please try again.\n\n");
        }
    } while (option != 4);
    return 0;
}