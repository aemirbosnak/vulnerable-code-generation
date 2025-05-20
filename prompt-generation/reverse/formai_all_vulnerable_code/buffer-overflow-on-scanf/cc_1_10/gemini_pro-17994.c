//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char number[20];
} Contact;

Contact contacts[100];
int num_contacts = 0;

pthread_mutex_t lock;

void add_contact(Contact contact) {
    pthread_mutex_lock(&lock);
    contacts[num_contacts++] = contact;
    pthread_mutex_unlock(&lock);
}

void search_contact(char *name) {
    pthread_mutex_lock(&lock);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("%s: %s\n", contacts[i].name, contacts[i].number);
            break;
        }
    }
    pthread_mutex_unlock(&lock);
}

void *phone_book_thread(void *arg) {
    char *input = (char *)arg;
    char *command = strtok(input, " ");
    if (strcmp(command, "add") == 0) {
        char *name = strtok(NULL, " ");
        char *number = strtok(NULL, " ");
        Contact contact = { .name = name, .number = number };
        add_contact(contact);
    } else if (strcmp(command, "search") == 0) {
        char *name = strtok(NULL, " ");
        search_contact(name);
    }
    return NULL;
}

int main() {
    pthread_mutex_init(&lock, NULL);
    pthread_t threads[100];
    int num_threads = 0;
    while (1) {
        char input[100];
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        pthread_create(&threads[num_threads++], NULL, phone_book_thread, input);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&lock);
    return 0;
}