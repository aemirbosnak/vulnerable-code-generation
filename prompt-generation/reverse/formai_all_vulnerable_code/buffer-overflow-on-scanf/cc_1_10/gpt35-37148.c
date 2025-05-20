//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 5
#define MAX_QUESTIONS 10
#define MAX_ANSWER_SIZE 10
#define ELEMENTS 118

struct Player {
    char name[30];
    int score;
};

int get_random_element();
void get_element_name(int element, char* name);
int ask_question(int element);
void get_player_name(int player_number, char* name);
void display_scores(struct Player* players, int num_players);
void sort_scores(struct Player* players, int num_players);
void play_game(struct Player* players, int num_players);

int main() {
    // Set random seed
    srand(time(NULL));
    
    // Define players
    struct Player players[MAX_PLAYERS];
    int num_players = 0;
    char name[30];
    char response[10];
    
    // Get player names
    printf("Enter the number of players (max 5): ");
    scanf("%d", &num_players);
    
    for (int i = 0; i < num_players; i++) {
        get_player_name(i+1, name);
        strcpy(players[i].name, name);
        players[i].score = 0;
    }
    
    // Play game
    play_game(players, num_players);
    
    // Sort and display scores
    sort_scores(players, num_players);
    display_scores(players, num_players);
    
    return 0;
}

int get_random_element() {
    return rand() % ELEMENTS + 1;
}

void get_element_name(int element, char* name) {
    switch(element) {
        case 1:
            strcpy(name, "Hydrogen");
            break;
        case 2:
            strcpy(name, "Helium");
            break;
        // omitted for brevity
        case 118:
            strcpy(name, "Oganesson");
            break;
        default:
            strcpy(name, "");
    }
}

int ask_question(int element) {
    char name[MAX_ANSWER_SIZE];
    char answer[MAX_ANSWER_SIZE];
    
    get_element_name(element, name);
    
    printf("What is the symbol for %s?\n", name);
    scanf("%s", answer);
    
    return strcmp(answer, "H") == 0;
}

void get_player_name(int player_number, char* name) {
    printf("Enter name for player %d: ", player_number);
    scanf("%s", name);
}

void display_scores(struct Player* players, int num_players) {
    printf("\nScores:\n");
    
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

void sort_scores(struct Player* players, int num_players) {
    for (int i = 0; i < num_players; i++) {
        for (int j = i+1; j < num_players; j++) {
            if (players[j].score > players[i].score) {
                struct Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
}

void play_game(struct Player* players, int num_players) {
    int element, is_correct;
    
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        element = get_random_element();
        
        for (int j = 0; j < num_players; j++) {
            get_player_name(j+1, players[j].name);
            is_correct = ask_question(element);
            players[j].score += is_correct;
            printf("%s's score: %d\n", players[j].name, players[j].score);
        }
    }
}