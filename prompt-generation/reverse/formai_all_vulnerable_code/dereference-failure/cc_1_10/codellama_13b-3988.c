//Code Llama-13B DATASET v1.0 Category: Text Summarizer ; Style: safe
// Unique C Text Summarizer Example Program

#include <stdio.h>
#include <string.h>

// Function to get the summary of the given text
void getSummary(char *text, int numSentences) {
    // Split the text into sentences
    char *sentences[numSentences];
    int i, j;
    for (i = 0, j = 0; i < strlen(text); i++) {
        if (text[i] == '.') {
            sentences[j] = strndup(text + i - j, j);
            j = 0;
        } else {
            j++;
        }
    }

    // Calculate the length of each sentence
    int lengths[numSentences];
    for (i = 0; i < numSentences; i++) {
        lengths[i] = strlen(sentences[i]);
    }

    // Calculate the average length of the sentences
    int totalLength = 0;
    for (i = 0; i < numSentences; i++) {
        totalLength += lengths[i];
    }
    int averageLength = totalLength / numSentences;

    // Select the sentences that are within the average length +/- 10%
    int selectedSentences[numSentences];
    int numSelectedSentences = 0;
    for (i = 0; i < numSentences; i++) {
        if (lengths[i] >= averageLength * 0.9 && lengths[i] <= averageLength * 1.1) {
            selectedSentences[numSelectedSentences++] = i;
        }
    }

    // Print the selected sentences
    for (i = 0; i < numSelectedSentences; i++) {
        printf("%s\n", sentences[selectedSentences[i]]);
    }
}

int main() {
    // Get the text from the user
    char text[1000];
    printf("Enter the text: ");
    fgets(text, 1000, stdin);

    // Get the number of sentences from the user
    int numSentences;
    printf("Enter the number of sentences: ");
    scanf("%d", &numSentences);

    // Call the getSummary function
    getSummary(text, numSentences);

    return 0;
}