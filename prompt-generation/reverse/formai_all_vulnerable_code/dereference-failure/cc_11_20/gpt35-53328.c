//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: surrealist
#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    // Encoding table
    char *morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    int len = strlen(text);

    printf("\nMorse Code:");
    for(int i=0; i<len; i++) {
        if(text[i] == ' ') {
            printf("   ");
        } else if(text[i] >= 'a' && text[i] <= 'z') {
            int index = text[i] - 'a';
            printf("%s ", morse[index]);

        } else if(text[i] >= 'A' && text[i] <= 'Z') {
            int index = text[i] - 'A';
            printf("%s ", morse[index]);

        } else {
            printf("  ");
        }
    }

    printf("\nSurrealist Code:");
    for(int i=0; i<len; i++) {
        if(text[i] == ' ') {
            printf("        ");
        } else if(text[i] >= 'a' && text[i] <= 'z') {
            int index = text[i] - 'a';
            for(int j=0; j<strlen(morse[index]); j++) {
                if(morse[index][j] == '.') {
                    printf("$");
                } else {
                    printf("&");
                }
            }
            printf(" ");
        } else if(text[i] >= 'A' && text[i] <= 'Z') {
            int index = text[i] - 'A';
            for(int j=0; j<strlen(morse[index]); j++) {
                if(morse[index][j] == '.') {
                    printf("#");
                } else {
                    printf("@");
                }
            }
            printf(" ");
        } else {
            printf("        ");
        }
    }

    return 0;
}