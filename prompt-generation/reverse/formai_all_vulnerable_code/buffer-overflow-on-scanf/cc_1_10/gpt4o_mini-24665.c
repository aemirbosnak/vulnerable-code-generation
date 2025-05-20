//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: real-life
#include <stdio.h>

// Struct to represent a fruit basket
typedef struct {
    char name[20];
    int quantity;
    float price_per_unit;
} FruitBasket;

// Function to calculate the total price of fruits in the basket
float calculate_total_price(FruitBasket basket[], int num_fruits) {
    float total = 0.0;
    for (int i = 0; i < num_fruits; i++) {
        total += basket[i].quantity * basket[i].price_per_unit;
    }
    return total;
}

// Function to display the details of the fruit basket
void display_basket(FruitBasket basket[], int num_fruits) {
    printf("Fruit Basket Details:\n");
    printf("%-20s %-10s %-15s %-10s\n", "Fruit Name", "Quantity", "Price/Unit", "Total Price");
    float total_price = 0.0;
    
    for (int i = 0; i < num_fruits; i++) {
        float item_total = basket[i].quantity * basket[i].price_per_unit;
        printf("%-20s %-10d $%-14.2f $%-10.2f\n", basket[i].name, basket[i].quantity, basket[i].price_per_unit, item_total);
        total_price += item_total;
    }

    printf("---------------------------------------------------------\n");
    printf("Total Price of the Basket: $%.2f\n", total_price);
}

// Function to add fruit to the basket
void add_fruit(FruitBasket basket[], int *num_fruits, char name[], int quantity, float price_per_unit) {
    if (*num_fruits < 100) {
        strcpy(basket[*num_fruits].name, name);
        basket[*num_fruits].quantity = quantity;
        basket[*num_fruits].price_per_unit = price_per_unit;
        (*num_fruits)++;
    } else {
        printf("Basket is full! Cannot add more fruits.\n");
    }
}

// Main Function
int main() {
    FruitBasket basket[100]; // Maximum of 100 different fruits
    int num_fruits = 0;      // To keep track of the number of different fruits in the basket
    
    // Add some fruits to the basket
    add_fruit(basket, &num_fruits, "Apples", 5, 0.50);
    add_fruit(basket, &num_fruits, "Oranges", 3, 0.75);
    add_fruit(basket, &num_fruits, "Bananas", 10, 0.30);
    add_fruit(basket, &num_fruits, "Berries", 20, 0.10);
    
    // Display the fruit basket with total price
    display_basket(basket, num_fruits);
    
    // Assume a discount is given if total price exceeds $10
    float total_price = calculate_total_price(basket, num_fruits);
    float discount = 0.0;
    
    if (total_price > 10.0) {
        discount = total_price * 0.1; // 10% discount
        printf("Applying a discount of $%.2f on the total price.\n", discount);
    } else {
        printf("No discount applied.\n");
    }

    float final_price = total_price - discount;
    printf("Final Price after discount (if any): $%.2f\n", final_price);
    
    // Simulate checkout by asking user if they would like to continue shopping or checkout
    char choice;
    printf("Would you like to checkout? (y/n): ");
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y') {
        printf("Thank you for shopping with us!\n");
    } else {
        printf("Feel free to continue shopping!\n");
    }
    
    return 0;
}