//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_NUM_LEN 15

struct contact {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
};

int main() {
    struct contact contacts[100];
    int num_contacts = 0;

    printf("Welcome to the C Phone Book!\n");
    printf("Enter the number of contacts you want to add: ");
    scanf("%d", &num_contacts);

    for (int i = 0; i < num_contacts; i++) {
        printf("Enter contact name: ");
        scanf("%s", contacts[i].name);

        printf("Enter contact number: ");
        scanf("%s", contacts[i].number);

        printf("Contact added!\n");
    }

    printf("Enter a name to search for: ");
    scanf("%s", &contacts[0].name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, &contacts[0].name) == 0) {
            printf("Contact found!\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Number: %s\n", contacts[i].number);
        }
    }

    printf("Enter a name to delete: ");
    scanf("%s", &contacts[0].name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, &contacts[0].name) == 0) {
            for (int j = i; j < num_contacts - 1; j++) {
                strcpy(contacts[j].name, contacts[j + 1].name);
                strcpy(contacts[j].number, contacts[j + 1].number);
            }
            num_contacts--;
        }
    }

    printf("Contacts deleted!\n");

    return 0;
}