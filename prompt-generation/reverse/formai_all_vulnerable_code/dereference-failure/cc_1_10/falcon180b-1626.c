//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_ADDRESS_LENGTH 200
#define MAX_PHONE_NUMBER_LENGTH 20
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact_t;

typedef struct {
    int num_contacts;
    contact_t contacts[100];
} contact_list_t;

int read_contact_file(contact_list_t *contact_list) {
    FILE *contact_file;
    char line[1000];
    char *token;
    int line_num = 0;
    contact_t contact;

    contact_file = fopen("contacts.txt", "r");
    if (contact_file == NULL) {
        printf("Error: could not open contacts file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), contact_file)!= NULL) {
        line_num++;
        token = strtok(line, ",");
        strcpy(contact.name, token);

        token = strtok(NULL, ",");
        strcpy(contact.address, token);

        token = strtok(NULL, ",");
        strcpy(contact.phone_number, token);

        token = strtok(NULL, ",");
        strcpy(contact.email, token);

        contact_list->contacts[contact_list->num_contacts++] = contact;
    }

    fclose(contact_file);
    return 0;
}

void print_contact_list(contact_list_t *contact_list) {
    int i;

    printf("Name\tAddress\tPhone Number\tEmail\n");
    for (i = 0; i < contact_list->num_contacts; i++) {
        printf("%s\t%s\t%s\t%s\n", contact_list->contacts[i].name, contact_list->contacts[i].address, contact_list->contacts[i].phone_number, contact_list->contacts[i].email);
    }
}

int main() {
    contact_list_t contact_list;

    memset(&contact_list, 0, sizeof(contact_list));
    read_contact_file(&contact_list);
    print_contact_list(&contact_list);

    return 0;
}