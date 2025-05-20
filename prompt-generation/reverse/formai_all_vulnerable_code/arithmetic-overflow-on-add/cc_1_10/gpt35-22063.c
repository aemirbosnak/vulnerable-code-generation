//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINE_NAME_LEN 50
#define MAX_MEDICINE_TYPES 10

struct Medicine
{
    char name[MAX_MEDICINE_NAME_LEN];
    int quantity;
    float price;
};

struct MedicineType
{
    char name[MAX_MEDICINE_NAME_LEN];
    struct Medicine* medicines;
    int num_medicines;
};

struct MedicalStore
{
    char name[MAX_MEDICINE_NAME_LEN];
    struct MedicineType types[MAX_MEDICINE_TYPES];
    int num_types;
};

void add_medicine_type(struct MedicalStore* store)
{
    char type_name[MAX_MEDICINE_NAME_LEN];

    printf("Enter name of medicine type: ");
    scanf("%s", type_name);

    struct MedicineType* type = &(store->types[store->num_types]);

    strcpy(type->name, type_name);

    type->medicines = (struct Medicine*) malloc(sizeof(struct Medicine));
    type->num_medicines = 0;

    store->num_types++;
}

void add_medicine(struct MedicalStore* store)
{
    int type_index;

    printf("Enter medicine type index: ");
    scanf("%d", &type_index);

    struct MedicineType* type = &(store->types[type_index]);

    if (type->num_medicines == 0)
        type->medicines = (struct Medicine*) malloc(sizeof(struct Medicine));
    else
        type->medicines = (struct Medicine*) realloc(type->medicines, (type->num_medicines+1)*sizeof(struct Medicine));

    struct Medicine* medicine = &(type->medicines[type->num_medicines]);

    printf("Enter name of medicine: ");
    scanf("%s", medicine->name);

    printf("Enter quantity: ");
    scanf("%d", &medicine->quantity);

    printf("Enter price: ");
    scanf("%f", &medicine->price);

    type->num_medicines++;
}

void print_medicines(struct MedicineType* type)
{
    for (int i = 0; i < type->num_medicines; i++)
    {
        struct Medicine* medicine = &(type->medicines[i]);

        printf("Medicine name: %s\n", medicine->name);
        printf("Quantity: %d\n", medicine->quantity);
        printf("Price: %f\n", medicine->price);
        printf("\n");
    }
}

void display_store(struct MedicalStore* store)
{
    printf("Store Name: %s\n\n", store->name);

    for (int i = 0; i < store->num_types; i++)
    {
        struct MedicineType* type = &(store->types[i]);

        printf("Medicine Type Name: %s\n", type->name);
        print_medicines(type);
    }
}

int main()
{
    struct MedicalStore store;

    printf("Enter name of store: ");
    scanf("%s", store.name);

    store.num_types = 0;

CHOOSE_OPERATION:
    printf("Choose an operation:\n");
    printf("1. Add Medicine Type\n");
    printf("2. Add Medicine\n");
    printf("3. Display Store\n");
    printf("4. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            add_medicine_type(&store);
            break;
        case 2:
            add_medicine(&store);
            break;
        case 3:
            display_store(&store);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice, please choose again\n");
            break;
    }

    goto CHOOSE_OPERATION;

    return 0;
}