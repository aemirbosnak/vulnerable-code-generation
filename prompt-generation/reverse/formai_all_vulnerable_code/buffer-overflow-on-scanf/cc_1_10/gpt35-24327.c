//FormAI DATASET v1.0 Category: Linked list operations ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void add_at_begin(struct node **h, int d){
    struct node *temp, *temp2;
    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = d;
    temp2 = *h;
    *h = temp;
    temp->next = temp2;
    printf("Node added successfully");
}

void add_at_end(struct node **h, int d){
    struct node *temp, *temp2;
    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = d;
    temp->next = NULL;
    if(*h == NULL)
    {
        *h = temp;
        printf("Node added successfully");
        return;
    }
    temp2 = *h;
    while(temp2->next != NULL)
        temp2 = temp2->next;
    temp2->next = temp;
    printf("Node added successfully");
}

void display(struct node *h){
    if(h == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(h != NULL)
    {
        printf("%d ", h->data);
        h = h->next;
    }
}

void delete_node(struct node **h, int d){
    struct node *temp, *prev;
    temp = *h;
    prev = NULL;
    if(temp != NULL && temp->data == d)
    {
        *h = temp->next;
        free(temp);
        printf("Node deleted successfully");
        return;
    }
    while(temp != NULL && temp->data != d)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("Node not found");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted successfully");
}

int main()
{
    struct node *head = NULL;
    int choice, data;
    while(1){
        printf("\n\n1->Add at Begin  2->Add at End  3->Delete  4->Display\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                printf("\nEnter data to be inserted: ");
                scanf("%d", &data);
                add_at_begin(&head, data);
                break;
            }
            case 2:{
                printf("\nEnter data to be inserted: ");
                scanf("%d", &data);
                add_at_end(&head, data);
                break;
            }
            case 3:{
                printf("\nEnter data to be deleted: ");
                scanf("%d", &data);
                delete_node(&head, data);
                break;
            }
            case 4:{
                printf("\n\nLinkedList: ");
                display(head);
                break;
            }
            default:{
                printf("\n\nInvalid Choice");
                break;
            }
        }
    }
    return 0;
}