//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fortune_teller();

int main() {
    fortune_teller();
    return 0;
}

void fortune_teller() {
    char user_input;
    int prediction_prob = 0;
    int question_count = 0;
    int yes_count = 0;

    srand(time(NULL)); // Initialize random seed

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I will use my psychic powers to answer your yes/no questions!\n");

    while(1) {
        printf("\nEnter your yes/no question: ");
        scanf(" %c", &user_input);

        question_count++;

        // Check if user wants to quit
        if(user_input == 'q') {
            printf("\nThanks for playing! Come back again soon!\n");
            break;
        }

        // Calculate probability of yes prediction
        prediction_prob = (rand() % 100) + 1;

        // Output prediction based on probability
        if(prediction_prob < 50) {
            printf("\n\t-> I see a no in your future!\n");
        } else {
            printf("\n\t-> Yes! Definitely yes!\n");
            yes_count++;
        }

        // Determine if a fortune has been given yet
        if(question_count % 5 == 0) {
            if(yes_count >= 3) {
                printf("\n\t-> Congratulations! You are blessed by the fortune gods!\n");
            } else {
                printf("\n\t-> Better luck next time!\n");
            }

            // Reset counters after fortune has been given
            question_count = yes_count = 0;
        }
    }
}