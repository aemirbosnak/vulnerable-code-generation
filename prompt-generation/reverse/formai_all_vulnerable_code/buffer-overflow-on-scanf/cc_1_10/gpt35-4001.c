//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
typedef struct Medicine // Structure representing a medicine
{
    char name[30];
    int quantity;
    float price;
} Medicine;
void add_medicine(Medicine*, int*); // Function for adding a new medicine to the store
void buy_medicine(Medicine*, int); // Function for buying medicine from the store
void display_stock(Medicine*, int); // Function for displaying the current stock of medicines
int main()
{
    int option, num_meds = 0, i;
    Medicine meds[100];
    do
    {
        printf("\nMedical Store Management\n1. Add new medicine\n2. Buy medicine\n3. Display stock\n4. Exit\nEnter your option: ");
        scanf("%d", &option);
        switch (option)
        {
            case 1:
                add_medicine(meds, &num_meds);
                break;
            case 2:
                buy_medicine(meds, num_meds);
                break;
            case 3:
                display_stock(meds, num_meds);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please enter again.\n");
                break;
        }
    } while (option != 4);
    return 0;
}
void add_medicine(Medicine* meds, int* num_meds)
{
    printf("\nAdding new medicine...\n");
    printf("Enter medicine name: ");
    scanf("%s", meds[*num_meds].name);
    printf("Enter quantity: ");
    scanf("%d", &meds[*num_meds].quantity);
    printf("Enter price: ");
    scanf("%f", &meds[*num_meds].price);
    (*num_meds)++;
    printf("Medicine added successfully!\n");
}
void buy_medicine(Medicine* meds, int num_meds)
{
    int i, found = 0, med_index, qty_buy;
    char med_name[30];
    printf("\nBuying medicine...\n");
    printf("Enter medicine name: ");
    scanf("%s", med_name);
    for (i = 0; i < num_meds; i++)
    {
        if (strcmp(med_name, meds[i].name) == 0)
        {
            found = 1;
            med_index = i;
            break;
        }
    }
    if (found)
    {
        printf("Enter quantity to buy: ");
        scanf("%d", &qty_buy);
        if (qty_buy > meds[med_index].quantity)
        {
            printf("Not enough stock available!\n");
        }
        else
        {
            printf("Total cost: %.2f\n", meds[med_index].price*qty_buy);
            meds[med_index].quantity -= qty_buy;
            printf("Medicine bought successfully!\n");
        }
    }
    else
    {
        printf("Medicine not found in stock!\n");
    }
}
void display_stock(Medicine* meds, int num_meds)
{
    int i;
    printf("\nCurrent stock:\n%-30s %-10s %-10s\n", "Medicine Name", "Quantity", "Price");
    for (i = 0; i < num_meds; i++)
    {
        printf("%-30s %-10d %-10.2f\n", meds[i].name, meds[i].quantity, meds[i].price);
    }
}