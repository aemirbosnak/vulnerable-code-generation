//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printIntro() {
    printf("Welcome to the Star Factory!\n");
    printf("We're here to print some amusing star patterns.\n");
    printf("Just sit back, relax, and watch the universe unfold!\n");
}

void printTriangle(int n) {
    printf("\nHere's a Triangle for you!\n");

    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
        sleep(1); // So you'll get time to laugh!
    }
}

void printPyramid(int n) {
    printf("\nBehold! A majestic Pyramid!\n");

    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
        sleep(1);
    }
}

void printDiamond(int n) {
    printf("\nWatch out! A sparkling Diamond!\n");

    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
        sleep(1);
    }
    
    for (int i = n-1; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
        sleep(1);
    }
}

void starExtravaganza() {
    int choice;
    printf("\nPick a pattern to print:\n");
    printf("1. Triangle\n");
    printf("2. Pyramid\n");
    printf("3. Diamond\n");
    printf("Enter your choice (1-3): ");
    
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printTriangle(5);
            break;
        case 2:
            printPyramid(5);
            break;
        case 3:
            printDiamond(5);
            break;
        default:
            printf("Oops! That's not a valid choice. Our stars are confused now!\n");
    }
}

void printGoodbye() {
    printf("\nThank you for visiting the Star Factory!\n");
    printf("Remember, stars are like dreams; you have to reach for them!\n");
    printf("Keep shining!\n");
}

int main() {
    printIntro();
    starExtravaganza();
    printGoodbye();
    return 0;
}