//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medical_store
{
    char name[50];
    float price;
    int quantity;
};

void main()
{
    struct medical_store medicine[100];
    int i, j, n, m;
    char ch;

    printf("\n\n\n======= Welcome to the Medical Store Management System =======\n\n");
    printf("Enter the number of medicines you want to add: ");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter the name of medicine %d: ", i+1);
        scanf(" %[^\n]s", medicine[i].name);

        printf("Enter the price of medicine %d: ", i+1);
        scanf("%f", &medicine[i].price);

        printf("Enter the quantity of medicine %d: ", i+1);
        scanf("%d", &medicine[i].quantity);
    }

    do
    {
        printf("\n\n\n======= Medical Store Management System =======\n\n");
        printf("1. Add new medicine \n");
        printf("2. Display all medicines \n");
        printf("3. Search for a medicine \n");
        printf("4. Remove a medicine \n");
        printf("5. Update a medicine \n");
        printf("6. Exit \n");
        printf("\nEnter your choice: ");
        scanf("%d", &m);

        switch(m)
        {
            case 1:
                printf("\nEnter the number of medicines you want to add: ");
                scanf("%d", &n);

                for(i=0;i<n;i++)
                {
                    printf("\nEnter the name of medicine %d: ", i+1);
                    scanf(" %[^\n]s", medicine[i].name);

                    printf("Enter the price of medicine %d: ", i+1);
                    scanf("%f", &medicine[i].price);

                    printf("Enter the quantity of medicine %d: ", i+1);
                    scanf("%d", &medicine[i].quantity);
                }
                break;

            case 2:
                printf("\n\n\n======= List of All Medicines =======\n\n");
                for(i=0;i<n;i++)
                {
                    printf("%d) Name: %s\tPrice: %f\tQuantity: %d\n", i+1, medicine[i].name, medicine[i].price, medicine[i].quantity);
                }
                break;

            case 3:
                printf("\nEnter the name of the medicine you want to search for: ");
                char search_name[50];
                int flag=0;
                scanf(" %[^\n]s", search_name);

                for(i=0;i<n;i++)
                {
                    if(strcmp(search_name, medicine[i].name)==0)
                    {
                        flag=1;
                        printf("\n\n======= Medicine Details =======\n\n");
                        printf("Name: %s\tPrice: %f\tQuantity: %d\n", medicine[i].name, medicine[i].price, medicine[i].quantity);
                        break;
                    }
                }
                if(flag==0)
                    printf("\nMedicine not found!\n");
                break;

            case 4:
                printf("\nEnter the name of the medicine you want to remove: ");
                char remove_name[50];
                int remove_pos;
                int remove_flag=0;
                scanf(" %[^\n]s", remove_name);

                for(i=0;i<n;i++)
                {
                    if(strcmp(remove_name, medicine[i].name)==0)
                    {
                        remove_flag=1;
                        remove_pos=i;
                        break;
                    }
                }

                if(remove_flag==0)
                    printf("\nMedicine not found!\n");
                else
                {
                    for(i=remove_pos;i<n-1;i++)
                    {
                        strcpy(medicine[i].name, medicine[i+1].name);
                        medicine[i].price=medicine[i+1].price;
                        medicine[i].quantity=medicine[i+1].quantity;
                    }
                    printf("\nMedicine removed successfully!\n");
                    n--;
                }
                break;

            case 5:
                printf("\nEnter the name of the medicine you want to update: ");
                char update_name[50];
                int update_flag=0;
                scanf(" %[^\n]s", update_name);

                for(i=0;i<n;i++)
                {
                    if(strcmp(update_name, medicine[i].name)==0)
                    {
                        update_flag=1;
                        printf("\nEnter the updated details of medicine %d: \n", i+1);
                        printf("Name: ");
                        scanf(" %[^\n]s", medicine[i].name);
                        printf("Price: ");
                        scanf("%f", &medicine[i].price);
                        printf("Quantity: ");
                        scanf("%d", &medicine[i].quantity);
                        break;
                    }
                }
                if(update_flag==0)
                    printf("\nMedicine not found!\n");
                else
                    printf("\nMedicine updated successfully!\n");
                break;

            case 6:
                exit(0);

            default :
                printf("\nInvalid choice!\n");
        }
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ch);
    }while(ch=='y' || ch=='Y');
}