//FormAI DATASET v1.0 Category: Mailing list manager ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 50

struct mailing_list {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct mailing_list *next;
};

typedef struct mailing_list MailingList;

MailingList *head = NULL;

void add_email() {
    MailingList *new_email = malloc(sizeof(MailingList));
    printf("Enter name: ");
    scanf("%s", new_email->name);
    printf("Enter email: ");
    scanf("%s", new_email->email);
    new_email->next = head;
    head = new_email;
    printf("Email added!\n\n");
}

void remove_email() {
    char email[MAX_EMAIL_LENGTH];
    MailingList *cur_email = head;
    MailingList *prev_email = NULL;
    printf("Enter the email you wish to remove: ");
    scanf("%s", email);
    while (cur_email != NULL) {
        if (strcmp(cur_email->email, email) == 0) {
            if (prev_email == NULL) {
                head = cur_email->next;
            } else {
                prev_email->next = cur_email->next;
            }
            free(cur_email);
            printf("Email removed!\n\n");
            return;
        }
        prev_email = cur_email;
        cur_email = cur_email->next;
    }
    printf("Email not found!\n\n");
}

void print_list() {
    MailingList *cur_email = head;
    printf("Name\t\tEmail\n");
    printf("----\t\t-----\n");
    while (cur_email != NULL) {
        printf("%s\t\t%s\n", cur_email->name, cur_email->email);
        cur_email = cur_email->next;
    }
    printf("\n");
}

void save_list() {
    FILE *fp = fopen("mailing_list.txt", "w");
    if (fp == NULL) {
        printf("Failed to create/open file.\n");
        return;
    }
    MailingList *cur_email = head;
    while (cur_email != NULL) {
        fprintf(fp, "%s,%s\n", cur_email->name, cur_email->email);
        cur_email = cur_email->next;
    }
    fclose(fp);
    printf("Mailing list saved to file!\n\n");
}

void load_list() {
    FILE *fp = fopen("mailing_list.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return;
    }
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    while (fscanf(fp, "%[^,],%s\n", name, email) == 2) {
        MailingList *new_email = malloc(sizeof(MailingList));
        strcpy(new_email->name, name);
        strcpy(new_email->email, email);
        new_email->next = head;
        head = new_email;
    }
    fclose(fp);
    printf("Mailing list loaded from file!\n\n");
}

int main() {
    int choice;
    do {
        printf("MENU\n");
        printf("----\n");
        printf("1. Add email\n");
        printf("2. Remove email\n");
        printf("3. Print mailing list\n");
        printf("4. Save mailing list to file\n");
        printf("5. Load mailing list from file\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                remove_email();
                break;
            case 3:
                print_list();
                break;
            case 4:
                save_list();
                break;
            case 5:
                load_list();
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n\n");
                break;
        }
    } while (choice != 6);
    return 0;
}