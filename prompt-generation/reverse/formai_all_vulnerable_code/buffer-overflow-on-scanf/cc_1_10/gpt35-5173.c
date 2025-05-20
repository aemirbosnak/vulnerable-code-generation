//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Medicine
{
    int med_id;
    char med_name[50];
    int quantity;
    float price;
    struct Medicine *next;
};

struct Medicine *head = NULL;  //head node

void insertMedicine()
{
    struct Medicine *new_med = (struct Medicine*)malloc(sizeof(struct Medicine));  //create new node
    printf("\nEnter Medicine ID: ");
    scanf("%d",&new_med->med_id);
    printf("\nEnter Medicine Name: ");
    scanf(" %[^\n]s",new_med->med_name);
    printf("\nEnter Quantity: ");
    scanf("%d",&new_med->quantity);
    printf("\nEnter Price: ");
    scanf("%f",&new_med->price);

    if(head==NULL)   //if list is empty
    {
        head = new_med;   //make new node the head node
        new_med->next = NULL;
        printf("\nMedicine Added Successfully!");
        return;
    }

    else if(head->price > new_med->price)  //if new node has lowest price
    {
        new_med->next = head;
        head = new_med;
        printf("\nMedicine Added Successfully!");
        return;
    }

    else   //find the correct position to insert the new node
    {
        struct Medicine *temp = head;
        while(temp->next!=NULL && temp->next->price <= new_med->price)
        {
            temp = temp->next;
        }
        new_med->next = temp->next;
        temp->next = new_med;
        printf("\nMedicine Added Successfully!");
        return;
    }
}

void display()
{
    if(head==NULL)  //if list is empty
    {
        printf("\nEmpty List");
        return;
    }

    struct Medicine *temp = head;
    printf("\nMedicine ID\tMedicine Name\tQuantity\tPrice\n");
    while(temp!=NULL)
    {
        printf("%d\t\t%s\t\t%d\t\t%.2f\n",temp->med_id,temp->med_name,temp->quantity,temp->price);
        temp = temp->next;
    }
}

void searchMedicine(int id)
{
    if(head==NULL)  //if list is empty
    {
        printf("\nEmpty List");
        return;
    }

    struct Medicine *temp = head;
    while(temp!=NULL)
    {
        if(temp->med_id == id)
        {
            printf("\nMedicine Found!\n");
            printf("\nMedicine ID\tMedicine Name\tQuantity\tPrice\n");
            printf("%d\t\t%s\t\t%d\t\t%.2f\n",temp->med_id,temp->med_name,temp->quantity,temp->price);
            return;
        }
        temp = temp->next;
    }

    printf("\nMedicine Not Found!");
}

void deleteMedicine(int id)
{
    if(head==NULL)   //if list is empty
    {
        printf("\nEmpty List");
        return;
    }

    if(head->med_id == id)  //if head node needs to be deleted
    {
        struct Medicine *temp = head;
        head = head->next;
        free(temp);
        printf("\nMedicine Deleted Successfully!");
        return;
    }

    else   //find the node to be deleted
    {
        struct Medicine *temp = head;
        while(temp->next!=NULL && temp->next->med_id!=id)
        {
            temp = temp->next;
        }

        if(temp->next == NULL)  //if node not found
        {
            printf("\nMedicine Not Found!");
            return;
        }

        else   //delete the node
        {
            struct Medicine *del = temp->next;
            temp->next = del->next;
            free(del);
            printf("\nMedicine Deleted Successfully!");
            return;
        }
    }
}

int main()
{
    int choice, id;
    while(1)
    {
        printf("\n-----------------------------------------------\n");
        printf("\n1. Add Medicine\n2. Display List\n3. Search Medicine\n4. Delete Medicine\n5. Exit\n");
        printf("\nEnter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                insertMedicine();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("\nEnter Medicine ID to search: ");
                scanf("%d",&id);
                searchMedicine(id);
                break;

            case 4:
                printf("\nEnter Medicine ID to delete: ");
                scanf("%d",&id);
                deleteMedicine(id);
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid Choice!");
        }
    }
    return 0;
}