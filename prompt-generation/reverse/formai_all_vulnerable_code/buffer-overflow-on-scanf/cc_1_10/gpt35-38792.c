//FormAI DATASET v1.0 Category: Mailing list manager ; Style: recursive
#include <stdio.h>
#include <string.h>

struct Node
{
    char email[50];
    struct Node *next;
};

void displayList(struct Node *start)
{
    if(start == NULL)
    {
        printf("Mailing list is empty.\n");
        return;
    }

    printf("Mailing list:\n");
    printf("----------------------------\n");
    while(start != NULL)
    {
        printf("%s\n", start->email);
        start = start->next;
    }
    printf("----------------------------\n");
}

struct Node* addToList(struct Node *start, char email[])
{
    if(start == NULL)
    {
        start = (struct Node*) malloc(sizeof(struct Node));
        strcpy(start->email, email);
        start->next = NULL;
    }
    else
    {
        start->next = addToList(start->next, email);
    }

    return start;
}

struct Node* removeFromList(struct Node *start, char email[])
{
    if(start == NULL)
    {
        printf("Email not found.\n");
        return start;
    }
    else if(strcmp(start->email, email) == 0)
    {
        struct Node *temp = start;
        start = start->next;
        free(temp);
        printf("Email deleted successfully.\n");
        return start;
    }
    else
    {
        start->next = removeFromList(start->next, email);
        return start;
    }
}

int main()
{
    struct Node *start = NULL;
    int choice;
    char email[50];

    printf("Mailing list manager:\n");
    printf("---------------------------------\n");

    while(1)
    {
        printf("\n1. Display mailing list\n");
        printf("2. Add email to mailing list\n");
        printf("3. Remove email from mailing list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayList(start);
                break;

            case 2:
                printf("Enter email to add: ");
                scanf("%s", email);
                start = addToList(start, email);
                printf("Email added successfully.\n");
                break;

            case 3:
                printf("Enter email to remove: ");
                scanf("%s", email);
                start = removeFromList(start, email);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}