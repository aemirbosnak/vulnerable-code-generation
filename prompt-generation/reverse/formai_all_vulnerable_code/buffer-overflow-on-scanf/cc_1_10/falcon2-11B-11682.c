//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: random
#include <stdio.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    char category[50];
};

int main() {
    struct medicine medicines[10]; // Array to store medicine details
    
    int num_medicines = sizeof(medicines) / sizeof(medicines[0]);
    int num_elements, i, choice;
    
    printf("Medical Store Management System\n\n");
    printf("1. Add medicine details\n");
    printf("2. Remove medicine details\n");
    printf("3. Display medicine details\n");
    printf("4. Display total stock\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    while (choice!= 5) {
        switch (choice) {
            case 1: // Add medicine details
                printf("Enter medicine name: ");
                scanf("%s", medicines[num_elements].name);
                printf("Enter medicine category: ");
                scanf("%s", medicines[num_elements].category);
                printf("Enter medicine quantity: ");
                scanf("%d", &medicines[num_elements].quantity);
                num_elements++;
                printf("Medicine added successfully.\n");
                break;
                
            case 2: // Remove medicine details
                printf("Enter medicine name to remove: ");
                scanf("%s", medicines[num_elements].name);
                for (i = 0; i < num_elements; i++) {
                    if (strcmp(medicines[i].name, medicines[num_elements].name) == 0) {
                        strcpy(medicines[i].name, "");
                        medicines[i].quantity = 0;
                        num_elements--;
                        printf("Medicine removed successfully.\n");
                        break;
                    }
                }
                break;
                
            case 3: // Display medicine details
                printf("Medicine Details:\n");
                for (i = 0; i < num_elements; i++) {
                    printf("Name: %s, Category: %s, Quantity: %d\n", medicines[i].name, medicines[i].category, medicines[i].quantity);
                }
                break;
                
            case 4: // Display total stock
                printf("Total stock of each medicine category:\n");
                for (i = 0; i < num_elements; i++) {
                    printf("%s: %d\n", medicines[i].category, medicines[i].quantity);
                }
                break;
                
            default: // Invalid choice
                printf("Invalid choice.\n");
        }
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }
    
    return 0;
}