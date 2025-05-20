//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

int main() {
    FILE *file;
    Contact contacts[MAX_CONTACTS];
    int count = 0;

    // Open the file for reading
    file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Read in the contacts
    char line[MAX_NAME_LENGTH + MAX_NUMBER_LENGTH + 3];
    while (fgets(line, sizeof(line), file)!= NULL) {
        int i = 0;
        while (line[i]!= '\t') {
            contacts[count].name[i] = line[i];
            i++;
        }
        contacts[count].name[i] = '\0';
        i++;
        while (i < strlen(line)) {
            contacts[count].number[i - MAX_NAME_LENGTH - 1] = line[i];
            i++;
        }
        contacts[count].number[i - MAX_NAME_LENGTH - 1] = '\0';
        count++;
    }

    // Close the file
    fclose(file);

    // Print out the contacts
    printf("Phonebook:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].number);
    }

    return 0;
}