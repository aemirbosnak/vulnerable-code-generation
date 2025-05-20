//FormAI DATASET v1.0 Category: Pattern printing ; Style: recursive
#include <stdio.h>

void printUpperLeft(int n);
void printUpperRight(int n);
void printLowerLeft(int n);
void printLowerRight(int n);

int main() {
    int n;
    printf("Enter the number of rows in the pattern: ");
    scanf("%d", &n);

    printf("The pattern is:\n");
    printUpperLeft(n);
    printf("\n");
    printLowerRight(n);
    printf("\n");
    printUpperRight(n);
    printf("\n");
    printLowerLeft(n);
    printf("\n");

    return 0;
}

void printUpperLeft(int n) {
    if(n > 0) {
        printUpperLeft(n-1);
        for(int i = 0; i < n; i++) {
            printf("*");
        }
        printf("\n");
    }
}

void printUpperRight(int n) {
    if(n > 0) {
        for(int i = 0; i < n-1; i++) {
            printf(" ");
        }
        for(int j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
        printUpperRight(n-1);
    }
}

void printLowerLeft(int n) {
    if(n > 0) {
        for(int i = 0; i < n; i++) {
            printf("*");
        }
        printf("\n");
        printLowerLeft(n-1);
    }
}

void printLowerRight(int n) {
    if(n > 0) {
        for(int i = 0; i < n-1; i++) {
            printf(" ");
        }
        for(int j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
        printLowerRight(n-1);
    }
}