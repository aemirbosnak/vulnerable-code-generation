#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void translateAlienToEnglish(char *alienStr) {
    char *translations[] = {"hello", "world", "yes", "no"};
    char *englishWords[] = {"hi", "planet", "yup", "nah"};

    for (int i = 0; i < strlen(alienStr); i++) {
        if (alienStr[i] >= 'a' && alienStr[i] <= 'z') {
            alienStr[i] -= 32;
        }
    }

    for (int i = 0; i < strlen(alienStr); i += 5) {
        char word[6];
        strncpy(word, &alienStr[i], 5);
        word[5] = '\0';

        for (int j = 0; j < 4; j++) {
            if (strcmp(word, translations[j]) == 0) {
                strcpy(&alienStr[i], englishWords[j]);
                break;
            }
        }
    }
}

int main() {
    char alienStr[] = "HELLO WORLD YES NO";
    translateAlienToEnglish(alienStr);
    printf("%s\n", alienStr);
    return 0;
}
