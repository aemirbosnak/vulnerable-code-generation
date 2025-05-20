//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};

int main() {
    int choice, i, n, found = 0;
    char search_name[50];
    float total = 0.0;
    struct medicine med[100];
    
    printf("Welcome to the C Medical Store Management System\n");
    
    while(1) {
        printf("\nChoose an option from the menu:\n1. Add medicine\n2. Update medicine\n3. Delete medicine\n4. Search medicine\n5. Display all medicines\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // adding a new medicine
                printf("\nEnter the number of medicines to add: ");
                scanf("%d", &n);
                
                for(i=0; i<n; i++) {
                    printf("\nEnter the name of medicine %d: ", i+1);
                    scanf("%s", &med[i].name);
                    fflush(stdin);
                    printf("Enter the quantity of medicine %d: ", i+1);
                    scanf("%d", &med[i].quantity);
                    printf("Enter the price of medicine %d: ", i+1);
                    scanf("%f", &med[i].price);
                }
                
                printf("\n%d medicine(s) added successfully!\n", n);
                break;
                
            case 2: // updating an existing medicine
                printf("\nEnter the name of medicine to update: ");
                scanf("%s", &search_name);
                
                found = 0;
                for(i=0; i<n; i++) {
                    if(strcmp(search_name, med[i].name) == 0) {
                        printf("\nEnter the updated quantity and price of medicine %s: ", med[i].name);
                        scanf("%d%f", &med[i].quantity, &med[i].price);
                        found = 1;
                        break;
                    }
                }
                
                if(found == 0) {
                    printf("\nMedicine %s not found!\n", search_name);
                } else {
                    printf("\nMedicine %s updated successfully!\n", med[i].name);
                }
                break;
                
            case 3: // deleting an existing medicine
                printf("\nEnter the name of medicine to delete: ");
                scanf("%s", &search_name);
                
                found = 0;
                for(i=0; i<n; i++) {
                    if(strcmp(search_name, med[i].name) == 0) {
                        strcpy(med[i].name, "");
                        med[i].quantity = 0;
                        med[i].price = 0.0;
                        found = 1;
                        break;
                    }
                }
                
                if(found == 0) {
                    printf("\nMedicine %s not found!\n", search_name);
                } else {
                    printf("\nMedicine %s deleted successfully!\n", search_name);
                }
                break;
                
            case 4: // searching for a medicine
                printf("\nEnter the name of medicine to search: ");
                scanf("%s", &search_name);
                
                found = 0;
                for(i=0; i<n; i++) {
                    if(strcmp(search_name, med[i].name) == 0) {
                        printf("\nMedicine %s found!\n", search_name);
                        printf("Quantity: %d\n", med[i].quantity);
                        printf("Price: Rs. %.2f per unit\n", med[i].price);
                        found = 1;
                        break;
                    }
                }
                
                if(found == 0) {
                    printf("\nMedicine %s not found!\n", search_name);
                }
                break;
                
            case 5: // displaying all medicines
                printf("\nMedicine\tQuantity\tPrice\n");
                for(i=0; i<n; i++) {
                    if(strcmp(med[i].name, "") != 0) {
                        printf("%s\t\t%d\t\tRs. %.2f\n", med[i].name, med[i].quantity, med[i].price);
                        total += med[i].price * med[i].quantity;
                    }
                }
                printf("\nTotal value of stock: Rs. %.2f\n", total);
                break;
                
            case 6:
                exit(0); // terminating the program
                break;
                
            default:
                printf("\nInvalid choice!\n");
        }
    }
    
    return 0;
}