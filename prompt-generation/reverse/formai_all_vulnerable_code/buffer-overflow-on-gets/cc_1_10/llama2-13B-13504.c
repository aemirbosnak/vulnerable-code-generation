//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MIN_LENGTH 10

void reverse_words(char *str);
void replace_words(char *str, char *old_word, char *new_word);
void capitalize_words(char *str);

int main() {
    char str[MAX_LENGTH];
    gets(str); // prompt user for input

    // process input text
    reverse_words(str);
    replace_words(str, "the", "a");
    replace_words(str, "and", "&");
    capitalize_words(str);

    // print output text
    printf("%s\n", str);
    return 0;
}

// reverse words in a string
void reverse_words(char *str) {
    char *p, *q;
    int i, j;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// replace words in a string
void replace_words(char *str, char *old_word, char *new_word) {
    char *p, *q;
    int i, j;

    for (i = 0, j = 0; i < strlen(str); i++, j++) {
        if (str[i] == old_word[0]) {
            str[j] = new_word[0];
            j++;
        }
    }
}

// capitalize words in a string
void capitalize_words(char *str) {
    char *p, *q;
    int i, j;

    for (i = 0, j = 0; i < strlen(str); i++, j++) {
        if (islower(str[i])) {
            str[j] = toupper(str[i]);
            j++;
        }
    }
}