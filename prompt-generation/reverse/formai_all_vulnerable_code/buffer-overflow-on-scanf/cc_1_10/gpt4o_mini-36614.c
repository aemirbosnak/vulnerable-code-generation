//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 5
#define MAX_OPTIONS 4
#define NAME_LENGTH 50

typedef struct {
    char question[256];
    char options[MAX_OPTIONS][256];
    int correctAnswer; // index of the correct option
} Question;

typedef struct {
    char name[NAME_LENGTH];
    int score;
} User;

void displayMenu() {
    printf("\n*** Online Examination System ***\n");
    printf("1. Take Exam\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

void printExamInstructions() {
    printf("Instructions:\n");
    printf("- You will be presented with multiple choice questions.\n");
    printf("- Choose the correct option by entering the number (0 to %d).\n", MAX_OPTIONS - 1);
    printf("- A score higher than 70%% is considered a pass!\n");
}

void conductExam(User *user, Question *questions) {
    user->score = 0;
    
    printf("Starting the examination for %s...\n", user->name);
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d: %s\n", j, questions[i].options[j]);
        }

        int answer;
        printf("Your answer (0-%d): ", MAX_OPTIONS - 1);
        scanf("%d", &answer);

        if (answer == questions[i].correctAnswer) {
            printf("Correct! 🎉\n");
            user->score++;
        } else {
            printf("Wrong! 😢 The correct answer was option %d.\n", questions[i].correctAnswer);
        }
    }
    
    printf("\nExam finished! Your score: %d/%d\n", user->score, MAX_QUESTIONS);
    if (user->score > (MAX_QUESTIONS * 0.7)) {
        printf("Congratulations %s! You passed the exam!\n", user->name);
    } else {
        printf("Sorry %s, you didn't pass. Better luck next time!\n", user->name);
    }
}

void initializeQuestions(Question *questions) {
    // Sample questions
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].options[0], "Berlin");
    strcpy(questions[0].options[1], "Madrid");
    strcpy(questions[0].options[2], "Paris");
    strcpy(questions[0].options[3], "Lisbon");
    questions[0].correctAnswer = 2;

    strcpy(questions[1].question, "What is 5 + 7?");
    strcpy(questions[1].options[0], "10");
    strcpy(questions[1].options[1], "12");
    strcpy(questions[1].options[2], "15");
    strcpy(questions[1].options[3], "11");
    questions[1].correctAnswer = 1;

    strcpy(questions[2].question, "What is the color of the sky?");
    strcpy(questions[2].options[0], "Green");
    strcpy(questions[2].options[1], "Blue");
    strcpy(questions[2].options[2], "Red");
    strcpy(questions[2].options[3], "Yellow");
    questions[2].correctAnswer = 1;

    strcpy(questions[3].question, "Which planet is known as the Red Planet?");
    strcpy(questions[3].options[0], "Earth");
    strcpy(questions[3].options[1], "Mars");
    strcpy(questions[3].options[2], "Jupiter");
    strcpy(questions[3].options[3], "Saturn");
    questions[3].correctAnswer = 1;

    strcpy(questions[4].question, "What is the boiling point of water?");
    strcpy(questions[4].options[0], "90 degrees Celsius");
    strcpy(questions[4].options[1], "100 degrees Celsius");
    strcpy(questions[4].options[2], "80 degrees Celsius");
    strcpy(questions[4].options[3], "120 degrees Celsius");
    questions[4].correctAnswer = 1;
}

int main() {
    User user;
    Question questions[MAX_QUESTIONS];

    printf("Welcome to the Online Examination System!\n");
    printf("Enter your name: ");
    scanf("%s", user.name);

    initializeQuestions(questions);
    
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 1) {
            printExamInstructions();
            conductExam(&user, questions);
        } else if (choice == 2) {
            printf("Thank you for using the Online Examination System. Goodbye!\n");
            break;
        } else {
            printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}