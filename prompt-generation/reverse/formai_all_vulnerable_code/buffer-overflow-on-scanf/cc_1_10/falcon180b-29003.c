//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBERS_PER_CONTACT 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char numbers[MAX_NUMBERS_PER_CONTACT][15];
    int num_numbers;
} Contact;

int main() {
    Contact phone_book[100];
    int num_contacts = 0;

    while (num_contacts < 100) {
        printf("Enter a name (or type \"done\" to finish): ");
        scanf("%s", phone_book[num_contacts].name);

        if (strcmp(phone_book[num_contacts].name, "done") == 0) {
            break;
        }

        printf("Enter a phone number: ");
        scanf("%s", phone_book[num_contacts].numbers[0]);
        phone_book[num_contacts].num_numbers = 1;

        while (phone_book[num_contacts].num_numbers < MAX_NUMBERS_PER_CONTACT) {
            printf("Enter another phone number (or press enter to finish): ");
            scanf("%s", phone_book[num_contacts].numbers[phone_book[num_contacts].num_numbers]);

            if (strcmp(phone_book[num_contacts].numbers[phone_book[num_contacts].num_numbers], "") == 0) {
                break;
            }

            phone_book[num_contacts].num_numbers++;
        }

        num_contacts++;
    }

    printf("\nPhone Book:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s - ", phone_book[i].name);

        for (int j = 0; j < phone_book[i].num_numbers; j++) {
            printf("%s ", phone_book[i].numbers[j]);
        }

        printf("\n");
    }

    return 0;
}