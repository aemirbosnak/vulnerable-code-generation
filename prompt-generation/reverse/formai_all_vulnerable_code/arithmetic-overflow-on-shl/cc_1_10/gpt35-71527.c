//FormAI DATASET v1.0 Category: Bitwise operations ; Style: happy
#include <stdio.h>

int main() {
    int happy = 1;
    int bitwise = 0;
    int result = 0;
    
    printf("Welcome to the Happy Bitwise Operations program!\n");
    printf("Are you ready to learn about bitwise operators? (%d for yes, %d for no)\n", happy, bitwise);
    scanf("%d", &happy);
    
    if (happy) {
        printf("Great! Let's start by setting some variables.\n");
        
        printf("Enter a number for bitwise operations: ");
        scanf("%d", &bitwise);
        
        printf("Your number is %d!\n", bitwise);
        
        printf("Now, let's set another variable for our first operation.\n");
        printf("Enter a second number: ");
        int op = 0;
        scanf("%d", &op);
        printf("Your second number is %d!\n", op);
        
        printf("Here are some common bitwise operators we can use:\n");
        printf("& - bitwise AND\n");
        printf("| - bitwise OR\n");
        printf("^ - bitwise XOR\n");
        printf("~ - bitwise NOT (one's complement)\n");
        printf("<< - bitwise left-shift\n");
        printf(">> - bitwise right-shift\n");
        
        printf("Which operation would you like to perform? Enter the symbol: ");
        char operation;
        scanf(" %c", &operation);
        
        switch (operation) {
            case '&':
                result = bitwise & op;
                break;
            case '|':
                result = bitwise | op;
                break;
            case '^':
                result = bitwise ^ op;
                break;
            case '~':
                result = ~bitwise;
                break;
            case '<':
                printf("How many bits would you like to shift left? ");
                int shift_left;
                scanf("%d", &shift_left);
                result = bitwise << shift_left;
                break;
            case '>':
                printf("How many bits would you like to shift right? ");
                int shift_right;
                scanf("%d", &shift_right);
                result = bitwise >> shift_right;
                break;
            default:
                printf("Invalid operator, please try again.\n");
                break;
        }
        
        printf("The result of your operation is: %d\n", result);
    } else {
        printf("Aww, that's too bad. Maybe next time! Goodbye!\n");
    }
    
    return 0;
}