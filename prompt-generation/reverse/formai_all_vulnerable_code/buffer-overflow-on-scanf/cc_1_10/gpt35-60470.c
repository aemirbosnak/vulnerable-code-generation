//FormAI DATASET v1.0 Category: Product Inventory System ; Style: invasive
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int code;
    char name[50];
    float price;
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    Product p;
    printf("\nEnter product code: ");
    scanf("%d", &p.code);
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    products[num_products++] = p;
    printf("\nProduct added successfully.\n");
}

void view_product() {
    int code, i;
    printf("\nEnter product code: ");
    scanf("%d", &code);
    for (i = 0; i < num_products; i++) {
        if (products[i].code == code) {
            printf("Name: %s\n", products[i].name);
            printf("Price: %.2f\n", products[i].price);
            printf("Quantity: %d\n", products[i].quantity);
            return;
        }
    }
    printf("\nSorry, product not found.\n");
}

void update_product() {
    int code, i;
    printf("\nEnter product code: ");
    scanf("%d", &code);
    for (i = 0; i < num_products; i++) {
        if (products[i].code == code) {
            printf("Enter new product name (or '-' to skip): ");
            scanf("%s", products[i].name);
            printf("Enter new product price (or -1 to skip): ");
            scanf("%f", &products[i].price);
            printf("Enter new product quantity (or -1 to skip): ");
            scanf("%d", &products[i].quantity);
            printf("\nProduct updated successfully.\n");
            return;
        }
    }
    printf("\nSorry, product not found.\n");
}

void delete_product() {
    int code, i, j;
    printf("\nEnter product code: ");
    scanf("%d", &code);
    for (i = 0; i < num_products; i++) {
        if (products[i].code == code) {
            for (j = i; j < num_products - 1; j++) {
                products[j] = products[j+1];
            }
            num_products--;
            printf("\nProduct deleted successfully.\n");
            return;
        }
    }
    printf("\nSorry, product not found.\n");
}

void list_products() {
    int i;
    printf("\nProduct list:\n");
    for (i = 0; i < num_products; i++) {
        printf("%d. %s (Code: %d) (Price: %.2f) (Quantity: %d)\n", i+1, products[i].name, products[i].code, products[i].price, products[i].quantity);
    }
}

void search_product() {
    char name[50], *found = NULL;
    int i;
    printf("\nEnter product name: ");
    scanf("%s", name);
    printf("\nSearch results:\n");
    for (i = 0; i < num_products; i++) {
        found = strstr(products[i].name, name);
        if (found != NULL) {
            printf("%d. %s (Code: %d) (Price: %.2f) (Quantity: %d)\n", i+1, products[i].name, products[i].code, products[i].price, products[i].quantity);
        }
    }
}

void save_products() {
    FILE *fp;
    int i;
    fp = fopen("products.dat", "wb");
    if (fp == NULL) {
        printf("\nUnable to open file for writing.\n");
        return;
    }
    for (i = 0; i < num_products; i++) {
        fwrite(&products[i], sizeof(Product), 1, fp);
    }
    fclose(fp);
    printf("\nProducts saved to file successfully.\n");
}

void load_products() {
    FILE *fp;
    Product p;
    fp = fopen("products.dat", "rb");
    if (fp == NULL) {
        printf("\nUnable to open file for reading.\n");
        return;
    }
    num_products = 0;
    while (fread(&p, sizeof(Product), 1, fp)) {
        products[num_products++] = p;
    }
    fclose(fp);
    printf("\nProducts loaded from file successfully.\n");
}

int main() {
    int choice = 0;
    printf("Welcome to the Product Inventory System.\n");
    while (choice != 9) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a product\n");
        printf("2. View a product\n");
        printf("3. Update a product\n");
        printf("4. Delete a product\n");
        printf("5. List all products\n");
        printf("6. Search products\n");
        printf("7. Save products to file\n");
        printf("8. Load products from file\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_product(); break;
            case 2: view_product(); break;
            case 3: update_product(); break;
            case 4: delete_product(); break;
            case 5: list_products(); break;
            case 6: search_product(); break;
            case 7: save_products(); break;
            case 8: load_products(); break;
            case 9: printf("\nGoodbye.\n"); break;
            default: printf("\nInvalid choice.\n"); break;
        }
    }
    return 0;
}