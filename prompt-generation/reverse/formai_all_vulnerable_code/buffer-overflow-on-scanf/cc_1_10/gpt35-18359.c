//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine
{
    char name[50];
    int quantity;
    float price;
};

void addMedicine(struct medicine *medicines, int *count)
{
    char name[50];
    int quantity;
    float price;

    printf("Enter the name of the medicine: ");
    scanf("%s", name);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &price);

    strcpy(medicines[*count].name, name);
    medicines[*count].quantity = quantity;
    medicines[*count].price = price;

    (*count)++;
}

void showMedicines(struct medicine *medicines, int count)
{
    if(count == 0)
    {
        printf("No medicines found.\n");
        return;
    }

    printf("Name    Quantity    Price\n");

    for(int i = 0; i < count; i++)
    {
        printf("%s    %d    %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

void searchMedicine(struct medicine *medicines, int count)
{
    if(count == 0)
    {
        printf("No medicines found.\n");
        return;
    }

    char name[50];
    printf("Enter the name of the medicine: ");
    scanf("%s", name);

    for(int i = 0; i < count; i++)
    {
        if(strcmp(medicines[i].name, name) == 0)
        {
            printf("Name    Quantity    Price\n");
            printf("%s    %d    %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
            return;
        }
    }

    printf("Medicine not found.\n");
}

int main()
{
    struct medicine medicines[100];
    int count = 0;
    int choice;

    do
    {
        printf("\n");
        printf("1. Add medicine\n");
        printf("2. Show all medicines\n");
        printf("3. Search for a medicine\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                showMedicines(medicines, count);
                break;
            case 3:
                searchMedicine(medicines, count);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}