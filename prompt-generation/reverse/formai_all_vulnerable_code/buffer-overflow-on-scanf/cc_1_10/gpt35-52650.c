//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: peaceful
#include<stdio.h>
#include<string.h>

#define MAX_LEN 1000

void drawStar(int n);
void drawHeart();
void drawMusic();
void drawFlower();

int main() {
    char text[MAX_LEN];
    int choice;

    printf("Please enter some text to convert to ASCII art: ");
    fgets(text, MAX_LEN, stdin);

    printf("Please select an option to convert text to ASCII art:\n");
    printf("1. Star\n");
    printf("2. Heart\n");
    printf("3. Music\n");
    printf("4. Flower\n");

    printf("Option: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            drawStar(strlen(text));
            break;
        case 2:
            drawHeart();
            break;
        case 3:
            drawMusic();
            break;
        case 4:
            drawFlower();
            break;
        default:
            printf("Invalid option!\n");
    }

    return 0;
}

void drawStar(int n) {
    int i, j;

    for(i=0; i<n; i++) {
        for(j=0; j<=i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    for(i=0; i<n; i++) {
        for(j=n; j>i; j--) {
            printf("* ");
        }
        printf("\n");
    }
}

void drawHeart() {
    printf("   ♥♥   \n");
    printf(" ♥♥♥♥♥♥ \n");
    printf("♥♥♥♥♥♥♥♥♥\n");
    printf(" ♥♥♥♥♥♥ \n");
    printf("   ♥♥   \n");
}

void drawMusic() {
    printf("♫ ♪ ♫ ♪ ♫ ♪ ♫ ♪ ♫\n");
    printf("  ♫ ♪  MUSIC  ♪ ♫\n");
    printf("♫ ♪ ♫ ♪ ♫ ♪ ♫ ♪ ♫\n");
}

void drawFlower() {
    printf("     /\\ \n");
    printf("    /  \\    /\\ \n");
    printf("   /    \\  /  \\ \n");
    printf("  /      \\/    \\ \n");
    printf(" /              \\ \n");
    printf("/                \\ \n");
    printf("         ♥        \n");
    printf("         ♥        \n");
    printf("         ♥        \n");
}