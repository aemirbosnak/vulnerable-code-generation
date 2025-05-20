//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: brave
#include <stdio.h>

void printA() {
    printf("      /\\       \n");
    printf("     /  \\      \n");
    printf("    /____\\     \n");
    printf("   /      \\    \n");
    printf("  /        \\   \n");
    printf(" /          \\  \n");
}

void printR() {
    printf(" ____       \n");
    printf("|    \\      \n");
    printf("|     \\     \n");
    printf("|_____/     \n");
    printf("| \\         \n");
    printf("|  \\        \n");
    printf("|   \\       \n");
}

void printT() {
    printf(" _______     \n");
    printf("|       |    \n");
    printf("|       |    \n");
    printf("|_______|    \n");
    printf("    |    \n");
    printf("    |    \n");
    printf("    |    \n");
}

int main() {
    char input[100];
    printf("Enter a three-letter word: ");
    scanf("%s", input);

    if (strlen(input) != 3) {
        printf("Invalid input!\n");
        return 0;
    }

    // Print ASCII art for each letter
    printf("\n\n");
    printA();
    printf("\n\n");
    printR();
    printf("\n\n");
    printT();
    printf("\n\n");

    // Print ASCII art for the input word
    for (int i = 0; i < 3; i++) {
        if (input[i] == 'A') {
            printA();
        } else if (input[i] == 'R') {
            printR();
        } else if (input[i] == 'T') {
            printT();
        } else {
            printf("Invalid input character!\n");
            return 0;
        }
    }

    return 0;
}