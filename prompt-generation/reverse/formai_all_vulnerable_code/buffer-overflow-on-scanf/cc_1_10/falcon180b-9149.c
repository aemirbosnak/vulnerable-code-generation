//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 64
#define MAX_NUMBERS_PER_CONTACT 3
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char numbers[MAX_NUMBERS_PER_CONTACT][16];
    int num_numbers;
} Contact;

int main() {
    Contact phonebook[MAX_CONTACTS];
    int num_contacts = 0;

    while(1) {
        printf("Enter a name to add to the phonebook (or type 'quit' to exit):\n");
        scanf("%s", phonebook[num_contacts].name);

        if(strcmp(phonebook[num_contacts].name, "quit") == 0) {
            break;
        }

        phonebook[num_contacts].num_numbers = 0;

        while(1) {
            printf("Enter a phone number for %s (or type 'done' to finish):\n", phonebook[num_contacts].name);
            scanf("%s", phonebook[num_contacts].numbers[phonebook[num_contacts].num_numbers]);

            if(strcmp(phonebook[num_contacts].numbers[phonebook[num_contacts].num_numbers], "done") == 0) {
                break;
            }

            phonebook[num_contacts].num_numbers++;
        }

        num_contacts++;
    }

    printf("Phonebook:\n");
    for(int i = 0; i < num_contacts; i++) {
        printf("%s:\n", phonebook[i].name);
        for(int j = 0; j < phonebook[i].num_numbers; j++) {
            printf("\t%s\n", phonebook[i].numbers[j]);
        }
    }

    return 0;
}