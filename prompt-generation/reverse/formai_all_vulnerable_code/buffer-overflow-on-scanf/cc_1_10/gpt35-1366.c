//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PLAYERS 4

void add(int num1, int num2)
{
    printf("Result: %d\n", num1 + num2);
}

void subtract(int num1, int num2)
{
    printf("Result: %d\n", num1 - num2);
}

void multiply(int num1, int num2)
{
    printf("Result: %d\n", num1 * num2);
}

void divide(int num1, int num2)
{
    if (num2 == 0) {
        printf("Error: Cannot divide by zero\n");
        return;
    }
    printf("Result: %d\n", num1 / num2);
}

void square(int num1)
{
    printf("Result: %d\n", num1 * num1);
}

void square_root(int num1)
{
    if (num1 < 0) {
        printf("Error: Cannot take square root of negative number\n");
        return;
    }
    printf("Result: %lf\n", sqrt(num1));
}

int main()
{
    int num_players;
    int i, j;
    char operation_choice;
    int num1, num2;
    
    // Get number of players
    printf("How many players are there? ");
    scanf("%d", &num_players);
    if (num_players < 2 || num_players > MAX_PLAYERS) {
        printf("Error: Invalid number of players\n");
        return 1;
    }
    
    // Initialize scores
    int scores[num_players];
    for (i = 0; i < num_players; i++) {
        scores[i] = 0;
    }
    
    // Game loop
    while (1) {
        // Get operation choice
        printf("Player %d, what operation would you like to perform? (+,-,*,/,^,r)\n", (j % num_players) + 1);
        scanf(" %c", &operation_choice);
        
        // Get operands
        printf("Enter two numbers: ");
        scanf("%d %d", &num1, &num2);
        
        // Perform operation
        switch (operation_choice) {
            case '+':
                add(num1, num2);
                break;
            case '-':
                subtract(num1, num2);
                break;
            case '*':
                multiply(num1, num2);
                break;
            case '/':
                divide(num1, num2);
                break;
            case '^':
                printf("Result: %lf\n", pow(num1, num2));
                break;
            case 'r':
                square(num1);
                square(num2);
                break;
            default:
                printf("Error: Invalid operation choice\n");
                continue;
        }
        
        // Update score
        scores[j % num_players]++;
        
        // Print scores
        printf("Scores: ");
        for (i = 0; i < num_players; i++) {
            printf("Player %d: %d ", i + 1, scores[i]);
        }
        printf("\n");
        
        // Check for winner
        for (i = 0; i < num_players; i++) {
            if (scores[i] >= 10) {
                printf("Player %d wins!\n", i + 1);
                return 0;
            }
        }
        
        // Increment player index
        j++;
    }
    
    return 0;
}