//FormAI DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 30
#define MAX_RETRIES 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

void save_contacts(Contact contacts[], int num_contacts) {
    FILE *file = fopen("contacts.txt", "wb");

    if (file != NULL) {
        fwrite(&num_contacts, sizeof(int), 1, file);

        for (int i = 0; i < num_contacts; i++) {
            fwrite(&contacts[i], sizeof(Contact), 1, file);
        }

        fclose(file);
        printf("Contacts saved successfully.\n");
    } else {
        printf("Error saving contacts.\n");
    }
}

int load_contacts(Contact contacts[]) {
    FILE *file = fopen("contacts.txt", "rb");

    if (file != NULL) {
        int num_contacts;

        fread(&num_contacts, sizeof(int), 1, file);

        for (int i = 0; i < num_contacts; i++) {
            fread(&contacts[i], sizeof(Contact), 1, file);
        }

        fclose(file);
        printf("Contacts loaded successfully.\n");
        return num_contacts;
    } else {
        printf("Error loading contacts.\n");
        return 0;
    }
}

void add_contact(Contact contacts[], int *num_contacts) {
    if (*num_contacts < MAX_RETRIES) {
        printf("Name: ");
        scanf("%s", contacts[*num_contacts].name);

        printf("Email: ");
        scanf("%s", contacts[*num_contacts].email);

        printf("Contact added successfully.\n");
        (*num_contacts)++;
    } else {
        printf("Maximum number of contacts reached.\n");
    }
}

int menu() {
    int option;

    printf("1. Add contact\n");
    printf("2. List contacts\n");
    printf("3. Save contacts\n");
    printf("4. Load contacts\n");
    printf("5. Exit\n");

    do {
        printf("Option: ");
        scanf("%d", &option);
    } while (option < 1 || option > 5);

    return option;
}

int main() {
    Contact contacts[MAX_RETRIES];
    int num_contacts = 0;
    int option;

    do {
        option = menu();

        switch (option) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                for (int i = 0; i < num_contacts; i++) {
                    printf("%s %s\n", contacts[i].name, contacts[i].email);
                }
                break;
            case 3:
                save_contacts(contacts, num_contacts);
                break;
            case 4:
                num_contacts = load_contacts(contacts);
                break;
        }
    } while (option != 5);

    return 0;
}