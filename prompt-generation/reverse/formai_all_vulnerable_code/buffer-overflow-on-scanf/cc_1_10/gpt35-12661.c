//FormAI DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact{
    char name[50];
    char phone[15];
    struct Contact *next;
};

struct Contact *addContact(struct Contact *head, char *name, char *phone);
struct Contact *searchContact(struct Contact *head, char *name);
struct Contact *editContact(struct Contact *head, char *name);
struct Contact *deleteContact(struct Contact *head, char *name);
void displayContacts(struct Contact *head);
void clearContacts(struct Contact *head);

int main()
{
    struct Contact *head = NULL;
    int choice = 0;

    while(1)
    {
        printf("\n1. Add Contact\n2. Search Contact\n3. Edit Contact\n4. Delete Contact\n5. Display Contacts\n6. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                char name[50], phone[15];
                printf("\nEnter the Name: ");
                scanf("%s", name);
                printf("Enter the Phone Number: ");
                scanf("%s", phone);
                head = addContact(head, name, phone);
                break;
            }
            case 2:
            {
                char name[50];
                printf("\nEnter the Name to Search: ");
                scanf("%s", name);
                struct Contact *result = searchContact(head, name);
                if(result != NULL)
                {
                    printf("\nName: %s\nPhone Number: %s\n", result->name, result->phone);
                }
                else
                {
                    printf("\nContact not found.\n");
                }
                break;
            }
            case 3:
            {
                char name[50];
                printf("\nEnter the Name to Edit: ");
                scanf("%s", name);
                head = editContact(head, name);
                break;
            }
            case 4:
            {
                char name[50];
                printf("\nEnter the Name to Delete: ");
                scanf("%s", name);
                head = deleteContact(head, name);
                break;
            }
            case 5:
            {
                displayContacts(head);
                break;
            }
            case 6:
            {
                clearContacts(head);
                printf("\nGoodbye!\n");
                exit(0);
                break;
            }
            default:
            {
                printf("\nInvalid Choice.\n");
                break;
            }
        }
    }

    return 0;
}

struct Contact *addContact(struct Contact *head, char *name, char *phone)
{
    if(head == NULL)
    {
        head = (struct Contact*) malloc(sizeof(struct Contact));
        strcpy(head->name, name);
        strcpy(head->phone, phone);
        head->next = NULL;
    }
    else
    {
        head->next = addContact(head->next, name, phone);
    }

    return head;
}

struct Contact *searchContact(struct Contact *head, char *name)
{
    if(head == NULL)
    {
        return NULL;
    }
    else if(strcmp(head->name, name) == 0)
    {
        return head;
    }
    else
    {
        return searchContact(head->next, name);
    }
}

struct Contact *editContact(struct Contact *head, char *name)
{
    if(head == NULL)
    {
        printf("\nContact not found.\n");
    }
    else if(strcmp(head->name, name) == 0)
    {
        printf("\nEnter the New Phone Number: ");
        scanf("%s", head->phone);
    }
    else
    {
        head->next = editContact(head->next, name);
    }

    return head;
}

struct Contact *deleteContact(struct Contact *head, char *name)
{
    if(head == NULL)
    {
        printf("\nContact not found.\n");
    }
    else if(strcmp(head->name, name) == 0)
    {
        struct Contact *temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        head->next = deleteContact(head->next, name);
    }

    return head;
}

void displayContacts(struct Contact *head)
{
    if(head == NULL)
    {
        printf("\nNo Contacts found.\n");
    }
    else
    {
        printf("\nContacts:\n\n");
        while(head != NULL)
        {
            printf("Name: %s\nPhone Number: %s\n\n", head->name, head->phone);
            head = head->next;
        }
    }
}

void clearContacts(struct Contact *head)
{
    if(head == NULL)
    {
        return;
    }

    clearContacts(head->next);
    free(head);
}