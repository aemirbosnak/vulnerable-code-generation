//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_CONTACTS 100
#define NAME_SIZE 50
#define PHONE_SIZE 15

typedef struct {
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
    pthread_mutex_t lock;
} PhoneBook;

PhoneBook phoneBook;

void* add_contact(void* arg) {
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];

    printf("Enter Name: ");
    fgets(name, NAME_SIZE, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    printf("Enter Phone: ");
    fgets(phone, PHONE_SIZE, stdin);
    phone[strcspn(phone, "\n")] = 0; // Remove newline

    pthread_mutex_lock(&phoneBook.lock);
    if (phoneBook.count < MAX_CONTACTS) {
        strcpy(phoneBook.contacts[phoneBook.count].name, name);
        strcpy(phoneBook.contacts[phoneBook.count].phone, phone);
        phoneBook.count++;
        printf("Contact added: %s - %s\n", name, phone);
    } else {
        printf("Phone book is full!\n");
    }
    pthread_mutex_unlock(&phoneBook.lock);

    return NULL;
}

void* view_contacts(void* arg) {
    pthread_mutex_lock(&phoneBook.lock);
    printf("Phone Book Contacts:\n");
    for (int i = 0; i < phoneBook.count; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook.contacts[i].name, phoneBook.contacts[i].phone);
    }
    pthread_mutex_unlock(&phoneBook.lock);

    return NULL;
}

void* search_contact(void* arg) {
    char name[NAME_SIZE];
    printf("Enter Name to search: ");
    fgets(name, NAME_SIZE, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    pthread_mutex_lock(&phoneBook.lock);
    int found = 0;
    for (int i = 0; i < phoneBook.count; i++) {
        if (strcmp(phoneBook.contacts[i].name, name) == 0) {
            printf("Contact Found: %s - %s\n", phoneBook.contacts[i].name, phoneBook.contacts[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
    pthread_mutex_unlock(&phoneBook.lock);

    return NULL;
}

void display_menu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Exit\n");
}

int main() {
    phoneBook.count = 0;
    pthread_mutex_init(&phoneBook.lock, NULL);

    int choice;
    pthread_t thread;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear input buffer

        switch (choice) {
            case 1:
                pthread_create(&thread, NULL, add_contact, NULL);
                pthread_detach(thread);
                break;
            case 2:
                pthread_create(&thread, NULL, view_contacts, NULL);
                pthread_detach(thread);
                break;
            case 3:
                pthread_create(&thread, NULL, search_contact, NULL);
                pthread_detach(thread);
                break;
            case 4:
                pthread_mutex_destroy(&phoneBook.lock);
                printf("Exiting phone book. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        sleep(1); // Wait for a moment
    }

    return 0;
}