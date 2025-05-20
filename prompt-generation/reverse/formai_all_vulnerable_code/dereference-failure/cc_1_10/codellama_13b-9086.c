//Code Llama-13B DATASET v1.0 Category: Sentiment analysis tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024

typedef struct {
    char* text;
    int length;
} Text;

void read_text(Text* text) {
    char* buffer = (char*)malloc(MAX_TEXT_LENGTH * sizeof(char));
    fgets(buffer, MAX_TEXT_LENGTH, stdin);
    text->text = buffer;
    text->length = strlen(buffer);
}

int is_positive_sentiment(Text* text) {
    char* positive_words[] = {"good", "happy", "great", "awesome", "amazing", "excellent", "fantastic", "super"};
    int positive_words_count = sizeof(positive_words) / sizeof(char*);
    int is_positive = 0;
    for (int i = 0; i < positive_words_count; i++) {
        if (strstr(text->text, positive_words[i])) {
            is_positive = 1;
            break;
        }
    }
    return is_positive;
}

int is_negative_sentiment(Text* text) {
    char* negative_words[] = {"bad", "sad", "terrible", "awful", "disappointing", "unhappy", "not good", "not great", "not awesome", "not excellent", "not fantastic", "not super"};
    int negative_words_count = sizeof(negative_words) / sizeof(char*);
    int is_negative = 0;
    for (int i = 0; i < negative_words_count; i++) {
        if (strstr(text->text, negative_words[i])) {
            is_negative = 1;
            break;
        }
    }
    return is_negative;
}

int main() {
    Text text;
    read_text(&text);
    int is_positive = is_positive_sentiment(&text);
    int is_negative = is_negative_sentiment(&text);
    if (is_positive && is_negative) {
        printf("Mixed sentiment\n");
    } else if (is_positive) {
        printf("Positive sentiment\n");
    } else if (is_negative) {
        printf("Negative sentiment\n");
    } else {
        printf("Neutral sentiment\n");
    }
    return 0;
}