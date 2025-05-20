//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<limits.h>
#include<math.h>
#include<time.h>
#include<stdbool.h>
#include<float.h>

#define MAX 1000000000

int main() {
    int num1 = 0, num2 = 0;
    int choice;
    char str[20];

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Enter the operation you want to perform:\n1. AND\n2. OR\n3. XOR\n4. NOT\n5. Left Shift\n6. Right Shift\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("The result of AND operation is: %d\n", num1 & num2);
            break;
        case 2:
            printf("The result of OR operation is: %d\n", num1 | num2);
            break;
        case 3:
            printf("The result of XOR operation is: %d\n", num1 ^ num2);
            break;
        case 4:
            printf("The result of NOT operation is: %d\n", ~num1);
            break;
        case 5:
            printf("Enter the number of places to shift: ");
            scanf("%d", &num2);
            printf("The result of Left Shift operation is: %d\n", num1 << num2);
            break;
        case 6:
            printf("Enter the number of places to shift: ");
            scanf("%d", &num2);
            printf("The result of Right Shift operation is: %d\n", num1 >> num2);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}