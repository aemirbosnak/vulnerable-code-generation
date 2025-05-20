//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 100

void reverse_str(char *str);
void reverse_words(char *str);

int main() {
    char str[MAX_STR_LEN];
    gets(str); // input string from user

    // reverse the string
    reverse_str(str);

    // reverse the words in the string
    reverse_words(str);

    printf("Original string: %s\n", str);
    printf("Reversed string: %s\n", str);
    printf("Reversed words: %s\n", str);

    return 0;
}

void reverse_str(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void reverse_words(char *str) {
    int i, j, word_start, word_end;
    char word[MAX_STR_LEN];

    for (i = 0, word_start = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            word_end = i;
            while (!isalpha(str[word_end - 1])) {
                word_end--;
            }
            strcpy(word, &str[word_start]);
            word[word_end - word_start] = 0;
            reverse_str(word);
            printf("%s ", word);
            word_start = word_end + 1;
        }
    }
}