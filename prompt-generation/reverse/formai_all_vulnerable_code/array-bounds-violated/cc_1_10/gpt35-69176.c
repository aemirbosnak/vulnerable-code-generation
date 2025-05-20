//FormAI DATASET v1.0 Category: Product Inventory System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200
#define MAX_CATEGORY_LENGTH 20
#define MAX_PRICE_LENGTH 10

// Define a struct for our inventory item
typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float price;
    int quantity;
} inventory_item;

// Declare our inventory array
inventory_item inventory[MAX_PRODUCTS];

// Declare function prototypes
void add_product();
void list_products();
void search_products();

int main() {
    int option;

    // Begin by clearing our inventory array
    memset(inventory, 0, sizeof(inventory));

    // Show the options menu to the user
    do {
        printf("\nPlease enter an option:\n\n");
        printf("1. Add Product\n");
        printf("2. List Products\n");
        printf("3. Search Products\n");
        printf("4. Exit\n\n");
        printf("> ");
        scanf("%d", &option);
        fflush(stdin);

        switch (option) {
            case 1: add_product(); break;
            case 2: list_products(); break;
            case 3: search_products(); break;
            case 4: printf("\nGoodbye!\n"); break;
            default: printf("Invalid option.\n"); break;
        }
    } while (option != 4);

    return 0;
}

void add_product() {
    // Find the first free slot in the inventory
    int empty_slot_index = -1;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strlen(inventory[i].name) == 0) {
            empty_slot_index = i;
            break;
        }
    }

    if (empty_slot_index == -1) {
        printf("\nError: Inventory is full.\n");
        return;
    }

    // Get the product details from the user
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    char price_string[MAX_PRICE_LENGTH];
    float price;

    printf("\nPlease enter the product name:\n> ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strlen(name)-1] = '\0';

    printf("\nPlease enter the product description:\n> ");
    fgets(description, MAX_DESCRIPTION_LENGTH, stdin);
    description[strlen(description)-1] = '\0';

    printf("\nPlease enter the product category:\n> ");
    fgets(category, MAX_CATEGORY_LENGTH, stdin);
    category[strlen(category)-1] = '\0';

    printf("\nPlease enter the product price:\n> ");
    fgets(price_string, MAX_PRICE_LENGTH, stdin);
    price = atof(price_string);

    inventory[empty_slot_index].quantity = 1;

    // Add the product to the inventory
    strcpy(inventory[empty_slot_index].name, name);
    strcpy(inventory[empty_slot_index].description, description);
    strcpy(inventory[empty_slot_index].category, category);
    inventory[empty_slot_index].price = price;

    printf("\nProduct added successfully!\n");
}

void list_products() {
    // Print the header row
    printf("\n+-------+--------------------------------------------------+--------------------+--------+----------+\n");
    printf("| Index | Name                                             | Description        | Price  | Quantity |\n");
    printf("+-------+--------------------------------------------------+--------------------+--------+----------+\n");

    // Print each product in the inventory
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strlen(inventory[i].name) > 0) {
            char index_string[3];
            sprintf(index_string, "%d", i);

            char price_string[MAX_PRICE_LENGTH];
            sprintf(price_string, "%0.2f", inventory[i].price);

            char quantity_string[3];
            sprintf(quantity_string, "%d", inventory[i].quantity);

            printf("| %-5s | %-48s | %-18s | $%5s | %-8s |\n", index_string, inventory[i].name, inventory[i].description, price_string, quantity_string);
        }
    }

    printf("+-------+--------------------------------------------------+--------------------+--------+----------+\n");
}

void search_products() {
    // Get the search term from the user
    char search_term[MAX_NAME_LENGTH];
    printf("\nEnter a search term:\n> ");
    fgets(search_term, MAX_NAME_LENGTH, stdin);
    search_term[strlen(search_term)-1] = '\0';

    // Print the header row
    printf("\n+-------+--------------------------------------------------+--------------------+--------+----------+\n");
    printf("| Index | Name                                             | Description        | Price  | Quantity |\n");
    printf("+-------+--------------------------------------------------+--------------------+--------+----------+\n");

    // Print each product in the inventory that matches the search term
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strlen(inventory[i].name) > 0 && strstr(inventory[i].name, search_term) != NULL) {
            char index_string[3];
            sprintf(index_string, "%d", i);

            char price_string[MAX_PRICE_LENGTH];
            sprintf(price_string, "%0.2f", inventory[i].price);

            char quantity_string[3];
            sprintf(quantity_string, "%d", inventory[i].quantity);

            printf("| %-5s | %-48s | %-18s | $%5s | %-8s |\n", index_string, inventory[i].name, inventory[i].description, price_string, quantity_string);
        }
    }

    printf("+-------+--------------------------------------------------+--------------------+--------+----------+\n");
}