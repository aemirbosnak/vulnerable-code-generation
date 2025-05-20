//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define constants for the number of elements in the table and the max length of element name
#define NUM_ELEMENTS 118
#define MAX_NAME_LENGTH 50

// define a struct to hold information about each element
typedef struct{
    int atomic_number;
    char symbol[3];
    char name[MAX_NAME_LENGTH];
    float atomic_mass;
} Element;

// create an array of element structs to hold all the elements of the periodic table
Element periodic_table[NUM_ELEMENTS] = {
    {1, "H", "Hydrogen", 1.008},
    {2, "He", "Helium", 4.003},
    {3, "Li", "Lithium", 6.941},
    {4, "Be", "Beryllium", 9.012},
    {5, "B", "Boron", 10.81},
    // and so on for all the elements in the table
};

// define a function to retrieve a random element from the table
Element get_random_element(){
    int index = rand() % NUM_ELEMENTS;
    return periodic_table[index];
}

// define a struct to hold information about each player
typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

// define a function to prompt the user to enter the name of a player
void get_player_name(Player *player){
    printf("Enter your name: ");
    fgets(player->name, MAX_NAME_LENGTH, stdin);
    // remove newline character from input
    player->name[strcspn(player->name, "\n")] = 0;
}

// define a function to display the current leaderboard
void display_leaderboard(Player *players, int num_players){
    printf("\n-----LEADERBOARD-----\n");
    for(int i=0; i<num_players; i++){
        printf("%s: %d\n", players[i].name, players[i].score);
    }
    printf("---------------------\n\n");
}

int main(){
    // seed the random number generator
    srand(time(NULL));

    // prompt the user to enter the number of players
    int num_players;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);
    getchar(); // consume extra newline character

    // initialize an array of player structs
    Player players[num_players];

    // prompt each player to enter their name
    for(int i=0; i<num_players; i++){
        printf("Player %d:\n", i+1);
        get_player_name(&players[i]);
    }

    // display the leaderboard before the quiz starts
    display_leaderboard(players, num_players);

    // play the quiz
    int num_questions = 5; // play 5 questions for each player
    for(int i=0; i<num_players; i++){
        // initialize the player's score to zero
        players[i].score = 0;

        // play the quiz for this player
        printf("%s, it's your turn to play.\n", players[i].name);
        for(int q=0; q<num_questions; q++){
            // get a random element from the periodic table
            Element element = get_random_element();

            // prompt the player with the atomic number of the element
            int guess;
            printf("What is the atomic number of %s? ", element.name);
            scanf("%d", &guess);
            getchar(); // consume extra newline character

            // check if the player's guess is correct
            if(guess == element.atomic_number){
                printf("Correct!\n");
                players[i].score++;
            }
            else{
                printf("Incorrect. The atomic number of %s is %d.\n", element.name, element.atomic_number);
            }
        }

        // display the player's score after the quiz
        printf("%s, you scored %d out of %d.\n", players[i].name, players[i].score, num_questions);

        // update the leaderboard
        display_leaderboard(players, num_players);
    }

    printf("Thanks for playing!\n");

    return 0;
}