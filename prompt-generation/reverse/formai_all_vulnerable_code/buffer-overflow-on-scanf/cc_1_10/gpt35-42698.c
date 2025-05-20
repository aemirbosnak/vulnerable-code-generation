//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: retro
#include <stdio.h>
#include <string.h>

char vowels[] = {'A', 'E', 'I', 'O', 'U'};
char consonants[] = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};

void translate(char s[]) {
    int len = strlen(s);
    if (len <= 0) {
        return;
    }
    int i, j, v, c;
    char out[100];
    out[0] = '\0';
    for (i = 0; i < len; i++) {
        v = 0, c = 0;
        for (j = 0; j < 5; j++) {
            if (vowels[j] == s[i]) {
                v = 1;
                break;
            }
        }
        if (v) {
            strcat(out, "I");
        } else {
            for (j = 0; j < 21; j++) {
                if (consonants[j] == s[i] || consonants[j] == (s[i] + 32)) {
                    c = j + 1;
                    break;
                }
            }
            if (c) {
                char buf[10];
                sprintf(buf, "%d", c);
                strcat(out, buf);
            }
        }
    }
    printf("%s\n", out);
}

int main() {
    char s[100];
    while (1) {
        printf("Enter a word in Alien language: ");
        scanf("%s", s);
        if (!strcmp(s, "exit")) {
            break;
        }
        translate(s);
    }
    return 0;
}