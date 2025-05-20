//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int play_game();

int main() {
    int score = 0;
    char choice;
    srand(time(NULL)); // initialize random seed
    
    printf("Welcome to the Terminal-Based Science Game!\n\n");
    
    do {
        printf("----------------------------\n");
        printf("|   Choose an Option:      |\n");
        printf("|   1. Play Game           |\n");
        printf("|   2. How to Play         |\n");
        printf("|   3. Exit                |\n");
        printf("----------------------------\n\n");
        printf("Your Choice: ");
        scanf(" %c", &choice);
        
        switch(choice) {
            case '1':
                score += play_game();
                break;
            case '2':
                printf("\nInstructions:\n\n");
                printf("The game is simple. You will be given a question in the field of science.\n");
                printf("You must answer the question within 10 seconds. Failure to answer\n");
                printf("correctly or within the time limit will result in game over. The score\n");
                printf("will be calculated based on the number of questions correctly answered.\n\n");
                break;
            case '3':
                printf("Thanks for playing! Your final score is %d.\n", score);
                break;
            default:
                printf("Invalid input. Please choose a valid option.\n\n");
                break;
        }
    } while (choice != '3');
    
    return 0;
}

int play_game() {
    int score = 0;
    char answer;
    int time_limit = 10; // time limit for each question
    
    printf("\n\nStarting game...\n\n");
    
    // question 1
    printf("Question 1: What is the largest organ in the human body?\n");
    printf("A. Heart\nB. Lungs\nC. Liver\nD. Skin\n\n");
    printf("Answer: ");
    scanf(" %c", &answer);
    if (answer == 'D' || answer == 'd') {
        printf("Correct!\n");
        score += 1;
    } else {
        printf("Incorrect.\n");
        printf("The correct answer is D.\n");
        return score;
    }
    printf("\n");
    sleep(1); // wait for 1 second
    
    // question 2
    printf("Question 2: What is the chemical symbol for gold?\n");
    printf("A. Ag\nB. Au\nC. Cu\nD. Fe\n\n");
    printf("Answer: ");
    scanf(" %c", &answer);
    if (answer == 'B' || answer == 'b') {
        printf("Correct!\n");
        score += 1;
    } else {
        printf("Incorrect.\n");
        printf("The correct answer is B.\n");
        return score;
    }
    printf("\n");
    sleep(1); // wait for 1 second
    
    // question 3
    printf("Question 3: What is the smallest unit of matter?\n");
    printf("A. Atom\nB. Molecule\nC. Cell\nD. Electron\n\n");
    printf("Answer: ");
    scanf(" %c", &answer);
    if (answer == 'A' || answer == 'a') {
        printf("Correct!\n");
        score += 1;
    } else {
        printf("Incorrect.\n");
        printf("The correct answer is A.\n");
        return score;
    }
    printf("\n");
    sleep(1); // wait for 1 second
    
    // question 4
    printf("Question 4: What is the force that holds atoms together in a molecule?\n");
    printf("A. Magnetism\nB. Gravity\nC. Electromagnetism\nD. Chemical Bonds\n\n");
    printf("Answer: ");
    scanf(" %c", &answer);
    if (answer == 'D' || answer == 'd') {
        printf("Correct!\n");
        score += 1;
    } else {
        printf("Incorrect.\n");
        printf("The correct answer is D.\n");
        return score;
    }
    printf("\n");
    sleep(1); // wait for 1 second
    
    // question 5
    printf("Question 5: What is the process by which plants make their own food?\n");
    printf("A. Respiration\nB. Transpiration\nC. Photosynthesis\nD. Digestion\n\n");
    printf("Answer: ");
    scanf(" %c", &answer);
    if (answer == 'C' || answer == 'c') {
        printf("Correct!\n");
        score += 1;
    } else {
        printf("Incorrect.\n");
        printf("The correct answer is C.\n");
        return score;
    }
    printf("\n");
    sleep(1); // wait for 1 second
    
    printf("Congratulations! You have completed the game.\n");
    printf("Your score is %d out of 5.\n\n", score);
    return score;
}