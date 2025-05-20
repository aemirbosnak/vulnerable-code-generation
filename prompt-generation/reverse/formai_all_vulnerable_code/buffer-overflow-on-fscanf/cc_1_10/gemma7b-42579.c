//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void display_menu()
{
    printf("\nPlease select an option:");
    printf("\n1. Add item");
    printf("\n2. Search item");
    printf("\n3. Remove item");
    printf("\n4. Update item");
    printf("\n5. Exit");
    printf("\nEnter your selection:");
}

void add_item(int item_id)
{
    char item_name[20];
    int quantity;
    float price;

    printf("Enter item name:");
    scanf("%s", item_name);

    printf("Enter quantity:");
    scanf("%d", &quantity);

    printf("Enter price:");
    scanf("%f", &price);

    FILE *fp = fopen("items.txt", "a");
    fprintf(fp, "%d, %s, %d, %f\n", item_id, item_name, quantity, price);
    fclose(fp);
}

void search_item(int item_id)
{
    FILE *fp = fopen("items.txt", "r");
    char item_name[20];
    int quantity;
    float price;

    while (fscanf(fp, "%d, %s, %d, %f\n", &item_id, item_name, &quantity, &price) != EOF)
    {
        if (item_id == item_id)
        {
            printf("Item name: %s\n", item_name);
            printf("Quantity: %d\n", quantity);
            printf("Price: %f\n", price);
        }
    }
    fclose(fp);
}

void remove_item(int item_id)
{
    FILE *fp = fopen("items.txt", "r");
    char item_name[20];
    int quantity;
    float price;

    FILE *fpw = fopen("temp.txt", "w");

    while (fscanf(fp, "%d, %s, %d, %f\n", &item_id, item_name, &quantity, &price) != EOF)
    {
        if (item_id != item_id)
        {
            fprintf(fpw, "%d, %s, %d, %f\n", item_id, item_name, quantity, price);
        }
    }
    fclose(fp);
    fclose(fpw);

    remove("items.txt");
    rename("temp.txt", "items.txt");
}

void update_item(int item_id)
{
    char item_name[20];
    int quantity;
    float price;

    FILE *fp = fopen("items.txt", "r");
    char old_item_name[20];

    while (fscanf(fp, "%d, %s, %d, %f\n", &item_id, old_item_name, &quantity, &price) != EOF)
    {
        if (strcmp(old_item_name, item_name) == 0)
        {
            printf("Enter new item name:");
            scanf("%s", item_name);

            printf("Enter new quantity:");
            scanf("%d", &quantity);

            printf("Enter new price:");
            scanf("%f", &price);

            FILE *fpw = fopen("temp.txt", "w");

            fprintf(fpw, "%d, %s, %d, %f\n", item_id, item_name, quantity, price);

            fclose(fp);
            fclose(fpw);

            remove("items.txt");
            rename("temp.txt", "items.txt");
        }
    }
    fclose(fp);
}

int main()
{
    int item_id;

    display_menu();
    scanf("%d", &item_id);

    switch (item_id)
    {
        case 1:
            add_item(item_id);
            break;
        case 2:
            search_item(item_id);
            break;
        case 3:
            remove_item(item_id);
            break;
        case 4:
            update_item(item_id);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid input.");
    }

    return 0;
}