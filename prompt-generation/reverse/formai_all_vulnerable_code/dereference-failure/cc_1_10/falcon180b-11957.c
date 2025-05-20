//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char *name;
    char *email;
} Contact;

Contact *contacts = NULL;
int num_contacts = 0;

void add_contact(char *name, char *email) {
    Contact *new_contact = (Contact *) malloc(sizeof(Contact));
    new_contact->name = strdup(name);
    new_contact->email = strdup(email);
    contacts = realloc(contacts, sizeof(Contact) * ++num_contacts);
    contacts[num_contacts - 1] = *new_contact;
    free(new_contact);
}

void print_contacts() {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s <%s>\n", contacts[i].name, contacts[i].email);
    }
}

int main() {
    FILE *input_file;
    char line[MAX_LINE_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    Contact *contact = NULL;

    input_file = fopen("contacts.txt", "r");

    if (input_file == NULL) {
        printf("Error: Unable to open contacts file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        if (line[0] == '#') {
            continue;
        }

        contact = (Contact *) malloc(sizeof(Contact));
        strcpy(contact->name, line);

        while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL && line[0]!= '#') {
            strcat(contact->name, " ");
            strcat(contact->name, line);
        }

        while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL && line[0]!= '#') {
            strcpy(subject, line);
        }

        while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL && line[0]!= '#') {
            strcpy(email, line);
            break;
        }

        add_contact(contact->name, email);
        free(contact);
    }

    fclose(input_file);

    print_contacts();

    return 0;
}