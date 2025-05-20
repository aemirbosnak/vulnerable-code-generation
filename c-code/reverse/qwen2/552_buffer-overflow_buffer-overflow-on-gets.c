#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAX_LEN 100

int main() {
    char input[MAX_LEN];
    printf("Enter your message: ");
    gets(input);

    if (strstr(input, ":)") || strstr(input, ":-)") || strstr(input, ";)") || strstr(input, ":-D")) {
        printf("Sentiment: Happy\n");
    } else if (strstr(input, ":(") || strstr(input, ":-(") || strstr(input, ";(") || strstr(input, ":-|") || strstr(input, ":'(")) {
        printf("Sentiment: Sad\n");
    } else {
        printf("Sentiment: Neutral\n");
    }

    return 0;
}
