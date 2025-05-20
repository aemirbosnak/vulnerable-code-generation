//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_menu() {
    printf("Welcome to the Shape Shifting Sentiment Analysis Tool!\n");
    printf("======================================================\n");
    printf("[1] Analyze the sentiment of a single sentence\n");
    printf("[2] Analyze the sentiment of text from a file\n");
    printf("[3] Exit\n");
    printf("\nEnter your choice (1-3): ");
}

int calculate_sentiment(char *sentence) {
    int sentiment = 50; // start with a neutral sentiment of 50%
    int length = strlen(sentence);
    int i;

    for (i = 0; i < length; i++) {
        if (sentence[i] == '!' || sentence[i] == '?') {
            sentiment += 10; // increase sentiment by 10% for each exclamation or question mark
        } else if (sentence[i] == '.') {
            sentiment -= 5; // decrease sentiment by 5% for each period
        } else if (sentence[i] == ',') {
            sentiment -= 2; // decrease sentiment by 2% for each comma
        } else if (sentence[i] == '-') {
            sentiment -= 1; // decrease sentiment by 1% for each dash
        }
    }

    return sentiment;
}

void analyze_sentence() {
    char sentence[1000];

    printf("\nEnter a sentence to analyze: ");
    fgets(sentence, 1000, stdin);

    int sentiment = calculate_sentiment(sentence);

    printf("\nThe sentiment of the sentence \"%s\" is %d%%\n\n", sentence, sentiment);
}

void analyze_file() {
    char filename[1000];
    char sentence[1000];
    FILE *file;

    printf("\nEnter the name of the file to analyze: ");
    fgets(filename, 1000, stdin);
    filename[strcspn(filename, "\n")] = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("\nError: Could not open file \"%s\"\n\n", filename);
    } else {
        int sentiment_total = 0;
        int sentence_count = 0;

        while (fgets(sentence, 1000, file)) {
            int sentiment = calculate_sentiment(sentence);
            sentiment_total += sentiment;
            sentence_count++;
            printf("\nSentence: %s", sentence);
            printf("Sentiment: %d%%\n\n", sentiment);
        }

        float sentiment_average = (float)sentiment_total / sentence_count;

        printf("Average sentiment of the file \"%s\" is %.2f%%\n\n", filename, sentiment_average);

        fclose(file);
    }
}

int main() {
    int choice;
    do {
        print_menu();

        scanf("%d", &choice);

        if (choice == 1) {
            analyze_sentence();
        } else if (choice == 2) {
            analyze_file();
        } else if (choice == 3) {
            printf("\nThank you for using the Shape Shifting Sentiment Analysis Tool!\n\n");
        } else {
            printf("\nInvalid choice. Please enter a valid choice (1-3)\n\n");
        }
    } while (choice != 3);

    return 0;
}