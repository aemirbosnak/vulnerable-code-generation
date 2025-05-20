//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void analyze_sentiment(char* text);
void shapeshift_animal(int sentiment);

int main() {
    char input[1000];
    printf("Enter some text: ");
    scanf("%[^\n]", input);
    analyze_sentiment(input);
    return 0;
}

void analyze_sentiment(char* text) {
    int sentiment = 0;
    char *p = strtok(text, " ");
    while (p != NULL) {
        if (strcmp(p, "happy") == 0) {
            sentiment += 2;
        } else if (strcmp(p, "good") == 0) {
            sentiment += 1;
        } else if (strcmp(p, "bad") == 0) {
            sentiment -= 1;
        } else if (strcmp(p, "sad") == 0) {
            sentiment -= 2;
        }
        p = strtok(NULL, " ");
    }
    shapeshift_animal(sentiment);
}

void shapeshift_animal(int sentiment) {
    srand(time(0));
    int random_num = rand() % 3;
    switch (random_num) {
        case 0:
            if (sentiment >= 0) {
                printf("You are a happy cat!\n");
            } else {
                printf("You are a grumpy cat.\n");
            }
            break;
        case 1:
            if (sentiment >= 0) {
                printf("You are a cheerful dog!\n");
            } else {
                printf("You are a sad dog.\n");
            }
            break;
        case 2:
            if (sentiment >= 0) {
                printf("You are a bouncing bunny!\n");
            } else {
                printf("You are a gloomy bunny.\n");
            }
            break;
    }
}