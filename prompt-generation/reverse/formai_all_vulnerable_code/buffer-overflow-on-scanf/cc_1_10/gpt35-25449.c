//FormAI DATASET v1.0 Category: Bitwise operations ; Style: puzzling
#include <stdio.h>

int main() {
    int a = 0b1101;
    int b = 0b0110;
    int c;

    c = a ^ b;
    printf("The result of XORing %d and %d is %d\n", a, b, c);
    printf("Can you guess what the result will be after shifting %d one place to the left?\n", c);

    c = c << 1;
    printf("The shifted result is %d\n", c);
    printf("Did you get it right?\n");

    printf("Now let's try a different operation. What do you think is the result of ANDing %d and %d?\n", a, b);
    printf("Enter your guess in binary form (e.g. 0b0101): ");
    int guess;
    scanf("%d", &guess);

    c = a & b;
    printf("The actual result is %d\n", c);
    if (guess == c)
        printf("Congratulations! You got it right.\n");
    else
        printf("Sorry, that's not correct. Better luck next time.\n");

    printf("Let's move on to another operation. This time we'll use the NOT operator.\n");
    printf("What do you think is the result of NOTing %d?\n", a);

    c = ~a;
    printf("The actual result is %d\n", c);
    if (c == 0b0010)
        printf("You're good at this! That's correct.\n");
    else
        printf("Oops, that's not right. The correct answer is %d\n", 0b0010);

    printf("Finally, let's use the OR operator. What do you think is the result of ORing %d and %d?\n", a, b);
    printf("Enter your guess in binary form (e.g. 0b1010): ");
    scanf("%d", &guess);

    c = a | b;
    printf("The actual result is %d\n", c);
    if (guess == c)
        printf("You're a bitwise genius! That's correct.\n");
    else
        printf("Oh no, that's incorrect. Better luck next time.\n");

    return 0;
}