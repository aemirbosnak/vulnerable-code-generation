//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 0, y = 0, z = 0;
    char operation;

    printf("Welcome to the post-apocalyptic calculator.\n");
    printf("Please enter numbers and operations as prompted.\n");

    while (1) {
        printf("Enter number or operation: ");
        scanf("%c", &operation);

        if (operation == '+' || operation == '-' || operation == '*' || operation == '/') {
            printf("Enter number: ");
            scanf("%d", &z);

            if (x == 0 && y == 0) {
                x = z;
            } else if (y == 0) {
                y = z;
            } else {
                switch (operation) {
                    case '+':
                        x += y;
                        break;
                    case '-':
                        x -= y;
                        break;
                    case '*':
                        x *= y;
                        break;
                    case '/':
                        if (y == 0) {
                            printf("Error: Division by zero.\n");
                            exit(1);
                        }
                        x /= y;
                        break;
                }
                y = z;
            }
        } else {
            if (x == 0) {
                printf("Error: No numbers entered.\n");
                exit(1);
            } else {
                printf("Result: %d\n", x);
                exit(0);
            }
        }
    }

    return 0;
}