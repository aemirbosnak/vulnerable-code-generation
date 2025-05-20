//FormAI DATASET v1.0 Category: Online Examination System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Welcome message
    printf("Welcome to our online examination system!\n\n");

    // Ask user for name and ID
    char name[50];
    int id;

    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Please enter your ID number: ");
    scanf("%d", &id);

    // Display instructions
    printf("\nYou will be presented with 10 multiple-choice questions. Please select the most appropriate answer.\n");

    // Define questions and answers
    char q1[] = "What is the capital of France?\n";
    char a1[] = "a) Paris\nb) Rome\nc) Madrid\nd) Berlin\n";
    char ans1 = 'a';

    char q2[] = "What is the tallest mountain in the world?\n";
    char a2[] = "a) Mount Kilimanjaro\nb) Mount Everest\nc) Mount McKinley\nd) Mount Fuji\n";
    char ans2 = 'b';

    char q3[] = "What is the currency of Japan?\n";
    char a3[] = "a) Yen\nb) Dollar\nc) Pound\nd) Euro\n";
    char ans3 = 'a';

    char q4[] = "What is the largest continent by area?\n";
    char a4[] = "a) North America\nb) Europe\nc) Asia\nd) Africa\n";
    char ans4 = 'c';

    char q5[] = "Which planet is known as the Red Planet?\n";
    char a5[] = "a) Venus\nb) Mars\nc) Jupiter\nd) Uranus\n";
    char ans5 = 'b';

    char q6[] = "What is the smallest country in the world by area?\n";
    char a6[] = "a) Monaco\nb) Vatican City\nc) San Marino\nd) Liechtenstein\n";
    char ans6 = 'b';

    char q7[] = "What is the total number of elements in the periodic table?\n";
    char a7[] = "a) 118\nb) 98\nc) 113\nd) 89\n";
    char ans7 = 'a';

    char q8[] = "What is the national animal of Australia?\n";
    char a8[] = "a) Koala\nb) Kangaroo\nc) Emu\nd) Tasmanian Devil\n";
    char ans8 = 'b';

    char q9[] = "What is the highest waterfall in the world?\n";
    char a9[] = "a) Angel Falls\nb) Niagara Falls\nc) Victoria Falls\nd) Iguazu Falls\n";
    char ans9 = 'a';

    char q10[] = "What is the largest ocean in the world?\n";
    char a10[] = "a) Atlantic Ocean\nb) Indian Ocean\nc) Southern Ocean\nd) Pacific Ocean\n";
    char ans10 = 'd';

    // Initialize variables for user's score and answers
    int score = 0;
    char answer;

    // Question 1
    printf("\n%s", q1);
    printf("%s", a1);
    printf("Please enter your answer: ");
    scanf(" %c", &answer);
    if (answer == ans1) { // Check if answer is correct
        score++;
    }

    // Question 2
    printf("\n%s", q2);
    printf("%s", a2);
    printf("Please enter your answer: ");
    scanf(" %c", &answer);
    if (answer == ans2) {
        score++;
    }

    // Question 3
    printf("\n%s", q3);
    printf("%s", a3);
    printf("Please enter your answer: ");
    scanf(" %c", &answer);
    if (answer == ans3) {
        score++;
    }

    // Question 4
    printf("\n%s", q4);
    printf("%s", a4);
    printf("Please enter your answer: ");
    scanf(" %c", &answer);
    if (answer == ans4) {
        score++;
    }

    // Question 5
    printf("\n%s", q5);
    printf("%s", a5);
    printf("Please enter your answer: ");
    scanf(" %c", &answer);
    if (answer == ans5) {
        score++;
    }

    // Question 6
    printf("\n%s", q6);
    printf("%s", a6);
    printf("Please enter your answer: ");
    scanf(" %c", &answer);
    if (answer == ans6) {
        score++;
    }

    // Question 7
    printf("\n%s", q7);
    printf("%s", a7);
    printf("Please enter your answer: ");
    scanf(" %c", &answer);
    if (answer == ans7) {
        score++;
    }

    // Question 8
    printf("\n%s", q8);
    printf("%s", a8);
    printf("Please enter your answer: ");
    scanf(" %c", &answer);
    if (answer == ans8) {
        score++;
    }

    // Question 9
    printf("\n%s", q9);
    printf("%s", a9);
    printf("Please enter your answer: ");
    scanf(" %c", &answer);
    if (answer == ans9) {
        score++;
    }

    // Question 10
    printf("\n%s", q10);
    printf("%s", a10);
    printf("Please enter your answer: ");
    scanf(" %c", &answer);
    if (answer == ans10) {
        score++;
    }

    // Display final score
    printf("\nThank you for taking the exam, %s! Your final score is %d/10.", name, score);

    return 0;
}