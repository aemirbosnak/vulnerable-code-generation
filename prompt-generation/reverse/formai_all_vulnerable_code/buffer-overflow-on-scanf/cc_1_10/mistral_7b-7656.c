//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIST_SIZE 1000
#define EMAIL_SIZE 50

typedef struct {
    char name[50];
    char email[50];
} Subscriber;

Subscriber list[MAX_LIST_SIZE];
int list_size = 0;

void add_subscriber(char *name, char *email) {
    if (list_size >= MAX_LIST_SIZE) {
        printf("Mailing list is full!\n");
        return;
    }
    strcpy(list[list_size].name, name);
    strcpy(list[list_size].email, email);
    list_size++;
}

void remove_subscriber(char *email) {
    int i;
    for (i = 0; i < list_size; i++) {
        if (strcmp(list[i].email, email) == 0) {
            for (int j = i; j < list_size - 1; j++) {
                strcpy(list[j].email, list[j + 1].email);
                strcpy(list[j].name, list[j + 1].name);
            }
            list_size--;
            return;
        }
    }
    printf("Email not found in mailing list!\n");
}

void send_newsletter(char *newsletter_text) {
    int i;
    printf("Sending newsletter to %d subscribers:\n", list_size);
    for (i = 0; i < list_size; i++) {
        printf("%s (%s)\n", list[i].name, list[i].email);
        printf("----------------------------------------\n");
        printf("%s\n", newsletter_text);
    }
}

int main() {
    char name[EMAIL_SIZE], email[EMAIL_SIZE];
    int choice;
    char newsletter_text[200] = "Hello Subscribers,\n\nWe are excited to share our latest news with you!\n\n...";

    while (true) {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Send Newsletter\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Email: ");
                scanf("%s", email);
                add_subscriber(name, email);
                break;
            case 2:
                printf("Enter Email to remove: ");
                scanf("%s", email);
                remove_subscriber(email);
                break;
            case 3:
                send_newsletter(newsletter_text);
                break;
            case 4:
                printf("Quitting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}