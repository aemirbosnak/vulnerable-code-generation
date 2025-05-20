//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_LENGTH 50

typedef struct {
    char emails[MAX_EMAILS][MAX_LENGTH];
    int count;
} MailingList;

void addEmail(MailingList *list, const char *email) {
    if (list->count < MAX_EMAILS) {
        strcpy(list->emails[list->count++], email);
        printf("Welcome aboard, %s! You've made a great choice joining our mailing list!\n", email);
    } else {
        printf("Whoa there! We've hit our limit of cool cats in this list!\n");
    }
}

void removeEmail(MailingList *list, const char *email) {
    int found = 0;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            found = 1;
            printf("Oh no! %s is leaving our mailing list. We’ll miss you dearly!\n", email);
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            break;
        }
    }
    if (!found) {
        printf("Hmm, we couldn't find %s in our beloved list. Are you sure you were ever here?\n", email);
    }
}

void viewList(const MailingList *list) {
    printf("Here are the fine folks signed up for our fabulous mailing list:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->emails[i]);
    }
    if (list->count == 0) {
        printf("Oh dear! Looks like no one loves us yet. 😢\n");
    }
}

void sendNewsletters(const MailingList *list) {
    printf("Sending out the latest gossip to all our fabulous subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("📧 Sending newsletter to: %s ... Have fun!\n", list->emails[i]);
    }
    printf("Done! If our emails don’t make you laugh, well… we tried!\n");
}

void showMenu() {
    printf("\nWelcome to the Silly Mailing List Manager!\n");
    printf("1. Add an email\n");
    printf("2. Remove an email\n");
    printf("3. View mailing list\n");
    printf("4. Send newsletters\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MailingList list = { .count = 0 };
    char email[MAX_LENGTH];
    int choice;

    while (1) {
        showMenu();
        scanf("%d", &choice);
        getchar(); // to consume the newline character left in the buffer

        switch (choice) {
            case 1:
                printf("Enter the email to add: ");
                fgets(email, MAX_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                addEmail(&list, email);
                break;
            case 2:
                printf("Enter the email to remove: ");
                fgets(email, MAX_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                removeEmail(&list, email);
                break;
            case 3:
                viewList(&list);
                break;
            case 4:
                sendNewsletters(&list);
                break;
            case 5:
                printf("Exiting the mailing list with a wink! 😜\n");
                exit(0);
            default:
                printf("Oops! That's not an option. Try again and let's be friends!\n");
        }
    }

    return 0;
}