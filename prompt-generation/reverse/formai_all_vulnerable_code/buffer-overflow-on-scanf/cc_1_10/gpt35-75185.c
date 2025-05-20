//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: peaceful
#include <stdio.h>

void printA() {
    printf("   /\\   \n");
    printf("  /  \\  \n");
    printf(" /    \\ \n");
    printf("/______\\\n");
    printf("|      |\n");
}

void printB() {
    printf(" _____ \n");
    printf("|     \\\n");
    printf("|_____ \\\n");
    printf("|     \\\n");
    printf("|_____/\n");
}

void printC() {
    printf("  ____ \n");
    printf(" / ___|\n");
    printf("| |    \n");
    printf("| |___ \n");
    printf(" \\____|\n");
}

void printD() {
    printf(" _____ \n");
    printf("|     \\\n");
    printf("|     |\n");
    printf("|_____/ \n");
}

int main() {
    char text[100];
    printf("Enter some text: ");
    scanf("%[^\n]s", text);

    int length = strlen(text);

    for (int i = 0; i < length; i++) {
        char c = toupper(text[i]);

        switch (c) {
            case 'A':
                printA();
                break;
            case 'B':
                printB();
                break;
            case 'C':
                printC();
                break;
            case 'D':
                printD();
                break;
            default:
                printf("   /\n");
                printf("  /  \n");
                printf(" /    \n");
                printf("/______\n");
                printf("|      |\n");
                break;
        }
    }

    return 0;
}