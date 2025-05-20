//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: medieval
int main()
{
    int choice;
    float amount = 0.0;
    char item[50];
    do
    {
        printf("\nWelcome to the Medieval Cafe Billing System\n");
        printf("1. Place an order\n");
        printf("2. View bill\n");
        printf("3. Pay bill\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the item you wish to order: ");
                scanf("%s", item);
                if(strcmp(item, "Ale") == 0)
                {
                    amount += 2.5;
                    printf("You ordered an Ale for $2.5\n");
                }
                else if(strcmp(item, "Bread") == 0)
                {
                    amount += 1.0;
                    printf("You ordered Bread for $1.0\n");
                }
                else if(strcmp(item, "Stew") == 0)
                {
                    amount += 3.5;
                    printf("You ordered Stew for $3.5\n");
                }
                else
                {
                    printf("Invalid item\n");
                }
                break;

            case 2:
                printf("Your current bill is $%.2f\n", amount);
                break;

            case 3:
                printf("You paid $%.2f\n", amount);
                break;

            case 4:
                printf("Thank you for visiting the Medieval Cafe Billing System\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }while(choice!= 4);

    return 0;
}