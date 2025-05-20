//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

char words[MAX_WORDS][MAX_WORD_LEN];
char buffer[MAX_WORD_LEN];
int idx = 0;

void generate_words() {
    FILE* fp = fopen("/usr/share/dict/words", "r");
    for (int i = 0; i < MAX_WORDS; i++) {
        fscanf(fp, "%s", words[i]);
    }
    fclose(fp);
}

void print_words() {
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("%s ", words[i]);
    }
}

double get_typing_speed(time_t start, time_t end, int chars_typed) {
    double time_diff = difftime(end, start);
    double minutes = time_diff / 60.0;
    return chars_typed / (minutes * 5.0);
}

int main() {
    generate_words();
    time_t start_time = time(NULL);
    int chars_typed = 0;
    printf("Type the following words:\n");
    while (idx < MAX_WORDS) {
        printf("%s ", words[idx]);
        fflush(stdout);
        scanf("%s", buffer);
        chars_typed += strlen(buffer);
        if (strcasecmp(buffer, words[idx]) != 0) {
            printf("\nIncorrect! Type the word again:\n");
            fflush(stdout);
            scanf("%s", buffer);
            chars_typed += strlen(buffer);
        }
        idx++;
    }

    time_t end_time = time(NULL);
    double typing_speed = get_typing_speed(start_time, end_time, chars_typed);
    printf("\n\nTotal characters typed: %d\n", chars_typed);
    printf("Typing speed: %.2f WPM\n", typing_speed);

    return 0;
}