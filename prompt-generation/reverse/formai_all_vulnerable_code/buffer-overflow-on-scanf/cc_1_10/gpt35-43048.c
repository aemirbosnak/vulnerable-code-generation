//FormAI DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 10
int generate_random_number(){
    int random_number;
    srand(time(NULL));
    random_number = rand() % 10 + 1;
    return random_number;
}

// Function to print a funny joke
void print_joke(){
    printf("\n Why was the math book sad?\n Because it had too many problems.\n\n");
}

int main(){

    int first_number, second_number, result, answer;

    printf("\nWelcome to the Funny Math Exercise Program!\n");
    print_joke(); // printing the joke

    while(1){

        first_number = generate_random_number();
        second_number = generate_random_number();

        printf("What is the result of %d multiplied by %d?\n", first_number, second_number);

        result = first_number * second_number;

        scanf("%d", &answer);

        if(answer == result){
            printf("Good job! You are a math genius!\n");
        }else{
            printf("Oh no! That's not correct! The correct answer is %d.\n", result);
            printf("Don't worry, you can try again!\n");
        }

        printf("Do you want to play again? Type 1 for YES or 0 for NO.\n");

        int play_again;
        scanf("%d", &play_again);

        if(play_again == 0){
            printf("Thanks for playing the Funny Math Exercise Program! See you next time!\n");
            break;
        }

    }

    return 0;
}