//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

int compare_names(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int compare_emails(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void print_contact(Contact contact) {
    printf("Name: %s\nEmail: %s\n", contact.name, contact.email);
}

int main() {
    int num_contacts;
    Contact *contacts;
    char input_buffer[1024];

    printf("Welcome to the Happy Mailing List Manager!\n");
    printf("How many contacts would you like to add? ");
    scanf("%d", &num_contacts);

    contacts = malloc(num_contacts * sizeof(Contact));

    for (int i = 0; i < num_contacts; i++) {
        printf("Enter the name for contact #%d: ", i + 1);
        scanf("%s", contacts[i].name);

        printf("Enter the email for contact #%d: ", i + 1);
        scanf("%s", contacts[i].email);
    }

    qsort(contacts, num_contacts, sizeof(Contact), compare_names);

    for (int i = 0; i < num_contacts; i++) {
        print_contact(contacts[i]);
    }

    free(contacts);

    return 0;
}