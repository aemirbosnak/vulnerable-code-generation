//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: minimalist
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/* Score definition */
#define POSITIVE 1
#define NEUTRAL 0
#define NEGATIVE -1

/* Function to calculate the sentiment of a string */
int sentiment(const char *str) {
    int score = NEUTRAL;

    /* Loop through each character in the string */
    for (int i = 0; i < strlen(str); i++) {
        char c = tolower(str[i]);

        /* Check if the character is a letter */
        if (isalpha(c)) {
            /* Check if the character is a positive word */
            if (strstr("good happy love positive amazing", c) != NULL) {
                score = POSITIVE;
            }
            /* Check if the character is a negative word */
            else if (strstr("bad sad hate negative horrible", c) != NULL) {
                score = NEGATIVE;
            }
        }
    }

    return score;
}

/* Main function */
int main() {
    /* Get the input string from the user */
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    /* Calculate the sentiment of the string */
    int score = sentiment(str);

    /* Print the sentiment of the string */
    switch (score) {
        case POSITIVE:
            printf("The sentiment of the string is positive.\n");
            break;
        case NEUTRAL:
            printf("The sentiment of the string is neutral.\n");
            break;
        case NEGATIVE:
            printf("The sentiment of the string is negative.\n");
            break;
    }

    return 0;
}