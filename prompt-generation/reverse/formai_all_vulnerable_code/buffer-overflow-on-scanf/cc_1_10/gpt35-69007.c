//FormAI DATASET v1.0 Category: Funny ; Style: enthusiastic
#include <stdio.h>

int main() {
    
    printf("Welcome to the Great Code-Off!\n");
    printf("Today, we will be testing your coding skills with three challenges.\n\n");
    
    int challenge1, challenge2, challenge3;
    int score = 0;
    
    printf("Challenge One:\n");
    printf("Write a program that takes in a number and prints out whether it is even or odd.\n");
    
    scanf("%d", &challenge1);
    
    if (challenge1 % 2 == 0) {
        printf("%d is even!\n", challenge1);
        score += 10;
    } else {
        printf("%d is odd.\n", challenge1);
    }
    
    printf("Current Score: %d/30\n\n", score);
    
    printf("Challenge Two:\n");
    printf("Write a program that takes in a string and reverses the order of the letters.\n");
    
    char challengeTwoString[100];
    char reversedString[100];
    
    scanf("%s", challengeTwoString);
    
    int length = 0;
    while (challengeTwoString[length] != '\0') {
        length++;
    }
    
    for (int i = length-1; i >= 0; i--) {
        reversedString[length-i-1] = challengeTwoString[i];
    }
    
    reversedString[length] = '\0';
    
    printf("Reversed String: %s\n", reversedString);
    
    score += 10;
    
    printf("Current Score: %d/30\n\n", score);
    
    printf("Challenge Three:\n");
    printf("Write a program that prints out the first 10 numbers in the Fibonacci sequence.\n");
    
    int fibonacciSequence[10];
    
    fibonacciSequence[0] = 0;
    fibonacciSequence[1] = 1;
    
    for (int i = 2; i < 10; i++) {
        fibonacciSequence[i] = fibonacciSequence[i-1] + fibonacciSequence[i-2];
    }
    
    printf("Fibonacci Sequence: ");
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", fibonacciSequence[i]);
    }
    
    score += 10;
    
    printf("\n\nCongratulations! Your final score is: %d/30.\n\n", score);
    
    printf("Thanks for playing!\n");
    
    return 0;
}