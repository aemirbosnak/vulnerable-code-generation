//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random question about the periodic table
void quiz() {
    // Array of questions about the periodic table
    const char* questions[] = {
        "What element is located in the first row of the periodic table?",
        "What element is located in the second row of the periodic table?",
        "What element is located in the third row of the periodic table?",
        "What element is located in the fourth row of the periodic table?",
        "What element is located in the fifth row of the periodic table?",
        "What element is located in the sixth row of the periodic table?",
        "What element is located in the seventh row of the periodic table?",
        "What element is located in the eighth row of the periodic table?",
        "What element is located in the ninth row of the periodic table?",
        "What element is located in the tenth row of the periodic table?"
    };

    // Randomly select a question from the array
    int index = rand() % 10;
    char* question = questions[index];

    // Print the question
    printf("Question: %s\n", question);

    // Get the correct answer from the user
    int correct_answer;
    printf("What is the correct answer? ");
    scanf("%d", &correct_answer);

    // Check if the user's answer is correct
    if (correct_answer == (rand() % 10)) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is %d.\n", (rand() % 10));
    }
}

int main() {
    // Generate a random seed for the quiz
    srand(time(NULL));

    // Perform the quiz
    quiz();

    // Print a message indicating that the quiz is complete
    printf("Periodic Table Quiz Complete!\n");

    return 0;
}