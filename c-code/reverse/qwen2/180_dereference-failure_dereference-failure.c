#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

char* translateAlienToEnglish(const char* alienString) {
    int length = 0;
    while (alienString[length] != '\0') {
        length++;
    }
    
    char* englishString = (char*)malloc((length + 1) * sizeof(char));
    if (englishString == NULL) {
        return NULL; // Memory allocation failed
    }

    int i = 0;
    while (alienString[i] != '\0') {
        if (alienString[i] == 'A') {
            englishString[i] = 'a';
        } else if (alienString[i] == 'B') {
            englishString[i] = 'b';
        } else if (alienString[i] == 'C') {
            englishString[i] = 'c';
        } else {
            englishString[i] = '?'; // Unknown character
        }
        i++;
    }
    englishString[i] = '\0';

    return englishString;
}

int main() {
    const char* alienString = "ABC";
    char* englishString = translateAlienToEnglish(alienString);
    if (englishString != NULL) {
        printf("Translated: %s\n", englishString);
        free(englishString);
    } else {
        printf("Memory allocation failed.\n");
    }
    return 0;
}
