//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 10
#define TIME_LIMIT 30

char *words[MAX_WORDS];
int lengths[MAX_WORDS];

void init() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    // read words and lengths from file
    int count = 0;
    while (count < MAX_WORDS && fscanf(file, "%s %d", words[count], &lengths[count]) == 2) {
        count++;
    }

    fclose(file);
}

int main() {
    init();

    // prompt user for name
    printf("Enter your name: ");
    char name[20];
    scanf("%s", name);

    // start timer
    clock_t start = clock();

    // display instructions
    printf("\nInstructions:\n");
    printf("Type the words that appear on the screen as quickly and accurately as possible.\n");
    printf("Press enter after each word.\n");

    // start test
    int score = 0;
    int wrong = 0;
    int total = 0;
    int i = 0;
    while (i < MAX_WORDS) {
        printf("\n");
        printf("Word %d: ", i + 1);
        char word[MAX_WORD_LENGTH + 1];
        strncpy(word, words[i], lengths[i]);
        word[lengths[i]] = '\0';
        printf("%s", word);

        char input[MAX_WORD_LENGTH + 1];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(word, input) == 0) {
            score++;
        } else {
            wrong++;
        }

        total++;
        i++;

        if (i == MAX_WORDS) {
            break;
        } else if (clock() - start > TIME_LIMIT * CLOCKS_PER_SEC) {
            break;
        }
    }

    // display results
    printf("\n\nResults:\n");
    printf("Name: %s\n", name);
    printf("Score: %d\n", score);
    printf("Words per minute: %d\n", score * (60 / TIME_LIMIT));
    printf("Accuracy: %.2f%%\n", ((float)score / total) * 100);
    printf("Wrong: %d\n", wrong);

    return 0;
}