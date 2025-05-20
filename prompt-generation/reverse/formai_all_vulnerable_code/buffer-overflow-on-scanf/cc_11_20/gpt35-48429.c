//FormAI DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char type[50];
    int quantity;
} product;

int main() {
    int choice;
    product p;
    FILE *fp;

    while (1) {
        printf("\n*****Welcome to the product database simulator!*****\n");
        printf("1. Add a product\n");
        printf("2. Search for a product\n");
        printf("3. Update a product\n");
        printf("4. Delete a product\n");
        printf("5. Display all products\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fp = fopen("products.bin", "ab");
                printf("Enter product id: ");
                scanf("%d", &p.id);
                printf("Enter product name: ");
                scanf("%s", p.name);
                printf("Enter product type: ");
                scanf("%s", p.type);
                printf("Enter product quantity: ");
                scanf("%d", &p.quantity);
                fwrite(&p, sizeof(product), 1, fp);
                fclose(fp);
                printf("Product added successfully!\n");
                break;
            case 2:
                fp = fopen("products.bin", "rb");
                int searchId;
                printf("Enter product id to search: ");
                scanf("%d", &searchId);
                while (fread(&p, sizeof(product), 1, fp)) {
                    if (p.id == searchId) {
                        printf("\nProduct found!\n");
                        printf("Product id: %d\n", p.id);
                        printf("Product name: %s\n", p.name);
                        printf("Product type: %s\n", p.type);
                        printf("Product quantity: %d\n", p.quantity);
                        break;
                    }
                }
                if (feof(fp)) {
                    printf("\nProduct not found!\n");
                }
                fclose(fp);
                break;
            case 3:
                fp = fopen("products.bin", "rb+");
                int updateId;
                printf("Enter product id to update: ");
                scanf("%d", &updateId);
                while (fread(&p, sizeof(product), 1, fp)) {
                    if (p.id == updateId) {
                        printf("\nProduct found!\n");
                        printf("Enter updated product name: ");
                        scanf("%s", p.name);
                        printf("Enter updated product type: ");
                        scanf("%s", p.type);
                        printf("Enter updated product quantity: ");
                        scanf("%d", &p.quantity);
                        fseek(fp, -sizeof(product), SEEK_CUR);
                        fwrite(&p, sizeof(product), 1, fp);
                        printf("\nProduct updated successfully!\n");
                        break;
                    }
                }
                if (feof(fp)) {
                    printf("\nProduct not found!\n");
                }
                fclose(fp);
                break;
            case 4:
                fp = fopen("products.bin", "rb");
                FILE *temp;
                temp = fopen("temp.bin", "wb");
                int deleteId;
                printf("Enter product id to delete: ");
                scanf("%d", &deleteId);
                while (fread(&p, sizeof(product), 1, fp)) {
                    if (p.id != deleteId) {
                        fwrite(&p, sizeof(product), 1, temp);
                    }
                }
                fclose(fp);
                fclose(temp);
                remove("products.bin");
                rename("temp.bin", "products.bin");
                printf("\nProduct deleted successfully!\n");
                break;
            case 5:
                fp = fopen("products.bin", "rb");
                while (fread(&p, sizeof(product), 1, fp)) {
                    printf("\nProduct id: %d\n", p.id);
                    printf("Product name: %s\n", p.name);
                    printf("Product type: %s\n", p.type);
                    printf("Product quantity: %d\n", p.quantity);
                }
                fclose(fp);
                break;
            case 6:
                printf("Thank you for using the product database simulator!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}