//FormAI DATASET v1.0 Category: Hotel Management System ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct customer
{
    char name[20];
    long int contactno;
    int roomno;
    char address[50];
    int nrooms;
};

int main()
{
    int n;
    printf("\nEnter number of customers: ");
    scanf("%d",&n);

    struct customer c[n];

    for(int i=0;i<n;i++)
    {
        printf("\nEnter details for Customer %d: ",i+1);
        printf("\nName: ");
        scanf("%s",c[i].name);

        printf("Contact Number: ");
        scanf("%ld",&c[i].contactno);

        printf("Room Number: ");
        scanf("%d",&c[i].roomno);

        printf("Address: ");
        scanf("%s",c[i].address);

        printf("Number of Rooms: ");
        scanf("%d",&c[i].nrooms);
    }

    int choice;
    printf("\nMenu: \n1. View Customer Details\n2. Update Customer Details\n3. Delete Customer Details\n4. Exit\nEnter your choice: ");
    scanf("%d",&choice);

    do{
        switch(choice)
        {
            case 1:
                printf("\nEnter Customer Number: ");
                int num1;
                scanf("%d",&num1);
                printf("\nName: %s\nContact Number: %ld\nRoom Number: %d\nAddress: %s\nNumber of Rooms: %d\n",c[num1-1].name,c[num1-1].contactno,c[num1-1].roomno,c[num1-1].address,c[num1-1].nrooms);
                break;
            case 2:
                printf("\nEnter Customer Number: ");
                int num2;
                scanf("%d",&num2);
                printf("\nExisting Details: ");
                printf("\nName: %s\nContact Number: %ld\nRoom Number: %d\nAddress: %s\nNumber of Rooms: %d\n",c[num2-1].name,c[num2-1].contactno,c[num2-1].roomno,c[num2-1].address,c[num2-1].nrooms);
                printf("\nEnter New Details: ");

                printf("\nName: ");
                scanf("%s",c[num2-1].name);

                printf("Contact Number: ");
                scanf("%ld",&c[num2-1].contactno);

                printf("Room Number: ");
                scanf("%d",&c[num2-1].roomno);

                printf("Address: ");
                scanf("%s",c[num2-1].address);

                printf("Number of Rooms: ");
                scanf("%d",&c[num2-1].nrooms);
                break;
            case 3:
                printf("\nEnter Customer Number to Delete: ");
                int num3;
                scanf("%d",&num3);
                for(int i=num3-1;i<n-1;i++)
                {
                    strcpy(c[i].name,c[i+1].name);
                    c[i].contactno=c[i+1].contactno;
                    c[i].roomno=c[i+1].roomno;
                    strcpy(c[i].address,c[i+1].address);
                    c[i].nrooms=c[i+1].nrooms;
                }
                n--;
                break;
            default:
                printf("Invalid choice!");
        }

        printf("\nMenu: \n1. View Customer Details\n2. Update Customer Details\n3. Delete Customer Details\n4. Exit\nEnter your choice: ");
        scanf("%d",&choice);

    }while(choice!=4);

    return 0;
}