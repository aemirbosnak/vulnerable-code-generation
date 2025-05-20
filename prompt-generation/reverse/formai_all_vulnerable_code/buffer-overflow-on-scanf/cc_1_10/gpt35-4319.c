//FormAI DATASET v1.0 Category: Email Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTS 10
#define MAX_EMAILS 100

struct Email {
    char sender[50];
    char receiver[50];
    char subject[50];
    char message[100];
};

struct Client {
    char name[50];
    struct Email inbox[MAX_EMAILS];
    int inbox_size;
};

struct Client clients[MAX_CLIENTS];
int num_clients = 0;

int send_email(int sender_index, int receiver_index, char* subject, char* message) {
    if (sender_index == receiver_index) {
        printf("You cannot send an email to yourself.\n");
        return 0;
    }

    if (clients[receiver_index].inbox_size >= MAX_EMAILS) {
        printf("%s's inbox is full.\n", clients[receiver_index].name);
        return 0;
    }

    struct Email email;
    strcpy(email.sender, clients[sender_index].name);
    strcpy(email.receiver, clients[receiver_index].name);
    strcpy(email.subject, subject);
    strcpy(email.message, message);

    clients[receiver_index].inbox[clients[receiver_index].inbox_size++] = email;

    printf("Email sent from %s to %s with subject \"%s\"\n", clients[sender_index].name, clients[receiver_index].name, subject);
    return 1;
}

void show_inbox(int client_index) {
    printf("%s's Inbox:\n", clients[client_index].name);
    for (int i = 0; i < clients[client_index].inbox_size; i++) {
        printf("From: %s\nSubject: %s\nMessage: %s\n\n", clients[client_index].inbox[i].sender, clients[client_index].inbox[i].subject, clients[client_index].inbox[i].message);
    }
    printf("\n");
}

int main() {
    printf("Welcome to the Email Client!\n");

    while (1) {
        printf("Commands: add_client, send_email, show_inbox, exit\n");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "add_client") == 0) {
            if (num_clients >= MAX_CLIENTS) {
                printf("Maximum number of clients reached.\n");
            }
            else {
                struct Client client;
                printf("Enter client name: ");
                scanf("%s", client.name);
                client.inbox_size = 0;
                clients[num_clients++] = client;
                printf("%s added.\n", client.name);
            }
        }

        else if (strcmp(command, "send_email") == 0) {
            char sender[50], receiver[50], subject[50], message[100];
            printf("Enter sender name: ");
            scanf("%s", sender);
            int sender_index = -1;
            for (int i = 0; i < num_clients; i++) {
                if (strcmp(clients[i].name, sender) == 0) {
                    sender_index = i;
                    break;
                }
            }
            if (sender_index == -1) {
                printf("%s is not a valid client.\n", sender);
                continue;
            }

            printf("Enter receiver name: ");
            scanf("%s", receiver);
            int receiver_index = -1;
            for (int i = 0; i < num_clients; i++) {
                if (strcmp(clients[i].name, receiver) == 0) {
                    receiver_index = i;
                    break;
                }
            }
            if (receiver_index == -1) {
                printf("%s is not a valid client.\n", receiver);
                continue;
            }

            printf("Enter subject: ");
            scanf("%s", subject);

            printf("Enter message: ");
            scanf("%s", message);

            send_email(sender_index, receiver_index, subject, message);
        }

        else if (strcmp(command, "show_inbox") == 0) {
            char name[50];
            printf("Enter client name: ");
            scanf("%s", name);

            int client_index = -1;
            for (int i = 0; i < num_clients; i++) {
                if (strcmp(clients[i].name, name) == 0) {
                    client_index = i;
                    break;
                }
            }
            if (client_index == -1) {
                printf("%s is not a valid client.\n", name);
                continue;
            }

            show_inbox(client_index);
        }

        else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        else {
            printf("Invalid command.\n");
        }
    }
}