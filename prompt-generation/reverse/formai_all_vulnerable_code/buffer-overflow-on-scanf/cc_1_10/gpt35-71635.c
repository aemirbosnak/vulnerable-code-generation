//FormAI DATASET v1.0 Category: Data validation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_TEL_LEN 20
#define MAX_EMAIL_LEN 50

typedef struct {
    char name[MAX_NAME_LEN + 1];
    char telephone[MAX_TEL_LEN + 1];
    char email[MAX_EMAIL_LEN + 1];
} Contact;

void clear_input_buffer(void) {
    while (getchar() != '\n')
        ;
}

int is_name_valid(const char *name) {
    int len = strlen(name);
    if (len < 2 || len > MAX_NAME_LEN) {
        return 0;
    }

    for (int i = 0; i < len; ++i) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            return 0;
        }
    }

    return 1;
}

int is_telephone_valid(const char *telephone) {
    int len = strlen(telephone);
    if (len < 10 || len > MAX_TEL_LEN) {
        return 0;
    }

    for (int i = 0; i < len; ++i) {
        if (!isdigit(telephone[i])) {
            return 0;
        }
    }

    return 1;
}

int is_email_valid(const char *email) {
    int len = strlen(email);
    if (len < 5 || len > MAX_EMAIL_LEN) {
        return 0;
    }

    // find the '@' symbol
    int at_pos = -1;
    for (int i = 0; i < len; ++i) {
        if (email[i] == '@') {
            at_pos = i;
            break;
        }
    }

    if (at_pos == -1 || at_pos == 0 || at_pos == len - 1) {
        return 0;
    }

    // check the username part of the email
    for (int i = 0; i < at_pos; ++i) {
        if (!isalnum(email[i]) && email[i] != '_' && email[i] != '.') {
            return 0;
        }
    }

    // check the domain part of the email
    for (int i = at_pos + 1; i < len; ++i) {
        if (!isalnum(email[i]) && email[i] != '.' && email[i] != '-') {
            return 0;
        }
    }

    return 1;
}

void add_contact(Contact *contacts, int *num_contacts) {
    // get name
    char name[MAX_NAME_LEN + 1];
    printf("Enter name:\n");
    do {
        fgets(name, MAX_NAME_LEN + 1, stdin);
        name[strcspn(name, "\n")] = '\0'; // remove trailing newline
        if (!is_name_valid(name)) {
            printf("Invalid name! Name must contain only letters and spaces (max %d characters).\n", MAX_NAME_LEN);
            printf("Enter name:\n");
        }
    } while (!is_name_valid(name));

    // get telephone
    char telephone[MAX_TEL_LEN + 1];
    printf("Enter telephone number:\n");
    do {
        fgets(telephone, MAX_TEL_LEN + 1, stdin);
        telephone[strcspn(telephone, "\n")] = '\0'; // remove trailing newline
        if (!is_telephone_valid(telephone)) {
            printf("Invalid telephone number! Telephone number must contain only digits (max %d characters).\n", MAX_TEL_LEN);
            printf("Enter telephone number:\n");
        }
    } while (!is_telephone_valid(telephone));

    // get email
    char email[MAX_EMAIL_LEN + 1];
    printf("Enter email:\n");
    do {
        fgets(email, MAX_EMAIL_LEN + 1, stdin);
        email[strcspn(email, "\n")] = '\0'; // remove trailing newline
        if (!is_email_valid(email)) {
            printf("Invalid email! Please enter a valid email address (max %d characters).\n", MAX_EMAIL_LEN);
            printf("Enter email:\n");
        }
    } while (!is_email_valid(email));

    // add contact to array
    strcpy(contacts[*num_contacts].name, name);
    strcpy(contacts[*num_contacts].telephone, telephone);
    strcpy(contacts[*num_contacts].email, email);
    *num_contacts += 1;
}

int main(void) {
    Contact contacts[100];
    int num_contacts = 0;

    // display menu
    while (1) {
        printf("1. Add contact\n");
        printf("2. View contacts\n");
        printf("3. Exit\n");
        printf("Enter choice (1-3):\n");

        int choice;
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                printf("Contacts:\n");
                for (int i = 0; i < num_contacts; ++i) {
                    printf("Name: %s\n", contacts[i].name);
                    printf("Telephone: %s\n", contacts[i].telephone);
                    printf("Email: %s\n", contacts[i].email);
                }
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a choice between 1 and 3.\n");
                break;
        }
    }

    return 0;
}