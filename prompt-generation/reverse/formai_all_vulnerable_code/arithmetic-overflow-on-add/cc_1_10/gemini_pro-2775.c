//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WPM_THRESHOLD 60
#define ACCURACY_THRESHOLD 95

typedef struct {
    char *text;
    int length;
} Text;

typedef struct {
    int correct;
    int incorrect;
    int total;
} Results;

Text generate_random_text(int length) {
    Text text;
    text.length = length;
    text.text = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        text.text[i] = 'a' + rand() % 26;
    }
    text.text[length] = '\0';
    return text;
}

Results get_results(const char *typed_text, const Text original_text) {
    Results results;
    results.correct = 0;
    results.incorrect = 0;
    results.total = original_text.length;
    for (int i = 0; i < original_text.length; i++) {
        if (typed_text[i] == original_text.text[i]) {
            results.correct++;
        } else {
            results.incorrect++;
        }
    }
    return results;
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a random text to type.\n");
    printf("Try to type as fast as you can with as few errors as possible.\n");

    int length;
    printf("Enter the length of the text (in characters): ");
    scanf("%d", &length);

    Text original_text = generate_random_text(length);

    printf("\nHere is the text:\n");
    printf("%s\n", original_text.text);

    printf("\nStart typing now!\n");

    char typed_text[length + 1];
    scanf("%s", typed_text);

    Results results = get_results(typed_text, original_text);

    printf("\nYour results:\n");
    printf("Words per minute: %f\n", results.correct / 5.0);
    printf("Accuracy: %f%%\n", (float)results.correct / results.total * 100);

    if (results.correct / 5.0 >= WPM_THRESHOLD && (float)results.correct / results.total * 100 >= ACCURACY_THRESHOLD) {
        printf("Congratulations! You passed the test.\n");
    } else {
        printf("Sorry, you did not pass the test.\n");
    }

    free(original_text.text);
    return 0;
}