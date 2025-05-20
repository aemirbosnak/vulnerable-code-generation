//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ANSWERS 8

typedef struct {
    char question[100];
    char answer[20];
} QuestionAnswerPair;

void error_handler(const char *message) {
    printf("%s\n", message);
    exit(1);
}

void print_menu() {
    printf("\nWelcome to the Automated Fortune Teller!\n");
    printf("---------------------------------------\n");
    printf("Enter your question (Type 'quit' to exit):\n");
}

int generate_random_number(int min, int max) {
    int range = max - min + 1;
    int random_number = rand() % range;
    return random_number + min;
}

int main() {
    srand(time(NULL));

    QuestionAnswerPair answers[NUM_ANSWERS] = {
        {"What is the future of my relationship?", "It is certain."},
        {"Will I get a promotion?", "It is decidedly so."},
        {"Should I buy a house?", "Reply hazy, try again."},
        {"Is it a good time to invest?", "Ask again later."},
        {"Will I win the lottery?", "Concentrate and ask again."},
        {"What should I do today?", "Signs point to yes."},
        {"Will I find true love?", "Yes, definitely."},
        {"Will I be successful?", "You may rely on it."}
    };

    char user_input[100];

    while (1) {
        print_menu();
        fgets(user_input, sizeof(user_input), stdin);
        user_input[strlen(user_input) - 1] = '\0'; // remove newline character

        if (strcmp(user_input, "quit") == 0) {
            break;
        }

        int index = generate_random_number(0, NUM_ANSWERS - 1);
        printf("Your question: %s\n", user_input);
        printf("Answer: %s\n", answers[index].answer);
    }

    return 0;
}