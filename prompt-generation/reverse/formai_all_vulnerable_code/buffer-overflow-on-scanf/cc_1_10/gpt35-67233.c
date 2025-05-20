//FormAI DATASET v1.0 Category: Online Examination System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 10

int main() {
    srand(time(NULL)); // seed the random number generator
    
    int score = 0;
    char answers[NUM_QUESTIONS];
    
    // generate random questions and answers for the exam
    char questions[NUM_QUESTIONS][256] = {
        {"What is the capital of Italy?\n(a) Madrid\n(b) Rome\n(c) Paris\n(d) Berlin\n"},
        {"What is the largest planet in our solar system?\n(a) Saturn\n(b) Mars\n(c) Jupiter\n(d) Venus\n"},
        {"What is the smallest country in the world?\n(a) Monaco\n(b) San Marino\n(c) Vatican City\n(d) Liechtenstein\n"},
        {"What is the chemical symbol for gold?\n(a) Au\n(b) Ag\n(c) Fe\n(d) Cu\n"},
        {"What is the tallest mountain in the world?\n(a) Kilimanjaro\n(b) Mount Everest\n(c) Mount Fuji\n(d) Mount McKinley\n"},
        {"What is the smallest particle in the universe?\n(a) Atom\n(b) Proton\n(c) Neutron\n(d) Electron\n"},
        {"What is the capital of Australia?\n(a) Sydney\n(b) Melbourne\n(c) Brisbane\n(d) Canberra\n"},
        {"What is the largest ocean in the world?\n(a) Pacific Ocean\n(b) Indian Ocean\n(c) Atlantic Ocean\n(d) Arctic Ocean\n"},
        {"What is the primary language spoken in Brazil?\n(a) Portuguese\n(b) Spanish\n(c) French\n(d) Italian\n"},
        {"What is the longest river in Africa?\n(a) Congo River\n(b) Nile River\n(c) Niger River\n(d) Zambezi River\n"}
    };
    
    char answers_key[NUM_QUESTIONS] = {'b', 'c', 'c', 'a', 'b', 'a', 'd', 'a', 'a', 'b'};
    
    // display instructions to the user
    printf("Welcome to the Online Examination System!\n");
    printf("You will be presented with %d multiple choice questions.\n", NUM_QUESTIONS);
    printf("Select the correct answer by typing in the letter choice (a, b, c, or d).\n");
    printf("Good luck!\n\n");
    
    // loop through each question and get the user's answer
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("%s", questions[i]);
        scanf(" %c", &answers[i]);
        printf("\n");
    }
    
    // grade the exam and display the results
    printf("Grading exam...\n\n");
    
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (answers[i] == answers_key[i]) {
            printf("Question %d: Correct\n", i+1);
            score++;
        } else {
            printf("Question %d: Incorrect (Correct answer: %c)\n", i+1, answers_key[i]);
        }
    }
    
    printf("\nFinal Score: %d/%d\n", score, NUM_QUESTIONS);
    
    return 0;
}