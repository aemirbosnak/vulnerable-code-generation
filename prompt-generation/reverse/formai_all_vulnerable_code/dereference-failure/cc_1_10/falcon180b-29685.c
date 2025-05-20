//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 50
#define MAX_NUMBERS_PER_CONTACT 5
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LEN];
    int num_phone_numbers;
    char *phone_numbers[MAX_NUMBERS_PER_CONTACT];
} Contact;

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;
    char input[100];

    while (1) {
        printf("Enter a name to add to the phone book or 'exit' to quit: ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        Contact *new_contact = &contacts[num_contacts];
        strcpy(new_contact->name, input);
        new_contact->num_phone_numbers = 0;

        while (1) {
            printf("Enter a phone number (or 'done' to finish): ");
            scanf("%s", input);

            if (strcmp(input, "done") == 0) {
                break;
            }

            char *phone_number = malloc(strlen(input) + 1);
            strcpy(phone_number, input);
            new_contact->phone_numbers[new_contact->num_phone_numbers++] = phone_number;
        }

        num_contacts++;
    }

    printf("\nPhone Book:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s:\n", contacts[i].name);
        for (int j = 0; j < contacts[i].num_phone_numbers; j++) {
            printf("  %s\n", contacts[i].phone_numbers[j]);
        }
        printf("\n");
    }

    return 0;
}