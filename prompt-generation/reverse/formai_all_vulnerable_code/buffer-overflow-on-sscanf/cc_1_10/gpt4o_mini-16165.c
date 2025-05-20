//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
    pthread_mutex_t mutex;
} PhoneBook;

PhoneBook phoneBook;

void initialize_phone_book() {
    phoneBook.count = 0;
    pthread_mutex_init(&phoneBook.mutex, NULL);
}

void add_contact(char *name, char *phone) {
    pthread_mutex_lock(&phoneBook.mutex);
    if (phoneBook.count < MAX_CONTACTS) {
        strncpy(phoneBook.contacts[phoneBook.count].name, name, NAME_LENGTH);
        strncpy(phoneBook.contacts[phoneBook.count].phone, phone, PHONE_LENGTH);
        phoneBook.count++;
        printf("Contact added: %s, %s\n", name, phone);
    } else {
        printf("Phone book is full!\n");
    }
    pthread_mutex_unlock(&phoneBook.mutex);
}

void delete_contact(char *name) {
    pthread_mutex_lock(&phoneBook.mutex);
    for (int i = 0; i < phoneBook.count; i++) {
        if (strcmp(phoneBook.contacts[i].name, name) == 0) {
            printf("Deleting contact: %s\n", phoneBook.contacts[i].name);
            for (int j = i; j < phoneBook.count - 1; j++) {
                phoneBook.contacts[j] = phoneBook.contacts[j + 1];
            }
            phoneBook.count--;
            pthread_mutex_unlock(&phoneBook.mutex);
            return;
        }
    }
    printf("Contact not found!\n");
    pthread_mutex_unlock(&phoneBook.mutex);
}

void search_contact(char *name) {
    pthread_mutex_lock(&phoneBook.mutex);
    for (int i = 0; i < phoneBook.count; i++) {
        if (strcmp(phoneBook.contacts[i].name, name) == 0) {
            printf("Found contact: %s, %s\n", phoneBook.contacts[i].name, phoneBook.contacts[i].phone);
            pthread_mutex_unlock(&phoneBook.mutex);
            return;
        }
    }
    printf("Contact not found!\n");
    pthread_mutex_unlock(&phoneBook.mutex);
}

void *user_interface(void *arg) {
    char command[100];
    char name[NAME_LENGTH], phone[PHONE_LENGTH];

    while (1) {
        printf("Enter command (add <name> <phone>, delete <name>, search <name>, exit): ");
        fgets(command, sizeof(command), stdin);
        if (sscanf(command, "add %s %s", name, phone) == 2) {
            add_contact(name, phone);
        } else if (sscanf(command, "delete %s", name) == 1) {
            delete_contact(name);
        } else if (sscanf(command, "search %s", name) == 1) {
            search_contact(name);
        } else if (strcmp(command, "exit\n") == 0) {
            printf("Exiting.\n");
            break;
        } else {
            printf("Invalid command!\n");
        }
    }
    
    return NULL;
}

int main() {
    initialize_phone_book();
    
    pthread_t ui_thread;
    pthread_create(&ui_thread, NULL, user_interface, NULL);
    pthread_join(ui_thread, NULL);
    
    pthread_mutex_destroy(&phoneBook.mutex);
    return 0;
}