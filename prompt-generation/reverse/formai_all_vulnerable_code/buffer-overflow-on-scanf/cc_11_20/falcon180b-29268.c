//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: detailed
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int main() {
    char input[MAX_LEN];
    char *token;
    char *endptr;
    double num1, num2;
    int choice;
    char repeat = 'y';

    printf("Welcome to the Scientific Calculator!\n");
    while(repeat == 'y') {
        printf("Enter your expression: ");
        fgets(input, MAX_LEN, stdin);
        token = strtok(input, " ");
        while(token!= NULL) {
            if(isdigit(token[0])) {
                num1 = strtod(token, &endptr);
                num2 = strtod(endptr, NULL);
                printf("Number: %lf\n", num1);
            } else {
                switch(token[0]) {
                    case '+':
                        printf("Operation: +\n");
                        break;
                    case '-':
                        printf("Operation: -\n");
                        break;
                    case '*':
                        printf("Operation: *\n");
                        break;
                    case '/':
                        printf("Operation: /\n");
                        break;
                    case '^':
                        printf("Operation: ^\n");
                        break;
                    case's':
                        printf("Operation: sin\n");
                        break;
                    case 'c':
                        printf("Operation: cos\n");
                        break;
                    case 't':
                        printf("Operation: tan\n");
                        break;
                    case 'l':
                        printf("Operation: log\n");
                        break;
                    case 'n':
                        printf("Operation: ln\n");
                        break;
                    case '.':
                        printf("Operation: decimal\n");
                        break;
                    default:
                        printf("Invalid input: %s\n", token);
                }
            }
            token = strtok(NULL, " ");
        }
        printf("\nDo you want to continue? (y/n): ");
        scanf("%c", &repeat);
    }
    return 0;
}