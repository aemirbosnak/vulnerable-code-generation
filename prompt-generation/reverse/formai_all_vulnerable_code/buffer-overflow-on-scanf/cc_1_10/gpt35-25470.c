//FormAI DATASET v1.0 Category: Pattern printing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printTopHalf(int n) {
    int margin = 0;
    for(int i = 1; i <= n/2 + 1; i++) {
        for(int j = n/2 + 1 - margin; j >= 1; j--) {
            printf(" ");
        }
        for(int j = 1; j <= i; j++) {
            printf("*");
        }
        for(int j = 1; j < i; j++) {
            printf("*");
        }
        printf("\n");
        margin++;
    }
}

void printBottomHalf(int n) {
    int margin = n/2 - 1;
    for(int i = n/2; i >= 1; i--) {
        for(int j = 1; j <= margin; j++) {
            printf(" ");
        }
        for(int j = 1; j <= i; j++) {
            printf("*");
        }
        for(int j = 1; j < i; j++) {
            printf("*");
        }
        printf("\n");
        margin--;
    }
}

int main() {
    int n;
    bool validInput = false;
    while(!validInput) {
        printf("Enter an odd integer greater than or equal to 5: ");
        scanf("%d", &n);
        if(n % 2 == 1 && n >= 5) {
            validInput = true;
        } else {
            printf("Invalid input. Please enter an odd integer greater than or equal to 5.\n");
        }
    }

    printTopHalf(n);
    printBottomHalf(n);

    return 0;
}