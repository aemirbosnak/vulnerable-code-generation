//FormAI DATASET v1.0 Category: Educational ; Style: energetic
#include <stdio.h>

int main() {
    printf("Welcome to the Energizing Program!\n\n");
    
    printf("Enter a number: ");
    int num;
    scanf("%d", &num);
    
    printf("\n\nCalculating...\n\n");
    
    int factorial = 1;
    for(int i = 1; i <= num; i++) {
        factorial *= i;
    }
    
    printf("The factorial of %d is %d!\n\n", num, factorial);
    printf("Now let's use some energy to calculate the Fibonacci sequence up to %d terms!\n\n", num);
    
    int fib[num];
    fib[0] = 0;
    fib[1] = 1;
    
    for(int i = 2; i < num; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    printf("The Fibonacci sequence up to the %dth term is:\n", num);
    for(int i = 0; i < num; i++) {
        printf("%d ", fib[i]);
    }
    
    printf("\n\nGreat job! Now let's move onto some energizing string manipulation!\n\n");
    
    char str1[50], str2[50];
    printf("Enter a string: ");
    scanf("%s", str1);
    
    printf("\nEnter another string: ");
    scanf("%s", str2);
    
    printf("\n\nCombining the two strings...\n\n");
    
    char combined[100];
    int length = 0;
    for(int i = 0; str1[i] != '\0'; i++) {
        combined[length++] = str1[i];
    }
    
    for(int i = 0; str2[i] != '\0'; i++) {
        combined[length++] = str2[i];
    }
    
    printf("The combined string is: %s", combined);
    
    printf("\n\nThat concludes our Energizing Program! Stay energized!\n");
    
    return 0;
}