//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: calm
#include<stdio.h>
#include<string.h>

// Function to calculate sentiment score
int sentiment_score(char sentence[]) {
    char positive_words[10][20] = {"good", "great", "wonderful", "excellent", "fantastic", "perfect", "awesome", "happy", "love", "nice"};
    char negative_words[10][20] = {"bad", "terrible", "poor", "horrible", "awful", "dislike", "hate", "angry", "sad", "unhappy"};

    int positive_count = 0, negative_count = 0;

    // splitting the sentence into words
    char* word = strtok(sentence, " ");

    // loop to count positive and negative words
    while (word != NULL) {
        for (int i = 0; i < 10; i++) {
            if (strcmp(word, positive_words[i]) == 0) {
                positive_count++;
            }
            else if (strcmp(word, negative_words[i]) == 0) {
                negative_count++;
            }
        }
        word = strtok(NULL, " ");
    }

    // calculating sentiment score
    int sentiment_score = positive_count - negative_count;

    return sentiment_score;
}

int main() {
    char sentence[100];

    // Getting input from user
    printf("Enter a sentence: ");
    gets(sentence);

    // calling sentiment score function and storing the result
    int score = sentiment_score(sentence);

    // displaying sentiment score
    printf("Sentiment score is: %d\n", score);

    if (score > 0) {
        printf("Positive sentiment\n");
    }
    else if (score < 0) {
        printf("Negative sentiment\n");
    }
    else {
        printf("Neutral sentiment\n");
    }

    return 0;
}