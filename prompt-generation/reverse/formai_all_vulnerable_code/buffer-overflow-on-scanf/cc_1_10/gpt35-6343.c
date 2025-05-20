//FormAI DATASET v1.0 Category: Email Client ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MESSAGES 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

struct Message {
    int id;
    char subject[MAX_SUBJECT_LENGTH];
    char content[MAX_CONTENT_LENGTH];
};

struct Inbox {
    struct Message messages[MAX_MESSAGES];
    int message_count;
};

void display_menu() {
    printf("\n\nWelcome to My Email Client\n\n");
    printf("1. Compose new email\n");
    printf("2. View inbox\n");
    printf("3. Exit\n");
}

void compose_email(struct Inbox* inbox) {
    printf("Compose New Email\n");
    printf("Please enter subject: ");
    char subject[MAX_SUBJECT_LENGTH];
    fgets(subject, MAX_SUBJECT_LENGTH, stdin);
    subject[strcspn(subject, "\n")] = 0;
    printf("Please enter content: ");
    char content[MAX_CONTENT_LENGTH];
    fgets(content, MAX_CONTENT_LENGTH, stdin);
    content[strcspn(content, "\n")] = 0;
    struct Message message = { inbox->message_count + 1, subject, content };
    inbox->messages[inbox->message_count++] = message;
    printf("\nEmail sent successfully!\n");
}

void view_inbox(struct Inbox* inbox) {
    printf("Inbox (%d messages)\n", inbox->message_count);
    for (int i = 0; i < inbox->message_count; i++) {
        printf("\nMessage %d\n", i + 1);
        printf("Subject: %s\n", inbox->messages[i].subject);
        printf("Content: %s\n", inbox->messages[i].content);
    }
}

int main() {
    struct Inbox inbox = { {}, 0 };
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        while (getchar() != '\n');
        switch (choice) {
            case 1:
                compose_email(&inbox);
                break;
            case 2:
                view_inbox(&inbox);
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}