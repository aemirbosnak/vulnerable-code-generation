//FormAI DATASET v1.0 Category: Bitwise operations ; Style: lively
#include<stdio.h>

int main() {
    
    printf("Welcome to the Bitwise Operation Game!\n\n");
    printf("In this game, you will enter two values and choose an operator to perform a bitwise operation on them.\n\n");
    printf("Please enter the first value: ");
    unsigned int val1;
    scanf("%u", &val1);
    printf("Please enter the second value: ");
    unsigned int val2;
    scanf("%u", &val2);
    
    printf("\nChoose an operation: \n");
    printf("1. & (Bitwise AND)\n");
    printf("2. | (Bitwise OR)\n");
    printf("3. ^ (Bitwise XOR)\n");
    printf("4. << (Left shift)\n");
    printf("5. >> (Right shift)\n");
    printf("\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: 
            printf("\nPerforming Bitwise AND operation on %u and %u\n", val1, val2);
            unsigned int result1 = val1 & val2;
            printf("%u & %u = %u\n", val1, val2, result1);
            break;
        case 2:
            printf("\nPerforming Bitwise OR operation on %u and %u\n", val1, val2);
            unsigned int result2 = val1 | val2;
            printf("%u | %u = %u\n", val1, val2, result2);
            break;
        case 3: 
            printf("\nPerforming Bitwise XOR operation on %u and %u\n", val1, val2);
            unsigned int result3 = val1 ^ val2;
            printf("%u ^ %u = %u\n", val1, val2, result3);
            break;
        case 4:
            printf("\nEnter number of positions to left-shift: ");
            int shiftAmount1;
            scanf("%d", &shiftAmount1);
            printf("\nPerforming Left shift operation on %u by %d positions\n", val1, shiftAmount1);
            unsigned int result4 = val1 << shiftAmount1;
            printf("%u << %d = %u\n", val1, shiftAmount1, result4);
            break;
        case 5:
            printf("\nEnter number of positions to right-shift: ");
            int shiftAmount2;
            scanf("%d", &shiftAmount2);
            printf("\nPerforming Right shift operation on %u by %d positions\n", val1, shiftAmount2);
            unsigned int result5 = val1 >> shiftAmount2;
            printf("%u >> %d = %u\n", val1, shiftAmount2, result5);
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
    }
    
    return 0;
}