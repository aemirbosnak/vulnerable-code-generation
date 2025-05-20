//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Initializing variables to hold user input and output
    char input[1000], c;
    int i = 0, choice, count = 0;
    float sentiment = 0.0;

    // Prompting user for input
    printf("Enter a sentence to perform sentiment analysis:\n");
    scanf("%[^\n]", input);

    // Prompting user for sentiment analysis method
    printf("\nSelect a sentiment analysis method:\n");
    printf("1. Positive word count\n");
    printf("2. Negative word count\n");
    printf("3. Overall sentiment rating\n");
    scanf("%d", &choice);

    // Reading from file containing positive words
    FILE *f1 = fopen("positive_words.txt", "r");

    if (f1 == NULL) {
        printf("File error.");
        exit(1);
    }

    while ((c = fgetc(f1)) != EOF) {

        // Loop through positive words file character by character
        if (c != '\n') {

            // If not end of line, add character to current word
            input[i] = c;
            i++;
        }
        else {

            // If end of line, terminate current word and compare to input
            input[i] = '\0';

            // If word is found in input, increment positive word count
            if (strstr(input, input) != NULL) {
                count++;
            }

            i = 0;
        }
    }

    // Closing positive word file
    fclose(f1);

    // Reading from file containing negative words
    FILE *f2 = fopen("negative_words.txt", "r");

    if (f2 == NULL) {
        printf("File error.");
        exit(1);
    }

    // Reusing i variable to track negative word count
    i = 0;

    while ((c = fgetc(f2)) != EOF) {

        // Loop through negative words file character by character
        if (c != '\n') {

            // If not end of line, add character to current word
            input[i] = c;
            i++;
        }
        else {

            // If end of line, terminate current word and compare to input
            input[i] = '\0';

            // If word is found in input, increment negative word count
            if (strstr(input, input) != NULL) {
                count--;
            }

            i = 0;
        }
    }

    // Closing negative word file
    fclose(f2);

    // Calculating overall sentiment rating
    sentiment = (float) count / (strlen(input) + 1) * 100;

    // Outputting results based on user's selected method
    switch (choice) {
        case 1:
            printf("\nPositive word count: %d", count);
            break;

        case 2:
            printf("\nNegative word count: %d", abs(count));
            break;

        case 3:
            printf("\nOverall sentiment rating: %.2f%%", sentiment);
            break;

        default:
            printf("\nInvalid choice.");
            break;
    }

    return 0;
}