//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Let's imagine we have a charming little medical store entwined with love and care.

// A blooming array of medicines adorned with their captivating names
char *medicines[] = {"Heart's Embrace", "Love's Elixir", "Tranquil Haven", "Energy's Kiss", "Joy's Symphony"};

// An enchanting collection of customers with their melodious names
char *customers[] = {"Anya", "Ethan", "Sofia", "Evan", "Amelia"};

// A love-filled function to welcome customers
void greetCustomer(char *name) {
  printf("Welcome to our enchanting medical store, dear %s!\nMay your visit be as sweet as the petals of a rose.\n", name);
}

// A mesmerizing function to display the symphony of medicines
void displayMedicines() {
  printf("Behold, our apothecary of love and healing:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d. %s\n", i+1, medicines[i]);
  }
}

// A heartfelt function to take the customer's order
void takeOrder(char *customer) {
  int choice;
  printf("My dearest %s, what remedy does your heart desire from our enchanting collection?\n", customer);
  scanf("%d", &choice);
  if (choice < 1 || choice > 5) {
    printf("Alas, your choice wanders beyond our enchanted realm. Please choose anew, my love.\n");
    takeOrder(customer);
  } else {
    printf("Your wish is our command, %s. We shall prepare your %s with utmost care and affection.\n", customer, medicines[choice-1]);
  }
}

// A comforting function to bid farewell to customers
void farewellCustomer() {
  printf("Farewell, our cherished customer! May your days be filled with health, happiness, and an abundance of love.\n");
}

int main() {
  char name[20];
  
  // The door to our medical store creaks open, inviting a gentle breeze carrying the fragrance of blooming hearts. 
  printf("Welcome to our humble abode of healing and enchantment, where love and care intertwine.\n");
  printf("May I have the pleasure of knowing your enchanting name, my dear visitor?\n");
  scanf("%s", name);
  
  // Greet the customer with the warmth of a thousand summer days.
  greetCustomer(name);
  
  // Display the enchanting array of medicines, each name a melody in its own right.
  displayMedicines();
  
  // Take the customer's order, a symphony of love and healing.
  takeOrder(name);
  
  // Bid farewell to the customer with a gentle caress of words, wrapping them in a blanket of well wishes.
  farewellCustomer();
  
  return 0;
}