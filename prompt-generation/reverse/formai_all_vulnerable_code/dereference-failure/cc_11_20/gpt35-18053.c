//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct medicine {
    char name[100];
    float price;
    int quantity;
} medicine;

int main() {
    int choice, medicineCount = 0;
    medicine *medicines = NULL;
    FILE *fp;
    fp = fopen("medicine.dat", "a+");

    if (fp == NULL) {
        printf("File could not be opened!\n");
        return 1;
    }

    printf("Welcome to the Medical Store Management System!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add medicine\n");
        printf("2. List medicines\n");
        printf("3. Update medicine quantity\n");
        printf("4. Sell medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter medicine name: ");
                char name[100];
                scanf("%s", name);

                printf("Enter medicine price: ");
                float price;
                scanf("%f", &price);

                printf("Enter medicine quantity: ");
                int quantity;
                scanf("%d", &quantity);

                medicineCount++;
                medicines = realloc(medicines, sizeof(medicine) * medicineCount);
                strcpy(medicines[medicineCount - 1].name, name);
                medicines[medicineCount - 1].price = price;
                medicines[medicineCount - 1].quantity = quantity;

                fprintf(fp, "%s %.2f %d\n", name, price, quantity);

                printf("\nMedicine added successfully!\n");
                break;

            case 2:
                printf("\nList of all medicines:\n\n");
                printf("| %-3s | %-30s | %-10s | %-8s |\n", "ID", "NAME", "PRICE", "QUANTITY");
                printf("+----+--------------------------------+------------+----------+\n");

                for (int i = 0; i < medicineCount; i++) {
                    printf("| %-3d | %-30s | %-10.2f | %-8d |\n", i + 1, medicines[i].name, medicines[i].price, medicines[i].quantity);
                }
                break;

            case 3:
                printf("\nEnter the medicine ID: ");
                int id;
                scanf("%d", &id);

                if (id <= 0 || id > medicineCount) {
                    printf("\nInvalid ID!\n");
                    break;
                }

                printf("Enter the new quantity: ");
                scanf("%d", &quantity);

                medicines[id - 1].quantity = quantity;

                fseek(fp, 0, SEEK_SET);

                for (int i = 0; i < medicineCount; i++) {
                    fprintf(fp, "%s %.2f %d\n", medicines[i].name, medicines[i].price, medicines[i].quantity);
                }

                printf("\nQuantity updated successfully!\n");
                break;

            case 4:
                printf("\nEnter the medicine ID: ");
                scanf("%d", &id);

                if (id <= 0 || id > medicineCount) {
                    printf("\nInvalid ID!\n");
                    break;
                }

                printf("Enter the quantity to sell: ");
                scanf("%d", &quantity);

                if (quantity > medicines[id - 1].quantity) {
                    printf("\nInsufficient quantity!\n");
                    break;
                }

                float totalAmount = quantity * medicines[id - 1].price;
                medicines[id - 1].quantity -= quantity;

                fseek(fp, 0, SEEK_SET);

                for (int i = 0; i < medicineCount; i++) {
                    fprintf(fp, "%s %.2f %d\n", medicines[i].name, medicines[i].price, medicines[i].quantity);
                }

                printf("\nMedicine sold successfully!\nTotal amount: %.2f\n", totalAmount);
                break;

            case 5:
                printf("\nThank you for using the Medical Store Management System!\n");
                fclose(fp);
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    }
}