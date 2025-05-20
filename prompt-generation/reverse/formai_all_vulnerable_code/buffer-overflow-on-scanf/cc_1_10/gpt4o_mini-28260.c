//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_USERS 10

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

typedef struct {
    char username[MAX_NAME_LENGTH];
    Product products[MAX_PRODUCTS];
    int product_count;
} User;

User users[MAX_USERS];
int user_count = 0;

void addUser(char *username) {
    if (user_count < MAX_USERS) {
        strncpy(users[user_count].username, username, MAX_NAME_LENGTH);
        users[user_count].product_count = 0;
        user_count++;
        printf("User %s added successfully!\n", username);
    } else {
        printf("User limit reached! Cannot add more users.\n");
    }
}

void addProduct(User *user, char *name, int quantity) {
    if (user->product_count < MAX_PRODUCTS) {
        Product new_product;
        new_product.id = user->product_count + 1;
        strncpy(new_product.name, name, MAX_NAME_LENGTH);
        new_product.quantity = quantity;
        user->products[user->product_count] = new_product;
        user->product_count++;
        printf("Product %s added with quantity %d.\n", name, quantity);
    } else {
        printf("Product limit reached for user %s! Cannot add more products.\n", user->username);
    }
}

void viewProducts(User *user) {
    printf("Products for user %s:\n", user->username);
    for (int i = 0; i < user->product_count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", user->products[i].id, user->products[i].name, user->products[i].quantity);
    }
}

User* selectUser(char *username) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return &users[i];
        }
    }
    return NULL;
}

void printMenu() {
    printf("\n-- Product Inventory System --\n");
    printf("1. Add User\n");
    printf("2. Select User\n");
    printf("3. Add Product\n");
    printf("4. View Products\n");
    printf("5. Exit\n");
    printf("------------------------------\n");
}

int main() {
    char username[MAX_NAME_LENGTH];
    User *current_user = NULL;
    int choice;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username to add: ");
                scanf("%s", username);
                addUser(username);
                break;

            case 2:
                printf("Enter username to select: ");
                scanf("%s", username);
                current_user = selectUser(username);
                if (current_user != NULL) {
                    printf("User %s selected.\n", current_user->username);
                } else {
                    printf("User %s not found!\n", username);
                }
                break;

            case 3:
                if (current_user != NULL) {
                    char product_name[MAX_NAME_LENGTH];
                    int quantity;
                    printf("Enter product name: ");
                    scanf("%s", product_name);
                    printf("Enter product quantity: ");
                    scanf("%d", &quantity);
                    addProduct(current_user, product_name, quantity);
                } else {
                    printf("No user selected! Please select a user first.\n");
                }
                break;

            case 4:
                if (current_user != NULL) {
                    viewProducts(current_user);
                } else {
                    printf("No user selected! Please select a user first.\n");
                }
                break;

            case 5:
                printf("Exiting the system.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}