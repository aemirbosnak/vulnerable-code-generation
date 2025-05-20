//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>

int main() {
  // Initialize variables
  int coinCount;
  int totalValue;
  char currentCoin;
  char previousCoin;
  
  // Prompt the user to enter the number of coins
  printf("Enter the number of coins: ");
  scanf("%d", &coinCount);
  
  // Loop through each coin and calculate the total value
  for (int i = 0; i < coinCount; i++) {
    // Prompt the user to enter the type of coin
    printf("Enter the type of coin (C for copper, S for silver, G for gold): ");
    scanf(" %c", &currentCoin);
    
    // Check if the user entered a valid coin type
    if (currentCoin!= 'C' && currentCoin!= 'S' && currentCoin!= 'G') {
      printf("Invalid coin type. Please try again.\n");
      i--; // Move back to the previous coin type
      continue; // Loop back to the coin prompt
    }
    
    // Prompt the user to enter the value of the coin
    printf("Enter the value of the coin: ");
    scanf("%d", &totalValue);
    
    // Check if the user entered a valid coin value
    if (totalValue <= 0) {
      printf("Invalid coin value. Please try again.\n");
      i--; // Move back to the previous coin value
      continue; // Loop back to the coin prompt
    }
    
    // Calculate the total value of all coins
    totalValue += totalValue; // Multiply the value of the coin by the number of coins
    
    // Update the previous coin type
    previousCoin = currentCoin;
  }
  
  // Print the total value of all coins
  printf("The total value of all coins is %d\n", totalValue);
  
  // Print the sequence of coins
  printf("The sequence of coins is: ");
  printf("%c", previousCoin); // Print the previous coin type
  for (int i = 1; i < coinCount; i++) {
    printf("%c %c", currentCoin, previousCoin); // Print the current and previous coin types
    previousCoin = currentCoin; // Update the previous coin type
    currentCoin = previousCoin; // Update the current coin type
  }
  printf("%c", previousCoin); // Print the previous coin type
  printf("\n");
  
  return 0;
}