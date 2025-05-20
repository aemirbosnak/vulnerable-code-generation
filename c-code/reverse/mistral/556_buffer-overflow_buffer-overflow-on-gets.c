#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#define MAX_INPUT 256

int analyze_sentiment(char *input) {
    int sentiment = 0;
    int i = 0;

    if (strstr(input, ":-)") || strstr(input, ":-)")) sentiment = 1;
    if (strstr(input, ":-(") || strstr(input, ":-(")) sentiment = -1;
    if (strstr(input, "(Neutral)")) sentiment = 0;

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == ' ' && (input[i + 1] == ':' || input[i + 1] == '(')) sentiment = -1;
        if (input[i] == ' ' && (input[i - 1] == ':' || input[i - 1] == ')')) sentiment = 1;
    }

    return sentiment;
}

int main() {
    char input[MAX_INPUT];

    printf("Enter a string: ");
    gets(input);

    printf("Sentiment: %s\n", (analyze_sentiment(input) > 0) ? "Positive" : (analyze_sentiment(input) < 0) ? "Negative" : "Neutral");

    return 0;
}
