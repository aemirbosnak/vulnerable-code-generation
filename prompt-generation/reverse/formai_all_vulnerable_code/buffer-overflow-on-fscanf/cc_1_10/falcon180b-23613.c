//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length, words, correct, incorrect, speed;
    char sentence[500], word[100];
    FILE *fp;
    time_t start, end;

    fp = fopen("sentences.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    srand(time(NULL));
    length = rand() % 500 + 100;
    words = rand() % 10 + 5;
    correct = 0;
    incorrect = 0;

    fprintf(stdout, "Length of sentence: %d words\n", length);
    fprintf(stdout, "Number of words to type: %d\n", words);
    fflush(stdout);

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    for (int i = 0; i < length; i++) {
        fscanf(fp, "%s", word);
        strcat(sentence, word);
        if (i < length - 1)
            strcat(sentence, " ");
    }

    fprintf(stdout, "Sentence to type: %s\n", sentence);
    fflush(stdout);

    time(&start);
    while (1) {
        fgets(word, 100, stdin);
        if (feof(stdin))
            break;
        if (strcmp(word, sentence) == 0) {
            correct++;
            break;
        } else {
            incorrect++;
        }
    }

    time(&end);
    speed = (int) (60 * (double) words / (double) (end - start));

    fprintf(stdout, "You typed %d words correctly and %d words incorrectly.\n", correct, incorrect);
    fprintf(stdout, "Your typing speed is %d words per minute.\n", speed);

    fclose(fp);
    return 0;
}