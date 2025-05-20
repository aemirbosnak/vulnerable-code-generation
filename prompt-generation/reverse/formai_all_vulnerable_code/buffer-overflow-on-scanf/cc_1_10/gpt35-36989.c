//FormAI DATASET v1.0 Category: Database Indexing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_ADDRESS_LENGTH 100
#define MAX_INDEX 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
} Contact;

typedef struct {
    int index;
    int position;
} IndexItem;

typedef struct {
    IndexItem items[MAX_INDEX];
    int count;
} Index;

Index createIndex() {
    Index index = {0};
    return index;
}

void addIndexItem(Index *index, int position) {
    if (index->count < MAX_INDEX) {
        index->items[index->count].position = position;
        index->count++;
    }
}

void printIndex(Index *index) {
    printf("Index:\n");
    for (int i = 0; i < index->count; i++) {
        printf("[%d] -> %d\n", index->items[i].index, index->items[i].position);
    }
}

int compareName(const void *a, const void *b) {
    Contact *contactA = (Contact *)a;
    Contact *contactB = (Contact *)b;
    return strcmp(contactA->name, contactB->name);
}

int compareEmail(const void *a, const void *b) {
    Contact *contactA = (Contact *)a;
    Contact *contactB = (Contact *)b;
    return strcmp(contactA->email, contactB->email);
}

int comparePhone(const void *a, const void *b) {
    Contact *contactA = (Contact *)a;
    Contact *contactB = (Contact *)b;
    return strcmp(contactA->phone, contactB->phone);
}

int compareAddress(const void *a, const void *b) {
    Contact *contactA = (Contact *)a;
    Contact *contactB = (Contact *)b;
    return strcmp(contactA->address, contactB->address);
}

void sortContacts(Contact *contacts, int count, int indexField, Index *index) {
    switch (indexField) {
        case 1:
            qsort(contacts, count, sizeof(Contact), compareName);
            break;
        case 2:
            qsort(contacts, count, sizeof(Contact), compareEmail);
            break;
        case 3:
            qsort(contacts, count, sizeof(Contact), comparePhone);
            break;
        case 4:
            qsort(contacts, count, sizeof(Contact), compareAddress);
            break;
        default:
            break;
    }

    index->count = 0;
    for (int i = 0; i < count; i++) {
        addIndexItem(index, i);
        if (i > 0) {
            switch (indexField) {
                case 1:
                    if (strcmp(contacts[i].name, contacts[i-1].name) == 0) {
                        index->items[i].index = index->items[i-1].index;
                    }
                    else {
                        index->items[i].index = i;
                    }
                    break;
                case 2:
                    if (strcmp(contacts[i].email, contacts[i-1].email) == 0) {
                        index->items[i].index = index->items[i-1].index;
                    }
                    else {
                        index->items[i].index = i;
                    }
                    break;
                case 3:
                    if (strcmp(contacts[i].phone, contacts[i-1].phone) == 0) {
                        index->items[i].index = index->items[i-1].index;
                    }
                    else {
                        index->items[i].index = i;
                    }
                    break;
                case 4:
                    if (strcmp(contacts[i].address, contacts[i-1].address) == 0) {
                        index->items[i].index = index->items[i-1].index;
                    }
                    else {
                        index->items[i].index = i;
                    }
                    break;
                default:
                    break;
            }
        }
        else {
            index->items[i].index = i;
        }
    }
}

void printContacts(Contact *contacts, int count, Index *index) {
    printf("Contacts:\n");
    for (int i = 0; i < index->count; i++) {
        int position = index->items[i].position;
        printf("[%d] %s <%s> %s - %s\n", index->items[i].index, contacts[position].name, contacts[position].email, contacts[position].phone, contacts[position].address);
    }
}

int main() {
    int indexField;
    Index index = createIndex();
    Contact contacts[] = {
        {"John Doe", "john.doe@example.com", "555-111-1111", "123 Main St"},
        {"Jane Doe", "jane.doe@example.com", "555-222-2222", "456 Oak St"},
        {"Bob Smith", "bob.smith@example.com", "555-111-1111", "789 Elm St"},
        {"Alice Smith", "alice.smith@example.com", "555-333-3333", "321 Maple St"}
    };
    int count = sizeof(contacts) / sizeof(Contact);
    printf("Unsorted:\n");
    for (int i = 0; i < count; i++) {
        printf("[%d] %s <%s> %s - %s\n", i, contacts[i].name, contacts[i].email, contacts[i].phone, contacts[i].address);
    }
    printf("What field should the contacts be sorted by? (1) Name (2) Email (3) Phone (4) Address: ");
    scanf("%d", &indexField);
    sortContacts(contacts, count, indexField, &index);
    printIndex(&index);
    printContacts(contacts, count, &index);
    return 0;
}