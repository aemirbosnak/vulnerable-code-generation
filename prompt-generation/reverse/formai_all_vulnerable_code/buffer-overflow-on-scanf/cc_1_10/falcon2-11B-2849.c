//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_TELEPHONE_LENGTH 15

// Structure to store contact information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char telephone[MAX_TELEPHONE_LENGTH];
} Contact;

// Function to print contact information
void printContact(Contact* contact) {
    printf("Name: %s\n", contact->name);
    printf("Address: %s\n", contact->address);
    printf("Telephone: %s\n", contact->telephone);
}

// Function to parse and store contact information
void parseContact(Contact* contact, char* line) {
    char* token = strtok(line, ",");
    while (token!= NULL) {
        if (strlen(token) > 0) {
            strcpy(contact->name, token);
        }
        token = strtok(NULL, ",");
        if (strlen(token) > 0) {
            strcpy(contact->address, token);
        }
        token = strtok(NULL, ",");
        if (strlen(token) > 0) {
            strcpy(contact->telephone, token);
        }
    }
}

int main() {
    Contact contact;
    char line[MAX_NAME_LENGTH + MAX_ADDRESS_LENGTH + MAX_TELEPHONE_LENGTH + 1];
    while (1) {
        printf("Enter contact information (or 'q' to quit): ");
        if (scanf("%s", line)!= 1) {
            break;
        }
        if (strcmp(line, "q") == 0) {
            break;
        }
        parseContact(&contact, line);
        printContact(&contact);
    }
    return 0;
}