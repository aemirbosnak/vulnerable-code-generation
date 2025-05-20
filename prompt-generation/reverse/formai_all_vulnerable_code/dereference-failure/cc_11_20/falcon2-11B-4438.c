//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000
#define MAX_SENTENCES 10

int main() {
    char text[MAX_LEN];
    char sentence[MAX_LEN];
    char words[MAX_LEN][MAX_LEN];
    char summary[MAX_LEN];

    printf("Enter a text:\n");
    fgets(text, MAX_LEN, stdin);

    int num_sentences = 0;
    int i = 0;
    while (text[i]!= '\0' && text[i]!= '\n') {
        sentence[i] = text[i];
        i++;
    }
    sentence[i] = '\0';
    num_sentences++;

    while (fgets(text, MAX_LEN, stdin)!= NULL && text[0]!= '\n') {
        i = 0;
        while (text[i]!= '\0' && text[i]!= '\n') {
            words[num_sentences][i] = text[i];
            i++;
        }
        words[num_sentences][i] = '\0';
        num_sentences++;
    }

    int num_words = 0;
    for (int i = 0; i < num_sentences; i++) {
        int j = 0;
        while (words[i][j]!= '\0') {
            if (j!= 0 && strcmp(words[i], words[i-1]) == 0) {
                continue;
            }
            summary[num_words] = words[i][j];
            num_words++;
            j++;
        }
        if (num_words == MAX_LEN) {
            break;
        }
    }

    summary[num_words] = '\0';
    printf("Summary: %s\n", summary);

    return 0;
}