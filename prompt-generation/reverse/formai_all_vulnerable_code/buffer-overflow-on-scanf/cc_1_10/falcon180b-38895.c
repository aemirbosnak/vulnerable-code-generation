//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *add_entry(void *arg) {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter phone number: ");
    scanf("%s", phone);

    pthread_mutex_lock(&lock);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Duplicate entry found!\n");
            pthread_mutex_unlock(&lock);
            return NULL;
        }
    }

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].phone, phone);
    num_entries++;

    printf("Entry added successfully!\n");
    pthread_mutex_unlock(&lock);

    return NULL;
}

void *search_entry(void *arg) {
    char name[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", name);

    pthread_mutex_lock(&lock);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone);
            pthread_mutex_unlock(&lock);
            return NULL;
        }
    }

    printf("Entry not found!\n");
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_t thread_id[2];

    printf("Phonebook initialized with %d entries.\n", num_entries);
    printf("Enter 1 to add an entry.\n");
    printf("Enter 2 to search for an entry.\n");

    while (1) {
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                pthread_create(&thread_id[0], NULL, add_entry, NULL);
                break;
            }

            case 2: {
                pthread_create(&thread_id[1], NULL, search_entry, NULL);
                break;
            }

            default: {
                printf("Invalid choice!\n");
            }
        }
    }

    return 0;
}