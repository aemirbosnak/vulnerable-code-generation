//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTION 4
#define MAX_NAME 30

typedef struct {
    char question[256];
    char options[MAX_OPTION][100];
    int correct_answer;
} QuizQuestion;

void display_welcome_message();
void start_game();
void display_question(QuizQuestion q, int question_number);
int get_user_answer();
int check_answer(int user_answer, int correct_answer);
void display_final_score(int score, int total_questions);
void play_again();

int main() {
    display_welcome_message();
    start_game();
    return 0;
}

void display_welcome_message() {
    printf("*****************************************\n");
    printf("******* Welcome to the Ultimate Quiz! *****\n");
    printf("*****************************************\n");
    printf("Get ready to test your knowledge on various topics!\n");
    printf("Can you beat the high score? Let's find out!\n\n");
}

void start_game() {
    QuizQuestion quiz[MAX_QUESTIONS] = {
        {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Lisbon"}, 2},
        {"Who wrote 'Romeo and Juliet'?", {"Charles Dickens", "William Shakespeare", "Mark Twain", "Jane Austen"}, 1},
        {"What is the largest planet in our Solar System?", {"Earth", "Mars", "Jupiter", "Saturn"}, 2},
        {"Which element has the chemical symbol 'O'?", {"Osmium", "Oxygen", "Gold", "Silver"}, 1},
        {"How many continents are there?", {"5", "6", "7", "8"}, 2},
        {"What year did the Titanic sink?", {"1912", "1905", "1898", "1923"}, 0},
        {"Who painted the Mona Lisa?", {"Vincent Van Gogh", "Pablo Picasso", "Leonardo da Vinci", "Claude Monet"}, 2},
        {"What is the smallest prime number?", {"0", "1", "2", "3"}, 2},
        {"Which gas do plants absorb from the atmosphere?", {"Oxygen", "Carbon Dioxide", "Nitrogen", "Helium"}, 1},
        {"What is H2O commonly known as?", {"Hydrogen Peroxide", "Water", "Salt", "Ammonia"}, 1}
    };

    int score = 0;
    int total_questions = MAX_QUESTIONS;

    for (int i = 0; i < total_questions; i++) {
        display_question(quiz[i], i + 1);
        int user_answer = get_user_answer();
        if (check_answer(user_answer, quiz[i].correct_answer)) {
            printf("Correct! 🎉\n\n");
            score++;
        } else {
            printf("Oops! The correct answer was: %s\n\n", quiz[i].options[quiz[i].correct_answer]);
        }
    }
    
    display_final_score(score, total_questions);
    play_again();
}

void display_question(QuizQuestion q, int question_number) {
    printf("Question %d: %s\n", question_number, q.question);
    for (int i = 0; i < MAX_OPTION; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

int get_user_answer() {
    int answer;
    printf("Your answer (1-%d): ", MAX_OPTION);
    scanf("%d", &answer);
    return answer - 1; // Convert to 0-based index
}

int check_answer(int user_answer, int correct_answer) {
    return user_answer == correct_answer;
}

void display_final_score(int score, int total_questions) {
    printf("*****************************************\n");
    printf("Your final score: %d out of %d\n", score, total_questions);
    printf("*****************************************\n");
}

void play_again() {
    char choice;
    printf("Would you like to play again? (y/n): ");
    scanf(" %c", &choice); // Space before %c to consume newline

    if (choice == 'y' || choice == 'Y') {
        printf("\nFantastic! Restarting the game...\n");
        start_game();
    } else {
        printf("Thank you for playing! Goodbye! 👋\n");
    }
}