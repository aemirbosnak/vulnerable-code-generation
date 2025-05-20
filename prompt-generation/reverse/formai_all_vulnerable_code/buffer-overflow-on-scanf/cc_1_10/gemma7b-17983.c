//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, item_num, quantity;
    float total_cost = 0.0f;
    char name[20];
    FILE *fp;

    // Open a file for logging transactions
    fp = fopen("transactions.txt", "a");

    // Display menu options
    printf("\nWelcome to the Future Cafe! Please select an option:");
    printf("\n1. View Menu");
    printf("\n2. Place Order");
    printf("\n3. View Order History");
    printf("\n4. Exit");

    // Get the user's choice
    scanf("%d", &choice);

    // Process the user's choice
    switch (choice)
    {
        case 1:
            // Display the menu
            printf("\nAvailable items:");
            printf("\n1. Coffee ( $2.00 )");
            printf("\n2. Tea ( $1.50 )");
            printf("\n3. Juice ( $1.00 )");
            printf("\n4. Smoothie ( $2.50 )");
            printf("\nPlease select an item:");
            scanf("%d", &item_num);

            // Get the item's cost
            switch (item_num)
            {
                case 1:
                    total_cost += 2.00;
                    break;
                case 2:
                    total_cost += 1.50;
                    break;
                case 3:
                    total_cost += 1.00;
                    break;
                case 4:
                    total_cost += 2.50;
                    break;
            }

            break;
        case 2:
            // Get the user's name and order quantity
            printf("\nEnter your name:");
            scanf("%s", name);
            printf("\nHow many items would you like to order?");
            scanf("%d", &quantity);

            // Calculate the total cost
            total_cost = quantity * total_cost;

            // Write the transaction to the file
            fprintf(fp, "Transaction: %s, %d items, Total Cost: $%.2f\n", name, quantity, total_cost);

            // Display the total cost
            printf("\nYour total cost is: $%.2f", total_cost);

            break;
        case 3:
            // Display the order history
            fp = fopen("transactions.txt", "r");
            printf("\nOrder History:");
            char line[100];
            while (fgets(line, 100, fp) != NULL)
            {
                printf("%s", line);
            }
            fclose(fp);

            break;
        case 4:
            // Exit the program
            exit(0);
            break;
    }

    fclose(fp);

    return 0;
}