//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int main()
{
    int option, i, j, n=0, id;
    char name[20];
    float weight, total_weight=0;
    int stored_items[MAX_SIZE];
    char stored_names[MAX_SIZE][20];
    float stored_weights[MAX_SIZE];

    while(1)
    {
        //Display Menu
        printf("\nWarehouse Management System\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. View all items\n");
        printf("4. View total weight\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                //Add Item
                printf("\nEnter item ID: ");
                scanf("%d", &id);
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item weight: ");
                scanf("%f", &weight);
                stored_items[n] = id;
                strcpy(stored_names[n], name);
                stored_weights[n] = weight;
                n++;
                printf("\nItem added successfully!\n");
                break;

            case 2:
                //Remove Item
                printf("\nEnter item ID to remove: ");
                scanf("%d", &id);
                for(i=0; i<n; i++)
                {
                    if(stored_items[i]==id)
                    {
                        for(j=i; j<n-1; j++)
                        {
                            stored_items[j] = stored_items[j+1];
                            strcpy(stored_names[j], stored_names[j+1]);
                            stored_weights[j] = stored_weights[j+1];
                        }
                        n--;
                        printf("\nItem removed successfully!\n");
                        break;
                    }
                }
                if(i==n)
                    printf("\nItem not found!\n");
                break;

            case 3:
                //View all items
                printf("\nAll Items: \n");
                printf("ID\tName\tWeight\n");
                for(i=0; i<n; i++)
                {
                    printf("%d\t%s\t%.2f\n", stored_items[i], stored_names[i], stored_weights[i]);
                }
                break;

            case 4:
                //View total weight
                for(i=0; i<n; i++)
                {
                    total_weight += stored_weights[i];
                }
                printf("\nTotal weight of all items: %.2f\n", total_weight);
                break;

            case 5:
                //Exit
                printf("\nExiting...\n");
                exit(0);
                break;

            default:
                printf("\nInvalid option!\n");

        }
    }

    return 0;
}