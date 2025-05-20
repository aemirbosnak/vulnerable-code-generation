//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define NAME_LEN 50
#define NUMBER_LEN 15

struct entry {
    char name[NAME_LEN];
    char number[NUMBER_LEN];
};

struct entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void *add_entry(void *arg) {
    char name[NAME_LEN];
    char number[NUMBER_LEN];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", number);

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].number, number);
    num_entries++;

    pthread_exit(0);
}

void *search_entry(void *arg) {
    char search_name[NAME_LEN];

    printf("Enter name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].number);
            pthread_exit(0);
        }
    }

    printf("Entry not found.\n");
    pthread_exit(0);
}

int main() {
    pthread_t thread_id[2];

    printf("Phonebook application\n");
    printf("1. Add entry\n2. Search entry\n");

    while(1) {
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                pthread_create(&thread_id[0], NULL, add_entry, NULL);
                pthread_join(thread_id[0], NULL);
                break;

            case 2:
                pthread_create(&thread_id[1], NULL, search_entry, NULL);
                pthread_join(thread_id[1], NULL);
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}