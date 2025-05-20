//Falcon2-11B DATASET v1.0 Category: Arithmetic ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num1, num2, result;
    int total = 0;

    printf("Welcome to the Happy Addition Game!\n");
    printf("I am going to give you two numbers and you have to add them.\n");
    printf("I'll be happy if you get the right answer!\n");
    printf("Are you ready?\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    result = num1 + num2;
    printf("The sum of %d and %d is %d.\n", num1, num2, result);
    printf("You got it right! I am so happy!\n");
    total++;

    printf("Let's try another one!\n");
    printf("I am going to give you two numbers and you have to subtract them.\n");
    printf("I'll be happy if you get the right answer!\n");
    printf("Are you ready?\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    result = num1 - num2;
    printf("The difference of %d and %d is %d.\n", num1, num2, result);
    printf("You got it right! I am so happy!\n");
    total++;

    printf("Let's try another one!\n");
    printf("I am going to give you two numbers and you have to multiply them.\n");
    printf("I'll be happy if you get the right answer!\n");
    printf("Are you ready?\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    result = num1 * num2;
    printf("The product of %d and %d is %d.\n", num1, num2, result);
    printf("You got it right! I am so happy!\n");
    total++;

    printf("Let's try another one!\n");
    printf("I am going to give you two numbers and you have to divide them.\n");
    printf("I'll be happy if you get the right answer!\n");
    printf("Are you ready?\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    result = num1 / num2;
    printf("The quotient of %d and %d is %d.\n", num1, num2, result);
    printf("You got it right! I am so happy!\n");
    total++;

    printf("You are awesome! You got all the answers right!\n");
    printf("You scored a total of %d points.\n", total);
    printf("I am so happy! Thank you for playing!\n");
    return 0;
}