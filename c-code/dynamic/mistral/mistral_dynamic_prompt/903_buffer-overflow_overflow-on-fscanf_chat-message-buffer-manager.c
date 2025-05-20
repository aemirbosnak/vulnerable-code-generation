#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100
#define MAX_CLIENTS 10

typedef struct Client {
    char name[20];
    char message[BUFFER_SIZE];
} Client;

Client clients[MAX_CLIENTS];
int client_count = 0;

void add_client(char *name, char *message) {
    if (client_count == MAX_CLIENTS) {
        printf("Too many clients.\n");
        return;
    }
    strcpy(clients[client_count].name, name);
    strcpy(clients[client_count].message, message);
    client_count++;
}

int main() {
    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        printf("Enter name: ");
        char name[20];
        scanf("%s", name);
        fgets(clients[i].message, BUFFER_SIZE, stdin);
        add_client(name, clients[i].message);
    }

    for (i = 0; i < client_count; i++) {
        printf("%s - %s", clients[i].name, clients[i].message);
    }
    return 0;
}
