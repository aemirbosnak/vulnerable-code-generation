//FormAI DATASET v1.0 Category: Funny ; Style: curious
#include <stdio.h>

int main() {
    int num1, num2, sum;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    sum = num1 + num2;
    if (sum > 100) {
        printf("Woohoo! The sum is greater than 100!\n");
    }
    else {
        printf("Oops, the sum is not greater than 100.\n");
    }

    printf("\nAn interesting fact - did you know that the largest integer you can represent in C is %d?\n", __INT_MAX__);
    printf("\nGo ahead and try it out!\n");
    
    /* Try adding 1 to the largest integer */
    int max_int = __INT_MAX__;
    int sum_max = max_int + 1;
    printf("\nThe sum of %d and 1 is %d.\n", max_int, sum_max);
    printf("Oh no! It seems like we've caused an overflow error. Don't worry though, it's just a learning opportunity.\n");

    printf("\nHave you ever heard of the phrase 'Garbage in, garbage out'? It means that if you provide wrong inputs, you'll get wrong outputs.");
    printf("\nLet's see an example - enter a letter: ");
    char letter;
    scanf(" %c", &letter);
    int ascii_value = (int)letter;
    printf("\nThe ASCII value of the letter %c is %d.\n", letter, ascii_value);
    printf("Not what you were expecting? That's because you provided garbage input!\n");
    
    printf("\nLast but not least - let's play a game of guessing numbers!");
    printf("\nI'm thinking of a number between 1 and 100. Guess which number I'm thinking of: ");
    int secret_num = 47;
    int guess;
    scanf("%d", &guess);
    while (guess != secret_num) {
        if (guess > secret_num) {
            printf("Too high! Guess again: ");
        }
        else {
            printf("Too low! Guess again: ");
        }
        scanf("%d", &guess);
    }
    printf("\nCongratulations, you guessed it! The secret number was indeed %d. You're a real champ.\n", secret_num);
    return 0;
}