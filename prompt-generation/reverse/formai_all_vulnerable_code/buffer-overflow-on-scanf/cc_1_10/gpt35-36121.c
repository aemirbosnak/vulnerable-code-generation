//FormAI DATASET v1.0 Category: Mailing list manager ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node 
{
    char email[50];
    struct node *next;
};

typedef struct node NODE;

void append(NODE **head_ref, char new_email[50])
{
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    strcpy(new_node->email, new_email);
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    NODE *last_node = *head_ref;
    while (last_node->next != NULL)
    {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

void display(NODE *head)
{
    NODE *temp = head;
    int count = 1;
    printf("Email List:\n");
    while (temp != NULL)
    {
        printf("%d. %s\n", count, temp->email);
        temp = temp->next;
        count++;
    }
    printf("\n");
}

char* delete_by_index(NODE **head_ref, int position)
{
    if (*head_ref == NULL)
    {
        printf("Error: List is Empty!\n");
        return NULL;
    }

    NODE *temp = *head_ref;

    if (position == 1)
    {
        *head_ref = temp->next;
        char* deleted_email = strdup(temp->email);
        free(temp);
        return deleted_email;
    }

    int count = 1;
    while (temp != NULL && count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Error: Invalid Position!\n");
        return NULL;
    }

    NODE *deleted_node = temp->next;
    temp->next = deleted_node->next;
    char* deleted_email = strdup(deleted_node->email);
    free(deleted_node);
    return deleted_email;
}

void free_list(NODE *head)
{
    NODE *curr_node = head;
    NODE *next_node = NULL;

    while (curr_node != NULL)
    {
        next_node = curr_node->next;
        free(curr_node);
        curr_node = next_node;
    }
}

int main()
{
    int choice, index;
    char email[50];
    NODE *head = NULL;

    printf("-----------Mailing List Manager-----------\n");

    do
    {
        printf("\nAvailable Operations:\n");
        printf("1. Append an Email\n");
        printf("2. Delete an Email by Index\n");
        printf("3. Display Email List\n");
        printf("4. Exit Program\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Email to Append: ");
                scanf("%s", email);
                append(&head, email);
                printf("Email Added Successfully!\n");
                break;

            case 2:
                printf("Enter Index of Email to Delete: ");
                scanf("%d", &index);
                char* deleted_email = delete_by_index(&head, index);
                if (deleted_email != NULL)
                {
                    printf("%s Deleted Successfully!\n", deleted_email);
                    free(deleted_email);
                }
                break;

            case 3:
                display(head);
                break;

            case 4:
                printf("Exiting Mailing List Manager...\n");
                break;

            default:
                printf("Invalid Choice! Try Again.\n");
                break;
        }

    } while (choice != 4);

    free_list(head);
    return 0;
}