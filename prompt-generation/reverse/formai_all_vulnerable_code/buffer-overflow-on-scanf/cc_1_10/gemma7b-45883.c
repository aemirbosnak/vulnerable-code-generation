//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Medicine
{
    char name[50];
    int quantity;
    float price;
} Medicine;

void display_medicine(Medicine *med)
{
    printf("Name: %s\n", med->name);
    printf("Quantity: %d\n", med->quantity);
    printf("Price: %.2f\n", med->price);
}

void add_medicine(Medicine **med, int *size)
{
    *med = (Medicine *)realloc(*med, (*size) * sizeof(Medicine));
    (*med)->name[0] = '\0';
    (*med)->quantity = 0;
    (*med)->price = 0.0f;
    (*size)++;
}

void search_medicine(Medicine *med, int size)
{
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);

    for (int i = 0; i < size; i++)
    {
        if (strcmp(name, med[i].name) == 0)
        {
            display_medicine(&med[i]);
            break;
        }
    }

    if (strcmp(name, "") == 0)
    {
        printf("No medicine found.\n");
    }
}

int main()
{
    Medicine *med = NULL;
    int size = 0;

    add_medicine(&med, &size);
    add_medicine(&med, &size);
    add_medicine(&med, &size);

    search_medicine(med, size);

    return 0;
}