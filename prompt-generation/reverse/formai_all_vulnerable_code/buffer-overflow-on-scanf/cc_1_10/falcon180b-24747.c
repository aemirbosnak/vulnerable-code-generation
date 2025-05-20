//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_VALUE_SIZE 1024
#define MAX_NUM_KEYS 100

struct key_value_pair {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
};

int num_keys = 0;
struct key_value_pair database[MAX_NUM_KEYS];

void add_key_value_pair() {
    if (num_keys >= MAX_NUM_KEYS) {
        printf("Error: Maximum number of key-value pairs reached.\n");
        return;
    }

    char key[MAX_KEY_SIZE];
    printf("Enter key: ");
    scanf("%s", key);

    char value[MAX_VALUE_SIZE];
    printf("Enter value: ");
    scanf("%[^\n]", value);

    strcpy(database[num_keys].key, key);
    strcpy(database[num_keys].value, value);

    num_keys++;
}

void print_key_value_pairs() {
    printf("\nKey-Value Pairs:\n");
    for (int i = 0; i < num_keys; i++) {
        printf("%s -> %s\n", database[i].key, database[i].value);
    }
}

void search_key_value_pair() {
    char key[MAX_KEY_SIZE];
    printf("Enter key to search: ");
    scanf("%s", key);

    for (int i = 0; i < num_keys; i++) {
        if (strcmp(database[i].key, key) == 0) {
            printf("Value: %s\n", database[i].value);
            return;
        }
    }

    printf("Key not found.\n");
}

int main() {
    printf("Welcome to the C Database Simulation!\n");

    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add key-value pair\n");
        printf("2. Print all key-value pairs\n");
        printf("3. Search for a key\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_key_value_pair();
                break;
            case 2:
                print_key_value_pairs();
                break;
            case 3:
                search_key_value_pair();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}