//FormAI DATASET v1.0 Category: Math exercise ; Style: surrealist
#include <stdio.h>

int main() {
    int x = 5;
    float y = 3.14;
    char z = 'a';
    
    printf("Enter a number: ");
    scanf("%d", &x);
    
    printf("Enter a decimal number: ");
    scanf("%f", &y);
    
    printf("Enter a letter: ");
    scanf(" %c", &z);
    
    printf("The square of %d is %d.\n", x, x * x);
    
    printf("The sine of %.2f is %.2f.\n", y, sin(y));
    
    printf("The ASCII code of %c is %d.\n", z, z);
    
    printf("To solve this math problem, you must first find the key to the locked door.\n");
    printf("The key is hidden somewhere in the code... can you find it?\n");
    
    int a = x + 2;
    float b = y / 2;
    char c = z + 1;
    
    int product = a * x;
    float quotient = b / y;
    char shifted = c - 1;
    
    printf("The product of %d and %d is %d.\n", a, x, product);
    
    printf("The quotient of %.2f and %.2f is %.2f.\n", b, y, quotient);
    
    printf("The letter %c shifted backwards is %c.\n", z, shifted);
    
    printf("You have found the key! Enter it now to solve the math problem.\n");
    
    int key;
    scanf("%d", &key);
    
    if (key == product + quotient - shifted) {
        printf("Congratulations! You have solved the math problem.\n");
    } else {
        printf("Sorry, that is not the correct solution. Please try again.\n");
    }
    
    return 0;
}