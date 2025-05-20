//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define HAPPY_NUM 7

typedef struct {
    int num1;
    int num2;
    int result;
} HappyCalculator;

void happyAdd(HappyCalculator *calc) {
    calc->result = calc->num1 + calc->num2;
    printf("\nNumber %d and %d added happily gives %d!\n", calc->num1, calc->num2, calc->result);
}

void happySubtract(HappyCalculator *calc) {
    calc->result = calc->num1 - calc->num2;
    printf("\nNumber %d is happier than %d, resulting in %d!\n", calc->num1, calc->num2, calc->result);
}

void happyMultiply(HappyCalculator *calc) {
    calc->result = calc->num1 * calc->num2;
    printf("\nNumber %d and %d make %d little happy numbers when multiplied together!\n", calc->num1, calc->num2, calc->result);
}

void happyDivide(HappyCalculator *calc) {
    if (calc->num2 != 0) {
        calc->result = calc->num1 / calc->num2;
        printf("\nNumber %d is %d times happier than %d!\n", calc->num1, calc->num1 / calc->num2, calc->num2);
    } else {
        printf("\nCannot divide by zero, try again with non-zero number!\n");
    }
}

int main() {
    HappyCalculator calc;
    int choice;

    printf("Welcome to the Happy Arithmetic Calculator!\n");
    printf("Enter numbers to perform arithmetic operations with happiness!\n");

    while (1) {
        printf("\nEnter the operation number (1 for addition, 2 for subtraction, 3 for multiplication, 4 for division): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4) {
            printf("Enter first number: ");
            scanf("%d", &calc.num1);
            printf("Enter second number: ");
            scanf("%d", &calc.num2);

            switch (choice) {
                case 1:
                    happyAdd(&calc);
                    break;
                case 2:
                    happySubtract(&calc);
                    break;
                case 3:
                    happyMultiply(&calc);
                    break;
                case 4:
                    happyDivide(&calc);
                    break;
            }

            printf("\nDo you want to calculate again? (y/n): ");
            char answer;
            scanf("%c", &answer);

            if (answer != 'y') {
                break;
            }
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}