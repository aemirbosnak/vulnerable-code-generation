//FormAI DATASET v1.0 Category: Database Indexing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_ADDRESS_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

typedef struct {
    char key[MAX_NAME_LENGTH];
    int offset;
} Index;

int main() {
    char filename[50];
    printf("Enter the name of the contact file: ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("File not found!\n");
        return 1;
    }
    
    // Indexing the contacts using key-value pairs
    Index *index = (Index*)malloc(sizeof(Index) * 100);
    int contactCount = 0;
    
    // Read contact records from file and build index
    while (!feof(file)) {
        Contact contact;
        int position = ftell(file);
        fscanf(file, "%s%s%s", contact.name, contact.address, contact.phone);
        
        if (strlen(contact.name) == 0) {
            break;
        }
        
        // Add record to index
        strcpy(index[contactCount].key, contact.name);
        index[contactCount].offset = position;
        contactCount++;
    }
    
    fclose(file);
    
    printf("File contains %d contacts.\n", contactCount);
    
    // Sort index alphabetically
    for (int i = 0; i < contactCount - 1; i++) {
        for (int j = i + 1; j < contactCount; j++) {
            if (strcmp(index[i].key, index[j].key) > 0) {
                Index temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }
    
    // Print sorted index
    printf("\nIndex:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%s: %d\n", index[i].key, index[i].offset);
    }
    
    // Search for a contact by name using index
    char searchName[MAX_NAME_LENGTH];
    printf("\nEnter a name to search: ");
    scanf("%s", searchName);
    
    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(searchName, index[i].key) == 0) {
            file = fopen(filename, "r");
            if (fseek(file, index[i].offset, SEEK_SET) != 0) {
                printf("Error seeking file position!\n");
                return 1;
            }
            Contact contact;
            fscanf(file, "%s%s%s", contact.name, contact.address, contact.phone);
            printf("Contact found:\nName: %s\nAddress: %s\nPhone: %s\n", contact.name, contact.address, contact.phone);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Contact not found!\n");
    }
    
    free(index);
    
    return 0;
}