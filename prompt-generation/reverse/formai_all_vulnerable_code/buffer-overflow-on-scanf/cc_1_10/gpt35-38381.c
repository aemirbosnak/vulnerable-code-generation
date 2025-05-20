//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_QUESTION 5 // maximum number of questions in a quiz
#define MAX_OPTION 4 // maximum number of options for a question
#define MAX_NAME_LEN 40 // maximum length of a player name
#define MAX_ATTEMPTS 3 // maximum number of attempts per question

// function to print the main menu
void printMenu() {
    printf("\n===== PERIODIC TABLE QUIZ =====\n");
    printf("1. Start Quiz\n");
    printf("2. View High Scores\n");
    printf("3. Quit\n");
    printf("Enter Choice: ");
}

// function to start the quiz
void startQuiz() {
    char names[MAX_QUESTION][MAX_NAME_LEN]; // to store names of elements
    char symbols[MAX_QUESTION][MAX_OPTION][3]; // to store symbols of elements
    char correct_answers[MAX_QUESTION][3]; // to store correct answer for each question
    char player_answers[MAX_QUESTION][MAX_ATTEMPTS][3]; // to store player's answers for each question
    int attempts[MAX_QUESTION]; // to store number of attempts for each question
    int scores[MAX_QUESTION]; // to store scores for each question
    int total_score = 0; // to store total score of the player
    int i, j, k, l; // loop variables

    // initialize random seed
    srand(time(NULL));

    // read periodic table data from file
    FILE *fp = fopen("periodic_table.txt", "r");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // read data
    for(i=0; i<MAX_QUESTION; i++) {
        fscanf(fp, "%s", names[i]);
        for(j=0; j<MAX_OPTION; j++) {
            fscanf(fp, "%s", symbols[i][j]);
        }
        fscanf(fp, "%s", correct_answers[i]);
    }

    // close file pointer
    fclose(fp);

    // start quiz
    printf("\n===== PERIODIC TABLE QUIZ =====\n");
    printf("*** Rules: You have 3 attempts to answer each question ***\n");
    printf("*** Only the first answer will be counted for each question ***\n");
    printf("*** Each correct answer is worth 10 points ***\n");

    // ask player's name
    char player_name[MAX_NAME_LEN];
    printf("\nEnter your name: ");
    scanf("%s", player_name);
    printf("\nHello %s, let's start the quiz!\n", player_name);

    // shuffle questions
    for(i=0; i<MAX_QUESTION; i++) {
        j = rand() % MAX_QUESTION;
        if(i != j) {
            // swap names
            strcpy(names[i], names[i]+j);
            strcpy(names[i]+j, names[i]);
            strcpy(names[i], names[i]+j);

            // swap symbols
            for(k=0; k<MAX_OPTION; k++) {
                strcpy(symbols[i][k], symbols[i][k]+j);
                strcpy(symbols[i][k]+j, symbols[i][k]);
                strcpy(symbols[i][k], symbols[i][k]+j);
            }

            // swap correct answer
            char temp[3];
            strcpy(temp, correct_answers[i]+j);
            strcpy(correct_answers[i]+j, correct_answers[i]);
            strcpy(correct_answers[i], temp);
        }
    }

    for(i=0; i<MAX_QUESTION; i++) {
        // reset scores and attempts for current question
        scores[i] = 0;
        attempts[i] = 0;

        // ask question
        printf("\n===== QUESTION %d =====\n", i+1);
        printf("What is the symbol of %s?\n", names[i]);

        // shuffle options
        for(j=0; j<MAX_OPTION; j++) {
            k = rand() % MAX_OPTION;
            if(j != k) {
                // swap symbols
                char temp[3];
                strcpy(temp, symbols[i][j]+k);
                strcpy(symbols[i][j]+k, symbols[i][j]);
                strcpy(symbols[i][j], temp);
            }
        }

        // print options
        for(j=0; j<MAX_OPTION; j++) {
            printf("%d. %s\n", j+1, symbols[i][j]);
        }

        // read player answer
        printf("Enter your choice: ");
        scanf("%s", player_answers[i][attempts[i]]);

        while(strcmp(player_answers[i][attempts[i]], "1") != 0 && strcmp(player_answers[i][attempts[i]], "2") != 0 && strcmp(player_answers[i][attempts[i]], "3") != 0 && strcmp(player_answers[i][attempts[i]], "4") != 0) {
            printf("Invalid choice. Enter again: ");
            scanf("%s", player_answers[i][attempts[i]]);
        }

        // check answer
        if(strcmp(player_answers[i][attempts[i]], correct_answers[i]) == 0) {
            // correct answer
            scores[i] = 10;
            total_score += 10;
            printf("Correct! You got 10 points.\n");
        }
        else {
            // wrong answer
            total_score += 0;
            printf("Wrong! You got 0 points.\n");
        }

        // increase attempt count
        attempts[i]++;

        // check remaining attempts
        while(attempts[i] < MAX_ATTEMPTS) {
            printf("You have %d attempts left.\n", MAX_ATTEMPTS - attempts[i]);

            // read player answer
            printf("Enter your choice: ");
            scanf("%s", player_answers[i][attempts[i]]);

            while(strcmp(player_answers[i][attempts[i]], "1") != 0 && strcmp(player_answers[i][attempts[i]], "2") != 0 && strcmp(player_answers[i][attempts[i]], "3") != 0 && strcmp(player_answers[i][attempts[i]], "4") != 0) {
                printf("Invalid choice. Enter again: ");
                scanf("%s", player_answers[i][attempts[i]]);
            }

            // check answer
            if(strcmp(player_answers[i][attempts[i]], correct_answers[i]) == 0) {
                // correct answer
                scores[i] = 10;
                total_score += 10;
                printf("Correct! You got 10 points.\n");
                break;
            }
            else {
                // wrong answer
                total_score += 0;
                printf("Wrong! You got 0 points.\n");
            }

            // increase attempt count
            attempts[i]++;
        }

        // check if all attempts are exhausted
        if(attempts[i] == MAX_ATTEMPTS) {
            printf("You have exhausted all attempts. The correct answer is %s.\n", correct_answers[i]);
        }
    }

    // print scorecard
    printf("\n===== SCORECARD =====\n");
    printf("Player: %s\n", player_name);
    printf("Total score: %d\n", total_score);
    printf("Question  Score  Attempts  Correct Answer  Your Answer\n");
    for(i=0; i<MAX_QUESTION; i++) {
        char correct[3];
        if(scores[i] == 10) {
            strcpy(correct, "YES");
        }
        else {
            strcpy(correct, "NO");
        }

        printf("%-9d %-6d %-9d %-15s %-10s\n", i+1, scores[i], attempts[i], correct_answers[i], player_answers[i][0]);
    }

    // write score to file
    FILE *fs = fopen("scores.txt", "a");
    if(fs == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fs, "%s\t%d\n", player_name, total_score);

    // close file pointer
    fclose(fs);
}

// function to view high scores
void viewScores() {
    printf("\n===== HIGH SCORES =====\n");

    // read scores from file
    FILE *fp = fopen("scores.txt", "r");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char name[MAX_NAME_LEN];
    int score;
    printf("Rank  Player Name  Score\n");
    int rank = 1;

    while(fscanf(fp, "%s\t%d", name, &score) != EOF) {
        printf("%-5d %-12s %d\n", rank++, name, score);
    }

    // close file pointer
    fclose(fp);
}

int main() {
    int choice; // variable to store user choice

    do {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1: startQuiz();
                    break;

            case 2: viewScores();
                    break;

            case 3: printf("Quitting...\n");
                    break;

            default: printf("Invalid choice. Try again.\n");
                     break;
        }
    } while(choice != 3);

    return 0;
}