//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: multivariable
// mailing_list.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define structure for email
typedef struct {
    char *email;
    char *name;
} email_t;

// define structure for mailing list
typedef struct {
    int count;
    email_t *emails;
} mailing_list_t;

// function to add email to mailing list
void add_email(mailing_list_t *list, email_t *email) {
    list->emails = realloc(list->emails, (list->count + 1) * sizeof(email_t));
    list->emails[list->count++] = *email;
}

// function to remove email from mailing list
void remove_email(mailing_list_t *list, char *email) {
    int i;
    for (i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i].email, email) == 0) {
            list->count--;
            memmove(&list->emails[i], &list->emails[i + 1], (list->count - i) * sizeof(email_t));
            break;
        }
    }
}

// function to print mailing list
void print_mailing_list(mailing_list_t *list) {
    int i;
    for (i = 0; i < list->count; i++) {
        printf("%s <%s>\n", list->emails[i].name, list->emails[i].email);
    }
}

// main function
int main() {
    // create mailing list
    mailing_list_t list = { 0, NULL };

    // add emails to mailing list
    email_t email1 = { "john.doe@example.com", "John Doe" };
    email_t email2 = { "jane.doe@example.com", "Jane Doe" };
    add_email(&list, &email1);
    add_email(&list, &email2);

    // print mailing list
    print_mailing_list(&list);

    // remove email from mailing list
    remove_email(&list, "john.doe@example.com");

    // print mailing list again
    print_mailing_list(&list);

    // free memory
    free(list.emails);

    return 0;
}