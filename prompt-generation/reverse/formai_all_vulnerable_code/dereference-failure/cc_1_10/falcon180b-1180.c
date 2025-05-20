//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_WORD_LEN 20

struct word {
    char str[MAX_STR_LEN];
    int len;
    int pos;
};

void print_word(struct word *word) {
    int i;
    for (i = 0; i < word->len; i++) {
        printf("%c", word->str[i]);
    }
}

void delete_word(struct word *word, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("\b \b");
    }
}

int main() {
    char str[MAX_STR_LEN];
    int len;
    int pos = 0;
    int speed = 0;
    int start_time, end_time;
    struct word word;
    char input_str[MAX_STR_LEN];

    printf("Enter a string: ");
    fgets(str, MAX_STR_LEN, stdin);

    len = strlen(str);
    printf("String length: %d\n", len);

    srand(time(NULL));
    int rand_pos = rand() % len;
    strncpy(word.str, str + rand_pos, MAX_WORD_LEN);
    word.len = strlen(word.str);
    word.pos = rand_pos;

    printf("Type the following word: ");
    for (int i = 0; i < word.len; i++) {
        printf("%c", tolower(word.str[i]));
    }
    printf("\n");

    start_time = clock();
    while (pos < len) {
        char ch;
        scanf("%c", &ch);

        if (tolower(ch) == tolower(word.str[word.pos])) {
            word.pos++;
        } else {
            delete_word(&word, word.pos);
            word.pos = 0;
        }

        pos++;
        speed = (pos - word.pos) * 60 / (clock() - start_time + 1e-9);
        printf("Speed: %d wpm\n", speed);
    }

    printf("Congratulations! You have finished the test.\n");
    printf("Your typing speed is %d wpm.\n", speed);

    return 0;
}