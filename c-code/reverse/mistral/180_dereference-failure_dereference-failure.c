#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIEN_TO_ENGLISH_LENGTH 256

char* alienTranslation(char* alien) {
    static char english[ALIEN_TO_ENGLISH_LENGTH];

    for (int i = 0; alien[i] != '\0'; ++i) {
        switch (alien[i]) {
            case 'Z':
                english[i] = '4';
                break;
            case 'Q':
                english[i] = 'E';
                break;
            case '2':
                english[i] = 'Z';
                break;
            case 'P':
                english[i] = 'R';
                break;
            case 'E':
                english[i] = '3';
                break;
            case 'S':
                english[i] = '5';
                break;
            case '5':
                english[i] = 'S';
                break;
            default:
                english[i] = alien[i];
                break;
        }
    }

    // Handle the case where the input string is longer than the allocated memory.
    if (strlen(alien) > ALIEN_TO_ENGLISH_LENGTH) {
        english[ALIEN_TO_ENGLISH_LENGTH - 1] = '\0';
    }

    return english;
}

int main() {
    char alien[100];
    printf("Enter an alien language string: ");
    scanf("%s", alien);
    printf("Translation: %s\n", alienTranslation(alien));
    return 0;
}
