//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct medicine {
    char name[100];
    float price;
};

struct medicine medicines[10];

int main() {
    printf("Welcome to the Medical Store Management System\n");
    printf("1. Add a new medicine\n");
    printf("2. Remove a medicine\n");
    printf("3. View all medicines\n");
    printf("4. Modify the price of a medicine\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    while (choice!= 5) {
        switch (choice) {
            case 1:
                printf("Enter the name and price of the medicine: ");
                scanf("%s%f", medicines[choice].name, &medicines[choice].price);
                break;
            case 2:
                printf("Enter the name of the medicine to remove: ");
                scanf("%s", medicines[choice].name);
                for (int i = 0; i < 10; i++) {
                    if (strcmp(medicines[i].name, medicines[choice].name) == 0) {
                        for (int j = i; j < 10; j++) {
                            medicines[j] = medicines[j+1];
                        }
                        break;
                    }
                }
                break;
            case 3:
                printf("All medicines:\n");
                for (int i = 0; i < 10; i++) {
                    printf("%s - %.2f\n", medicines[i].name, medicines[i].price);
                }
                break;
            case 4:
                printf("Enter the name of the medicine to modify: ");
                scanf("%s", medicines[choice].name);
                printf("Enter the new price: ");
                scanf("%f", &medicines[choice].price);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    return 0;
}