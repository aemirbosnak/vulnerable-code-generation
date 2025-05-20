//FormAI DATASET v1.0 Category: Phone Book ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[30];
    int age;
    char phone[15];
} Contact;

Contact phonebook[MAX_CONTACTS];
int num_contacts = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void add_contact() {
    pthread_mutex_lock(&lock);
    if(num_contacts == MAX_CONTACTS) {
        printf("Phone book is full, cannot add new contact.\n");
    }
    else {
        Contact new_contact;
        printf("Enter name, age, and phone number separated by spaces: ");
        scanf("%s %d %s", new_contact.name, &new_contact.age, new_contact.phone);
        phonebook[num_contacts] = new_contact;
        num_contacts++;
        printf("Contact added successfully!\n");
    }
    pthread_mutex_unlock(&lock);
}

void search_contact() {
    pthread_mutex_lock(&lock);
    char search_name[30];
    printf("Enter name to search for: ");
    scanf("%s", search_name);
    int found = 0;
    for(int i=0; i<num_contacts; i++) {
        if(strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\nAge: %d\nPhone: %s\n", phonebook[i].name, phonebook[i].age, phonebook[i].phone);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Contact not found.\n");
    }
    pthread_mutex_unlock(&lock);
}

void delete_contact() {
    pthread_mutex_lock(&lock);
    char delete_name[30];
    printf("Enter name to delete: ");
    scanf("%s", delete_name);
    int found = 0;
    for(int i=0; i<num_contacts; i++) {
        if(strcmp(phonebook[i].name, delete_name) == 0) {
            phonebook[i] = phonebook[num_contacts-1];
            num_contacts--;
            printf("Contact deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Contact not found.\n");
    }
    pthread_mutex_unlock(&lock);
}

void* menu(void* arg) {
    char choice;
    do {
        printf("Please select an option:\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Delete contact\n");
        printf("4. Quit\n");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                add_contact();
                break;
            case '2':
                search_contact();
                break;
            case '3':
                delete_contact();
                break;
            case '4':
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != '4');
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, menu, NULL);
    pthread_join(tid, NULL);
    printf("Goodbye!\n");
    return 0;
}