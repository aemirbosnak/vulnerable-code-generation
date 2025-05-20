#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char* translateToEnglish(char* alienString) {
    if (alienString == NULL) return NULL;

    char* englishString = malloc(strlen(alienString) + 1);
    if (englishString == NULL) return NULL;

    for (int i = 0; alienString[i] != '\0'; i++) {
        englishString[i] = toupper(alienString[i]);
    }
    englishString[strlen(alienString)] = '\0';

    return englishString;
}

int main() {
    char alien[] = "hello world";
    char* english = translateToEnglish(alien);

    if (english != NULL) {
        printf("%s\n", english);
        free(english);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
