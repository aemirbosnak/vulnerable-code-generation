//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main() {
    char input[100];
    int i, j, k, n, flag;
    double num1, num2, result;
    
    printf("Enter the expression: ");
    scanf("%s", input);
    
    i = 0;
    flag = 0;
    
    while (input[i]!= '\0') {
        if (!isdigit(input[i])) {
            switch (input[i]) {
                case '+':
                    printf("%.0f + ", num1);
                    num1 = 0;
                    flag = 1;
                    break;
                    
                case '-':
                    printf("%.0f - ", num1);
                    num1 = 0;
                    flag = 1;
                    break;
                    
                case '*':
                    printf("%.0f * ", num1);
                    num1 = 0;
                    flag = 1;
                    break;
                    
                case '/':
                    printf("%.0f / ", num1);
                    num1 = 0;
                    flag = 1;
                    break;
                    
                case '=':
                    printf("%.0f = ", num1);
                    num1 = 0;
                    flag = 1;
                    break;
                    
                case '^':
                    printf("%.0f ^ ", num1);
                    num1 = 0;
                    flag = 1;
                    break;
                    
                case '(':
                    printf("( ");
                    flag = 1;
                    break;
                    
                case ')':
                    printf(") ");
                    flag = 1;
                    break;
                    
                default:
                    if (isalpha(input[i])) {
                        printf("%c", input[i]);
                    }
            }
        } else {
            if (flag == 0) {
                printf("%.0f ", num1);
                num1 = num1 * 10 + input[i] - '0';
            } else {
                printf("%c", input[i]);
            }
        }
        
        i++;
    }
    
    printf("\n");
    
    return 0;
}