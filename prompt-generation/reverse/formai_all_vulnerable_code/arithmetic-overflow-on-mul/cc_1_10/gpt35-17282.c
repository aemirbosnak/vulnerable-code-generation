//FormAI DATASET v1.0 Category: Calculator ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void add(int x, int y) {
    usleep(1000000); // Sleep for 1 second to simulate delay
    printf("\n%d + %d = %d\n\n", x, y, x+y);
}
void subtract(int x, int y) {
    usleep(500000); // Sleep for half a second to simulate delay
    printf("\n%d - %d = %d\n\n", x, y, x-y);
}

void multiply(int x, int y) {
    usleep(2000000); // Sleep for 2 seconds to simulate delay
    printf("\n%d * %d = %d\n\n", x, y, x*y);
}

void divide(int x, int y) {
    usleep(2500000); // Sleep for 2.5 seconds to simulate delay
    if(y!=0) {
        printf("\n%d / %d = %d\n\n", x, y, x/y);
    }
    else {
        printf("\nCannot divide by zero!\n\n");
    }
}

int main() {
    int choice, x, y;
    printf("\nWelcome to the Async Calculator\n");
    while(1) {
        printf("Enter your choice:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the first number: ");
                scanf("%d", &x);
                printf("Enter the second number: ");
                scanf("%d", &y);
                add(x, y);
                break;

            case 2:
                printf("Enter the first number: ");
                scanf("%d", &x);
                printf("Enter the second number: ");
                scanf("%d", &y);
                subtract(x, y);
                break;

            case 3:
                printf("Enter the first number: ");
                scanf("%d", &x);
                printf("Enter the second number: ");
                scanf("%d", &y);
                multiply(x, y);
                break;

            case 4:
                printf("Enter the first number: ");
                scanf("%d", &x);
                printf("Enter the second number: ");
                scanf("%d", &y);
                divide(x, y);
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Invalid input! Please enter a number between 1 and 5.\n");
                break;
        }
    }
    return 0;
}