//FormAI DATASET v1.0 Category: Mailing list manager ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100  // maximum number of email addresses to store
#define MAX_NAME_LEN 50  // maximum length of a name
#define MAX_EMAIL_LEN 50  // maximum length of an email address

// function declarations
void add_email(char *name, char *email);
void print_emails();
void save_emails();
void load_emails();
void remove_email(char *email);

// global email list
char *emails[MAX_EMAILS];
int num_emails = 0;

int main() {
    int choice;
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];

    load_emails();  // load saved emails from file

    while (1) {
        // display menu of options
        printf("\n1) Add email\n");
        printf("2) Print emails\n");
        printf("3) Save emails\n");
        printf("4) Remove email\n");
        printf("5) Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_email(name, email);
                break;
            case 2:
                print_emails();
                break;
            case 3:
                save_emails();
                break;
            case 4:
                printf("Enter email to remove: ");
                scanf("%s", email);
                remove_email(email);
                break;
            case 5:
                save_emails();  // save emails before quitting
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

void add_email(char *name, char *email) {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: maximum number of emails exceeded.\n");
        return;
    }

    // allocate memory for new email address
    char *new_email = (char *) malloc((strlen(name) + strlen(email) + 2) * sizeof(char));
    sprintf(new_email, "%s:%s", name, email);
    
    // add new email to list
    emails[num_emails] = new_email;
    num_emails++;

    printf("Email added successfully.\n");
}

void print_emails() {
    if (num_emails == 0) {
        printf("No emails to print.\n");
        return;
    }

    // print all email addresses
    for (int i = 0; i < num_emails; i++) {
        char *name = strtok(emails[i], ":");
        char *email = strtok(NULL, ":");
        printf("%d. %s: %s\n", i+1, name, email);
    }
}

void save_emails() {
    FILE *fp = fopen("emails.txt", "w");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return;
    }

    // save each email address to file
    for (int i = 0; i < num_emails; i++) {
        fprintf(fp, "%s\n", emails[i]);
    }

    fclose(fp);

    printf("Emails saved successfully.\n");
}

void load_emails() {
    FILE *fp = fopen("emails.txt", "r");
    if (fp == NULL) {
        printf("Warning: could not open file.\n");
        return;
    }

    // read email addresses from file
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    while (fscanf(fp, "%[^:]:%s\n", name, email) != EOF) {
        add_email(name, email);
    }

    fclose(fp);

    printf("Emails loaded successfully.\n");
}

void remove_email(char *email) {
    int found = 0;
    for (int i = 0; i < num_emails; i++) {
        if (strstr(emails[i], email) != NULL) {
            free(emails[i]);
            num_emails--;
            emails[i] = emails[num_emails];
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Email removed successfully.\n");
    } else {
        printf("Error: email not found.\n");
    }
}