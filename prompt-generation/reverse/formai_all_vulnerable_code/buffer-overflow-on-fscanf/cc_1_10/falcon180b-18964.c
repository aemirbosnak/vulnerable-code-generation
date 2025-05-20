//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0, correct = 0, incorrect = 0;
    char word[20];
    int length, i;
    double time_elapsed;
    FILE *file;

    srand(time(NULL));
    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a series of words to type.\n");
    printf("Type as many words as you can in 60 seconds.\n");
    printf("Press enter to begin.\n");

    scanf("%c", &word[0]);

    for (int j = 0; j < 5; j++) {
        fscanf(file, "%s", word);
        length = strlen(word);
        for (i = 0; i < length; i++) {
            word[i] = toupper(word[i]);
        }
        printf("%s\n", word);
    }

    fclose(file);

    clock_t start_time = clock();

    while (1) {
        scanf("%s", word);
        if (strcmp(word, "exit") == 0) {
            break;
        }
        length = strlen(word);
        for (i = 0; i < length; i++) {
            if (word[i]!= toupper(word[i])) {
                incorrect++;
            } else {
                correct++;
            }
        }
        score += correct * 10;
        score -= incorrect * 5;
        printf("Score: %d\n", score);
    }

    time_elapsed = (double) (clock() - start_time) / CLOCKS_PER_SEC;
    printf("Time elapsed: %.2f seconds\n", time_elapsed);
    printf("Words per minute: %.2f\n", (double) score / time_elapsed);

    return 0;
}