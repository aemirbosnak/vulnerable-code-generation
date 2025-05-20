//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: recursive
#include <stdio.h>

void drawLetterA(char c){
    int i, j;
    for(i=1;i<=5;i++){
        for(j=1;j<=5;j++){
            if((j==1 || j==5 || i==1 || i==3) && !(j==3 && i==2)){
                printf("%c", c);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void drawLetterB(char c) {
    int i, j;
    for (i = 0; i <= 4; i++) {
        for (j = 0; j <= 4; j++) {
            if ((j == 0 || (i == 0 || i == 2 || i == 4) && j != 4 || j == 4 && (i == 1 || i == 3))) {
                printf("%c", c);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void drawLetterC(char c) {
    int i, j;
    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= 5; j++) {
            if ((j == 1 && i != 1 && i != 5) || (j == 5 && i != 1 && i != 5) || (i == 1 && j != 1 && j != 5) || (i == 5 && j != 1 && j != 5)) {
                printf("%c", c);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void drawLetter(char c){
    switch (c) {
        case 'A':
        case 'a':
            drawLetterA(c);
            break;
        case 'B':
        case 'b':
            drawLetterB(c);
            break;
        case 'C':
        case 'c':
            drawLetterC(c);
            break;
        default:
            printf("Unknown letter");
            break;
    }
}

int main() {
    char c;
    printf("Enter a letter (A, B or C): ");
    scanf("%c", &c);
    drawLetter(c);
    return 0;
}