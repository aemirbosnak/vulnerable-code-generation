//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIST_SIZE 1000
#define EMAIL_MAX_LEN 50

typedef struct email {
    char name[20];
    char email[EMAIL_MAX_LEN];
} Email;

Email list[MAX_LIST_SIZE];
int subscribers_count = 0;

void add_email(char *name, char *email) {
    if (subscribers_count >= MAX_LIST_SIZE) {
        printf("Error: Mailing list is full.\n");
        return;
    }
    strcpy(list[subscribers_count].name, name);
    strcpy(list[subscribers_count].email, email);
    subscribers_count++;
}

void remove_email(char *email) {
    int i;
    for (i = 0; i < subscribers_count; i++) {
        if (strcmp(list[i].email, email) == 0) {
            for (int j = i; j < subscribers_count; j++) {
                strcpy(list[j].email, list[j + 1].email);
            }
            subscribers_count--;
            break;
        }
    }
}

void view_mailing_list() {
    int i;
    if (subscribers_count == 0) {
        printf("Error: Mailing list is empty.\n");
        return;
    }
    printf("Mailing List:\n");
    for (i = 0; i < subscribers_count; i++) {
        printf("%s: %s\n", list[i].name, list[i].email);
    }
}

int main() {
    char name[20], email[EMAIL_MAX_LEN];
    int choice;

    while (true) {
        printf("\nMailing List Manager\n");
        printf("1. Subscribe\n");
        printf("2. Unsubscribe\n");
        printf("3. View List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter your email: ");
                scanf("%s", email);
                add_email(name, email);
                break;
            case 2:
                printf("Enter your email to unsubscribe: ");
                scanf("%s", email);
                remove_email(email);
                break;
            case 3:
                view_mailing_list();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}