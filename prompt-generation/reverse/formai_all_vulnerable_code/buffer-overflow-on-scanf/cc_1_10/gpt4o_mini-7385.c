//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HISTORY 10

void print_invasion_probability(int score, float base_chance) {
    float probability = base_chance * (1 + (score / 100.0));
    printf("\n*** The probability of an alien invasion is: %.2f%% ***\n", probability);
}

void display_history(float history[], int count) {
    printf("\n*** Invasion Probability History ***\n");
    for (int i = 0; i < count; i++) {
        printf("History [%d]: %.2f%%\n", i + 1, history[i]);
    }
    printf("*************************************\n");
}

void save_probability_to_history(float history[], int* count, float probability) {
    if (*count < MAX_HISTORY) {
        history[*count] = probability;
        (*count)++;
    } else {
        printf("\nHistory is full! Cannot save new probability.\n");
    }
}

int main() {
    srand(time(0));
    
    int user_input;
    float invasion_history[MAX_HISTORY] = {0};
    int history_count = 0;
    float base_chance = 10.0;

    printf("-------------------------------------------------\n");
    printf("       Welcome to the Alien Invasion Probability Calculator!\n");
    printf("-------------------------------------------------\n");
    printf("Please enter your score based on your fear of aliens (0 - 100): ");
    
    while (1) {
        scanf("%d", &user_input);
        
        if (user_input < 0 || user_input > 100) {
            printf("Invalid score! Please enter a score between 0 and 100: ");
        } else {
            break;
        }
    }

    int randomness = rand() % 100 + 1;
    printf("Your fear level: %d\n", user_input);
    print_invasion_probability(user_input, base_chance + randomness * 0.2);
    
    float current_probability = base_chance + randomness * 0.2 + (user_input / 100.0) * 20.0;
    save_probability_to_history(invasion_history, &history_count, current_probability);
    
    char choice;
    printf("Would you like to see your probability history? (y/n): ");
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y') {
        display_history(invasion_history, history_count);
    }
    
    printf("Do you want to calculate again? (y/n): ");
    scanf(" %c", &choice);
    while (choice == 'y' || choice == 'Y') {
        printf("Please enter your score based on your fear of aliens (0 - 100): ");
        
        while (1) {
            scanf("%d", &user_input);
            
            if (user_input < 0 || user_input > 100) {
                printf("Invalid score! Please enter a score between 0 and 100: ");
            } else {
                break;
            }
        }

        randomness = rand() % 100 + 1;
        printf("Your fear level: %d\n", user_input);
        print_invasion_probability(user_input, base_chance + randomness * 0.2);

        current_probability = base_chance + randomness * 0.2 + (user_input / 100.0) * 20.0;
        save_probability_to_history(invasion_history, &history_count, current_probability);
        
        printf("Would you like to see your probability history? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice == 'y' || choice == 'Y') {
            display_history(invasion_history, history_count);
        }
        
        printf("Do you want to calculate again? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("\nThanks for using the Alien Invasion Probability Calculator!\n");
    printf("May the odds be ever in your favor!\n");
    return 0;
}