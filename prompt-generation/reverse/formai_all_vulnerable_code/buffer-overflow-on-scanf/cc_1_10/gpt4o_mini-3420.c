//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quackers_says(const char *message) {
    printf("Quackers says: \"%s\"\n", message);
}

int get_sum(int a, int b) {
    return a + b;
}

int get_product(int a, int b) {
    return a * b;
}

float get_average(int a, int b) {
    return (float)(a + b) / 2;
}

int main() {
    srand(time(0));  // Seed the random number generator
    int score = 0;
    int number_of_questions = 5;

    quackers_says("Welcome to the Duck-tastic Math Challenge!");

    for (int i = 0; i < number_of_questions; i++) {
        int num1 = rand() % 20 + 1;  // Random number between 1 and 20
        int num2 = rand() % 20 + 1;

        quackers_says("Here's your next question!");
        printf("Question %d: What is %d + %d? (Duck emojis encouraged!)\n", i + 1, num1, num2);
        
        int user_answer;
        printf("Your answer: ");
        scanf("%d", &user_answer);

        if (user_answer == get_sum(num1, num2)) {
            quackers_says("Waddle-tastic! You got it right!");
            score++;
        } else {
            printf("Quackers is quacking in disappointment. The correct answer is %d.\n", get_sum(num1, num2));
        }

        printf("\n");

        quackers_says("Next up, we have the product question!");
        printf("Question %d: What is %d * %d? (More duck emojis, please!)\n", i + 1, num1, num2);
        
        printf("Your answer: ");
        scanf("%d", &user_answer);

        if (user_answer == get_product(num1, num2)) {
            quackers_says("Paddling through problems like a math wizard!");
            score++;
        } else {
            printf("Oh no! Quackers is flapping his wings in distress. The correct answer is %d.\n", get_product(num1, num2));
        }

        printf("\n");

        quackers_says("Finally, let's find out the average!");
        printf("Question %d: What is the average of %d and %d? (Quackers loves averages!)\n", i + 1, num1, num2);
        
        printf("Your answer: ");
        scanf("%f", &user_answer);
        
        if (user_answer == get_average(num1, num2)) {
            quackers_says("You're a quacking genius!");
            score++;
        } else {
            printf("Quackers is quacking sadly. The correct answer is %.2f.\n", get_average(num1, num2));
        }

        printf("\n");
    }

    quackers_says("Now let's see how many Quack Points you earned...");
    printf("Your total score: %d out of %d.\n", score, number_of_questions * 3); // Each question has 3 answers

    if (score >= 12) {
        quackers_says("You are now officially a Duck Math Wizard!");
    } else if (score >= 6) {
        quackers_says("You are a Duck Math Apprentice! Keep practicing!");
    } else {
        quackers_says("Don't worry! Even the best ducks had to waddle before they could fly!");
    }

    quackers_says("Thank you for playing the Duck-tastic Math Challenge!");
    return 0;
}