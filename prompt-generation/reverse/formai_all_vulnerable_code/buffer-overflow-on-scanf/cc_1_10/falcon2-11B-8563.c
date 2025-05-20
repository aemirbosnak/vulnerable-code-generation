//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to the Funniest Online Examination System Ever!\n");
    printf("Please enter your name: ");
    char name[100];
    scanf("%s", name);
    printf("Hello %s, are you ready to take the funniest exam ever?\n", name);
    printf("Question 1: What is the square root of 4?\n");
    printf("(a) 2\n(b) 3\n(c) 4\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("That's right! You are a genius.\n");
    } else if (choice == 2) {
        printf("Wrong! The answer is 2.\n");
    } else if (choice == 3) {
        printf("Wrong! The answer is 4.\n");
    } else {
        printf("Invalid choice.\n");
    }
    printf("Question 2: What is the capital of France?\n");
    printf("(a) Rome\n(b) London\n(c) Paris\n");
    choice = 0;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Wrong! The capital of France is Paris.\n");
    } else if (choice == 2) {
        printf("Wrong! The capital of France is Paris.\n");
    } else if (choice == 3) {
        printf("That's right! You are a genius.\n");
    } else {
        printf("Invalid choice.\n");
    }
    printf("Question 3: What is the capital of Italy?\n");
    printf("(a) Paris\n(b) Rome\n(c) Venice\n");
    choice = 0;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Wrong! The capital of Italy is Rome.\n");
    } else if (choice == 2) {
        printf("Wrong! The capital of Italy is Rome.\n");
    } else if (choice == 3) {
        printf("That's right! You are a genius.\n");
    } else {
        printf("Invalid choice.\n");
    }
    printf("Congratulations, you have passed the funniest online examination system ever!\n");
    return 0;
}