//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int numMeds = 0; // number of available medicines

struct Medicine // structure of medicine objects
{
    int id;
    char name[50];
    int qty;
    float price;
};

struct Medicine meds[100]; // array of medicine objects

void addMedicine()
{
    if(numMeds >= 100) // check for max limit on medicines
    {
        printf("Medicine limit reached!\n");
        return;
    }

    struct Medicine newMed;

    printf("Enter medicine ID: ");
    scanf("%d", &newMed.id);

    printf("Enter medicine name: ");
    scanf("%s", newMed.name);

    printf("Enter medicine quantity: ");
    scanf("%d", &newMed.qty);

    printf("Enter medicine price: ");
    scanf("%f", &newMed.price);

    meds[numMeds] = newMed; // add new medicine to array
    numMeds++;

    printf("Medicine added successfully!\n");
}

void removeMedicine()
{
    int id;

    printf("Enter medicine ID to remove: ");
    scanf("%d", &id);

    for(int i = 0; i < numMeds; i++)
    {
        if(meds[i].id == id) // if medicine is found
        {
            for(int j = i; j < numMeds-1; j++) // shift array elements
            {
                meds[j] = meds[j+1];
            }
            numMeds--; // decrement total medicines count
            printf("Medicine removed successfully!\n");
            return;
        }
    }

    printf("Medicine not found!\n");
}

void viewMedicine()
{
    printf("ID\tName\tQuantity\tPrice\n");

    for(int i = 0; i < numMeds; i++) // print all medicines info
    {
        printf("%d\t%s\t%d\t\t%.2f\n", meds[i].id, meds[i].name, meds[i].qty, meds[i].price);
    }
}

void updateMedicine()
{
    int id, choice;

    printf("Enter medicine ID to update: ");
    scanf("%d", &id);

    for(int i = 0; i < numMeds; i++)
    {
        if(meds[i].id == id) // if medicine is found
        {
            printf("Enter choice to update:\n1. Name\n2. Quantity\n3. Price\n");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                    printf("Enter new medicine name: ");
                    scanf("%s", meds[i].name);
                    break;
                case 2:
                    printf("Enter new medicine quantity: ");
                    scanf("%d", &meds[i].qty);
                    break;
                case 3:
                    printf("Enter new medicine price: ");
                    scanf("%f", &meds[i].price);
                    break;
                default:
                    printf("Invalid choice!\n");
                    break;
            }

            printf("Medicine updated successfully!\n");
            return;
        }
    }

    printf("Medicine not found!\n");
}

int main()
{
    int choice;

    printf("Welcome to Medical Store Management System!\n");

    while(1)
    {
        printf("\nEnter choice:\n1. Add medicine\n2. Remove medicine\n3. View medicine\n4. Update medicine\n5. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addMedicine();
                break;
            case 2:
                removeMedicine();
                break;
            case 3:
                viewMedicine();
                break;
            case 4:
                updateMedicine();
                break;
            case 5:
                printf("Thank you for using our system!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}