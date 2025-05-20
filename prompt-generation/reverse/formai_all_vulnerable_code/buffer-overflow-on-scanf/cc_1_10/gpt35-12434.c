//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 10
#define MAX_SYMBOL_LENGTH 3


typedef struct {
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
} Element;


void generate_elements(Element elements[MAX_ELEMENTS]){
    //List of elements
    char *symbols[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne"};
    int atomic_numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int i;
    for(i = 0; i < MAX_ELEMENTS; i++){
        strcpy(elements[i].symbol, symbols[i]);
        elements[i].atomic_number = atomic_numbers[i];
    }
}

void shuffle_elements(Element elements[MAX_ELEMENTS]){
    //Seed random generator
    srand(time(0));

    //Fisher-Yates shuffle
    int i;
    for(i = MAX_ELEMENTS-1; i > 0; i--){
        int j = rand() % (i+1);

        //Swap elements
        Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

void print_instructions(){
    printf("Welcome to the Periodic Table quiz!\n\n");
    printf("The game is simple. I will show you a symbol and you have to guess the atomic number of the element.\n");
    printf("You will have a maximum of 3 attempts per question. Good luck!\n\n");
}

void play_game(Element elements[MAX_ELEMENTS]){
    int i, num_attempts = 0, correct_answers = 0;

    for(i = 0; i < MAX_ELEMENTS; i++){
        printf("What is the atomic number of %s? ", elements[i].symbol);

        while(num_attempts < 3){
            int guess;
            scanf("%d", &guess);

            if(guess == elements[i].atomic_number){
                printf("Correct!\n");
                correct_answers++;
                num_attempts = 0;
                break;
            }
            else{
                printf("Wrong.\n");
                num_attempts++;
            }

            if(num_attempts < 3){
                printf("Try again: ");
            }
        }

        if(num_attempts == 3){
            printf("Sorry, you're out of attempts. The correct answer was %d.\n", elements[i].atomic_number);
            num_attempts = 0;
        }
    }

    printf("Game over! You got %d out of %d questions correct.\n", correct_answers, MAX_ELEMENTS);
}

int main(){
    Element elements[MAX_ELEMENTS];
    generate_elements(elements);
    shuffle_elements(elements);

    print_instructions();

    play_game(elements);

    return 0;
}