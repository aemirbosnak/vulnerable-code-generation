//FormAI DATASET v1.0 Category: Mailing list manager ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_SUBSCRIBERS 100

struct subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

struct mailing_list {
    struct subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
};

void print_menu() {
    printf("\n");
    printf("1. Add subscriber\n");
    printf("2. Remove subscriber\n");
    printf("3. Send email to all subscribers\n");
    printf("4. Exit\n");
    printf("\n");
}

void add_subscriber(struct mailing_list *list) {
    if(list->count < MAX_SUBSCRIBERS) {
        struct subscriber sub;

        printf("Enter name: ");
        fgets(sub.name, MAX_NAME_LENGTH, stdin);
        sub.name[strlen(sub.name) - 1] = '\0';

        printf("Enter email: ");
        fgets(sub.email, MAX_EMAIL_LENGTH, stdin);
        sub.email[strlen(sub.email) - 1] = '\0';

        list->subscribers[list->count] = sub;
        list->count++;

        printf("Subscriber added successfully.\n");
    } else {
        printf("Mailing list full. Cannot add any more subscribers.\n");
    }
}

void remove_subscriber(struct mailing_list *list) {
    char email[MAX_EMAIL_LENGTH];
    int i, found = 0;

    printf("Enter email of subscriber to remove: ");
    fgets(email, MAX_EMAIL_LENGTH, stdin);
    email[strlen(email) - 1] = '\0';

    for(i = 0; i < list->count; i++) {
        if(strcmp(list->subscribers[i].email, email) == 0) {
            found = 1;
            break;
        }
    }

    if(found) {
        for(; i < list->count - 1; i++) {
            list->subscribers[i] = list->subscribers[i + 1];
        }

        list->count--;
        printf("Subscriber removed successfully.\n");
    } else {
        printf("Subscriber not found in mailing list.\n");
    }
}

void send_email(struct mailing_list *list) {
    FILE *fp;
    char message[200];
    int i;

    printf("Enter message to send: ");
    fgets(message, 200, stdin);
    message[strlen(message) - 1] = '\0';

    fp = fopen("mailing_list.txt", "w");

    for(i = 0; i < list->count; i++) {
        fprintf(fp, "To: %s\n", list->subscribers[i].email);
        fprintf(fp, "From: mailinglist@example.com\n");
        fprintf(fp, "Subject: New message from mailing list\n");
        fprintf(fp, "\n%s\n", message);
        fprintf(fp, "\n");
    }

    fclose(fp);

    printf("Email sent to all subscribers.\n");
}

int main() {
    struct mailing_list list = {0};
    int choice;

    while(1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                add_subscriber(&list);
                break;
            case 2:
                remove_subscriber(&list);
                break;
            case 3:
                send_email(&list);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}