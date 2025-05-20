//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: random
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    printf("Enter a sentence in C Alien Language: ");
    scanf("%[^\n]", sentence);

    char words[20][20];
    int i = 0, j = 0, k = 0;
    for (i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == ' ') {
            words[j][k] = '\0';
            j++;
            k = 0;
        } else {
            words[j][k] = sentence[i];
            k++;
        }
    }
    words[j][k] = '\0';

    char translated[20][20];
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int is_vowel = 0, length = 0;
    for (i = 0; i <= j; i++) {
        length = strlen(words[i]);
        for (k = 0; k < length; k++) {
            is_vowel = 0;
            for (int l = 0; l < 5; l++) {
                if (words[i][k] == vowels[l]) {
                    is_vowel = 1;
                    break;
                }
            }
            if (is_vowel == 1) {
                translated[i][k] = words[i][k];
            } else if (words[i][k] == 'g') {
                translated[i][k] = 'c';
            } else if (words[i][k] == 'h') {
                translated[i][k] = 'd';
            } else if (words[i][k] == 'k') {
                translated[i][k] = 'f';
            } else if (words[i][k] == 'z') {
                translated[i][k] = 'x';
            } else {
                translated[i][k] = words[i][k] + 3;
            }
        }
        translated[i][k] = '\0';
    }

    printf("\nTranslated sentence: ");
    for (i = 0; i <= j; i++) {
        printf("%s ", translated[i]);
    }

    return 0;
}