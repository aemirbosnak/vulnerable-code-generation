#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* alienTranslate(char* alienText) {
    int len = strlen(alienText);
    char* englishText = malloc(len * sizeof(char));
    int i = 0;

    for (; alienText[i] != '\0'; ++i) {
        if (islower(alienText[i])) {
            englishText[i] = toupper(alienText[i]);
        } else if (alienText[i] != '\n') {
            free(englishText);
            return NULL;
        } else {
            englishText[i] = alienText[i];
        }
    }

    englishText[i] = '\0';
    return englishText;
}

int main() {
    char alienText[] = "lorem ipsum dolor sit amet";
    char* englishText = alienTranslate(alienText);

    if (englishText != NULL) {
        printf("%s\n", englishText);
        free(englishText);
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}
