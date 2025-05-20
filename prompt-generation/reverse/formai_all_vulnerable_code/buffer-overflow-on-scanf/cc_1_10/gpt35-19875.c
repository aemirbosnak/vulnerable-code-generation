//FormAI DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Happy Number Game!\n\n");
    printf("The rules are simple: you must pick a number between 1 and 100.\n");
    printf("If your number matches the computer's number, you win!\n");
    printf("But if your number is not a 'happy number', you lose.\n");
    printf("Don't worry though, we only deal in happy numbers here!\n\n");
    
    // Generate a random "happy number"
    srand(time(NULL));
    int happy_num = rand() % 100 + 1;
    
    int guess;
    do {
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess);
        
        // Check if guess is a happy number
        int temp = guess;
        while (1) {
            int sum = 0;
            while (temp > 0) {
                int digit = temp % 10;
                sum += digit * digit;
                temp /= 10;
            }
            if (sum == 1) {
                break;
            }
            if (sum == guess || sum == 4) {
                printf("Sorry, %d is not a happy number. Please try again!\n", guess);
                break;
            }
            temp = sum;
        }
        
        if (guess == happy_num) {
            printf("Congratulations, you won! The happy number was %d.\n", happy_num);
        } else if (guess < happy_num) {
            printf("Sorry, %d is too low. Please try again!\n", guess);
        } else {
            printf("Sorry, %d is too high. Please try again!\n", guess);
        }
    } while (guess != happy_num);

    return 0;
}