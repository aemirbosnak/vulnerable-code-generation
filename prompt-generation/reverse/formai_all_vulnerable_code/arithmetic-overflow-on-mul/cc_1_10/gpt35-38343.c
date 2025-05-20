//FormAI DATASET v1.0 Category: Calculator ; Style: expert-level
#include <stdio.h>

int main() {
    int num1, num2, res, choice;

    while(1) {
        printf("*** Calculator ***\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        if(choice==5) {
            printf("Exiting program...\n");
            break;
        }
        printf("Enter first number: ");
        scanf("%d",&num1);
        printf("Enter second number: ");
        scanf("%d",&num2);

        switch(choice) {
            case 1:
                res = num1+num2;
                printf("Result: %d\n",res);
                break;
            case 2:
                res = num1-num2;
                printf("Result: %d\n",res);
                break;
            case 3:
                res = num1*num2;
                printf("Result: %d\n",res);
                break;
            case 4:
                if(num2 == 0) {
                    printf("Division by zero error!\n");
                }
                else {
                    float resFloat = num1/num2;
                    printf("Result: %f\n",resFloat);
                }
                break;
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}