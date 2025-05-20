//FormAI DATASET v1.0 Category: Table Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_game(){
    int guess, rand_num, num_guesses = 0;
    srand(time(NULL)); // seed the random number generator with the current time

    rand_num = rand() % 100 + 1;

    printf("Welcome to the Guessing Game! I have chosen a number between 1 and 100. Can you guess it?\n");

    do{
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if(guess < rand_num){
            printf("Too low! Try again.\n");
        } else if(guess > rand_num){
            printf("Too high! Try again.\n");
        }

        num_guesses++;

    } while(guess != rand_num);

    printf("Congratulations! You guessed my number in %d %s.\n", num_guesses, num_guesses == 1 ? "guess" : "guesses");
}

void print_table(int table_size){
    printf("=== Table of %d ===\n", table_size);
    for(int i = 1; i <= table_size; i++){
        for(int j = 1; j <= table_size; j++){
            printf("%3d ", i * j);
        }
        printf("\n");
    }
}

int main(){
    int choice;

    printf("Welcome to the Happy Table Game!\n");

    do{
        printf("Please choose from the following options:\n 1. Play the Guessing Game\n 2. Print a multiplication table\n 3. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                play_game();
                break;
            case 2:
                printf("Please enter the size of the table you would like to print: ");
                int table_size;
                scanf("%d", &table_size);
                print_table(table_size);
                break;
            case 3:
                printf("Thanks for playing! Goodbye.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice != 3);

    return 0;
}