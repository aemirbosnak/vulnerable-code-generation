//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVEL 5
#define MAX_EFFORT 30

typedef struct {
    int level;
    int performance;
} Machine;

void print_instructions() {
    printf("Welcome to the Victorian Computing Machine Game!\n");
    printf("Your objective is to optimize the performance of the machine.\n");
    printf("Each level requires a different amount of effort (1-30).\n");
    printf("Choose your effort wisely to advance through all levels!\n");
}

int get_player_effort() {
    int effort;
    printf("Enter your effort (1 to %d): ", MAX_EFFORT);
    scanf("%d", &effort);
    while (effort < 1 || effort > MAX_EFFORT) {
        printf("Invalid input. Choose a number between 1 and %d: ", MAX_EFFORT);
        scanf("%d", &effort);
    }
    return effort;
}

int calculate_performance(int effort) {
    return (rand() % (effort + 1)) + 1;  // Random performance based on effort
}

void play_game() {
    Machine machine = {1, 0};
    int total_performance = 0;
    
    while (machine.level <= MAX_LEVEL) {
        printf("\n--- Level %d ---\n", machine.level);
        int effort = get_player_effort();
        
        machine.performance = calculate_performance(effort);
        printf("Your performance for level %d is: %d\n", machine.level, machine.performance);
        
        total_performance += machine.performance;
        
        if (machine.performance >= machine.level * 5) {
            printf("Congratulations! You have completed level %d.\n", machine.level);
            machine.level++;
        } else {
            printf("Alas! You have not optimized enough to progress.\n");
        }
        
        if (machine.level > MAX_LEVEL) {
            printf("You have successfully optimized the Victorian Computing Machine! Total performance: %d\n", total_performance);
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    print_instructions();
    play_game();
    return 0;
}