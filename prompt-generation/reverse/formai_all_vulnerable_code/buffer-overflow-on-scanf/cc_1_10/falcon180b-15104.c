//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: modular
#include <stdio.h>

#define MAX 10

void pattern1(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void pattern2(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX - i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void pattern3(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX - i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void pattern4(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX - i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX - i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Pattern 1:\n");
    pattern1(n);
    printf("\nPattern 2:\n");
    pattern2(n);
    printf("\nPattern 3:\n");
    pattern3(n);
    printf("\nPattern 4:\n");
    pattern4(n);
    return 0;
}