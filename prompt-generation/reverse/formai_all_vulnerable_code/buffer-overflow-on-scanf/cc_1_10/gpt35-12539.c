//FormAI DATASET v1.0 Category: Math exercise ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //Seed the random number generator
    srand(time(NULL));
    
    //Generate two random numbers between 1 and 10
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;
    
    //Calculate the sum, difference, product, and quotient of the two numbers
    int sum = num1 + num2;
    int difference = abs(num1 - num2);
    int product = num1 * num2;
    float quotient = (float) num1 / num2;
    
    //Print the problem and ask the user for their answer
    printf("What is the sum of %d and %d?\n", num1, num2);
    int user_answer;
    scanf("%d", &user_answer);
    
    //Check if the user's answer is correct and provide feedback
    if (user_answer == sum) {
        printf("Congratulations! Your answer is correct.\n");
    } else {
        printf("I regret to inform you that your answer is incorrect.\n");
        printf("The correct answer is %d.\n", sum);
    }
    
    //Print the next problem and ask the user for their answer
    printf("What is the difference between %d and %d?\n", num1, num2);
    scanf("%d", &user_answer);
    
    //Check if the user's answer is correct and provide feedback
    if (user_answer == difference) {
        printf("Congratulations! Your answer is correct.\n");
    } else {
        printf("I regret to inform you that your answer is incorrect.\n");
        printf("The correct answer is %d.\n", difference);
    }
    
    //Print the next problem and ask the user for their answer
    printf("What is the product of %d and %d?\n", num1, num2);
    scanf("%d", &user_answer);
    
    //Check if the user's answer is correct and provide feedback
    if (user_answer == product) {
        printf("Congratulations! Your answer is correct.\n");
    } else {
        printf("I regret to inform you that your answer is incorrect.\n");
        printf("The correct answer is %d.\n", product);
    }
    
    //Print the next problem and ask the user for their answer
    printf("What is %d divided by %d to two decimal places?\n", num1, num2);
    float user_quotient;
    scanf("%f", &user_quotient);
    
    //Check if the user's answer is correct and provide feedback
    if (user_quotient == quotient) {
        printf("Congratulations! Your answer is correct.\n");
    } else {
        printf("I regret to inform you that your answer is incorrect.\n");
        printf("The correct answer is %.2f.\n", quotient);
    }
    
    return 0;
}