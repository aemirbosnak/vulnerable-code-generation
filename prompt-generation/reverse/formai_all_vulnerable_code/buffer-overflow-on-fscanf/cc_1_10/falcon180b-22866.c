//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_ADDRESS_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char address[MAX_ADDRESS_LEN];
} Contact;

void print_contact(Contact c) {
    printf("Name: %s\n", c.name);
    printf("Email: %s\n", c.email);
    printf("Address: %s\n\n", c.address);
}

int main(int argc, char **argv) {
    FILE *file;
    Contact contacts[100];
    int num_contacts = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fscanf(file, "%s %s %s", contacts[num_contacts].name, contacts[num_contacts].email, contacts[num_contacts].address)!= EOF) {
        num_contacts++;
        if (num_contacts == 100) {
            printf("Maximum number of contacts reached.\n");
            break;
        }
    }

    fclose(file);

    printf("Number of contacts: %d\n", num_contacts);

    for (int i = 0; i < num_contacts; i++) {
        print_contact(contacts[i]);
    }

    return 0;
}