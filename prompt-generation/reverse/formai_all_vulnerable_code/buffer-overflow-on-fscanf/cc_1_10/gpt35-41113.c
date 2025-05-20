//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STRING_SIZE 100

// Structure to store the alien words and their corresponding translation
struct AlienWord {
    char word[MAX_STRING_SIZE];
    char translation[MAX_STRING_SIZE];
};

// Structure to store player information
struct Player {
    int id;
    char name[MAX_STRING_SIZE];
};

// Function to read alien words and their translation from a file
void read_alien_words(struct AlienWord *alien_words, int num_words) {
    FILE *fptr = fopen("alien_words.txt", "r");
    if(fptr == NULL) {
        printf("Error: Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<num_words; i++) {
        fscanf(fptr, "%s %[^\n]s", alien_words[i].word, alien_words[i].translation);
    }

    fclose(fptr);
}

// Function to print the list of available alien words
void print_alien_words(struct AlienWord *alien_words, int num_words) {
    printf("\nAvailable Alien Words:\n");
    for(int i=0; i<num_words; i++) {
        printf("%s ", alien_words[i].word);
    }
    printf("\n\n");
}

// Function to get the player's name
void get_player_name(struct Player *player) {
    printf("Enter your name: ");
    scanf("%[^\n]s", player->name);
}

// Function to get the player's guess
void get_player_guess(char *guess) {
    printf("Enter your guess: ");
    scanf("%[^\n]s", guess);
}

// Function to check if the player's guess is correct
int is_guess_correct(char *guess, struct AlienWord *alien_words, int num_words) {
    for(int i=0; i<num_words; i++) {
        if(strcmp(guess, alien_words[i].word) == 0) {
            printf("%s\n\n", alien_words[i].translation);
            return 1;
        }
    }
    printf("Incorrect guess.\n\n");
    return 0;
}

int main() {
    // Number of alien words
    const int num_alien_words = 5;

    // Initialize alien words
    struct AlienWord alien_words[num_alien_words];
    read_alien_words(alien_words, num_alien_words);

    // Print available alien words
    print_alien_words(alien_words, num_alien_words);

    // Initialize players
    const int num_players = 2;
    struct Player players[num_players];
    for(int i=0; i<num_players; i++) {
        players[i].id = i+1;
        get_player_name(&players[i]);
    }

    // Start game round
    int current_player = 0;
    char guess[MAX_STRING_SIZE];
    while(1) {
        printf("%s's turn.\n", players[current_player].name);
        get_player_guess(guess);
        if(is_guess_correct(guess, alien_words, num_alien_words)) {
            printf("%s wins!\n", players[current_player].name);
            break;
        }
        current_player = (current_player + 1) % num_players;
    }

    return 0;
}