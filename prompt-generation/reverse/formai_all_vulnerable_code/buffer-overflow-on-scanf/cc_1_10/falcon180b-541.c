//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

struct email {
    char name[50];
    char email[100];
};

void add_email(struct email *emails, int count, char *name, char *email) {
    if (count >= MAX_EMAILS) {
        printf("Error: Mailing list is full.\n");
        return;
    }
    strcpy(emails[count].name, name);
    strcpy(emails[count].email, email);
    count++;
}

void delete_email(struct email *emails, int count, char *email) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(emails[i].email, email) == 0) {
            memmove(&emails[i], &emails[i+1], sizeof(struct email) * (count - i - 1));
            count--;
            break;
        }
    }
}

void print_emails(struct email *emails, int count) {
    int i;
    for (i = 0; i < count; i++) {
        printf("%s - %s\n", emails[i].name, emails[i].email);
    }
}

int main() {
    struct email emails[MAX_EMAILS];
    int count = 0;
    char name[50];
    char email[100];
    int choice;

    printf("Mailing List Manager\n");
    while (1) {
        printf("\n1. Add email\n2. Delete email\n3. Print emails\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_email(emails, count, name, email);
                break;
            case 2:
                printf("Enter email to delete: ");
                scanf("%s", email);
                delete_email(emails, count, email);
                break;
            case 3:
                print_emails(emails, count);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}