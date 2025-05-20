//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

Medicine medicine_list[MAX_MEDICINES];
int total_medicines = 0;

void add_medicine()
{
    if(total_medicines >= MAX_MEDICINES)
    {
        printf("Medicine store is full.\n");
        return;
    }

    Medicine new_medicine;
    printf("Enter medicine name: ");
    scanf("%s", new_medicine.name);
    printf("Enter medicine quantity: ");
    scanf("%d", &new_medicine.quantity);
    printf("Enter medicine price: ");
    scanf("%f", &new_medicine.price);

    medicine_list[total_medicines++] = new_medicine;

    printf("Medicine added successfully.\n");
}

void remove_medicine()
{
    if(total_medicines == 0)
    {
        printf("Medicine store is empty.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter medicine name to remove: ");
    scanf("%s", name);

    int found = 0;
    int index = 0;
    for(int i = 0; i < total_medicines; i++)
    {
        if(strcmp(medicine_list[i].name, name) == 0)
        {
            found = 1;
            index = i;
            break;
        }
    }

    if(found)
    {
        for(int i = index; i < total_medicines - 1; i++)
        {
            medicine_list[i] = medicine_list[i+1];
        }
        total_medicines--;
        printf("Medicine removed successfully.\n");
    }
    else
    {
        printf("Medicine not found.\n");
    }
}

void display_medicines()
{
    if(total_medicines == 0)
    {
        printf("Medicine store is empty.\n");
        return;
    }
    
    printf("Name\tQuantity\tPrice\n");
    for(int i = 0; i < total_medicines; i++)
    {
        printf("%s\t%d\t%.2f\n", medicine_list[i].name, medicine_list[i].quantity, medicine_list[i].price);
    }
}

void update_medicine_quantity()
{
    char name[MAX_NAME_LENGTH];
    printf("Enter medicine name to update quantity: ");
    scanf("%s", name);

    int found = 0;
    int index = 0;
    for(int i = 0; i < total_medicines; i++)
    {
        if(strcmp(medicine_list[i].name, name) == 0)
        {
            found = 1;
            index = i;
            break;
        }
    }

    if(found)
    {
        int quantity;
        printf("Enter new quantity: ");
        scanf("%d", &quantity);

        medicine_list[index].quantity = quantity;
        printf("Quantity updated successfully.\n");
    }
    else
    {
        printf("Medicine not found.\n");
    }
}

void update_medicine_price()
{
    char name[MAX_NAME_LENGTH];
    printf("Enter medicine name to update price: ");
    scanf("%s", name);

    int found = 0;
    int index = 0;
    for(int i = 0; i < total_medicines; i++)
    {
        if(strcmp(medicine_list[i].name, name) == 0)
        {
            found = 1;
            index = i;
            break;
        }
    }

    if(found)
    {
        float price;
        printf("Enter new price: ");
        scanf("%f", &price);

        medicine_list[index].price = price;
        printf("Price updated successfully.\n");
    }
    else
    {
        printf("Medicine not found.\n");
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("1. Add medicine\n");
        printf("2. Remove medicine\n");
        printf("3. Display medicines\n");
        printf("4. Update medicine quantity\n");
        printf("5. Update medicine price\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                add_medicine();
                break;
            case 2:
                remove_medicine();
                break;
            case 3:
                display_medicines();
                break;
            case 4:
                update_medicine_quantity();
                break;
            case 5:
                update_medicine_price();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}