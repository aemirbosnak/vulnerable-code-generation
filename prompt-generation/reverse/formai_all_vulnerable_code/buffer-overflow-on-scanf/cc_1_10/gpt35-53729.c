//FormAI DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void displayMenu();
void createNewEmail(FILE *fp);
void displayEmails(FILE *fp);
void searchEmails(FILE *fp);

struct Mail {
    char to[MAX];
    char from[MAX];
    char subject[MAX];
    char content[MAX];
};

int main(void) {
    FILE *fp;

    fp = fopen("emails.txt", "a+");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    displayMenu();

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice != 4) {
        switch (choice) {
            case 1:
                createNewEmail(fp);
                break;
            case 2:
                displayEmails(fp);
                break;
            case 3:
                searchEmails(fp);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    fclose(fp);

    return 0;
}

void displayMenu() {
    printf("\nEmail Client Menu\n");
    printf("-----------------\n");
    printf("1. Create New Email\n");
    printf("2. Display All Emails\n");
    printf("3. Search Emails\n");
    printf("4. Exit\n");
}

void createNewEmail(FILE *fp) {
    struct Mail email;

    printf("To: ");
    scanf("%s", email.to);
    printf("From: ");
    scanf("%s", email.from);
    printf("Subject: ");
    scanf("%s", email.subject);
    printf("Content: ");
    scanf("%s", email.content);

    fprintf(fp, "%s %s %s %s\n", email.to, email.from, email.subject, email.content);

    printf("Email created successfully.\n");
}

void displayEmails(FILE *fp) {
    struct Mail email;

    printf("All Emails:\n");

    rewind(fp);
    while (fscanf(fp, "%s %s %s %[^\n]", email.to, email.from, email.subject, email.content) != EOF) {
        printf("\nTo: %s\n", email.to);
        printf("From: %s\n", email.from);
        printf("Subject: %s\n", email.subject);
        printf("Content: %s\n", email.content);
    }
}

void searchEmails(FILE *fp) {
    struct Mail email;
    char searchQuery[MAX];

    printf("Enter search query: ");
    scanf("%s", searchQuery);

    rewind(fp);
    while (fscanf(fp, "%s %s %s %[^\n]", email.to, email.from, email.subject, email.content) != EOF) {
        if (strstr(email.content, searchQuery) != NULL) {
            printf("\nTo: %s\n", email.to);
            printf("From: %s\n", email.from);
            printf("Subject: %s\n", email.subject);
            printf("Content: %s\n", email.content);
        }
    }
}