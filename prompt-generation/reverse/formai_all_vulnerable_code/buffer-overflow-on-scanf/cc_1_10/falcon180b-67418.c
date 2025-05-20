//Falcon-180B DATASET v1.0 Category: Database querying ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 1000
#define MAX_NUM_KEYS 100

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} key_value_pair;

int num_keys = 0;
key_value_pair keys[MAX_NUM_KEYS];

void add_key_value_pair() {
    if(num_keys >= MAX_NUM_KEYS) {
        printf("Error: Cannot add more key-value pairs.\n");
        return;
    }
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
    printf("Enter key: ");
    scanf("%s", key);
    printf("Enter value: ");
    scanf("%s", value);
    strcpy(keys[num_keys].key, key);
    strcpy(keys[num_keys].value, value);
    num_keys++;
}

void search_key() {
    char search_key[MAX_KEY_SIZE];
    printf("Enter key to search: ");
    scanf("%s", search_key);
    for(int i=0; i<num_keys; i++) {
        if(strcmp(keys[i].key, search_key) == 0) {
            printf("Value for key '%s': %s\n", search_key, keys[i].value);
            return;
        }
    }
    printf("Key not found.\n");
}

int main() {
    printf("Welcome to the key-value database!\n");
    while(1) {
        printf("\nOptions:\n");
        printf("1. Add key-value pair\n");
        printf("2. Search key\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_key_value_pair();
                break;
            case 2:
                search_key();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}