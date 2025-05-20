//FormAI DATASET v1.0 Category: Arithmetic ; Style: shape shifting
#include <stdio.h>

int main() {
    int choice, num1, num2, result;
    float dec1, dec2, dec_result;
    char char1, char2, char_result;
    printf("Welcome to the shape-shifting arithmetic program!\n");
    printf("Please select the type of operation you would like to perform:\n");
    printf("1. Addition (Integer)\n");
    printf("2. Addition (Decimal)\n");
    printf("3. Addition (Character)\n");
    printf("4. Subtraction (Integer)\n");
    printf("5. Subtraction (Decimal)\n");
    printf("6. Multiplication (Integer)\n");
    printf("7. Multiplication (Decimal)\n");
    printf("8. Division (Integer)\n");
    printf("9. Division (Decimal)\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("You have chosen Addition (Integer).\n");
            printf("Please enter the first integer: ");
            scanf("%d", &num1);
            printf("Please enter the second integer: ");
            scanf("%d", &num2);
            result = num1 + num2;
            printf("The result is: %d\n", result);
            break;
        case 2:
            printf("You have chosen Addition (Decimal).\n");
            printf("Please enter the first decimal: ");
            scanf("%f", &dec1);
            printf("Please enter the second decimal: ");
            scanf("%f", &dec2);
            dec_result = dec1 + dec2;
            printf("The result is: %f\n", dec_result);
            break;
        case 3:
            printf("You have chosen Addition (Character).\n");
            printf("Please enter the first character: ");
            scanf(" %c", &char1);
            printf("Please enter the second character: ");
            scanf(" %c", &char2);
            char_result = char1 + char2;
            printf("The result is: %c\n", char_result);
            break;
        case 4:
            printf("You have chosen Subtraction (Integer).\n");
            printf("Please enter the first integer: ");
            scanf("%d", &num1);
            printf("Please enter the second integer: ");
            scanf("%d", &num2);
            result = num1 - num2;
            printf("The result is: %d\n", result);
            break;
        case 5:
            printf("You have chosen Subtraction (Decimal).\n");
            printf("Please enter the first decimal: ");
            scanf("%f", &dec1);
            printf("Please enter the second decimal: ");
            scanf("%f", &dec2);
            dec_result = dec1 - dec2;
            printf("The result is: %f\n", dec_result);
            break;
        case 6:
            printf("You have chosen Multiplication (Integer).\n");
            printf("Please enter the first integer: ");
            scanf("%d", &num1);
            printf("Please enter the second integer: ");
            scanf("%d", &num2);
            result = num1 * num2;
            printf("The result is: %d\n", result);
            break;
        case 7:
            printf("You have chosen Multiplication (Decimal).\n");
            printf("Please enter the first decimal: ");
            scanf("%f", &dec1);
            printf("Please enter the second decimal: ");
            scanf("%f", &dec2);
            dec_result = dec1 * dec2;
            printf("The result is: %f\n", dec_result);
            break;
        case 8:
            printf("You have chosen Division (Integer).\n");
            printf("Please enter the first integer: ");
            scanf("%d", &num1);
            printf("Please enter the second integer: ");
            scanf("%d", &num2);
            if(num2 == 0) {
                printf("Error: Division by zero!\n");
                break;
            }
            result = num1 / num2;
            printf("The result is: %d\n", result);
            break;
        case 9:
            printf("You have chosen Division (Decimal).\n");
            printf("Please enter the first decimal: ");
            scanf("%f", &dec1);
            printf("Please enter the second decimal: ");
            scanf("%f", &dec2);
            if(dec2 == 0) {
                printf("Error: Division by zero!\n");
                break;
            }
            dec_result = dec1 / dec2;
            printf("The result is: %f\n", dec_result);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}