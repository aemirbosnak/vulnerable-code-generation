//Falcon2-11B DATASET v1.0 Category: File handling ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node
{
    char data;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

int main()
{
    int choice, num, count;
    char ch;

    struct node* temp;

    while(1)
    {
        printf("1. Insert at the beginning.\n2. Insert at the end.\n3. Delete a node.\n4. Display the list.\n5. Search for a node.\n0. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter data to insert: ");
                scanf("%c", &ch);
                temp = (struct node*)malloc(sizeof(struct node));
                temp->data = ch;
                temp->next = head;
                head = temp;
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%c", &ch);
                temp = (struct node*)malloc(sizeof(struct node));
                temp->data = ch;
                if(tail == NULL)
                {
                    tail = temp;
                }
                else
                {
                    temp->next = NULL;
                    tail->next = temp;
                    tail = temp;
                }
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%c", &ch);
                temp = head;
                while(temp->data!= ch)
                {
                    if(temp->next == NULL)
                    {
                        printf("Node not found.\n");
                        break;
                    }
                    temp = temp->next;
                }
                if(temp->data == ch)
                {
                    if(temp == head)
                    {
                        head = head->next;
                        free(temp);
                    }
                    else
                    {
                        temp->next = temp->next->next;
                        free(temp);
                    }
                }
                break;
            case 4:
                temp = head;
                while(temp!= NULL)
                {
                    printf("%c\n", temp->data);
                    temp = temp->next;
                }
                break;
            case 5:
                printf("Enter data to search: ");
                scanf("%c", &ch);
                temp = head;
                while(temp!= NULL)
                {
                    if(temp->data == ch)
                    {
                        printf("Found at %d.\n", count);
                        break;
                    }
                    temp = temp->next;
                }
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        count++;
    }

    return 0;
}