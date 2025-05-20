//FormAI DATASET v1.0 Category: Scientific ; Style: excited
#include <stdio.h> 

int main() { 
    printf("Hey! I have the most exciting scientific program for you!\n"); 
   
    int x = 0;
    int y = 1;
    
    printf("Enter a number to find the Fibonacci Series up to that number: ");
    scanf("%d", &x);
    
    printf("The Fibonacci Series up to %d is: ", x);
    
    for(int i = 1; i <= x; i++) {
        printf("%d ", y);
        int z = x + y;
        x = y;
        y = z;
    }
    
    printf("\nWow! Isn't that amazing?\n");
    
    double radius = 0;
    printf("\nNext up, let's find the area of a circle!\n");
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    
    double area = 3.14159 * radius * radius;
    
    printf("The area of the circle with radius %lf is %.2lf\n", radius, area);
    
    printf("\nAre you ready for even more excitement?\n");
    
    int num = 0;
    int sum = 0;
    
    printf("Let's find the sum of all the numbers from 1 to any number you choose!\n");
    printf("Enter a number: ");
    scanf("%d", &num);
    
    for(int i = 1; i <= num; i++) {
        sum += i;
    }
    
    printf("The sum of all the numbers from 1 to %d is %d\n", num, sum);
    
    printf("\nWasn't that a rush? Programming is so much fun!\n");
    
    return 0; 
}