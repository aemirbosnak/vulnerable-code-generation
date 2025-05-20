#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* alienTranslate(char* alien) {
    char* english = (char*)malloc(strlen(alien) * sizeof(char));
    int i;

    for (i = 0; alien[i]; i++) {
        switch (alien[i]) {
            case 'g':
                english[i] = 's';
                break;
            case 's':
                english[i] = 'g';
                break;
            case 'r':
                english[i] = 'l';
                break;
            case 'l':
                english[i] = 'r';
                break;
            case 'z':
                english[i] = 'd';
                break;
            case 'd':
                english[i] = 'z';
                break;
            default:
                english[i] = alien[i];
                break;
        }
    }

    printf("%s\n", english);
    free(english);
    return english;
}

int main() {
    char alien[] = "gsrz";
    alienTranslate(alien);
    return 0;
}
