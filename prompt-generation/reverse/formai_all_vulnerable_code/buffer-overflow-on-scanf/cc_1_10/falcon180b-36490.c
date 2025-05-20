//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int a[MAX], n;

void input() {
    printf("Enter the number of elements (max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void display() {
    printf("The array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void add() {
    int sum = 0;
    printf("Enter the number to add: ");
    scanf("%d", &sum);

    for (int i = 0; i < n; i++) {
        a[i] += sum;
    }
}

void subtract() {
    int sub = 0;
    printf("Enter the number to subtract: ");
    scanf("%d", &sub);

    for (int i = 0; i < n; i++) {
        a[i] -= sub;
    }
}

void multiply() {
    int mul = 0;
    printf("Enter the number to multiply: ");
    scanf("%d", &mul);

    for (int i = 0; i < n; i++) {
        a[i] *= mul;
    }
}

void divide() {
    int div = 0, rem = 0;
    printf("Enter the number to divide: ");
    scanf("%d", &div);

    for (int i = 0; i < n; i++) {
        rem = a[i] % div;
        a[i] /= div;
    }

    printf("The remainder is %d\n", rem);
}

void main() {
    input();
    display();

    int choice;
    printf("Enter your choice:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            add();
            break;
        case 2:
            subtract();
            break;
        case 3:
            multiply();
            break;
        case 4:
            divide();
            break;
        default:
            printf("Invalid choice\n");
    }

    display();
}