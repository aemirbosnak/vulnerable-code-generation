//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAMES 100
#define MAX_PHONES 10
#define MAX_NAME_LEN 30
#define MAX_PHONE_LEN 15

typedef struct {
    char name[MAX_NAME_LEN + 1];
    char phone[MAX_PHONE_LEN + 1];
} Contact;

int main() {
    int num_contacts = 0;
    Contact contacts[MAX_NAMES];

    printf("Welcome to the Ada Lovelace Phone Book!\n");

    while (num_contacts < MAX_NAMES) {
        printf("Enter a name (or type 'quit' to exit):\n");
        char name[MAX_NAME_LEN + 1];
        scanf("%s", name);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        printf("Enter a phone number:\n");
        char phone[MAX_PHONE_LEN + 1];
        scanf("%s", phone);

        for (int i = 0; i < num_contacts; i++) {
            if (strcmp(contacts[i].name, name) == 0) {
                printf("Duplicate name found!\n");
                break;
            }
        }

        if (num_contacts == MAX_NAMES) {
            printf("Phone book is full!\n");
            break;
        }

        strcpy(contacts[num_contacts].name, name);
        strcpy(contacts[num_contacts].phone, phone);
        num_contacts++;
    }

    printf("\nPhone book:\n");

    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].phone);
    }

    return 0;
}