//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRODUCTS 100
#define MAX_CLIENTS 50
#define MAX_ORDERS 500

typedef struct Product {
    char name[20];
    int quantity;
} Product;

typedef struct Client {
    char name[20];
    int id;
    int orderIDs[10];
    int numOrders;
} Client;

typedef struct Order {
    int id;
    int clientID;
    Product products[10];
    int numProducts;
} Order;

Product products[MAX_PRODUCTS];
Client clients[MAX_CLIENTS];
Order orders[MAX_ORDERS];
int numProducts = 0;
int numClients = 0;
int numOrders = 0;

void addProduct(char name[20], int quantity) {
    if (numProducts == MAX_PRODUCTS) {
        printf("Sorry, warehouse is full!\n");
        return;
    }
    Product newProduct;
    strcpy(newProduct.name, name);
    newProduct.quantity = quantity;
    products[numProducts] = newProduct;
    numProducts++;

    printf("New product added: %s\n", name);
}

void addClient(char name[20]) {
    if (numClients == MAX_CLIENTS) {
        printf("Sorry, clients list is full!\n");
        return;
    }
    Client newClient;
    strcpy(newClient.name, name);
    newClient.id = rand() % 1000 + 1;
    clients[numClients] = newClient;
    numClients++;

    printf("New client added: %s with ID: %d\n", name, newClient.id);
}

void placeOrder(int clientID, char productsList[10][20]) {
    if (numOrders == MAX_ORDERS) {
        printf("Sorry, order list is full!\n");
        return;
    }
    Order newOrder;
    newOrder.id = rand() % 10000 + 1;
    newOrder.clientID = clientID;

    for (int i = 0; i < 10; i++) {
        if (productsList[i][0] == '\0')
            break;

        int productFound = 0;
        for (int j = 0; j < numProducts; j++) {
            if (strcmp(productsList[i], products[j].name) == 0) {
                productFound = 1;
                if (products[j].quantity > 0) {
                    products[j].quantity--;
                    newOrder.products[newOrder.numProducts] = products[j];
                    newOrder.numProducts++;
                    break;
                }
                else {
                    printf("Product %s is out of stock!\n", products[j].name);
                    break;
                }
            }
        }
        if (!productFound)
            printf("Product %s does not exist in the warehouse!\n", productsList[i]);
    }

    if (newOrder.numProducts > 0) {
        orders[numOrders] = newOrder;
        numOrders++;
        clients[clientID].orderIDs[clients[clientID].numOrders] = newOrder.id;
        clients[clientID].numOrders++;
        printf("New order placed with ID: %d\n", newOrder.id);
    }
    else {
        printf("No products were ordered!\n");
    }
}

void printClients() {
    printf("--- CLIENTS LIST ---\n");

    for (int i = 0; i < numClients; i++) {
        printf("%s (ID: %d)\n", clients[i].name, clients[i].id);

        if (clients[i].numOrders > 0) {
            printf("Orders:");
            for (int j = 0; j < clients[i].numOrders; j++) {
                printf(" %d", clients[i].orderIDs[j]);
            }
            printf("\n");
        }
        else {
            printf("No orders found for this client.\n");
        }
    }

    printf("--------------------\n");
}

void printOrders() {
    printf("--- ORDERS LIST ---\n");

    for (int i = 0; i < numOrders; i++) {
        printf("Order ID: %d - Client ID: %d\n", orders[i].id, orders[i].clientID);

        for (int j = 0; j < orders[i].numProducts; j++) {
            printf("- %s\n", orders[i].products[j].name);
        }
    }

    printf("-------------------\n");
}

int main() {
    srand(time(0));

    printf("Welcome to the Funny Warehouse Management System!\n");

    while (1) {
        printf("\n");
        printf("Type 'add_product' to add a new product\n");
        printf("Type 'add_client' to add a new client\n");
        printf("Type 'place_order' to place a new order\n");
        printf("Type 'print_clients' to print the clients list\n");
        printf("Type 'print_orders' to print the orders list\n");
        printf("Type 'exit' to exit\n");

        char command[20];
        scanf("%s", command);

        if (strcmp(command, "add_product") == 0) {
            printf("Enter product name: ");
            char name[20];
            scanf("%s", name);
            printf("Enter quantity: ");
            int quantity;
            scanf("%d", &quantity);
            addProduct(name, quantity);
        }
        else if (strcmp(command, "add_client") == 0) {
            printf("Enter client name: ");
            char name[20];
            scanf("%s", name);
            addClient(name);
        }
        else if (strcmp(command, "place_order") == 0) {
            printf("Enter client ID: ");
            int clientID;
            scanf("%d", &clientID);
            printf("Enter products (comma separated): ");
            char productsList[10][20];
            char productsInput[100];
            scanf("%s", productsInput);
            char* product = strtok(productsInput, ",");
            int index = 0;
            while (product != NULL) {
                strcpy(productsList[index], product);
                index++;
                product = strtok(NULL, ",");
            }
            placeOrder(clientID, productsList);
        }
        else if (strcmp(command, "print_clients") == 0) {
            printClients();
        }
        else if (strcmp(command, "print_orders") == 0) {
            printOrders();
        }
        else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Command not recognized, try again.\n");
        }
    }

    return 0;
}