//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: artistic
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define MAX_SENTENCE_LEN 80

int main() {
    char word[MAX_WORD_LEN];
    char sentence[MAX_SENTENCE_LEN];
    char correct[MAX_SENTENCE_LEN];
    int word_len, sentence_len, i, j, k;
    char *p;

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LEN, stdin);
    sentence_len = strlen(sentence);

    // remove newline character from the end of the sentence
    sentence[sentence_len - 1] = '\0';

    for (i = 0; i < sentence_len; i++) {
        if (sentence[i] == ' ') {
            continue;
        }

        word_len = 0;
        while (sentence[i + word_len] != ' ' && sentence[i + word_len] != '\0') {
            word_len++;
        }

        strncpy(word, sentence + i, word_len);
        word[word_len] = '\0';

        p = correct;
        for (j = 0; j < word_len; j++) {
            if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u') {
                *p++ = word[j];
            }
        }
        *p = '\0';

        if (strcmp(word, correct) != 0) {
            printf("Misspelled word: %s\n", word);
        }

        i += word_len - 1;
    }

    return 0;
}