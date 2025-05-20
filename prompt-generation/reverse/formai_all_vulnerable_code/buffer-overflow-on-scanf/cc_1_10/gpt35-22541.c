//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

// Function prototypes
void printInstructions(void);
bool playGame(void);
int calculateScore(int, int, double);

int main()
{
    // Seed the random number generator
    srand(time(NULL));
    
    // Print instructions to the user
    printInstructions();
    
    // Ask if user wants to play
    char playAgain;
    do {
        printf("\nDo you want to start playing? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain != 'y' && playAgain != 'n');
    
    if (playAgain == 'n') {
        printf("\nOkay, see you later!");
        return 0;
    }
    
    // Play game
    bool continuePlaying = true;
    int totalScore = 0;
    int totalWordsTyped = 0;
    double totalTime = 0;
    
    while (continuePlaying) {
        bool roundResult = playGame();
        if (roundResult) {
            totalWordsTyped++;
            totalTime += 10.0;
            totalScore += calculateScore(totalWordsTyped, totalScore, totalTime);
            
            printf("\nCongratulations, you typed the word correctly!");
            printf(" Your score for this round is %d.\n", calculateScore(totalWordsTyped, totalScore, totalTime));
        } 
        else {
            printf("\nSorry, you made a mistake! Better luck next time.\n");
        }
        
        // Check if user wants to play another round
        do {
            printf("\nDo you want to play another round? (y/n): ");
            scanf(" %c", &playAgain);
        } while (playAgain != 'y' && playAgain != 'n');
        
        if (playAgain == 'n') {
            printf("\nYou scored a total of %d points and typed %d words in %.2f seconds!", totalScore, totalWordsTyped, totalTime);
            printf("\nThanks for playing, bye!");
            continuePlaying = false;
        }
    }
    
    return 0;
}

// Function definitions

/*
 * Prints instructions for the typing speed test game.
 */
void printInstructions(void)
{
    printf("Welcome to the Typing Speed Test game!\n\n");
    printf("In this game, you will be shown a random word and you have to type it as fast as possible.\n");
    printf("You will get 10 seconds to type each word.\n\n");
    printf("For every word you type correctly, you will earn points as follows:\n\n");
    printf("\t1st word: 10 points\n");
    printf("\t2nd word: 20 points\n");
    printf("\t3rd word: 30 points\n");
    printf("\t4th word: 40 points\n");
    printf("\tetc.\n\n");
}

/*
 * Plays one round of the typing speed test game.
 * Returns true if user types the word correctly, false otherwise.
 */
bool playGame(void)
{
    // Generate random word
    char words[][15] = {"apple", "banana", "pear", "orange", "grape", 
                        "pineapple", "strawberry", "watermelon", "peach", "kiwi"};
    
    int numWords = sizeof(words) / sizeof(words[0]);
    int randomIndex = rand() % numWords;
    
    char randomWord[15];
    strcpy(randomWord, words[randomIndex]);
    
    // Ask user to type the word
    printf("\nThe word is: %s\n", randomWord);
    printf("\nYou have 10 seconds to type the word.\n\n");
    
    clock_t start = clock();
    
    char typedWord[15];
    scanf("%s", typedWord);
    
    clock_t end = clock();
    
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    
    // Check if user typed the word correctly
    if (strcmp(randomWord, typedWord) == 0) {
        return true;
    } 
    else {
        return false;
    }
}

/*
 * Calculates the score for a round of the typing speed test game.
 */
int calculateScore(int numWordsTyped, int totalScore, double totalTime)
{
    int score = numWordsTyped * 10 + totalScore;
    
    if (numWordsTyped >= 4) {
        score += (numWordsTyped - 3) * 10;
    }
    
    if (totalTime <= 30) {
        score += 50;
    }
    
    return score;
}