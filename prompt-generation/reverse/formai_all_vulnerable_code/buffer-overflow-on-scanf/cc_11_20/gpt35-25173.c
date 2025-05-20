//FormAI DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include <stdio.h>
#include <string.h>

struct product {
    char name[50];
    int quantity;
    float price;
};

int main()
{
    int choice, flag = 0;
    char searchName[50];
    struct product inventory[100];
    int count = 0;
    
    do {
        printf("-------- Product Inventory System --------\n");
        printf("Choose an option:\n");
        printf("1. Add a product\n");
        printf("2. Display all products\n");
        printf("3. Search a product by name\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter product name: ");
                scanf("%s", inventory[count].name);
                printf("Enter quantity: ");
                scanf("%d", &inventory[count].quantity);
                printf("Enter price: ");
                scanf("%f", &inventory[count].price);
                count++;
                printf("\nProduct added successfully!\n\n");
                break;
            case 2:
                if(count == 0) {
                    printf("\nNo products available in inventory!\n\n");
                } else {
                    printf("\n------ Product Inventory ------\n");
                    for(int i = 0; i < count; i++) {
                        printf("Product %d\n", i+1);
                        printf(" Name: %s\n Quantity: %d\n Price: $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
                    }
                }
                break;
            case 3:
                if(count == 0) {
                    printf("\nNo products available in inventory!\n\n");
                } else {
                    printf("\nEnter product name to search: ");
                    scanf("%s", searchName);
                    for(int i = 0; i < count; i++) {
                        if(strcmp(inventory[i].name, searchName) == 0) {
                            printf("\nProduct found!\n Name: %s\n Quantity: %d\n Price: $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0) {
                        printf("\nProduct not found!\n");
                    }
                }
                break;
            case 4:
                printf("\nThank you for using Product Inventory System!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while(choice != 4);
    
    return 0;
}