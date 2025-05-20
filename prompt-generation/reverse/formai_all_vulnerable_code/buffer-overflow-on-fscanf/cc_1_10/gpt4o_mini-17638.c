//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_WORDS 100
#define MAX_EMOTIONS 5

// Structure to represent emotion scores
typedef struct {
    char *emotion;
    int score;
} Emotion;

// Function prototypes
int load_emotions(const char *filename, Emotion emotions[]);
int analyze_sentiment(const char *line, Emotion emotions[], int emotion_count);

int main() {
    Emotion emotions[MAX_EMOTIONS];
    int emotion_count = load_emotions("emotions.txt", emotions);

    if (emotion_count == -1) {
        fprintf(stderr, "Failed to load emotions data.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    printf("Enter text for sentiment analysis:\n");
    
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;  // Remove newline character
        
        int score = analyze_sentiment(line, emotions, emotion_count);
        if (score > 0) {
            printf("Positive Sentiment Score: %d\n", score);
        } else if (score < 0) {
            printf("Negative Sentiment Score: %d\n", score);
        } else {
            printf("Neutral Sentiment.\n");
        }
        
        printf("Enter text for sentiment analysis:\n");
    }

    // Clean up
    for (int i = 0; i < emotion_count; i++) {
        free(emotions[i].emotion);
    }

    return 0;
}

// Load emotion words and their scores from a file
int load_emotions(const char *filename, Emotion emotions[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("File opening failed");
        return -1;
    }

    int count = 0;
    char word[MAX_LINE_LENGTH];
    int score;

    while (fscanf(file, "%s %d", word, &score) == 2) {
        if (count >= MAX_EMOTIONS) {
            fprintf(stderr, "Exceeded maximum emotions limit.\n");
            break;
        }
        emotions[count].emotion = malloc(strlen(word) + 1);
        if (!emotions[count].emotion) {
            fprintf(stderr, "Memory allocation failed.\n");
            fclose(file);
            return -1;
        }
        strcpy(emotions[count].emotion, word);
        emotions[count].score = score;
        count++;
    }

    fclose(file);
    return count;
}

// Analyze the sentiment of a given line of text
int analyze_sentiment(const char *line, Emotion emotions[], int emotion_count) {
    int total_score = 0;
    char *token;
    char *temp_line = malloc(strlen(line) + 1);
    
    if (!temp_line) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 0;
    }
    
    strcpy(temp_line, line);
    
    // Tokenize the input line
    token = strtok(temp_line, " ");
    while (token) {
        for (int i = 0; i < emotion_count; i++) {
            if (strcasecmp(token, emotions[i].emotion) == 0) {
                total_score += emotions[i].score;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    free(temp_line);
    return total_score;
}