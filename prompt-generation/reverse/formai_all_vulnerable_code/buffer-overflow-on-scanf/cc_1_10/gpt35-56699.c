//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char medicine_name[20];
    int quantity;
    float price;
} Medicine;

void add_medicine(Medicine *medicines, int *current_size)
{
    printf("Enter medicine name: ");
    scanf("%s", medicines[*current_size].medicine_name);

    printf("Enter medicine quantity: ");
    scanf("%d", &medicines[*current_size].quantity);

    printf("Enter medicine price: ");
    scanf("%f", &medicines[*current_size].price);

    (*current_size)++;
}

void display_medicines(Medicine *medicines, int current_size)
{
    printf("Medicine Name\tQuantity\tPrice\n");
    printf("---------------------------------------\n");

    for (int i = 0; i < current_size; i++)
    {
        printf("%s\t\t%d\t\t%.2f\n", medicines[i].medicine_name, 
        medicines[i].quantity, medicines[i].price);
    }
}

int main()
{
    Medicine *medicines = (Medicine *)malloc(sizeof(Medicine) * 10);
    int current_size = 0;
    int choice;

    do
    {
        printf("\n-------Medical Store Management System-------\n\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_medicine(medicines, &current_size);
            break;

        case 2:
            display_medicines(medicines, current_size);
            break;

        case 3:
            printf("Exiting...Thank you for using our system.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 3);

    free(medicines);
    return 0;
}