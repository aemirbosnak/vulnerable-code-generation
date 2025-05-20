//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_CHARS 20

char words[MAX_WORDS][MAX_CHARS];
int word_count;
double speed;

void load_words() {
    FILE *file;
    char word[MAX_CHARS];
    int i = 0;

    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open words.txt\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[i], word);
        i++;
    }

    fclose(file);
    word_count = i;
}

void start_test() {
    int i;
    char input[MAX_CHARS];
    time_t start, end;

    printf("Type the words as fast as you can!\n");
    for (i = 0; i < word_count; i++) {
        printf("%s ", words[i]);
        fgets(input, MAX_CHARS, stdin);
    }

    time(&start);
    while (fgetc(stdin)!= '\n');
    time(&end);

    speed = (double)word_count / (end - start);
    printf("Your typing speed is: %.2lf words per second\n", speed);
}

int main() {
    load_words();
    start_test();

    return 0;
}