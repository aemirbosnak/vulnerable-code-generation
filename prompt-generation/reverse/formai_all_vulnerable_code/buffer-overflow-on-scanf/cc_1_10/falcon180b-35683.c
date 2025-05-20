//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 10

struct word {
    char word[MAX_WORD_LEN];
    int length;
};

struct word words[MAX_WORDS];
int num_words = 0;

void add_word(char *word) {
    if (num_words >= MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        return;
    }

    int length = strlen(word);
    if (length > MAX_WORD_LEN) {
        printf("Error: Word is too long.\n");
        return;
    }

    strcpy(words[num_words].word, word);
    words[num_words].length = length;
    num_words++;
}

void generate_sentence(int length) {
    if (num_words == 0) {
        printf("Error: No words to generate sentence.\n");
        return;
    }

    char sentence[length + 1];
    sentence[0] = '\0';

    int i = rand() % num_words;
    strcat(sentence, words[i].word);

    for (int j = 1; j < length - words[i].length; j++) {
        i = rand() % num_words;
        strcat(sentence, " ");
        strcat(sentence, words[i].word);
    }

    printf("%s\n", sentence);
}

int main() {
    srand(time(NULL));

    char word[MAX_WORD_LEN];
    while (1) {
        printf("Enter a word (or press enter to finish): ");
        scanf("%s", word);

        if (word[0] == '\0') {
            break;
        }

        add_word(word);
    }

    int choice;
    do {
        printf("\n1. Typing Test\n2. Generate Sentence\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("clear");
                printf("Typing Test\n");
                for (int i = 0; i < num_words; i++) {
                    printf("%s\n", words[i].word);
                    sleep(1);
                }
                break;

            case 2:
                printf("Enter sentence length: ");
                int length;
                scanf("%d", &length);
                generate_sentence(length);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}