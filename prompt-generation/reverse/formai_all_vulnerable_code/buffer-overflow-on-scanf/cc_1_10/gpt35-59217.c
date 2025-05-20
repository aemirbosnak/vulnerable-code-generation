//FormAI DATASET v1.0 Category: Phone Book ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100 // Maximum number of contacts that can be stored

// Contact structure
struct Contact {
    char name[50];
    char phone[25];
    char address[100];
};

// Blockchain structure to store contact information
struct Block {
    int index;
    unsigned long timestamp;
    struct Contact contact;
    struct Block* next;
    char* hash;
};

struct Block* create_block(int index, unsigned long timestamp, struct Contact contact, char* previous_hash) {
    struct Block* block = (struct Block*)malloc(sizeof(struct Block));
    block->index = index;
    block->timestamp = timestamp;
    block->contact = contact;
    block->next = NULL;

    // Generate unique hash for block using contact info and previous hash
    char* hash = (char*)malloc(64*sizeof(char));
    sprintf(hash, "%d%s%s%s", index, contact.name, contact.phone, previous_hash);
    block->hash = hash;

    return block;
}

struct Block* add_block(struct Block* previous_block, struct Contact contact) {
    int index = previous_block->index + 1;
    unsigned long timestamp = (unsigned long)time(NULL);
    char* previous_hash = previous_block->hash;
    struct Block* block = create_block(index, timestamp, contact, previous_hash);
    previous_block->next = block;
    return block;
}

void print_contact(struct Contact contact) {
    printf("%s\t\t%s\t\t%s\n", contact.name, contact.phone, contact.address);
}

void print_block(struct Block* block) {
    printf("Index: %d\n", block->index);
    printf("Timestamp: %lu\n", block->timestamp);
    printf("Name: %s\n", block->contact.name);
    printf("Phone: %s\n", block->contact.phone);
    printf("Address: %s\n", block->contact.address);
    printf("Hash: %s\n", block->hash);
}

int main() {
    struct Block* genesis_block = create_block(0, (unsigned long)time(NULL), (struct Contact){"", "", ""}, "");
    struct Block* current_block = genesis_block;

    struct Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    int choice = 0;
    while (choice != 4) {
        printf("====================\n");
        printf("1. Add new contact\n");
        printf("2. List all contacts\n");
        printf("3. List blockchain\n");
        printf("4. Exit\n");
        printf("====================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add new contact
                if (num_contacts == MAX_CONTACTS) {
                    printf("Maximum contacts stored!\n");
                    break;
                }

                printf("Enter name: ");
                scanf("%s", &contacts[num_contacts].name);
                printf("Enter phone: ");
                scanf("%s", &contacts[num_contacts].phone);
                printf("Enter address: ");
                scanf("%s", &contacts[num_contacts].address);

                current_block = add_block(current_block, contacts[num_contacts]);
                printf("Contact added successfully!\n");

                num_contacts++;
                break;

            case 2: // List all contacts
                if (num_contacts == 0) {
                    printf("No contacts added yet!\n");
                    break;
                }

                printf("Name\t\tPhone\t\tAddress\n");
                for (int i = 0; i < num_contacts; i++) {
                    print_contact(contacts[i]);
                }
                break;

            case 3: // List blockchain
                printf("Blockchain:\n");
                while (genesis_block != NULL) {
                    print_block(genesis_block);
                    genesis_block = genesis_block->next;
                }
                break;

            case 4: // Exit
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}