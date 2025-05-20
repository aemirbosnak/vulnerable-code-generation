//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[30];
    char phone[15];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void *add_contact(void *arg) {
    char name[30];
    char phone[15];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", phone);

    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].phone, phone);

    num_contacts++;

    pthread_exit(0);
}

void *delete_contact(void *arg) {
    char name[30];

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < num_contacts - 1; j++) {
                strcpy(contacts[j].name, contacts[j + 1].name);
                strcpy(contacts[j].phone, contacts[j + 1].phone);
            }

            num_contacts--;

            pthread_exit(0);
        }
    }

    pthread_exit(0);
}

void *search_contact(void *arg) {
    char name[30];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);

            pthread_exit(0);
        }
    }

    pthread_exit(0);
}

int main() {
    pthread_t threads[3];

    pthread_create(&threads[0], NULL, add_contact, NULL);
    pthread_create(&threads[1], NULL, delete_contact, NULL);
    pthread_create(&threads[2], NULL, search_contact, NULL);

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}