//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 255

int main() {
    // Initialize our trusty spam detection system!
    char trainingData[100][MAX_STR_LEN];
    int trainingLabels[100];
    int numTrainingExamples = 0;

    // Let's train our system with some sparkling examples!
    printf("Train me, train me! Feed me the wisdom of spam and ham:\n");
    while (numTrainingExamples < 100) {
        char input[MAX_STR_LEN];
        int label;

        printf("Enter a message:\n");
        fgets(input, MAX_STR_LEN, stdin);
        strtok(input, "\n");  // Remove newline character

        printf("Is it spam (1) or ham (0)?\n");
        scanf("%d", &label);

        strcpy(trainingData[numTrainingExamples], input);
        trainingLabels[numTrainingExamples] = label;
        numTrainingExamples++;
    }

    // Hooray! Our system is trained and ready to dazzle!
    printf("\nLet's play the spam detection game!\n");

    while (1) {
        char message[MAX_STR_LEN];

        printf("\nEnter a message or type 'quit' to end:\n");
        fgets(message, MAX_STR_LEN, stdin);
        strtok(message, "\n");  // Remove newline character

        if (strcmp(message, "quit") == 0) {
            break;
        }

        // Now, let's analyze the message and give our verdict!
        int isSpam = 0;
        for (int i = 0; i < numTrainingExamples; i++) {
            if (strstr(message, trainingData[i])) {
                isSpam = trainingLabels[i];
                break;
            }
        }

        if (isSpam) {
            printf("Oh no! It's spam! Beware!\n");
        } else {
            printf("Yay! It's ham! Enjoy!\n");
        }
    }

    printf("\nThank you for playing the spam detection game! Stay safe out there!\n");
    return 0;
}