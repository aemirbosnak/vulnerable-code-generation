//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_AGE 120
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} Person;

Person entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, int age) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Too many entries.\n");
        return;
    }

    strncpy(entries[num_entries].name, name, MAX_NAME_LEN);
    entries[num_entries].age = age;
    num_entries++;
}

void search_entries(char* query) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, query) == 0) {
            printf("Name: %s\nAge: %d\n", entries[i].name, entries[i].age);
        }
    }
}

int main() {
    char input[100];

    while (1) {
        printf("Enter command (add/search/exit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("Enter name: ");
            scanf("%s", input);
            printf("Enter age: ");
            scanf("%d", &input);
            add_entry(input, atoi(input));
        } else if (strcmp(input, "search") == 0) {
            printf("Enter name to search: ");
            scanf("%s", input);
            search_entries(input);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}