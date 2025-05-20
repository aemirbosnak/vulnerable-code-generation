//FormAI DATASET v1.0 Category: Phone Book ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    char phone_number[MAX_SIZE];
} Contact;

typedef struct {
    int num_contacts;
    Contact contacts[MAX_SIZE];
} PhoneBook;

// Global phonebook object
PhoneBook phonebook = {0};

// Mutexes for accessing phonebook
pthread_mutex_t phonebook_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function for adding contacts
void add_contact(char* name, char* phone_num) {
    // Lock phonebook
    pthread_mutex_lock(&phonebook_mutex);

    // Check if phonebook is full
    if (phonebook.num_contacts >= MAX_SIZE) {
        printf("Error: phonebook is full\n");
        pthread_mutex_unlock(&phonebook_mutex);
        return;
    }

    // Create new contact
    Contact new_contact;
    strcpy(new_contact.name, name);
    strcpy(new_contact.phone_number, phone_num);

    // Add new contact to phonebook
    phonebook.contacts[phonebook.num_contacts] = new_contact;
    phonebook.num_contacts++;

    // Unlock phonebook
    pthread_mutex_unlock(&phonebook_mutex);

    printf("Contact added successfully!\n");
}

// Function for displaying all contacts in phonebook
void display_all_contacts() {
    // Lock phonebook
    pthread_mutex_lock(&phonebook_mutex);

    // Check if phonebook is empty
    if (phonebook.num_contacts == 0) {
        printf("Phonebook is empty\n");
        pthread_mutex_unlock(&phonebook_mutex);
        return;
    }

    printf("Contacts:\n");
    for (int i = 0; i < phonebook.num_contacts; i++) {
        printf("%d. %s: %s\n", i+1, phonebook.contacts[i].name, phonebook.contacts[i].phone_number);
    }

    // Unlock phonebook
    pthread_mutex_unlock(&phonebook_mutex);
}

// Thread function for input
void* input_thread_func(void* arg) {
    while (1) {
        printf("Enter 1 to add a contact, 2 to display all contacts, or 3 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            char name[MAX_SIZE];
            char phone_num[MAX_SIZE];
            printf("Enter contact name: ");
            scanf("%s", name);
            printf("Enter contact phone number: ");
            scanf("%s", phone_num);
            add_contact(name, phone_num);
        } else if (choice == 2) {
            display_all_contacts();
        } else if (choice == 3) {
            printf("Exiting...\n");
            exit(0);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}

// Thread function for processing
void* process_thread_func(void* arg) {
    while (1) {
        // Do some processing task here...
    }
}

int main() {
    // Create input thread
    pthread_t input_thread;
    pthread_create(&input_thread, NULL, input_thread_func, NULL);

    // Create processing thread
    pthread_t process_thread;
    pthread_create(&process_thread, NULL, process_thread_func, NULL);

    // Wait for input thread to finish
    pthread_join(input_thread, NULL);

    return 0;
}