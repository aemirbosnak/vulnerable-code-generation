//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char* name;
    char* email;
    char* phone;
    char* address;
} Contact;

void initialize_contact(Contact* contact) {
    contact->name = NULL;
    contact->email = NULL;
    contact->phone = NULL;
    contact->address = NULL;
}

void destroy_contact(Contact* contact) {
    if (contact->name!= NULL) {
        free(contact->name);
    }
    if (contact->email!= NULL) {
        free(contact->email);
    }
    if (contact->phone!= NULL) {
        free(contact->phone);
    }
    if (contact->address!= NULL) {
        free(contact->address);
    }
}

void parse_line(char* line, Contact* contact) {
    char* word = strtok(line, " ");
    while (word!= NULL) {
        if (strcasecmp(word, "Name") == 0) {
            contact->name = strdup(strtok(NULL, " "));
        } else if (strcasecmp(word, "Email") == 0) {
            contact->email = strdup(strtok(NULL, " "));
        } else if (strcasecmp(word, "Phone") == 0) {
            contact->phone = strdup(strtok(NULL, " "));
        } else if (strcasecmp(word, "Address") == 0) {
            contact->address = strdup(strtok(NULL, " "));
        }
        word = strtok(NULL, " ");
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    FILE* resume = fopen(argv[1], "r");
    if (resume == NULL) {
        printf("Error opening resume file.\n");
        return 1;
    }

    Contact contact;
    initialize_contact(&contact);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, resume)!= NULL) {
        parse_line(line, &contact);
    }

    fclose(resume);

    printf("Name: %s\n", contact.name);
    printf("Email: %s\n", contact.email);
    printf("Phone: %s\n", contact.phone);
    printf("Address: %s\n", contact.address);

    destroy_contact(&contact);

    return 0;
}