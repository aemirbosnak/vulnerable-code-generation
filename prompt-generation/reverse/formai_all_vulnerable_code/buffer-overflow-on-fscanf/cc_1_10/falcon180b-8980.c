//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECTS 100
#define MAX_BODIES 1000

typedef struct mailing_list {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} mailing_list_t;

typedef struct email_template {
    char subject[MAX_SUBJECTS];
    char body[MAX_BODIES];
} email_template_t;

int main() {
    mailing_list_t *mailing_list = NULL;
    email_template_t *email_template = NULL;
    int num_recipients = 0;

    // Read mailing list from file
    FILE *mailing_list_file = fopen("mailing_list.txt", "r");
    if (mailing_list_file == NULL) {
        printf("Error: Could not open mailing list file.\n");
        return 1;
    }

    while (fscanf(mailing_list_file, "%s %s\n", mailing_list->name, mailing_list->email)!= EOF) {
        mailing_list = realloc(mailing_list, sizeof(mailing_list_t) * ++num_recipients);
    }
    fclose(mailing_list_file);

    // Read email template from file
    FILE *email_template_file = fopen("email_template.txt", "r");
    if (email_template_file == NULL) {
        printf("Error: Could not open email template file.\n");
        return 1;
    }

    email_template = malloc(sizeof(email_template_t));
    if (fscanf(email_template_file, "%s %s", email_template->subject, email_template->body)!= 2) {
        printf("Error: Invalid email template format.\n");
        return 1;
    }
    fclose(email_template_file);

    // Send emails to mailing list
    for (int i = 0; i < num_recipients; i++) {
        char email_body[MAX_BODIES];
        sprintf(email_body, email_template->body, mailing_list[i].name);

        char command[100];
        sprintf(command, "echo '%s' | mail -s '%s' '%s'", email_body, email_template->subject, mailing_list[i].email);
        system(command);
    }

    free(mailing_list);
    free(email_template);

    return 0;
}