//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: paranoid
#include <stdio.h>
#include <string.h>

void welcome_message();
void prompt_user();
int check_answer(char *correct_answer, char *user_answer);

int main() {
    welcome_message();
    
    char user_answer[10];
    
    int score = 0;
    score += check_answer("Hydrogen", user_answer);
    prompt_user();
    scanf("%s", user_answer);
    score += check_answer("Iron", user_answer);
    prompt_user();
    scanf("%s", user_answer);
    score += check_answer("Oxygen", user_answer);
    prompt_user();
    scanf("%s", user_answer);
    score += check_answer("Sulfur", user_answer);
    prompt_user();
    scanf("%s", user_answer);
    score += check_answer("Neon", user_answer);

    printf("\nYou scored %d out of 5.\n", score);
    
    if (score == 5) {
        printf("Congratulations! You passed the periodic table quiz.\n");
    } else {
        printf("Unfortunately, you did not pass the periodic table quiz. Please try again.\n");
    }
    
    return 0;
}

void welcome_message() {
    printf("Welcome to the paranoid style periodic table quiz.\n");
    printf("In this quiz, you will be given five different elements from the periodic table.\n");
    printf("Your task is to guess the correct element from the given symbol.\n");
    printf("Good luck!\n\n");
}

void prompt_user() {
    printf("\nWhat is the element name for the following symbol?\n");
}

int check_answer(char *correct_answer, char *user_answer) {
    if (strcmp(correct_answer, user_answer) == 0) {
        printf("Correct! \n");
        return 1;
    } else {
        printf("Incorrect. The correct answer is %s.\n", correct_answer);
        return 0;
    }
}