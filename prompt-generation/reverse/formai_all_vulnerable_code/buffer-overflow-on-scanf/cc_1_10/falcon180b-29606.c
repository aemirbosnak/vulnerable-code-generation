//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000 // maximum number of words in the ebook
#define MAX_WORD_LENGTH 50 // maximum length of a word

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int main() {
    FILE *ebook;
    char filename[100];
    char line[100];
    char word[MAX_WORD_LENGTH];
    int word_length;
    char ch;
    int i, j;
    WordFrequency words[MAX_WORDS];
    int num_words = 0;

    // get ebook filename from user
    printf("Enter ebook filename: ");
    scanf("%s", filename);

    // open ebook file
    ebook = fopen(filename, "r");
    if (ebook == NULL) {
        printf("Error: could not open ebook file.\n");
        exit(1);
    }

    // read ebook line by line
    while (fgets(line, sizeof(line), ebook)!= NULL) {
        word_length = 0;
        while ((ch = line[word_length])!= '\0') {
            // skip non-alphabetic characters
            if (!isalpha(ch)) {
                word_length++;
                continue;
            }
            // check if word is already in the word frequency array
            for (i = 0; i < num_words; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    // word already exists, increase frequency
                    words[i].frequency++;
                    break;
                }
            }
            // word not found, add it to the array
            if (i == num_words) {
                strcpy(words[num_words].word, word);
                words[num_words].frequency = 1;
                num_words++;
            }
            // move to next character in line
            word_length++;
        }
    }

    // close ebook file
    fclose(ebook);

    // print word frequency table
    printf("Word frequency table:\n");
    for (i = 0; i < num_words; i++) {
        printf("%-20s %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}