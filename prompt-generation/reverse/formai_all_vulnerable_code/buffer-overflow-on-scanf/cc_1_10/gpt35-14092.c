//FormAI DATASET v1.0 Category: Online Examination System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* struct to store question and answer information */
struct question {
    char* question_text;
    char* answer;
};

/* function to print out a randomly selected question */
void ask_question(struct question* questions, int num_questions) {
    srand(time(NULL)); // seed random number generator

    int rand_index = rand() % num_questions; // generate random index for question array
    struct question selected_question = questions[rand_index]; // retrieve selected question

    printf("%s\n", selected_question.question_text); // print out question text
    printf("Your answer: ");
    char user_answer[50]; // buffer to store user's answer
    scanf("%s", user_answer); // get user's answer from input

    if (strcmp(user_answer, selected_question.answer) == 0) { // compare user's answer to correct answer
        printf("Correct! On to the next question.\n");
    }
    else {
        printf("Incorrect. The correct answer was %s.\n", selected_question.answer);
    }
}

int main() {
    /* array of sample questions */
    struct question questions[] = {
        {"What is the name of the legendary sword of King Arthur?", "Excalibur"},
        {"Who was the first female ruler of England?", "Queen Mary I"},
        {"What is the name of the mythical creature that is half-man and half-horse?", "Centaur"},
        {"What is the name of the Roman goddess of love?", "Venus"},
        {"Who was the Greek god of wine?", "Dionysus"},
        {"What is the name of the ancient Persian god of light?", "Ahura Mazda"},
        {"What is the name of the famous philosopher who was sentenced to death by drinking hemlock?", "Socrates"},
        {"Who were the Norse gods who lived in Asgard?", "The Aesir"}
    };

    int num_questions = sizeof(questions) / sizeof(struct question); // total number of questions

    printf("Welcome to the Medieval Online Examination System!\n");
    printf("You will be presented with a series of questions. Answer each one to the best of your ability.\n");

    while (1) { // loop to continuously ask questions until user quits
        ask_question(questions, num_questions);

        printf("Do you want to continue? (y/n): ");
        char user_choice[2]; // buffer to store user's choice
        scanf("%s", user_choice); // get user's choice from input

        if (strcmp(user_choice, "n") == 0) { // user chose to quit
            printf("Thank you for using the Medieval Online Examination System!\n");
            break;
        }
    }

    return 0;
}