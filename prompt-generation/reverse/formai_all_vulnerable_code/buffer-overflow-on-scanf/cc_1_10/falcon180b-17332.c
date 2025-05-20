//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_NAME_LENGTH 30
#define MAX_NUMBER_LENGTH 15
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

void add_entry(entry_t *phonebook, int count) {
    printf("Enter name (max %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", phonebook[count].name);

    printf("Enter phone number (max %d characters): ", MAX_NUMBER_LENGTH - 1);
    scanf("%s", phonebook[count].number);
}

void search_entry(entry_t *phonebook, int count, char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Found entry:\n");
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone number: %s\n", phonebook[i].number);
            return;
        }
    }

    printf("No entry found.\n");
}

int main() {
    srand(time(NULL));
    int count = (rand() % MAX_ENTRIES) + 1;

    entry_t phonebook[MAX_ENTRIES];

    for (int i = 0; i < count; i++) {
        add_entry(phonebook, i);
    }

    char name[MAX_NAME_LENGTH];

    while (1) {
        printf("Search for an entry:\n");
        scanf("%s", name);

        search_entry(phonebook, count, name);
    }

    return 0;
}