//FormAI DATASET v1.0 Category: Expense Tracker ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct expenses //structure to hold each expense
{
    char category[20];
    float amount;
    char date[20];
};

struct node //structure to hold each node in the linked list
{
    struct expenses expense;
       struct node *next;
};

struct node *head = NULL; //global pointer variable points to the start of the linked list

void insert_expense() //function to insert the expense details into the linked list
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter Category: ");
    scanf("%s", new_node->expense.category);

    printf("\nEnter Amount: ");
    scanf("%f", &new_node->expense.amount);

    printf("\nEnter Date (dd-mm-yyyy): ");
    scanf("%s", new_node->expense.date);

    new_node->next = head;
    head = new_node;

    printf("\nExpense Inserted Successfully!\n");
}

void view_expenses() //function to view all the expenses entered by the user
{
    struct node *ptr;
    ptr = head;

    if(ptr == NULL)
        printf("\nNo Expenses to Show!\n");
    else
    {
        printf("\nExpenses List:\n");

        while(ptr != NULL)
        {
            printf("\nCategory: %s\n", ptr->expense.category);
            printf("Amount: $%.2f\n", ptr->expense.amount);
            printf("Date: %s\n", ptr->expense.date);

            ptr = ptr->next;
        }
    }
}

void search_expense() //function to search for an expense by category
{
    char category[20];
    int flag = 0;
    struct node *ptr;
    ptr = head;

    if(ptr == NULL)
        printf("\nNo Expenses to Search!\n");
    else
    {
        printf("\nEnter Category to Search: ");
        scanf("%s", category);

        while(ptr != NULL)
        {
            if(strcmp(ptr->expense.category,category) == 0)
            {
                flag = 1;
                printf("\nCategory: %s\n", ptr->expense.category);
                printf("Amount: $%.2f\n", ptr->expense.amount);
                printf("Date: %s\n", ptr->expense.date);
            }

            ptr = ptr->next;
        }

        if(flag == 0)
            printf("\nNo Expenses Found with the Entered Category!\n");
    }
}

void delete_expense() //function to delete an expense based on its category
{
    char category[20];
    int flag = 0;
    struct node *ptr, *prev;
    ptr = head;

    if(ptr == NULL)
        printf("\nNo Expenses to Delete!\n");
    else
    {
        printf("\nEnter Category to Delete: ");
        scanf("%s", category);

        while(ptr != NULL)
        {
            if(strcmp(ptr->expense.category,category) == 0)
            {
                flag = 1;
                if(ptr == head)
                    head = ptr->next;
                else
                    prev->next = ptr->next;

                free(ptr);
                printf("\nExpense Deleted Successfully!\n");
                break;
            }

            prev = ptr;
            ptr = ptr->next;
        }

        if(flag == 0)
            printf("\nNo Expenses Found with the Entered Category!\n");
    }
}

int main() //main function to execute the program
{
    int choice;
    while(1)
    {
        printf("\nExpense Tracker: Choose an Option\n");
        printf("1. Insert Expense\n");
        printf("2. View All Expenses\n");
        printf("3. Search Expense by Category\n");
        printf("4. Delete Expense by Category\n");
        printf("5. Exit\n");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert_expense();
                break;

            case 2:
                view_expenses();
                break;

            case 3:
                search_expense();
                break;

            case 4:
                delete_expense();
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("\nInvalid Choice! Try Again!\n");
                break;
        }
    }

    return 0;
}