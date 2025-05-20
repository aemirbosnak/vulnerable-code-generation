//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: modular
// Modular Medical Store Management System Example Program

  // Header Files
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdbool.h>

  // Structures
  typedef struct {
    int id;
    char name[50];
    char address[100];
    char phone[15];
    float balance;
  } Customer;

  typedef struct {
    int id;
    char name[50];
    char description[200];
    float price;
    int quantity;
  } Product;

  typedef struct {
    int id;
    int customer_id;
    int product_id;
    int quantity;
    float total_price;
  } Order;

  // Function Declarations
  void display_menu();
  void create_customer();
  void display_customer();
  void create_product();
  void display_product();
  void place_order();
  void display_order();

  // Main Function
  int main() {
    display_menu();
    return 0;
  }

  // Function Definitions
  void display_menu() {
    printf("Welcome to the Medical Store Management System\n");
    printf("1. Create a new customer\n");
    printf("2. Display customer information\n");
    printf("3. Create a new product\n");
    printf("4. Display product information\n");
    printf("5. Place an order\n");
    printf("6. Display order information\n");
    printf("7. Exit\n");
    int choice = 0;
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        create_customer();
        break;
      case 2:
        display_customer();
        break;
      case 3:
        create_product();
        break;
      case 4:
        display_product();
        break;
      case 5:
        place_order();
        break;
      case 6:
        display_order();
        break;
      case 7:
        return;
      default:
        printf("Invalid choice. Please try again.");
    }
  }

  void create_customer() {
    Customer customer;
    printf("Enter customer ID: ");
    scanf("%d", &customer.id);
    printf("Enter customer name: ");
    scanf("%s", customer.name);
    printf("Enter customer address: ");
    scanf("%s", customer.address);
    printf("Enter customer phone number: ");
    scanf("%s", customer.phone);
    printf("Enter customer balance: ");
    scanf("%f", &customer.balance);
    printf("Customer added successfully!\n");
  }

  void display_customer() {
    Customer customer;
    printf("Enter customer ID: ");
    scanf("%d", &customer.id);
    printf("Customer name: %s\n", customer.name);
    printf("Customer address: %s\n", customer.address);
    printf("Customer phone number: %s\n", customer.phone);
    printf("Customer balance: %f\n", customer.balance);
  }

  void create_product() {
    Product product;
    printf("Enter product ID: ");
    scanf("%d", &product.id);
    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter product description: ");
    scanf("%s", product.description);
    printf("Enter product price: ");
    scanf("%f", &product.price);
    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);
    printf("Product added successfully!\n");
  }

  void display_product() {
    Product product;
    printf("Enter product ID: ");
    scanf("%d", &product.id);
    printf("Product name: %s\n", product.name);
    printf("Product description: %s\n", product.description);
    printf("Product price: %f\n", product.price);
    printf("Product quantity: %d\n", product.quantity);
  }

  void place_order() {
    Order order;
    printf("Enter order ID: ");
    scanf("%d", &order.id);
    printf("Enter customer ID: ");
    scanf("%d", &order.customer_id);
    printf("Enter product ID: ");
    scanf("%d", &order.product_id);
    printf("Enter quantity: ");
    scanf("%d", &order.quantity);
    printf("Enter total price: ");
    scanf("%f", &order.total_price);
    printf("Order placed successfully!\n");
  }

  void display_order() {
    Order order;
    printf("Enter order ID: ");
    scanf("%d", &order.id);
    printf("Customer ID: %d\n", order.customer_id);
    printf("Product ID: %d\n", order.product_id);
    printf("Quantity: %d\n", order.quantity);
    printf("Total price: %f\n", order.total_price);
  }