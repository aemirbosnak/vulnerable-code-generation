//FormAI DATASET v1.0 Category: Database querying ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} product;

void insert_product(product new_product) {
    FILE *fp;
    fp = fopen("products.dat", "ab");
    fwrite(&new_product, sizeof(product), 1, fp);
    fclose(fp);
}

void print_product(product p) {
    printf("Product ID: %d\nProduct Name: %s\nProduct Price: %.2f\nProduct Quantity: %d\n", p.id, p.name, p.price, p.quantity);
}

void search_product(int id) {
    FILE *fp;
    product p;
    int found = 0;
    fp = fopen("products.dat", "rb");
    while (fread(&p, sizeof(product), 1, fp)) {
        if (p.id == id) {
            print_product(p);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void update_product(int id, char field[], char new_value[]) {
    FILE *fp;
    product p;
    int found = 0;
    fp = fopen("products.dat", "r+b");
    while (fread(&p, sizeof(product), 1, fp)) {
        if (p.id == id) {
            if (strcmp(field, "name") == 0) {
                strcpy(p.name, new_value);
            } else if (strcmp(field, "price") == 0) {
                p.price = atof(new_value);
            } else if (strcmp(field, "quantity") == 0) {
                p.quantity = atoi(new_value);
            } else {
                printf("Invalid field name.\n");
                return;
            }
            fseek(fp, -sizeof(product), SEEK_CUR);
            fwrite(&p, sizeof(product), 1, fp);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void delete_product(int id) {
    FILE *fp, *temp;
    product p;
    int found = 0;
    fp = fopen("products.dat", "rb");
    temp = fopen("temp.dat", "wb");
    while (fread(&p, sizeof(product), 1, fp)) {
        if (p.id != id) {
            fwrite(&p, sizeof(product), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    if (found) {
        remove("products.dat");
        rename("temp.dat", "products.dat");
        printf("Product with ID %d deleted successfully.\n", id);
    } else {
        remove("temp.dat");
        printf("Product with ID %d not found.\n", id);
    }
}

void print_all_products() {
    FILE *fp;
    product p;
    fp = fopen("products.dat", "rb");
    while (fread(&p, sizeof(product), 1, fp)) {
        print_product(p);
        printf("\n");
    }
    fclose(fp);
}

int main() {
    product new_product;
    char option;
    int id;
    printf("Welcome to the Product Database Querying Example!\n");
    while (1) {
        printf("\n");
        printf("Select an option:\n");
        printf("a. Insert a product\n");
        printf("b. Search for a product by ID\n");
        printf("c. Update a product by ID and field\n");
        printf("d. Delete a product by ID\n");
        printf("e. Print all products\n");
        printf("f. Quit\n");
        printf("\n");
        scanf(" %c", &option);
        switch (option) {
            case 'a':
                printf("Enter product ID:\n");
                scanf("%d", &new_product.id);
                printf("Enter product name:\n");
                scanf("%s", new_product.name);
                printf("Enter product price:\n");
                scanf("%f", &new_product.price);
                printf("Enter product quantity:\n");
                scanf("%d", &new_product.quantity);
                insert_product(new_product);
                printf("Product inserted successfully!\n");
                break;
            case 'b':
                printf("Enter product ID to search:\n");
                scanf("%d", &id);
                search_product(id);
                break;
            case 'c':
                printf("Enter product ID to update:\n");
                scanf("%d", &id);
                printf("Enter field to update (name, price, or quantity):\n");
                char field[20];
                scanf("%s", field);
                printf("Enter new value:\n");
                char new_value[20];
                scanf("%s", new_value);
                update_product(id, field, new_value);
                break;
            case 'd':
                printf("Enter product ID to delete:\n");
                scanf("%d", &id);
                delete_product(id);
                break;
            case 'e':
                print_all_products();
                break;
            case 'f':
                printf("Quitting program.\n");
                exit(0);
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }
    return 0;
}