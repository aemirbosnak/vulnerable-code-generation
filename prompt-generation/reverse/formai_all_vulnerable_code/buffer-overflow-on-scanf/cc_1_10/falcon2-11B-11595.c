//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    double current_price;
    double previous_price;
    double change_in_price;
    int days_since_last_price;
    
    // Prompt user for starting price
    printf("Enter the initial stock price: ");
    scanf("%lf", &current_price);
    
    // Loop to track stock prices over time
    while (1) {
        // Prompt user to enter stock price
        printf("Enter the current stock price: ");
        scanf("%lf", &current_price);
        
        // Calculate change in price and number of days since last price
        change_in_price = current_price - previous_price;
        days_since_last_price = 1;
        
        // Print current price and change in price
        printf("Current price: %.2lf\n", current_price);
        printf("Change in price: %.2lf\n", change_in_price);
        
        // Prompt user if they want to continue tracking prices
        printf("Do you want to continue tracking stock prices? (Y/N): ");
        char response;
        scanf(" %c", &response);
        
        // Exit loop if user enters 'N'
        if (response == 'N') {
            break;
        }
        
        // Update previous price and days since last price
        previous_price = current_price;
        days_since_last_price++;
    }
    
    // Print total number of days tracked
    printf("Total number of days tracked: %d\n", days_since_last_price);
    
    // Return 0 to indicate successful program execution
    return 0;
}