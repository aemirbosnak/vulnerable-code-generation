//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000 // maximum number of emails allowed
#define MAX_NAME_LEN 50 // maximum length of a name
#define MAX_EMAIL_LEN 100 // maximum length of an email address

// email structure
typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Email;

// mailing list structure
typedef struct {
    Email *emails; // array of emails
    int num_emails; // number of emails in the list
} MailingList;

// function to initialize a new mailing list
MailingList* create_mailing_list() {
    MailingList *list = (MailingList*)malloc(sizeof(MailingList));
    list->emails = (Email*)malloc(MAX_EMAILS * sizeof(Email));
    list->num_emails = 0;
    return list;
}

// function to add an email to the mailing list
void add_email(MailingList *list, char *name, char *email) {
    Email *new_email = (Email*)malloc(sizeof(Email));
    strcpy(new_email->name, name);
    strcpy(new_email->email, email);
    list->emails[list->num_emails++] = *new_email;
    free(new_email);
}

// function to remove an email from the mailing list
void remove_email(MailingList *list, char *email) {
    int i;
    for (i = 0; i < list->num_emails; i++) {
        if (strcmp(list->emails[i].email, email) == 0) {
            list->num_emails--;
            while (i < list->num_emails) {
                list->emails[i] = list->emails[i+1];
                i++;
            }
            break;
        }
    }
}

// function to print the mailing list
void print_mailing_list(MailingList *list) {
    int i;
    for (i = 0; i < list->num_emails; i++) {
        printf("%s <%s>\n", list->emails[i].name, list->emails[i].email);
    }
}

// main function
int main() {
    MailingList *list = create_mailing_list();
    add_email(list, "John Doe", "john@example.com");
    add_email(list, "Jane Doe", "jane@example.com");
    print_mailing_list(list);
    remove_email(list, "john@example.com");
    print_mailing_list(list);
    free(list->emails);
    free(list);
    return 0;
}