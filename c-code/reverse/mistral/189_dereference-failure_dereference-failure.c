#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ALIEN_WORD 100
#define MAX_ENGLISH_WORD 20

void translate(char *alien, char *english) {
    int alien_len = strlen(alien);
    int english_len = strlen(english);
    int alien_map[26] = {0};
    int english_map[26] = {0};

    for (int i = 0; i < english_len; ++i)
        english_map[(int)tolower(english[i]) - 'a']++;

    for (int i = 0; i < alien_len; ++i) {
        char c = alien[i];
        if (isalpha(c)) {
            int index = tolower(c) - 'a';
            if (alien_map[index] == 0)
                alien_map[index] = i;
        }
    }

    for (int i = 0; i < english_len; ++i) {
        char c = english[i];
        if (isalpha(c)) {
            int index = tolower(c) - 'a';
            if (alien_map[index] != 0)
                printf("%c", alien[alien_map[index]]);
            else
                printf("%c", '_');
        } else
            printf("%c", c);
    }
}

int main() {
    char alien[MAX_ALIEN_WORD];
    char english[MAX_ENGLISH_WORD];

    scanf("%s", alien);
    scanf("%s", english);

    translate(alien, english);

    return 0;
}
