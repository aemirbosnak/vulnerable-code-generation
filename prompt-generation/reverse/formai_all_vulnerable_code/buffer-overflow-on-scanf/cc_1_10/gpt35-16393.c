//FormAI DATASET v1.0 Category: Stock market tracker ; Style: romantic
#include <stdio.h>

int main(void) {
    // Let's track the stock market together, my love
    printf("My darling, let's keep an eye on the stock market!\n\n");

    // We'll need some variables to store the values
    float apple_stock = 0.0f;
    float google_stock = 0.0f;
    float microsoft_stock = 0.0f;

    // Prompt the user for the current stock values
    printf("My love, what is the price of a share of Apple's stock today? $");
    scanf("%f", &apple_stock);
    printf("Thank you, darling. And Google's stock price? $");
    scanf("%f", &google_stock);
    printf("And how about Microsoft's stock price? $");
    scanf("%f", &microsoft_stock);

    // Show the user the entered values
    printf("\nThank you, dearest. We will keep track of Apple (AAPL), Google (GOOG), and Microsoft (MSFT).\n");
    printf("Today's stock prices are:\n");
    printf("AAPL: $%.2f\n", apple_stock);
    printf("GOOG: $%.2f\n", google_stock);
    printf("MSFT: $%.2f\n\n", microsoft_stock);

    // Now let's monitor the stock prices
    int seconds = 0;
    float apple_change = 0.0f;
    float google_change = 0.0f;
    float microsoft_change = 0.0f;

    printf("My love, let us watch the stock market closely...\n\n");

    while (1) {
        // Wait for a second
        sleep(1);

        // Increment our seconds counter
        seconds++;

        // Update the stock prices
        apple_change = (rand() % 201 - 100) / 100.0f;
        google_change = (rand() % 201 - 100) / 100.0f;
        microsoft_change = (rand() % 201 - 100) / 100.0f;

        apple_stock += apple_change;
        google_stock += google_change;
        microsoft_stock += microsoft_change;

        // Show the updated values
        printf("%d seconds have passed...\n", seconds);
        printf("AAPL: $%.2f (%+.2f)\n", apple_stock, apple_change);
        printf("GOOG: $%.2f (%+.2f)\n", google_stock, google_change);
        printf("MSFT: $%.2f (%+.2f)\n\n", microsoft_stock, microsoft_change);

        // Check if the stocks have crashed
        if (apple_stock <= 0 || google_stock <= 0 || microsoft_stock <= 0) {
            printf("Oh no! The stock market has crashed!\n");
            printf("We'll never give up, though, my love. We'll keep watching the market together.\n");
            break;
        }
    }

    // Return 0 to signify successful execution
    return 0;
}