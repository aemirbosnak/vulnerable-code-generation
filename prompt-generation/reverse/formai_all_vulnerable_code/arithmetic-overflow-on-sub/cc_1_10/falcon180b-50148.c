//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define BIT_AND 1
#define BIT_OR 2
#define BIT_XOR 3
#define BIT_NOT 4
#define BIT_LEFT_SHIFT 5
#define BIT_RIGHT_SHIFT 6
#define BIT_ROTATE_LEFT 7
#define BIT_ROTATE_RIGHT 8

int main() {
    int num1, num2, choice;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    printf("Enter your choice:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("7. Rotate Left\n");
    printf("8. Rotate Right\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case BIT_AND:
            printf("Bitwise AND of %d and %d is %d\n", num1, num2, num1 & num2);
            break;
        case BIT_OR:
            printf("Bitwise OR of %d and %d is %d\n", num1, num2, num1 | num2);
            break;
        case BIT_XOR:
            printf("Bitwise XOR of %d and %d is %d\n", num1, num2, num1 ^ num2);
            break;
        case BIT_NOT:
            printf("Bitwise NOT of %d is %d\n", num1, ~num1);
            break;
        case BIT_LEFT_SHIFT:
            printf("Left Shift of %d by %d is %d\n", num1, num2, num1 << num2);
            break;
        case BIT_RIGHT_SHIFT:
            printf("Right Shift of %d by %d is %d\n", num1, num2, num1 >> num2);
            break;
        case BIT_ROTATE_LEFT:
            printf("Left Rotate of %d by %d is %d\n", num1, num2, (num1 << num2) | (num1 >> (32 - num2)));
            break;
        case BIT_ROTATE_RIGHT:
            printf("Right Rotate of %d by %d is %d\n", num1, num2, (num1 >> num2) | (num1 << (32 - num2)));
            break;
        default:
            printf("Invalid choice\n");
    }
    
    return 0;
}