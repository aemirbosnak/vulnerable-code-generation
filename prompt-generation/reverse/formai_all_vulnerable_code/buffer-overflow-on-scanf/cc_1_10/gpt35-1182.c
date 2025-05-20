//FormAI DATASET v1.0 Category: Mailing list manager ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct member
{
    char name[50];
    char email[50];
    struct member *next;
};

struct member *create_member()
{
    struct member *new_member = (struct member*) malloc(sizeof(struct member));

    if (new_member == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter member name: ");
    scanf("%s", new_member->name);

    printf("Enter member email: ");
    scanf("%s", new_member->email);

    new_member->next = NULL;

    return new_member;
}

void add_member(struct member **head)
{
    struct member *new_member = create_member();

    if (*head == NULL)
    {
        *head = new_member;
        return;
    }

    struct member *last_member = *head;

    while (last_member->next != NULL)
    {
        last_member = last_member->next;
    }

    last_member->next = new_member;
}

void delete_member(struct member **head, char *email)
{
    if (*head == NULL)
    {
        printf("No members to delete.\n");
        return;
    }

    if (strcmp((*head)->email, email) == 0)
    {
        struct member *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct member *prev_member = *head;
    struct member *current_member = (*head)->next;

    while (current_member != NULL && strcmp(current_member->email, email) != 0)
    {
        prev_member = current_member;
        current_member = current_member->next;
    }

    if (current_member == NULL)
    {
        printf("Member not found.\n");
        return;
    }

    prev_member->next = current_member->next;
    free(current_member);
}

void display_members(struct member *head)
{
    if (head == NULL)
    {
        printf("No members to display.\n");
        return;
    }

    printf("Members:\n\n");

    while (head != NULL)
    {
        printf("Name: %s\n", head->name);
        printf("Email: %s\n\n", head->email);
        head = head->next;  
    }
}

int main()
{
    struct member *head = NULL;
    int choice;
    char email[50];

    while (1)
    {
        printf("Options:\n");
        printf("1. Add member\n");
        printf("2. Delete member\n");
        printf("3. Display members\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                add_member(&head);
                break;

            case 2:
                printf("Enter the email of the member to delete: ");
                scanf("%s", email);
                delete_member(&head, email);
                break;

            case 3:
                display_members(head);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}