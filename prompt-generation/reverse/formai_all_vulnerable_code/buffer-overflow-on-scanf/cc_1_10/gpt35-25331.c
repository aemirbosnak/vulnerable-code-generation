//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: shocked
#include <stdio.h>

/*
This program generates ASCII art from user inputted text. The art is displayed
in a shocked style.
*/ 

// Function to generate top section of art
void topSection(char text) {
    for(int i = 0; i < 9; i++) {
        if(i == 0)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text);
        else if(i == 1)
            printf("%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c\n", text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text);
        else if(i == 2 || i == 4 || i == 6 || i == 8)
            printf("%c%c%c%c%c%c%c  %c%c%c%c%c%c %c%c%c%c%c%c%c\n", text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text);
        else if(i == 3)
            printf("%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c\n", text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text);
        else if(i == 5)
            printf("%c%c%c%c%c%c%c %c%c%c %c%c%c %c%c%c%c%c%c%c\n", text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text);
        else
            printf("%c%c%c%c%c%c%c  %c%c%c%c%c%c %c%c%c%c%c%c%c\n", text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text);
    }
}

// Function to generate middle section of art
void middleSection(char text) {
    for(int i = 0; i < 3; i++) {
        if(i == 0)
            printf("         %c%c%c%c%c%c%c\n", text, text, text, text, text, text, text);
        else if(i == 1)
            printf("%c%c%c%c%c%c%c     %c%c\n", text, text, text, text, text, text, text, text, text);
        else
            printf("%c%c%c%c%c%c%c   %c%c%c%c%c%c%c   %c%c%c\n", text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text);
    }
}

// Function to generate bottom section of art
void bottomSection(char text) {
    for(int i = 0; i < 9; i++) {
        if(i == 0 || i == 8)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text);
        else if(i == 1 || i == 7)
            printf("%c%c%c%c%c%c%c  %c%c%c%c%c%c %c%c%c%c%c%c%c\n", text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text);
        else if(i == 2 || i == 6)
            printf("%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c\n", text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text);
        else if(i == 3)
            printf("%c%c%c%c%c%c%c %c%c%c %c%c%c %c%c%c%c%c%c%c\n", text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text);
        else
            printf("%c%c%c%c%c%c%c  %c%c%c%c%c%c %c%c%c%c%c%c%c\n", text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text, text);
    }
}

int main() {
    char input[20];
    printf("Enter text to generate ASCII art: ");
    scanf("%s", input);
    printf("\n");
    char text = input[0];
    topSection(text);
    middleSection(text);
    bottomSection(text);
    return 0;
}