//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: recursive
/*
 * C Spell Checker Recursive Program
 */

#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 100

int is_valid_word(char *word);
int is_in_dict(char *word);

int main() {
    char word[MAX_WORD_LEN];
    int word_count = 0;

    while (1) {
        printf("Enter a word: ");
        scanf("%s", word);

        if (strcmp(word, "quit") == 0) {
            break;
        }

        if (is_valid_word(word)) {
            if (is_in_dict(word)) {
                printf("Valid word: %s\n", word);
            } else {
                printf("Invalid word: %s\n", word);
            }
        } else {
            printf("Invalid word: %s\n", word);
        }

        word_count++;
    }

    printf("Total words: %d\n", word_count);

    return 0;
}

int is_valid_word(char *word) {
    int i;

    for (i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }

    return 1;
}

int is_in_dict(char *word) {
    int i;
    char *dict[] = {
        "apple",
        "banana",
        "orange",
        "mango",
        "pineapple",
        "strawberry",
        "pear",
        "peach",
        "cherry",
        "lemon",
        "lime",
        "grape",
        "watermelon",
        "kiwi",
        "blueberry",
        "raspberry",
        "blackberry",
        "apricot",
        "lychee",
        "durian",
        "starfruit",
        "pomegranate",
        "honeydew",
        "pomelo",
        "passionfruit",
        "date",
        "prune",
        "raisin",
        "currant",
        "barberry",
        "gooseberry",
        "boysenberry",
        "loganberry",
        "rambutan",
        "soursop",
        "custardapple",
        "pomegranate",
        "jackfruit",
        "aroma",
        "chewinggum",
        "chewingtobacco",
        "snuff",
        "snuffbox",
        "chewingstick",
        "chewinggum",
        "chewingtobacco",
        "snuff",
        "snuffbox",
        "chewingstick",
    };

    for (i = 0; i < sizeof(dict) / sizeof(dict[0]); i++) {
        if (strcmp(word, dict[i]) == 0) {
            return 1;
        }
    }

    return 0;
}