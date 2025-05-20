//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for storing information about a question
struct Question {
    char question[100];
    char answer[10];
    int points;
};

// Function to generate a random question
void generate_question(struct Question *q) {
    srand(time(NULL));
    int index = rand() % 10;
    switch (index) {
        case 0:
            strcpy(q->question, "What is the capital of France?");
            strcpy(q->answer, "Paris");
            q->points = 10;
            break;
        case 1:
            strcpy(q->question, "What is the largest planet in our solar system?");
            strcpy(q->answer, "Jupiter");
            q->points = 20;
            break;
        case 2:
            strcpy(q->question, "What is the smallest country in the world?");
            strcpy(q->answer, "Vatican City");
            q->points = 30;
            break;
        case 3:
            strcpy(q->question, "What is the largest living species of lizard?");
            strcpy(q->answer, "Saltwater Crocodile");
            q->points = 40;
            break;
        case 4:
            strcpy(q->question, "What is the largest mammal on Earth?");
            strcpy(q->answer, "Blue Whale");
            q->points = 50;
            break;
        case 5:
            strcpy(q->question, "What is the largest waterfall in the world?");
            strcpy(q->answer, "Victoria Falls");
            q->points = 60;
            break;
        case 6:
            strcpy(q->question, "What is the hottest temperature ever recorded on Earth?");
            strcpy(q->answer, "134 degrees Celsius");
            q->points = 70;
            break;
        case 7:
            strcpy(q->question, "What is the deepest part of the ocean?");
            strcpy(q->answer, "Challenger Deep");
            q->points = 80;
            break;
        case 8:
            strcpy(q->question, "What is the largest bird in the world?");
            strcpy(q->answer, "Stegosaurus");
            q->points = 90;
            break;
        case 9:
            strcpy(q->question, "What is the largest animal to ever exist on Earth?");
            strcpy(q->answer, "Blue Whale");
            q->points = 100;
            break;
    }
}

// Function to check if the answer is correct
int check_answer(struct Question *q, char *answer) {
    if (strcmp(q->answer, answer) == 0) {
        return q->points;
    } else {
        return 0;
    }
}

// Main function
int main() {
    // Create a question structure
    struct Question q;

    // Generate a random question
    generate_question(&q);

    // Print the question
    printf("%s\n", q.question);

    // Get the answer from the user
    char answer[10];
    scanf("%s", answer);

    // Check if the answer is correct
    int points = check_answer(&q, answer);

    // Print the result
    if (points > 0) {
        printf("Correct! You earned %d points.\n", points);
    } else {
        printf("Wrong answer. The correct answer is %s.\n", q.answer);
    }

    return 0;
}