//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: complete
#include <stdio.h>
#include <string.h>

struct medicine {
    int ID;
    char name[20];
    int quantity;
    float price;
};

typedef struct medicine Medicine;

int main() {
    Medicine inventory[100];
    int num_meds = 0, choice, id; 
    
    while(1) {
        printf("\nMedicine Store Management System\n");
        printf("1. Add a medicine to inventory\n");
        printf("2. Remove a medicine from inventory\n");
        printf("3. Update medicine quantity\n");
        printf("4. Display inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter medicine ID: ");
                scanf("%d", &inventory[num_meds].ID);
                printf("Enter medicine name: ");
                scanf("%s", inventory[num_meds].name);
                printf("Enter medicine quantity: ");
                scanf("%d", &inventory[num_meds].quantity);
                printf("Enter medicine price: ");
                scanf("%f", &inventory[num_meds].price);
                num_meds++;
                printf("\nMedicine added successfully!\n");
                break;
                
            case 2:
                printf("\nEnter medicine ID: ");
                scanf("%d", &id);
                for(int i = 0; i < num_meds; i++) {
                    if(inventory[i].ID == id) {
                        for(int j = i; j < num_meds; j++) {
                            inventory[j] = inventory[j+1];
                        }
                        num_meds--;
                        printf("\nMedicine removed successfully!\n");
                        break;
                    }
                    else {
                        printf("\nMedicine not found!\n");
                        break;
                    }
                    
                }
                break;
                
            case 3:
                printf("\nEnter medicine ID: ");
                scanf("%d", &id);
                for(int i = 0; i < num_meds; i++) {
                    if(inventory[i].ID == id) {
                        printf("Enter new quantity: ");
                        scanf("%d", &inventory[i].quantity);
                        printf("\nQuantity updated successfully!\n");
                        break;
                    }
                    else {
                        printf("\nMedicine not found!\n");
                        break;
                    }
                }
                break;
                
            case 4:
                printf("\nInventory:\n");
                printf("ID\tName\tQuantity\tPrice\n");
                for(int i = 0; i < num_meds; i++) {
                    printf("%d\t%s\t%d\t%.2f\n", inventory[i].ID, inventory[i].name, inventory[i].quantity, inventory[i].price);
                }
                break;
                
            case 5:
                printf("\nExiting program...\n");
                return 0;
                
            default:
                printf("\nInvalid choice!\n");
        }
    }
    
    return 0;
}