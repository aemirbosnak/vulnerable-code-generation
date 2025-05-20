//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct {
    char name[MAX_SIZE];
    int quantity;
    float price;
} medicine[MAX_SIZE];

int main() {
    int choice, i = 0;
    char ch;

    printf("Welcome to the Medical Store Management System!\n");
    printf("-------------------------------------------------\n");

    while (1) {
        system("clear");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine Details\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter medicine name: ");
            scanf("%s", medicine[i].name);
            printf("Enter quantity: ");
            scanf("%d", &medicine[i].quantity);
            printf("Enter price: ");
            scanf("%f", &medicine[i].price);
            i++;
            printf("Medicine added successfully!\n");
            break;

        case 2:
            printf("List of available medicines:\n");
            for (int j = 0; j < i; j++) {
                printf("%s - %d units - $%.2f\n", medicine[j].name, medicine[j].quantity, medicine[j].price);
            }
            break;

        case 3:
            printf("Enter medicine name to search: ");
            scanf("%s", ch);
            for (int j = 0; j < i; j++) {
                if (strcmp(medicine[j].name, ch) == 0) {
                    printf("%s - %d units - $%.2f\n", medicine[j].name, medicine[j].quantity, medicine[j].price);
                }
            }
            break;

        case 4:
            printf("Enter medicine name to update: ");
            scanf("%s", ch);
            for (int j = 0; j < i; j++) {
                if (strcmp(medicine[j].name, ch) == 0) {
                    printf("Enter new quantity: ");
                    scanf("%d", &medicine[j].quantity);
                    printf("Enter new price: ");
                    scanf("%f", &medicine[j].price);
                    printf("Medicine details updated successfully!\n");
                    break;
                }
            }
            break;

        case 5:
            printf("Enter medicine name to delete: ");
            scanf("%s", ch);
            for (int j = 0; j < i; j++) {
                if (strcmp(medicine[j].name, ch) == 0) {
                    for (int k = j; k < i - 1; k++) {
                        medicine[k] = medicine[k + 1];
                    }
                    i--;
                    printf("Medicine deleted successfully!\n");
                    break;
                }
            }
            break;

        case 6:
            printf("Thank you for using the Medical Store Management System!\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}