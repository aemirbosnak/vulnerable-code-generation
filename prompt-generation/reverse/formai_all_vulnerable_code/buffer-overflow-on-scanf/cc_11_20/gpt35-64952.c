//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure to hold medicine details
struct Medicine {
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
};

int main() {
    struct Medicine med[100];
    int count=0, choice, i, index;
    char searchName[50];
    float totalPrice=0;
    
    //infinite loop until user manually exits
    while(1) {
        printf("\n\nWelcome to the Medical Store Management System!\n");
        printf("--------------------------------------------------\n");
        printf("Enter 1 to add medicine details\n");
        printf("Enter 2 to update medicine details\n");
        printf("Enter 3 to view medicine details\n");
        printf("Enter 4 to search for a medicine\n");
        printf("Enter 5 to calculate total sales\n");
        printf("Enter 6 to exit\n");
        printf("Enter your choice: ");
        
        //reading user's choice
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: //add medicine details
                printf("\nEnter medicine name: ");
                scanf("%s", &med[count].name);
                printf("Enter manufacturer name: ");
                scanf("%s", &med[count].manufacturer);
                printf("Enter quantity: ");
                scanf("%d", &med[count].quantity);
                printf("Enter price: ");
                scanf("%f", &med[count].price);
                
                printf("\nMedicine details added successfully!\n\n");
                count++; //incrementing count variable to keep track of number of medicines added
                break;
            
            case 2: //update medicine details
                printf("\nEnter index of medicine to update: ");
                scanf("%d", &index);
                
                printf("\nEnter medicine name: ");
                scanf("%s", &med[index].name);
                printf("Enter manufacturer name: ");
                scanf("%s", &med[index].manufacturer);
                printf("Enter quantity: ");
                scanf("%d", &med[index].quantity);
                printf("Enter price: ");
                scanf("%f", &med[index].price);
                
                printf("\nMedicine details updated successfully!\n\n");
                break;
            
            case 3: //view medicine details
                printf("\nIndex\tName\tManufacturer\tQuantity\tPrice\n");
                printf("--------------------------------------------------\n");
                for(i=0; i<count; i++) {
                    printf("%d\t%s\t%s\t\t\t%d\t\t$%.2f\n", i, med[i].name, med[i].manufacturer, med[i].quantity, med[i].price);
                }
                break;
            
            case 4: //search for a medicine
                printf("\nEnter medicine name to search: ");
                scanf("%s", &searchName);
                
                for(i=0; i<count; i++) {
                    if(strcmp(med[i].name, searchName) == 0) {
                        printf("\nName\tManufacturer\tQuantity\tPrice\n");
                        printf("------------------------------------------\n");
                        printf("%s\t%s\t\t%d\t\t$%.2f\n", med[i].name, med[i].manufacturer, med[i].quantity, med[i].price);
                        break;
                    }
                }
                
                if(i == count) {
                    printf("\nMedicine not found!\n\n");
                }
                break;
            
            case 5: //calculate total sales
                for(i=0; i<count; i++) {
                    totalPrice += (med[i].quantity * med[i].price);
                }
                
                printf("\nTotal sales: $%.2f\n\n", totalPrice);
                break;
            
            case 6: //exit
                printf("\nThank you for using the Medical Store Management System!\n");
                exit(0);
            
            default:
                printf("\nInvalid choice!\n\n");
        }
    }
    
    return 0;
}