//FormAI DATASET v1.0 Category: Arithmetic ; Style: bold
#include <stdio.h>

int main() {
    int x = 10, y = 20;
    printf("x + y = %d\n", x + y);
    printf("x - y = %d\n", x - y);
    printf("x * y = %d\n", x * y);
    printf("x / y = %d\n", x / y);
    printf("x % y = %d\n", x % y);
    
    if(x < y) {
        printf("x is less than y.\n");
    } else if(x > y) {
        printf("x is greater than y.\n");
    } else {
        printf("x is equal to y.\n");
    }
    
    int i;
    for(i = 1; i <= 10; i++) {
        printf("%d * %d = %d\n", x, i, x * i);
    }
    
    int num, sum = 0;
    printf("Enter 5 numbers:\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", &num);
        sum += num;
    }
    printf("The sum of the 5 numbers is: %d\n", sum);
    
    int a = 5, b = 7, c = 2;
    int result = a + b - c * 2 / 2 + 1;
    printf("The result of the expression a + b - c * 2 / 2 + 1 is: %d\n", result);
    
    float f1 = 5.4, f2 = 3.2;
    printf("f1 + f2 = %f\n", f1 + f2);
    printf("f1 - f2 = %f\n", f1 - f2);
    printf("f1 * f2 = %f\n", f1 * f2);
    printf("f1 / f2 = %f\n", f1 / f2);
    
    int choice;
    printf("Enter your choice:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("x + y = %d\n", x + y);
            break;
        case 2:
            printf("x - y = %d\n", x - y);
            break;
        case 3:
            printf("x * y = %d\n", x * y);
            break;
        case 4:
            printf("x / y = %d\n", x / y);
            break;
        default:
            printf("Invalid choice.\n");
    }
    
    return 0;
}