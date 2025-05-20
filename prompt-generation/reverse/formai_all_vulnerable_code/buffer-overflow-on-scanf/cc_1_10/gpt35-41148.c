//FormAI DATASET v1.0 Category: Hotel Management System ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure to store customer details
struct customer{
    char name[20];
    char address[50];
    char phone[10];
    int room_no;
    int days;
};

//function to display menu
void menu()
{
    printf("\n\n\t\t=====Hotel Management System Menu=====");
    printf("\n\t\t1. Register a Customer");
    printf("\n\t\t2. Display Customer Details");
    printf("\n\t\t3. Update Customer Details");
    printf("\n\t\t4. Delete Customer Details");
    printf("\n\t\t5. Exit\n");
}

//function to register a customer
void register_customer(struct customer *p, int *count)
{
    printf("\nEnter Customer Details: ");
    printf("\nName: ");
    fgets(p[*count].name, 20, stdin);
    printf("Address: ");
    fgets(p[*count].address, 50, stdin);
    printf("Phone: ");
    fgets(p[*count].phone, 10, stdin);
    printf("Room Number: ");
    scanf("%d", &p[*count].room_no);
    printf("Number of days staying: ");
    scanf("%d", &p[*count].days);
    printf("\nCustomer registered successfully!\n");
    (*count)++;
}

//function to display customer details
void display_customer(struct customer *p, int *count)
{
    int i, room;
    printf("\nEnter Room Number: ");
    scanf("%d", &room);
    for(i=0;i<*count;i++)
    {
        if(p[i].room_no==room)
        {
            printf("\nCustomer Details: \n");
            printf("Name: %s", p[i].name);
            printf("Address: %s", p[i].address);
            printf("Phone: %s", p[i].phone);
            printf("Room Number: %d\n", p[i].room_no);
            printf("Number of days staying: %d\n", p[i].days);
            return;
        }
    }
    printf("\nCustomer not found!\n");
}

//function to update customer details
void update_customer(struct customer *p, int *count)
{
    int i, room;
    printf("\nEnter Room Number: ");
    scanf("%d", &room);
    for(i=0;i<*count;i++)
    {
        if(p[i].room_no==room)
        {
            printf("\nEnter Customer Details: ");
            printf("\nName: ");
            fgets(p[i].name, 20, stdin);
            printf("Address: ");
            fgets(p[i].address, 50, stdin);
            printf("Phone: ");
            fgets(p[i].phone, 10, stdin);
            printf("Room Number: ");
            scanf("%d", &p[i].room_no);
            printf("Number of days staying: ");
            scanf("%d", &p[i].days);
            printf("\nCustomer details updated successfully!\n");
            return;
        }
    }
    printf("\nCustomer not found!\n");
}

//function to delete customer details
void delete_customer(struct customer *p, int *count)
{
    int i, room;
    printf("\nEnter Room Number: ");
    scanf("%d", &room);
    for(i=0;i<*count;i++)
    {
        if(p[i].room_no==room)
        {
            strcpy(p[i].name,"");
            strcpy(p[i].address,"");
            strcpy(p[i].phone,"");
            p[i].room_no=0;
            p[i].days=0;
            printf("\nCustomer details deleted successfully!\n");
            return;
        }
    }
    printf("\nCustomer not found!\n");
}

//main function
int main()
{
    struct customer c[50];
    int choice, count=0;

    while(1)
    {
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch(choice)
        {
            case 1: register_customer(c, &count); break;
            case 2: display_customer(c, &count); break;
            case 3: update_customer(c, &count); break;
            case 4: delete_customer(c, &count); break;
            case 5: exit(0);
            default: printf("\nInvalid Choice!\n"); break;
        }
    }

    return 0;
}