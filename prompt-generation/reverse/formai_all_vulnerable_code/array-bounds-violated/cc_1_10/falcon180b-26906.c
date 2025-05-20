//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000
#define ALIEN_WORDS 10

struct Word {
    char english[MAX_LEN];
    char alien[MAX_LEN];
};

void translate(char *text) {
    FILE *fp;
    char ch;
    int i = 0;
    struct Word words[ALIEN_WORDS];

    fp = fopen("alien_words.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            words[i].english[0] = ch;
            words[i].english[1] = '\0';
            words[i].alien[0] = ch + 5;
            words[i].alien[1] = '\0';
            i++;
        }
    }

    fclose(fp);

    while ((ch = getchar())!= EOF) {
        if (isalpha(ch)) {
            int j;
            for (j = 0; j < i; j++) {
                if (tolower(ch) == tolower(words[j].english[0])) {
                    printf("%s ", words[j].alien);
                    break;
                }
            }
        } else {
            printf("%c", ch);
        }
    }
}

int main() {
    char text[MAX_LEN];

    printf("Enter the text to translate:\n");
    fgets(text, MAX_LEN, stdin);

    translate(text);

    return 0;
}