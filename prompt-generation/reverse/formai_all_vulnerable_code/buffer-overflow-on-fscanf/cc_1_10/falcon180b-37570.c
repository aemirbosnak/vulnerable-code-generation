//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBERS_PER_CONTACT 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char numbers[MAX_NUMBERS_PER_CONTACT][15];
    int num_numbers;
} Contact;

int main() {
    FILE *phonebook_file;
    Contact contacts[100];
    int num_contacts = 0;
    char filename[20];

    printf("Enter the name of the phone book file: ");
    scanf("%s", filename);

    phonebook_file = fopen(filename, "r");

    if (phonebook_file == NULL) {
        printf("Phone book file not found.\n");
        return 1;
    }

    while (fscanf(phonebook_file, "%s %s %s", contacts[num_contacts].name, contacts[num_contacts].numbers[0], contacts[num_contacts].numbers[1])!= EOF) {
        num_contacts++;
    }

    fclose(phonebook_file);

    printf("Enter the name of the contact you want to search for: ");
    char search_name[MAX_NAME_LENGTH];
    scanf("%s", search_name);

    tolower(search_name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Name: %s\n", contacts[i].name);

            for (int j = 0; j < contacts[i].num_numbers; j++) {
                printf("Phone number %d: %s\n", j + 1, contacts[i].numbers[j]);
            }
        }
    }

    return 0;
}