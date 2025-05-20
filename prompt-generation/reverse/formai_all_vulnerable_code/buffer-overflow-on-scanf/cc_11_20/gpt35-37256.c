//FormAI DATASET v1.0 Category: Table Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INGREDIENTS 4
#define MAX_ORDERS 10

typedef struct {
  char name[30];
  int price;
  int ingredients[MAX_INGREDIENTS];
} Pizza;

typedef struct {
  Pizza pizza;
  int quantity;
} Order;

int main() {
  srand(time(NULL));
  
  // Initialize ingredients
  char ingredients[MAX_INGREDIENTS][15] = {
    "cheese",
    "pepperoni",
    "mushrooms",
    "onions"
  };
  
  // Initialize pizzas
  Pizza pizzas[5] = {
    {"Cheese Pizza", 10, {1, 0, 0, 0}},
    {"Pepperoni Pizza", 12, {1, 1, 0, 0}},
    {"Mushroom Pizza", 15, {1, 0, 1, 0}},
    {"Onion Pizza", 13, {1, 0, 0, 1}},
    {"Supreme Pizza", 20, {1, 1, 1, 1}}
  };
  
  // Initialize orders
  Order orders[MAX_ORDERS];
  int num_orders = 0;
  
  // Initialize game variables
  int time_left = 60; // seconds
  int total_pizzas = 0;
  int total_sales = 0;
  
  // Start game loop
  while (time_left > 0) {
    printf("Time left: %d seconds\n", time_left);
    printf("Total pizzas: %d\n", total_pizzas);
    printf("Total sales: $%d\n", total_sales);
    
    // Generate new order
    if (rand() % 3 == 0 && num_orders < MAX_ORDERS) {
      orders[num_orders].quantity = 1 + rand() % 3;
      orders[num_orders].pizza = pizzas[rand() % 5];
      num_orders++;
      printf("New order: %d %s pizza(s) - $%d\n", orders[num_orders-1].quantity, orders[num_orders-1].pizza.name, orders[num_orders-1].quantity * orders[num_orders-1].pizza.price);
    }
    
    // Display menu
    printf("\nMENU:\n");
    for (int i = 0; i < 5; i++) {
      printf("%d. %s - $%d\n", i+1, pizzas[i].name, pizzas[i].price);
    }
    
    // Get player input
    int choice;
    printf("\nEnter your pizza choice (1-5): ");
    scanf("%d", &choice);
    
    // Validate player input
    while (choice < 1 || choice > 5) {
      printf("Invalid choice. Please enter a number between 1 and 5: ");
      scanf("%d", &choice);
    }
    
    // Display ingredients
    printf("\n%s:\n", pizzas[choice-1].name);
    for (int i = 0; i < MAX_INGREDIENTS; i++) {
      if (pizzas[choice-1].ingredients[i]) {
        printf("- %s\n", ingredients[i]);
      }
    }
    
    // Make pizza
    printf("\nMaking %s...\n", pizzas[choice-1].name);
    int pizza_time = 2 + rand() % 5; // seconds
    printf("Estimated time: %d seconds\n", pizza_time);
    int ingredients_used[MAX_INGREDIENTS];
    memcpy(ingredients_used, pizzas[choice-1].ingredients, MAX_INGREDIENTS * sizeof(int));
    total_pizzas++;
    
    // Validate ingredients
    for (int i = 0; i < MAX_INGREDIENTS; i++) {
      int available;
      printf("Enter the quantity of %s required: ", ingredients[i]);
      scanf("%d", &available);
      while (available < 0 || available > 10) {
          printf("Invalid entry! Please enter a number between 0 and 10 ");
          scanf("%d", &available);
      }
      if (available < ingredients_used[i]) {
        printf("You don't have enough %s!\n", ingredients[i]);
        printf("Order cancelled\n");
        total_pizzas--;
        break;
      }
      ingredients_used[i] = available - ingredients_used[i];
    }
    
    // Deliver pizza
    if (total_pizzas > 0) {
      int delivery_time = 1 + rand() % 3; // seconds
      printf("\nDelivery time: %d seconds\n", delivery_time);
      printf("\nOrder complete!\n");
      
      // Calculate sales
      int sales = 0;
      for (int i = 0; i < num_orders; i++) {
        if (memcmp(orders[i].pizza.ingredients, ingredients_used, MAX_INGREDIENTS * sizeof(int)) == 0) {
          total_sales += orders[i].quantity * orders[i].pizza.price;
          sales += orders[i].quantity * orders[i].pizza.price;
          printf("Sold %d %s pizza(s) for $%d\n", orders[i].quantity, orders[i].pizza.name, orders[i].quantity * orders[i].pizza.price);
          for (int j = i; j < num_orders - 1; j++) {
            orders[j] = orders[j+1];
          }
          num_orders--;
          i--;
        }
      }
      printf("Total sales from delivery: $%d\n", sales);
    }
    
    // Decrement time
    time_left--;
  }
  
  // Display final results
  printf("\nGAME OVER!\n");
  printf("Total pizzas made: %d\n", total_pizzas);
  printf("Total sales: $%d\n", total_sales);
  
  return 0;
}