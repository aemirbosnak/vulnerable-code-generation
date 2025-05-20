//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 50

typedef struct {
    int wpm;
    int accuracy;
} Result;

int get_typing_speed(char *text, size_t len, Result *result);
void generate_text(char *text, size_t len);

int main() {
    srand(time(0));
    char text[MAX_LEN + 1];
    Result result = {0, 0};
    generate_text(text, MAX_LEN);
    printf("Type the following sentence as fast as possible:\n\n%s\n\n", text);
    get_typing_speed(text, strlen(text), &result);
    printf("Your typing speed is %d words per minute with an accuracy of %d%%\n", result.wpm, result.accuracy);
    return 0;
}

// Generates the text for typing test
void generate_text(char *text, size_t len) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
    int index;
    for (size_t i = 0; i < len; i++) {
        index = rand() % (sizeof(charset) - 1);
        text[i] = charset[index];
    }
    text[len] = '\0';
}

// Calculates the typing speed and accuracy
int get_typing_speed(char *text, size_t len, Result *result) {
    char buffer[MAX_LEN + 1];
    double duration;
    clock_t start_time, end_time;
    int i, errors = 0;

    start_time = clock();
    fgets(buffer, MAX_LEN + 1, stdin);
    end_time = clock();
    duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    for (i = 0; i < len && i < MAX_LEN; i++) {
        if (tolower(text[i]) != tolower(buffer[i])) {
            errors++;
        }
    }
    result->accuracy = (int)(100.0 * (double)(len - errors) / (double)len);
    result->wpm = (int)(((double)len / 5.0) / (duration / 60.0));
    return 0;
}