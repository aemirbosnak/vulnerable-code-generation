//Code Llama-13B DATASET v1.0 Category: Text processing ; Style: protected
/*
 * C Text processing example program
 * Protected style
 */

#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    char word[20];
    int i, j, k;

    printf("Enter a text: ");
    scanf("%[^\n]", text);

    // Remove punctuation
    for (i = 0; text[i] != '\0'; i++) {
        if (!isalpha(text[i])) {
            text[i] = ' ';
        }
    }

    // Convert to lowercase
    for (i = 0; text[i] != '\0'; i++) {
        text[i] = tolower(text[i]);
    }

    // Tokenize the text
    i = 0;
    j = 0;
    while (text[i] != '\0') {
        if (text[i] == ' ') {
            word[j] = '\0';
            j = 0;
            i++;
        } else {
            word[j] = text[i];
            j++;
            i++;
        }
    }
    word[j] = '\0';

    // Count the frequency of each word
    for (i = 0; i < 20; i++) {
        int count = 0;
        for (j = 0; j < 20; j++) {
            if (word[i] == word[j]) {
                count++;
            }
        }
        printf("%s: %d\n", word[i], count);
    }

    return 0;
}