//Falcon-180B DATASET v1.0 Category: Email Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_WORD 64

typedef struct {
    char *name;
    char *address;
} Contact;

Contact *contacts = NULL;
int num_contacts = 0;

void add_contact(char *name, char *address) {
    Contact *contact = malloc(sizeof(Contact));
    contact->name = strdup(name);
    contact->address = strdup(address);
    contacts = realloc(contacts, sizeof(Contact) * ++num_contacts);
    contacts[num_contacts - 1] = *contact;
    free(contact);
}

int main() {
    char line[MAX_LINE];
    char word[MAX_WORD];
    char *name = NULL;
    char *address = NULL;
    int state = 0;

    while (fgets(line, MAX_LINE, stdin)!= NULL) {
        if (state == 0) {
            if (sscanf(line, "From: %[^<>]", word) == 1) {
                name = strdup(word);
                state = 1;
            }
        } else if (state == 1) {
            if (sscanf(line, "To: %[^<>]", word) == 1) {
                address = strdup(word);
                add_contact(name, address);
                name = NULL;
                address = NULL;
                state = 0;
            }
        }
    }

    for (int i = 0; i < num_contacts; i++) {
        printf("%s <%s>\n", contacts[i].name, contacts[i].address);
    }

    for (int i = 0; i < num_contacts; i++) {
        free(contacts[i].name);
        free(contacts[i].address);
    }
    free(contacts);

    return 0;
}