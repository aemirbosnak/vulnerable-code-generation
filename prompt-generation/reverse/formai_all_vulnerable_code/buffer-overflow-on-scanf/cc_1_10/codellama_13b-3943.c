//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: excited
// C Appointment Scheduler Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTS 100
#define MAX_APPOINTMENTS 10

typedef struct {
    char name[20];
    char appointment[20];
    int duration;
} Client;

void get_appointment(Client *client) {
    printf("Enter client name: ");
    scanf("%s", client->name);
    printf("Enter appointment name: ");
    scanf("%s", client->appointment);
    printf("Enter appointment duration (in minutes): ");
    scanf("%d", &client->duration);
}

void print_schedule(Client clients[], int num_clients) {
    printf("Appointment Schedule:\n");
    for (int i = 0; i < num_clients; i++) {
        printf("%s - %s (%d minutes)\n", clients[i].name, clients[i].appointment, clients[i].duration);
    }
}

int main() {
    Client clients[MAX_CLIENTS];
    int num_clients = 0;
    char choice;

    while (1) {
        printf("Menu:\n");
        printf("a - Add appointment\n");
        printf("p - Print schedule\n");
        printf("q - Quit\n");
        scanf("%c", &choice);

        switch (choice) {
            case 'a':
                if (num_clients < MAX_CLIENTS) {
                    get_appointment(&clients[num_clients]);
                    num_clients++;
                } else {
                    printf("Maximum number of clients reached.\n");
                }
                break;
            case 'p':
                print_schedule(clients, num_clients);
                break;
            case 'q':
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}