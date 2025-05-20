//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000

typedef struct {
    char *sentence;
    int length;
    int sentiment;
} Sentence;

int get_sentiment(char *sentence) {
    int sentiment = 0;
    if (strstr(sentence, "happy")!= NULL) {
        sentiment += 1;
    } else if (strstr(sentence, "sad")!= NULL) {
        sentiment -= 1;
    }
    return sentiment;
}

int main() {
    FILE *file;
    char buffer[MAX_SENTENCE_LENGTH];
    int sentences = 0;
    int i = 0;
    Sentence *sentences_array = malloc(MAX_SENTENCES * sizeof(Sentence));

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(buffer, MAX_SENTENCE_LENGTH, file)!= NULL) {
        if (strlen(buffer) > 0 && sentences < MAX_SENTENCES) {
            sentences_array[i].sentence = strdup(buffer);
            sentences_array[i].length = strlen(buffer);
            sentences_array[i].sentiment = get_sentiment(buffer);
            i++;
            sentences++;
        }
    }

    fclose(file);

    int total_sentiment = 0;
    for (int j = 0; j < i; j++) {
        total_sentiment += sentences_array[j].sentiment;
    }

    printf("Total sentiment: %d\n", total_sentiment);

    for (int k = 0; k < i; k++) {
        printf("Sentence %d: %s\n", k + 1, sentences_array[k].sentence);
        printf("Sentiment: %d\n\n", sentences_array[k].sentiment);
    }

    free(sentences_array);
    return 0;
}