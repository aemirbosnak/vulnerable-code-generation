//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

int main() {
    FILE *file;
    char filename[100];
    int num_contacts = 0;
    Contact contacts[MAX_CONTACTS];

    printf("Enter the name of the phone book file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: file not found\n");
        exit(1);
    }

    while (fscanf(file, "%s %s", contacts[num_contacts].name, contacts[num_contacts].number)!= EOF) {
        num_contacts++;
        if (num_contacts >= MAX_CONTACTS) {
            printf("Error: phone book is full\n");
            exit(1);
        }
    }

    fclose(file);

    printf("Enter the name of the contact you want to search for: ");
    scanf("%s", contacts[0].name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, contacts[0].name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Number: %s\n", contacts[i].number);
        }
    }

    return 0;
}