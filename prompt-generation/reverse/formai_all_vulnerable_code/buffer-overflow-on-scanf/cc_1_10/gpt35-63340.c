//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: surprised
#include<stdio.h>
#include<ctype.h>

void generateASCII(char inputChar) {
    printf("   ");
    for(int i=0;i<5;i++) {
        if(inputChar == ' ') {
            printf("    ");
            continue;
        }
        printf(" _ ");
    }
    printf("\n");
    printf("  ");
    for(int i=0;i<5;i++) {
        if(inputChar == ' ') {
            printf("   | ");
            continue;
        }
        printf("|_|");
    }
    printf("|\n");
    printf("  ");
    for(int i=0;i<5;i++) {
        if(inputChar == ' ') {
            printf("   | ");
            continue;
        }
        printf("|_|");
    }
    printf("|\n");
    printf("  ");
    for(int i=0;i<5;i++) {
        if(inputChar == ' ') {
            printf("    ");
            continue;
        }
        printf("| |");
    }
    printf("|\n");
    printf("  ");
    for(int i=0;i<5;i++) {
        if(inputChar == ' ') {
            printf("   | ");
            continue;
        }
        printf("|_|");
    }
    printf("|\n");
    printf("\n");
}

int main() {
    char inputString[1024];
    printf("Enter a string to convert to ASCII art:\n");
    scanf("%[^\n]", inputString);
    for(int i=0;inputString[i]!='\0';i++) {
        char currChar = tolower(inputString[i]);
        if(currChar < 'a' || currChar > 'z') {
            currChar = ' ';
        }
        generateASCII(currChar);
    }
    return 0;
}