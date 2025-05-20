//FormAI DATASET v1.0 Category: Mailing list manager ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50
#define MAX_LIST_LENGTH 100

struct EmailList {
    char** emails;
    int num_emails;
};

struct Contact {
    char* name;
    char email[MAX_EMAIL_LENGTH];
};

struct MailingList {
    char name[MAX_NAME_LENGTH];
    struct EmailList email_list;
};

struct MailingList mailing_list[MAX_LIST_LENGTH];
int num_mailing_lists = 0;

void make_mailing_list(struct Contact* contacts, int num_contacts) {
    char list_name[MAX_NAME_LENGTH];
    printf("Enter the name of the mailing list: ");
    scanf("%s", list_name);
    strcpy(mailing_list[num_mailing_lists].name, list_name);

    struct EmailList email_list;
    email_list.num_emails = num_contacts;
    email_list.emails = (char**)malloc(num_contacts * sizeof(char*));
    for(int i=0; i<num_contacts; i++) {
        email_list.emails[i] = (char*)malloc(MAX_EMAIL_LENGTH * sizeof(char));
        strcpy(email_list.emails[i], contacts[i].email);
    }

    mailing_list[num_mailing_lists].email_list = email_list;
    num_mailing_lists++;
}

void display_email_list(struct EmailList email_list) {
    printf("Email list:\n");
    for(int i=0; i<email_list.num_emails; i++) {
        printf("%s\n", email_list.emails[i]);
    }
}

void display_mailing_list(struct MailingList mailing_list) {
    printf("Mailing list: %s\n", mailing_list.name);
    display_email_list(mailing_list.email_list);
}

int main() {
    struct Contact contacts[3] = {
        {"Alice", "alice@example.com"},
        {"Bob", "bob@example.com"},
        {"Charlie", "charlie@example.com"}
    };

    make_mailing_list(contacts, 3);
    display_mailing_list(mailing_list[0]);

    return 0;
}