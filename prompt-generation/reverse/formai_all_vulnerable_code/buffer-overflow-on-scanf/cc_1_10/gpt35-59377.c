//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *ip_address;
    int count;
    struct node *next;
};

struct hashtable {
    int size;
    struct node **table;
};

char *get_ip_address() {
    char *ip_address = malloc(sizeof(char) * 16);
    printf("Enter IP Address: ");
    scanf("%s", ip_address);
    return ip_address;
}

void print_menu() {
    printf("\n1. Add IP Address\n");
    printf("2. Check IP Address\n");
    printf("3. List All IP Addresses\n");
    printf("4. Exit\n");
}

int hash(char *ip_address, int size) {
    int hash = 0;
    for (int i = 0; i < strlen(ip_address); i++) {
        hash += (int)ip_address[i];
    }
    return hash % size;
}

void add_ip_address(struct hashtable *ht) {
    char *ip_address = get_ip_address();
    int index = hash(ip_address, ht->size);

    if (ht->table[index] == NULL) {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->ip_address = ip_address;
        new_node->count = 1;
        new_node->next = NULL;
        ht->table[index] = new_node;
    } else {
        struct node *current = ht->table[index];
        struct node *previous = NULL;

        while (current != NULL) {
            if (strcmp(current->ip_address, ip_address) == 0) {
                current->count++;
                free(ip_address);
                return;
            }

            previous = current;
            current = current->next;
        }

        struct node *new_node = malloc(sizeof(struct node));
        new_node->ip_address = ip_address;
        new_node->count = 1;
        new_node->next = NULL;
        previous->next = new_node;
    }

    printf("IP Address added to the system.\n");
}

void check_ip_address(struct hashtable *ht) {
    char *ip_address = get_ip_address();
    int index = hash(ip_address, ht->size);

    if (ht->table[index] == NULL) {
        printf("IP Address is not present in the system.\n");
        free(ip_address);
        return;
    }

    struct node *current = ht->table[index];

    while (current != NULL) {
        if (strcmp(current->ip_address, ip_address) == 0) {
            printf("IP Address is present in the system. Count: %d\n", current->count);
            free(ip_address);
            return;
        }

        current = current->next;
    }

    printf("IP Address is not present in the system.\n");
    free(ip_address);
}

void list_ip_addresses(struct hashtable *ht) {
    printf("List of IP Addresses:\n");

    for (int i = 0; i < ht->size; i++) {
        if (ht->table[i] != NULL) {
            struct node *current = ht->table[i];

            while (current != NULL) {
                printf("%s: %d\n", current->ip_address, current->count);
                current = current->next;
            }
        }
    }
}

int main() {
    int choice;
    struct hashtable *ht = malloc(sizeof(struct hashtable));
    ht->size = 100;
    ht->table = calloc(ht->size, sizeof(struct node *));

    while (choice != 4) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_ip_address(ht);
                break;
            case 2:
                check_ip_address(ht);
                break;
            case 3:
                list_ip_addresses(ht);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}