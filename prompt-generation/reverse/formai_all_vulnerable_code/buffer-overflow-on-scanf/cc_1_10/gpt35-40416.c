//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: high level of detail
#include <stdio.h>
#include <string.h>

// Function to convert C Alien Language to English
void convertToEnglish(char word[]) {
    char c;
    for (int i = 0; word[i] != '\0'; i++) {
        c = word[i];
        switch (c) {
            case 'A':
                printf("An ");
                break;
            case 'B':
                printf("alien ");
                break;
            case 'C':
                printf("language ");
                break;
            case 'D':
                printf("translator ");
                break;
            case 'E':
                printf("is ");
                break;
            case 'F':
                printf("needed ");
                break;
            case 'G':
                printf("to ");
                break;
            case 'H':
                printf("communicate ");
                break;
            case 'I':
                printf("with ");
                break;
            case 'J':
                printf("extraterrestrial ");
                break;
            case 'K':
                printf("lifeforms.");
                break;
            default:
                printf("%c", c);
        }
    }
    printf("\n");
}

int main() {
    char alienWord[100];
    printf("Enter a C Alien Language word: ");
    scanf("%s", alienWord);

    printf("\nEnglish equivalent: ");
    convertToEnglish(alienWord);

    return 0;
}