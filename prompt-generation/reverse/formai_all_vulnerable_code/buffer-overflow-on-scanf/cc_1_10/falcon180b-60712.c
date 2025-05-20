//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: secure
#include <stdio.h>

// Define the periodic table quiz questions and answers
#define NUM_QUESTIONS 10

// Quiz question structure
typedef struct {
    char question[100];
    char answer[100];
} QuizQuestion;

// Quiz questions
QuizQuestion questions[] = {
    {"What element has the symbol Fe and is used to make steel? ", "Iron"},
    {"What element has the symbol Hg and is also known as quicksilver? ", "Mercury"},
    {"What element has the symbol O and makes up 21% of Earth's atmosphere? ", "Oxygen"},
    {"What element has the symbol Au and is used in jewelry? ", "Gold"},
    {"What element has the symbol Ag and is used in silverware? ", "Silver"},
    {"What element has the symbol C and is the basis of all life? ", "Carbon"},
    {"What element has the symbol H and is the most abundant in the universe? ", "Hydrogen"},
    {"What element has the symbol N and makes up 78% of Earth's atmosphere? ", "Nitrogen"},
    {"What element has the symbol Cl and is used to disinfect water? ", "Chlorine"},
    {"What element has the symbol Na and is commonly used in table salt? ", "Sodium"}
};

// Quiz function
int quiz() {
    int score = 0;
    int i;

    // Loop through each question
    for (i = 0; i < NUM_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);

        // Get user's answer
        char userAnswer[100];
        scanf("%s", userAnswer);

        // Check if answer is correct
        if (strcmp(userAnswer, questions[i].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", questions[i].answer);
        }
    }

    // Print final score
    printf("You got %d out of %d questions correct.\n", score, NUM_QUESTIONS);

    return score;
}

int main() {
    int quizScore;

    // Run quiz
    quizScore = quiz();

    return 0;
}