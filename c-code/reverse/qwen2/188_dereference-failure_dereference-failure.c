#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

char* translate(const char* alien) {
    int len = 0;
    while (alien[len] != '\0') len++;
    char* english = malloc(len * sizeof(char));
    if (!english) return NULL;
    for (int i = 0; i < len; i++) {
        switch (alien[i]) {
            case 'A': english[i] = 'a'; break;
            case 'B': english[i] = 'b'; break;
            case 'C': english[i] = 'c'; break;
            default: english[i] = '?'; break;
        }
    }
    return english;
}

int main() {
    const char* alien = "ABC";
    char* english = translate(alien);
    if (english) {
        printf("%s\n", english);
        free(english);
    } else {
        printf("Memory allocation failed.\n");
    }
    return 0;
}
