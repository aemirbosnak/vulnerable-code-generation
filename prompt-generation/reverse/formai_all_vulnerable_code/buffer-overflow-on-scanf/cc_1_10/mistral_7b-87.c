//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 101
#define KEY_LENGTH 50

typedef struct Entry {
    char name[KEY_LENGTH];
    int phone_number;
} Entry;

unsigned int hash_func(char *key) {
    unsigned int hash = 0;
    int c;

    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash code increased by hash code of next letter */

    return hash % TABLE_SIZE;
}

void print_table(Entry table[]) {
    int i;

    printf("Phonebook:\n");
    for (i = 0; i < TABLE_SIZE; i++) {
        if (table[i].name[0] != '\0') {
            printf("%s: %d\n", table[i].name, table[i].phone_number);
        }
    }
}

void add_entry(Entry table[], char *name, int phone_number) {
    int index = hash_func(name);

    if (table[index].name[0] == '\0') {
        strcpy(table[index].name, name);
        table[index].phone_number = phone_number;
    } else {
        add_entry(table, name, phone_number); // recursively try the next hash
    }
}

int main() {
    Entry phonebook[TABLE_SIZE];

    char command[10];
    char name[KEY_LENGTH];
    int phone_number;

    while (1) {
        printf("\nTuring Phonebook>\n");
        printf("Enter command (add name phone or quit): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        printf("Enter name: ");
        scanf("%s", name);

        for (int i = 0; i < strlen(name); i++) {
            name[i] = tolower(name[i]);
        }

        printf("Enter phone number: ");
        scanf("%d", &phone_number);

        add_entry(phonebook, name, phone_number);
    }

    print_table(phonebook);

    return 0;
}