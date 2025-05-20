#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTS 100
#define BUFFER_SIZE 256

struct client {
    char name[BUFFER_SIZE];
    int id;
    struct client* next;
};

struct client* head = NULL;

void allocate_client(char* name, int id) {
    struct client* new_client = (struct client*) malloc(sizeof(struct client));
    if (!new_client) {
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_client->name, name);
    new_client->id = id;
    new_client->next = head;
    head = new_client;
}

void print_clients() {
    struct client* current = head;
    int i = 1;
    while (current) {
        printf("%d: %s\n", current->id, current->name);
        current = current->next;
        i++;
        if (i >= MAX_CLIENTS) break;
    }
}

int main() {
    allocate_client("Alice", 1);
    allocate_client("Bob", 2);
    allocate_client("Charlie", 3);

    print_clients();

    struct client client3;
    printf("client3.name: %s\n", client3.name); // Dereference failure here

    print_clients();

    return 0;
}
