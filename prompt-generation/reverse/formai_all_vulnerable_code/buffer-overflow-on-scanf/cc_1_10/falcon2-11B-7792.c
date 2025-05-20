//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: innovative
#include <stdio.h>
#include <string.h>

// Prototype for the checkElement function
int checkElement(char *element);

int main() {
    int num_questions;
    int num_correct;
    char element[10];

    // Prompt user for number of questions to ask
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    // Prompt user for each element
    for (int i = 0; i < num_questions; i++) {
        // Prompt user for element
        printf("Enter element %d: ", i + 1);
        scanf("%s", element);

        // Check if element is valid
        if (checkElement(element) == 0) {
            // Element is correct
            printf("Correct!\n");
            num_correct++;
        } else {
            // Element is incorrect
            printf("Incorrect!\n");
        }
    }

    // Print results
    printf("You answered %d of %d questions correctly.\n", num_correct, num_questions);

    return 0;
}

// Function to check if element is valid
int checkElement(char *element) {
    // Check if element is in the range 1-118
    int length = strlen(element);
    if (length == 1 && element[0] >= '1' && element[0] <= '8') {
        // Element is valid
        return 0;
    } else if (length == 1 && element[0] >= 'L' && element[0] <= 'Z') {
        // Element is valid
        return 0;
    } else {
        // Element is invalid
        return 1;
    }
}