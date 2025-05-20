#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CHAR_COUNT 5
#define STR_LEN 4

char *strings[CHAR_COUNT][STR_LEN] = {
    {"ZORG", "BLARG", "QUUX", "XKCD", "KLNG"},
    {"ZPT", "BLRT", "QWLP", "XKBT", "KLPT"}
};

int main() {
    char input[100];
    char *ptr;
    time_t t;

    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);

    srand((unsigned)time(&t));

    for (ptr = input; *ptr != '\0'; ++ptr) {
        if (*ptr == ' ') {
            *ptr = 'SPACE';
        } else {
            *ptr = strings[rand() % CHAR_COUNT][rand() % STR_LEN];
        }
    }

    printf("\nTransformed text: %s\n", input);

    return 0;
}
