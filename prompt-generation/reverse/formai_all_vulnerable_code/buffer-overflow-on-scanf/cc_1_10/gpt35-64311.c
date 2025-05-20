//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Player struct
typedef struct player {
    char name[20];
    int age;
    float weight;
    float height;
    int score;
} player;

//Function to initialise player
player create_player() {
    player new_player;
    printf("\nEnter your name: ");
    scanf("%s", new_player.name);
    printf("\nEnter your age: ");
    scanf("%d", &new_player.age);
    printf("\nEnter your weight(in kgs): ");
    scanf("%f", &new_player.weight);
    printf("\nEnter your height(in cms): ");
    scanf("%f", &new_player.height);
    new_player.score = 0;
    return new_player;
}

//Function to get random number between 1 and 10
int get_random_number() {
    srand(time(NULL));
    int number = rand() % 10 + 1;
    return number;
}

//Function for player to run 1 km
void run_kilometer(player *p) {
    printf("\nYou are running 1 km...");
    int time_taken = get_random_number() * 60; //Randomly generate time taken
    printf("\nYou have completed your run in %d seconds", time_taken);
    int points_earned = 25; //25 points for completing 1 km run
    if (time_taken < 480) { //If time taken is less than or equal to 8 minutes(480 seconds)
        printf("\nCongratulations! You have earned a bonus of 25 points for completing the run in less than 8 minutes(i.e. 480 seconds)");
        points_earned += 25;
    }
    p->score += points_earned;
    printf("\nYou have earned %d points for this run", points_earned);
}

//Function for player to do 50 push-ups
void do_pushups(player *p) {
    printf("\nYou are doing 50 push-ups...");
    int time_taken = get_random_number() * 10; //Randomly generate time taken
    printf("\nYou have completed 50 push-ups in %d seconds", time_taken);
    int points_earned = 50; //50 points for completing 50 push-ups
    if (time_taken < 30) { //If time taken is less than or equal to 30 seconds
        printf("\nCongratulations! You have earned a bonus of 25 points for completing the push-ups in less than 30 seconds");
        points_earned += 25;
    }
    p->score += points_earned;
    printf("\nYou have earned %d points for this exercise", points_earned);
}

int main() {
    int num_players;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    player players[num_players];
    for (int i = 0; i < num_players; i++) {
        printf("\nPlayer %d", i+1);
        players[i] = create_player(); //initialise player
    }

    int choice;
    do {
        printf("\n\nEnter your choice:");
        printf("\n1. Run 1 km");
        printf("\n2. Do 50 push-ups");
        printf("\n3. Quit");
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                for (int i = 0; i < num_players; i++) {
                    printf("\n***Player %s is running***", players[i].name);
                    run_kilometer(&players[i]); //player runs 1 km
                }
                break;
            case 2:
                for (int i = 0; i < num_players; i++) {
                    printf("\n***Player %s is doing push-ups***", players[i].name);
                    do_pushups(&players[i]); //player does 50 push-ups
                }
                break;
            case 3:
                printf("\nQuitting program...");
                break;
            default:
                printf("\nInvalid choice. Try again.");
                break;
        }
    } while (choice != 3);

    for (int i = 0; i < num_players; i++) {
        printf("\n\nPlayer %s's fitness report:", players[i].name);
        printf("\nAge: %d", players[i].age);
        printf("\nWeight: %.2f kgs", players[i].weight);
        printf("\nHeight: %.2f cms", players[i].height);
        printf("\nScore: %d", players[i].score);
    }

    return 0;
}