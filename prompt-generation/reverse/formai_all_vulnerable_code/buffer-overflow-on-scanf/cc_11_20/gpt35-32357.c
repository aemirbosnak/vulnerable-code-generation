//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine
{
    int code;
    char name[20];
    int qty;
    float price;
};

int main()
{
    struct medicine med[100];
    int choice, count = 0, i;
    while(1)
    {
        printf("\n1. Add Medicine\n2. Search Medicine\n3. Update Medicine\n4. Delete Medicine\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: //Add Medicine
            {
                printf("\nAdd Medicine\n");
                printf("Enter Medicine Code: ");
                scanf("%d", &med[count].code);
                printf("Enter Medicine Name: ");
                scanf("%s", med[count].name);
                printf("Enter Medicine Quantity: ");
                scanf("%d", &med[count].qty);
                printf("Enter Medicine Price: ");
                scanf("%f", &med[count].price);
                count++;
                break;
            }
            case 2: //Search Medicine
            {
                int searchCode, flag = 0;
                printf("\nSearch Medicine\n");
                printf("Enter Medicine Code: ");
                scanf("%d", &searchCode);
                for(i=0;i<count;i++)
                {
                    if(med[i].code == searchCode)
                    {
                        printf("Medicine Name: %s\n", med[i].name);
                        printf("Medicine Quantity: %d\n", med[i].qty);
                        printf("Medicine Price: %.2f\n", med[i].price);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    printf("Medicine not found!\n");
                }
                break;
            }
            case 3: //Update Medicine
            {
                int updateCode, flag = 0;
                printf("\nUpdate Medicine\n");
                printf("Enter Medicine Code: ");
                scanf("%d", &updateCode);
                for(i=0;i<count;i++)
                {
                    if(med[i].code == updateCode)
                    {
                        printf("Enter Medicine Quantity: ");
                        scanf("%d", &med[i].qty);
                        printf("Enter Medicine Price: ");
                        scanf("%f", &med[i].price);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    printf("Medicine not found!\n");
                }
                break;
            }
            case 4: //Delete Medicine
            {
                int deleteCode, flag = 0;
                char confirm;
                printf("\nDelete Medicine\n");
                printf("Enter Medicine Code: ");
                scanf("%d", &deleteCode);
                for(i=0;i<count;i++)
                {
                    if(med[i].code == deleteCode)
                    {
                        printf("Are you sure you want to delete %s? (y/n)", med[i].name);
                        scanf(" %c", &confirm);
                        if(confirm == 'y')
                        {
                            memmove(&med[i], &med[i+1], (count-i-1)*sizeof(struct medicine));
                            count--;
                            printf("Medicine deleted successfully!\n");
                            flag = 1;
                        }
                        else
                        {
                            printf("Deletion cancelled!\n");
                        }
                        break;
                    }
                }
                if (flag == 0)
                {
                    printf("Medicine not found!\n");
                }
                break;
            }
            case 5: //Exit
            {
                printf("\nExiting Program!\n");
                exit(0);
            }
            default:
            {
                printf("\nInvalid Option! Try Again!\n");
            }
        }
    }
    return 0;
}