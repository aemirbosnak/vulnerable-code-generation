//FormAI DATASET v1.0 Category: Bitwise operations ; Style: curious
#include <stdio.h>

int main(void) {
    printf("Welcome to the Bitwise Operations Show!\n\n");
    
    printf("In this show, we will demonstrate some exciting bitwise operations.\n");
    printf("Are you ready for the show? (y/n): ");
    
    char answer;
    scanf("%c", &answer);
    printf("\n");
    
    if (answer == 'y') {
        printf("Great! Let's get started.\n\n");
        
        printf("This is our first act. We will perform the bitwise AND operation.\n");
        printf("Please enter two numbers that you would like to AND together: ");
        
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        
        int result = num1 & num2;
        printf("\n%d AND %d is %d.\n\n", num1, num2, result);
        
        printf("Wasn't that amazing? (y/n): ");
        scanf(" %c", &answer);
        printf("\n");
        
        if (answer == 'y') {
            printf("I'm glad you enjoyed it!\n\n");
        } else {
            printf("Oh no! I'm sorry the show didn't meet your expectations.\n\n");
        }
        
        printf("Moving on to act two. Here, we will perform the bitwise OR operation.\n");
        printf("Please enter two numbers that you would like to OR together: ");
        
        scanf("%d %d", &num1, &num2);
        
        result = num1 | num2;
        printf("\n%d OR %d is %d.\n\n", num1, num2, result);
        
        printf("How did you like that? (good/bad): ");
        scanf(" %s", answer);
        printf("\n");
        
        if (answer == "good") {
            printf("Fantastic! I'm glad you're enjoying the show!\n\n");
        } else {
            printf("I'm sorry to hear that.\n\n");
        }
        
        printf("Alright, we are now on our final act. This is the bitwise XOR operation.\n");
        printf("Please enter two numbers that you would like to XOR together: ");
        
        scanf("%d %d", &num1, &num2);
        
        result = num1 ^ num2;
        printf("\n%d XOR %d is %d.\n\n", num1, num2, result);
        
        printf("Wow, what a show! Did you have fun? (y/n): ");
        scanf(" %c", &answer);
        printf("\n");
        
        if (answer == 'y') {
            printf("I'm thrilled to hear that! Thank you for watching!\n\n");
        } else {
            printf("I'm sorry to hear that. We'll try to do better next time.\n\n");
        }
    } else {
        printf("I'm sorry to hear that. Maybe next time!\n\n");
    }
    
    return 0;
}