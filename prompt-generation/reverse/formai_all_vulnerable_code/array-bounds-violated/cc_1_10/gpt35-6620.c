//FormAI DATASET v1.0 Category: Database Indexing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_PHONE_LENGTH 20
#define MAX_ADDRESS_LENGTH 255

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
} Contact;

typedef struct {
    int id;
    long position;
} IndexEntry;

typedef struct {
    int size;
    IndexEntry *entries;
} Index;

void insert(Contact contact, FILE *dataFile, Index *index) {
    fseek(dataFile, 0, SEEK_END);
    long position = ftell(dataFile);
    fprintf(dataFile, "%s|%s|%s\n", contact.name, contact.phone, contact.address);
    
    IndexEntry entry = { index->size, position };
    index->size++;
    index->entries = realloc(index->entries, index->size * sizeof(IndexEntry));
    memcpy(&index->entries[index->size - 1], &entry, sizeof(IndexEntry));
}

Contact readContact(FILE *dataFile, long position) {
    Contact contact;
    fseek(dataFile, position, SEEK_SET);
    fscanf(dataFile, "%[^|]|%[^|]|%[^\n]\n",
        contact.name, contact.phone, contact.address);
    return contact;
}

void printContact(Contact contact) {
    printf("%s (%s) %s\n", contact.name, contact.phone, contact.address);
}

void printIndex(Index index, FILE *dataFile) {
    int i;
    for (i = 0; i < index.size; i++) {
        Contact contact = readContact(dataFile, index.entries[i].position);
        printf("%d - ", index.entries[i].id);
        printContact(contact);
    }
}

int binarySearch(char *term, Index index, FILE *dataFile) {
    int i = 0, j = index.size - 1;
    while (i <= j) {
        int m = (i + j) / 2;
        Contact contact = readContact(dataFile, index.entries[m].position);
        int cmp = strcmp(contact.name, term);
        if (cmp == 0) {
            return m;
        } else if (cmp < 0) {
            i = m + 1;
        } else {
            j = m - 1;
        }
    }
    return -1;
}

int main() {
    FILE *dataFile = fopen("data.txt", "a+");
    Index index = { 0, NULL };
    
    char choice;
    do {
        printf("Enter name (q to quit): ");
        char name[MAX_NAME_LENGTH];
        fgets(name, MAX_NAME_LENGTH, stdin);
        if (name[0] == 'q') {
            break;
        }
        name[strlen(name) - 1] = '\0';
        
        printf("Enter phone number: ");
        char phone[MAX_PHONE_LENGTH];
        fgets(phone, MAX_PHONE_LENGTH, stdin);
        phone[strlen(phone) - 1] = '\0';
        
        printf("Enter address: ");
        char address[MAX_ADDRESS_LENGTH];
        fgets(address, MAX_ADDRESS_LENGTH, stdin);
        address[strlen(address) - 1] = '\0';
        
        Contact contact = { "", "", "" };
        strcpy(contact.name, name);
        strcpy(contact.phone, phone);
        strcpy(contact.address, address);
        
        insert(contact, dataFile, &index);
    } while (1);
    
    printf("\n");
    printIndex(index, dataFile);
    
    printf("\nEnter a name to search (q to quit): ");
    char term[MAX_NAME_LENGTH];
    fgets(term, MAX_NAME_LENGTH, stdin);
    term[strlen(term) - 1] = '\0';
    while (term[0] != 'q') {
        int id = binarySearch(term, index, dataFile);
        if (id == -1) {
            printf("Not found.\n");
        } else {
            Contact contact = readContact(dataFile, index.entries[id].position);
            printContact(contact);
        }
        printf("\nEnter a name to search (q to quit): ");
        fgets(term, MAX_NAME_LENGTH, stdin);
        term[strlen(term) - 1] = '\0';
    }
    
    fclose(dataFile);
    return 0;
}