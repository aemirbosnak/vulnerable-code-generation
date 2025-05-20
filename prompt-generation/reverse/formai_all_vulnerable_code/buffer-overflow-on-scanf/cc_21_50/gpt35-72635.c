//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MED_NAME_LENGTH 50

typedef struct
{
    char name[MED_NAME_LENGTH];
    float price;
    int quantity;
} Medicine;

int main()
{
    Medicine medicines[MAX_MEDICINES];
    int numMedicines = 0;
    char choice;
    
    do
    {
        printf("\nSelect an option:\n");
        printf("1. Add new medicine\n");
        printf("2. Remove medicine\n");
        printf("3. Update medicine price\n");
        printf("4. Update medicine quantity\n");
        printf("5. Search medicine\n");
        printf("6. Display all medicines\n");
        printf("7. Exit\n");
        printf("Choice: ");
        scanf(" %c", &choice);
        
        switch(choice)
        {
            case '1':
                if(numMedicines == MAX_MEDICINES)
                {
                    printf("Cannot add more medicines, storage full.\n");
                    break;
                }
                printf("Enter medicine name: ");
                scanf("%s", medicines[numMedicines].name);
                printf("Enter medicine price: ");
                scanf("%f", &medicines[numMedicines].price);
                printf("Enter medicine quantity: ");
                scanf("%d", &medicines[numMedicines].quantity);
                numMedicines++;
                printf("Medicine added successfully.\n");
                break;
            
            case '2':
                if(numMedicines == 0)
                {
                    printf("Cannot remove medicines, storage empty.\n");
                    break;
                }
                printf("Enter the index of medicine to remove: ");
                int index;
                scanf("%d", &index);
                
                if(index < 0 || index >= numMedicines)
                {
                    printf("Index out of bounds.\n");
                    break;
                }
                printf("%s removed successfully.\n", medicines[index].name);
                
                for(int i = index; i < numMedicines - 1; i++)
                {
                    medicines[i] = medicines[i + 1];
                }
                numMedicines--;
                break;
                
            case '3':
                if(numMedicines == 0)
                {
                    printf("Cannot update medicines, storage empty.\n");
                    break;
                }
                printf("Enter the index of medicine to update: ");
                int index1;
                scanf("%d", &index1);
                
                if(index1 < 0 || index1 >= numMedicines)
                {
                    printf("Index out of bounds.\n");
                    break;
                }
                
                printf("Enter new price of %s: ", medicines[index1].name);
                float newPrice;
                scanf("%f", &newPrice);
                medicines[index1].price = newPrice;
                printf("%s price updated successfully.\n", medicines[index1].name);
                break;
                
            case '4':
                if(numMedicines == 0)
                {
                    printf("Cannot update medicines, storage empty.\n");
                    break;
                }
                printf("Enter the index of medicine to update: ");
                int index2;
                scanf("%d", &index2);
                
                if(index2 < 0 || index2 >= numMedicines)
                {
                    printf("Index out of bounds.\n");
                    break;
                }
                
                printf("Enter new quantity of %s: ", medicines[index2].name);
                int newQuantity;
                scanf("%d", &newQuantity);
                medicines[index2].quantity = newQuantity;
                printf("%s quantity updated successfully.\n", medicines[index2].name);
                break;
                
            case '5':
                if(numMedicines == 0)
                {
                    printf("No medicines to search for, storage empty.\n");
                    break;
                }
                printf("Enter the medicine name to search for: ");
                char searchQuery[MED_NAME_LENGTH];
                scanf("%s", searchQuery);
                
                for(int i = 0; i < numMedicines; i++)
                {
                    if(strcmp(medicines[i].name, searchQuery) == 0)
                    {
                        printf("%s - price: %.2f, quantity: %d\n", medicines[i].name, medicines[i].price, medicines[i].quantity);
                    }
                }
                break;
                
            case '6':
                if(numMedicines == 0)
                {
                    printf("No medicines to display, storage empty.\n");
                    break;
                }
                printf("Medicine Name\tPrice\tQuantity\n");
                for(int i = 0; i < numMedicines; i++)
                {
                    printf("%s\t\t%.2f\t%d\n", medicines[i].name, medicines[i].price, medicines[i].quantity);
                }
                break;
                
            case '7':
                printf("Goodbye!\n");
                break;
                
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != '7');
    
    return 0;
}