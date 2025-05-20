//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
/* Scene 1: Introduction */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int budget;
    float savings_rate, interest_rate;

    printf("Enter your budget: ");
    scanf("%d", &budget);
    printf("Enter your savings rate: ");
    scanf("%f", &savings_rate); 
    printf("Enter your expected interest rate: ");
    scanf("%f", &interest_rate);

    printf("\nOh Personal Finance Planner,\n");
    printf("I seek your guidance for my wealth to grow.\n");
    printf("With budget of %d and a savings rate of %.2f,\n", budget, savings_rate);
    printf("And an expected interest rate of %.2f,\n", interest_rate);
    printf("Pray tell me, how shall I proceed?\n\n");

/* Scene 2: Advice */
 
    if (savings_rate < 0.1) {
        printf("Oh dear friend, you must save more,\n");
        printf("To secure your future you cannot ignore.\n");
        printf("Invest in mutual funds and stocks,\n");
        printf("Aim for long term returns, don't check the clocks.\n");
    } else if (savings_rate >= 0.1 && savings_rate < 0.2) {
        printf("A moderate saver you are,\n");
        printf("Still, to increase wealth, you must raise the bar.\n");
        printf("Diversify investments, take on some risk,\n");
        printf("Don't shy away from stocks, they'll give you a brisk.\n");
    } else {
        printf("An admirable saver you are indeed,\n");
        printf("One day you'll have the wealth you need.\n");
        printf("Don't forget to invest wisely, though,\n");
        printf("Follow the stock market, watch it grow.\n");
    }

    if (interest_rate >= 0.05) {
        printf("Interest rates are favorable right now,\n");
        printf("Take advantage, don't ask how.\n");
        printf("Put money in CDs, build an emergency fund,\n");
        printf("A stable portfolio is always a good resound.\n");
    } else {
        printf("Interest rates are low, don't be discouraged,\n");
        printf("There are still options worth being encouraged.\n");
        printf("Dividend paying stocks, peer-to-peer lending,\n");
        printf("Don't put all your eggs in one basket, keep blending.\n");
    }

/* Scene 3: Conclusion */

    printf("\nThank you, Personal Finance Planner,\n");
    printf("Your advice is wise, it brought me new manner.\n");
    printf("With budget of %d and a savings rate of %.2f,\n", budget, savings_rate);
    printf("And an expected interest rate of %.2f,\n", interest_rate);
    printf("I will grow my wealth and follow your doctrine.\n");
    printf("Farewell for now, until my next summon.\n");
    
    return 0;
}