//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>

int main() {
    int score = 0;
    bool q1_ans = false, q2_ans = false, q3_ans = false, q4_ans = false;

    printf("WELCOME TO THE PERIODIC TABLE QUIZ!\n");
    printf("Answer the following questions to test your knowledge of the periodic table.\n\n");

    printf("Question 1: What is the symbol for gold?\n");
    printf("a. Au\tb. Ag\tc. Cu\td. Fe\n");
    char q1_choice;
    scanf(" %c", &q1_choice);
    switch(q1_choice) {
        case 'a':
            printf("Correct! Gold has the symbol Au.\n");
            q1_ans = true;
            break;
        case 'b':
        case 'c':
        case 'd':
            printf("Incorrect! The symbol for gold is Au.\n");
            break;
        default:
            printf("Invalid input!\n");
            break;
    }

    printf("\nQuestion 2: How many naturally occurring elements are there?\n");
    printf("a. 92\tb. 95\tc. 100\td. 118\n");
    char q2_choice;
    scanf(" %c", &q2_choice);
    switch(q2_choice) {
        case 'a':
            printf("Correct! There are 92 naturally occurring elements.\n");
            q2_ans = true;
            break;
        case 'b':
        case 'c':
        case 'd':
            printf("Incorrect! There are 92 naturally occurring elements.\n");
            break;
        default:
            printf("Invalid input!\n");
            break;
    }

    printf("\nQuestion 3: Which element is a liquid at room temperature?\n");
    printf("a. Helium\tb. Chromium\tc. Mercury\td. Silver\n");
    char q3_choice;
    scanf(" %c", &q3_choice);
    switch(q3_choice) {
        case 'c':
            printf("Correct! Mercury is a liquid at room temperature.\n");
            q3_ans = true;
            break;
        case 'a':
        case 'b':
        case 'd':
            printf("Incorrect! Mercury is a liquid at room temperature.\n");
            break;
        default:
            printf("Invalid input!\n");
            break;
    }

    printf("\nQuestion 4: Which element has the highest boiling point?\n");
    printf("a. Carbon\tb. Tungsten\tc. Platinum\td. Helium\n");
    char q4_choice;
    scanf(" %c", &q4_choice);
    switch(q4_choice) {
        case 'b':
            printf("Correct! Tungsten has the highest boiling point.\n");
            q4_ans = true;
            break;
        case 'a':
        case 'c':
        case 'd':
            printf("Incorrect! Tungsten has the highest boiling point.\n");
            break;
        default:
            printf("Invalid input!\n");
            break;
    }

    if(q1_ans) {
        score += 25;
    }
    if(q2_ans) {
        score += 25;
    }
    if(q3_ans) {
        score += 25;
    }
    if(q4_ans) {
        score += 25;
    }

    printf("\nYour final score is %d out of 100!\n", score);
    printf("Thanks for playing the Periodic Table Quiz!\n");

    return 0;
}