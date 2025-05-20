//FormAI DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define EMAIL_LENGTH 50

typedef struct subscriber
{
    char email[EMAIL_LENGTH];
} subscriber;

subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber(char *email)
{
    if (strlen(email) >= EMAIL_LENGTH)
    {
        printf("Error: email is too long.");
        return;
    }

    if (num_subscribers >= MAX_SUBSCRIBERS)
    {
        printf("Error: maximum number of subscribers reached.");
        return;
    }

    // Check if email is already in the list
    for (int i = 0; i < num_subscribers; i++)
    {
        if (strcmp(subscribers[i].email, email) == 0)
        {
            printf("Error: email already subscribed.");
            return;
        }
    }

    // Add email to list
    strcpy(subscribers[num_subscribers].email, email);
    num_subscribers++;

    printf("Subscriber added successfully!\n");
}

void remove_subscriber(char *email)
{
    int pos = -1;
    for (int i = 0; i < num_subscribers; i++)
    {
        if (strcmp(subscribers[i].email, email) == 0)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        printf("Error: email not found.");
        return;
    }

    // Remove email from list
    for (int i = pos; i < num_subscribers - 1; i++)
    {
        strcpy(subscribers[i].email, subscribers[i + 1].email);
    }
    num_subscribers--;

    printf("Subscriber removed successfully!\n");
}

void print_list()
{
    printf("Subscriber list:\n");
    for (int i = 0; i < num_subscribers; i++)
    {
        printf("#%d: %s\n", i + 1, subscribers[i].email);
    }
}

int main()
{
    // Main loop
    while (1)
    {
        char choice;
        char email[EMAIL_LENGTH];
        printf("Welcome to the mailing list manager!\n");
        printf("Please choose from the following options:\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Print subscriber list\n");
        printf("0. Exit\n");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            printf("Enter email address: ");
            scanf("%s", email);
            add_subscriber(email);
            break;

        case '2':
            printf("Enter email address: ");
            scanf("%s", email);
            remove_subscriber(email);
            break;

        case '3':
            print_list();
            break;

        case '0':
            printf("Thank you for using the mailing list manager!\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}