//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    char name[50];
    int quantity;
    float price;
};

int main() {
    struct Medicine med[100]; // Creating an array of 100 Medicine struct instances
    int choice, count = 0;
    char name[50];
    while(1) {
        printf("\n---- Medical Store Management System ----\n");
        printf("\n1. Add new medicine\n2. View medicine info\n3. Search medicine\n4. Update medicine info\n5. Delete medicine\n6. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter medicine name: ");
                scanf("%s", &med[count].name);
                printf("Enter medicine quantity: ");
                scanf("%d", &med[count].quantity);
                printf("Enter medicine price: ");
                scanf("%f", &med[count].price);
                count++; // Updating the count for the added medicine
                printf("\nMedicine added successfully!");
                break;
            case 2:
                printf("\nTotal medicines added: %d\n\n", count);
                printf("Name\tQuantity\tPrice\n");
                for(int i = 0; i < count; i++) {
                    printf("%s\t%d\t\t%.2f\n", med[i].name, med[i].quantity, med[i].price);
                }
                break;
            case 3:
                printf("\nEnter medicine name to search: ");
                scanf("%s", &name);
                for(int i = 0; i < count; i++) {
                    if(strcmp(med[i].name, name) == 0) {
                        printf("\nMedicine found!\n");
                        printf("Name\tQuantity\tPrice\n");
                        printf("%s\t%d\t\t%.2f\n", med[i].name, med[i].quantity, med[i].price);
                        break;
                    }
                    if(i == count - 1) {
                        printf("\nMedicine not found!");
                    }
                }
                break;
            case 4:
                printf("\nEnter medicine name to update: ");
                scanf("%s", &name);
                for(int i = 0; i < count; i++) {
                    if(strcmp(med[i].name, name) == 0) {
                        printf("\nEnter new quantity: ");
                        scanf("%d", &med[i].quantity);
                        printf("Enter new price: ");
                        scanf("%f", &med[i].price);
                        printf("\nMedicine updated successfully!");
                        break;
                    }
                    if(i == count - 1) {
                        printf("\nMedicine not found!");
                    }
                }
                break;
            case 5:
                printf("\nEnter medicine name to delete: ");
                scanf("%s", &name);
                for(int i = 0; i < count; i++) {
                    if(strcmp(med[i].name, name) == 0) {
                        for(int j = i; j < count - 1; j++) {
                            med[j] = med[j+1]; // Shifting the elements to left
                        }
                        count--; // Updating the count for the deleted medicine
                        printf("\nMedicine deleted successfully!");
                        break;
                    }
                    if(i == count - 1) {
                        printf("\nMedicine not found!");
                    }
                }
                break;
            case 6:
                exit(0); // Exiting the program
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}