//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <pthread.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_SIZE 50
#define MAX_NUMBER_SIZE 20

typedef struct {
    char name[MAX_NAME_SIZE];
    char number[MAX_NUMBER_SIZE];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void *add_entry_thread(void *arg) {
    char name[MAX_NAME_SIZE];
    char number[MAX_NUMBER_SIZE];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter number: ");
    scanf("%s", number);

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].number, number);

    num_entries++;

    printf("Entry added successfully.\n");
    return NULL;
}

void *search_entry_thread(void *arg) {
    char search_name[MAX_NAME_SIZE];
    int i;

    printf("Enter name to search: ");
    scanf("%s", search_name);

    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Number: %s\n", phonebook[i].number);
            return NULL;
        }
    }

    printf("Entry not found.\n");
    return NULL;
}

int main() {
    pthread_t add_thread, search_thread;

    srand(time(NULL));

    printf("Phonebook program started.\n");

    while (1) {
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Exit\n");

        int choice = rand() % 3;

        switch (choice) {
            case 0:
                break;
            case 1:
                pthread_create(&add_thread, NULL, add_entry_thread, NULL);
                break;
            case 2:
                pthread_create(&search_thread, NULL, search_entry_thread, NULL);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}