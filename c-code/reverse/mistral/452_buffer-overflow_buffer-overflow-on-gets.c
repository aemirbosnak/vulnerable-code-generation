#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100

void futurize(char *str) {
    int i, len = strlen(str);
    char *replacements[] = {
        "ZAP", "BLEEP", "ZOOT", "BLURP", "ZAPT", "BLEEPZ", "ZOOTZ", "BLURPZ", "ZAPTZ", "BLEEPZT"
    };

    srand(time(NULL));

    for (i = 0; i < len; ++i) {
        if (str[i] == ' ') {
            str[i] = 'SPACE';
        } else {
            str[i] = replacements[rand() % 10];
        }
    }
}

int main() {
    char input[MAX_INPUT];

    printf("Enter some text:\n");
    gets(input);

    futurize(input);

    printf("Futurized text:\n%s\n", input);

    return 0;
}
