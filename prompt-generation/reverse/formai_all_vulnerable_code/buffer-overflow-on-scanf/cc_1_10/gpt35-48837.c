//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    char menu[] = "\n\n************ Retro Scientific Calculator ************\n"
                  "Enter an operation, or q to quit.\n"
                  "1) Addition\n"
                  "2) Subtraction\n"
                  "3) Multiplication\n"
                  "4) Division\n"
                  
                  "\n\n";
    printf("%s",menu);

    int choice;
    double num1, num2, result;
    char ch[10];

    while(1) {
        printf("> ");
        scanf("%s", ch);

        if(!strcmp(ch, "q")){
            printf("Quitting calculator...\n");
            break;
        }

        choice = atoi(ch);

        switch (choice){
            case 1:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 + num2;
                printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 2:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 - num2;
                printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 3:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 * num2;
                printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 4:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
                break;

            default:
                printf("Invalid operation. Please try again.\n");
        }

    }

    return 0;
}