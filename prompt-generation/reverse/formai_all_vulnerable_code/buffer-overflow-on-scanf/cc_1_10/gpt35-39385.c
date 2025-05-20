//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

void printChar(char c, int size) {
    for(int i=0; i<size; i++) {
        printf("%c", c);
    }
}

void printA(int size) {
    printChar(' ', size/2);
    printf("  ");
    printChar('*', size/2);
    printf("\n");
    printChar(' ', size/2-1);
    printf(" * ");
    printChar(' ', size/2-1);
    printf("\n");
    printChar(' ', size/2-1);
    printf("***");
    printChar(' ', size/2-1);
    printf("\n");
    printChar(' ', size/2-1);
    printf(" * ");
    printChar(' ', size/2-1);
    printf("\n");
    printChar(' ', size/2-1);
    printf(" * ");
    printChar(' ', size/2-1);
    printf("\n");
}

void printB(int size) {
    printChar('*', size/2+1);
    printf("\n");
    printChar('*', size/2+1);
    printf("\n");
    printChar('*', size/2+1);
    printf("\n");
    printChar('*', size/2+1);
    printf("\n");
    printChar('*', size/2+1);
    printf("\n");
}

void printC(int size) {
    printChar(' ', size/2-2);
    printf("*****");
    printf("\n");
    printChar('*', size/2-2);
    printf("\n");
    printChar('*', size/2-2);
    printf("\n");
    printChar('*', size/2-2);
    printf("\n");
    printChar(' ', size/2-2);
    printf("*****");
    printf("\n");
}

void printText(char* text, int size) {
    int textLen = strlen(text);
    for(int i=0; i<5; i++) {
        for(int j=0; j<textLen; j++) {
            if(text[j] == 'A') {
                printA(size);
            } else if (text[j] == 'B') {
                printB(size);
            } else if (text[j] == 'C') {
                printC(size);
            } else {
                printf(" ");
            }
            printChar(' ', size/4);
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter the size (odd number): ");
    scanf("%d", &size);
    char* text = "ABCCBA";
    printText(text, size);

    return 0;
}