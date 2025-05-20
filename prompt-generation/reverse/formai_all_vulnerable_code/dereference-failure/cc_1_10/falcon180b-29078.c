//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_LIST_SIZE 1000
#define MAX_NAME_SIZE 50

typedef struct {
    char name[MAX_NAME_SIZE];
    char email[MAX_NAME_SIZE];
} contact;

typedef struct {
    contact *list;
    int size;
    pthread_mutex_t lock;
} mailing_list;

mailing_list list = {NULL, 0, PTHREAD_MUTEX_INITIALIZER};

void add_contact(contact *c) {
    pthread_mutex_lock(&list.lock);
    if (list.size >= MAX_LIST_SIZE) {
        printf("List is full.\n");
        pthread_mutex_unlock(&list.lock);
        return;
    }
    list.list = realloc(list.list, sizeof(contact) * (list.size + 1));
    if (list.list == NULL) {
        printf("Memory error.\n");
        pthread_mutex_unlock(&list.lock);
        return;
    }
    memcpy(&list.list[list.size], c, sizeof(contact));
    list.size++;
    pthread_mutex_unlock(&list.lock);
    printf("Contact added successfully.\n");
}

void remove_contact(char *name) {
    int i;
    pthread_mutex_lock(&list.lock);
    for (i = 0; i < list.size; i++) {
        if (strcmp(list.list[i].name, name) == 0) {
            memmove(&list.list[i], &list.list[i + 1], sizeof(contact) * (list.size - i - 1));
            list.size--;
            pthread_mutex_unlock(&list.lock);
            printf("Contact removed successfully.\n");
            return;
        }
    }
    pthread_mutex_unlock(&list.lock);
    printf("Contact not found.\n");
}

void print_list() {
    int i;
    pthread_mutex_lock(&list.lock);
    for (i = 0; i < list.size; i++) {
        printf("%s: %s\n", list.list[i].name, list.list[i].email);
    }
    pthread_mutex_unlock(&list.lock);
}

void *thread_func(void *arg) {
    char name[MAX_NAME_SIZE];
    char email[MAX_NAME_SIZE];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your email: ");
    scanf("%s", email);

    add_contact(&(contact){.name = strdup(name),.email = strdup(email)});

    return NULL;
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, NULL);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    print_list();

    return 0;
}