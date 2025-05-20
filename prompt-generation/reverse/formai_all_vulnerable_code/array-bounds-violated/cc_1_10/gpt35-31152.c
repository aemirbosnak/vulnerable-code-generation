//FormAI DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 4
#define MAX_WORDS 50
#define MAX_DICT_SIZE 10000

char dictionary[MAX_DICT_SIZE][100];
int dict_size;

struct Player {
    char name[20];
    int score;
    char words[MAX_WORDS][20];
    int num_words;
};

int read_dictionary(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        return 0;
    }
    int count = 0;
    char buffer[100];
    while (fgets(buffer, 100, fp) != NULL) {
        buffer[strlen(buffer)-1] = '\0';
        strcpy(dictionary[count], buffer);
        count++;
    }
    fclose(fp);
    dict_size = count;
    return 1;
}

int is_valid_word(char* word) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void add_word(struct Player* player, char* word) {
    if (is_valid_word(word)) {
        strcpy(player->words[player->num_words], word);
        player->num_words++;
        player->score += strlen(word);
    } else {
        printf("Invalid word: %s\n", word);
    }
}

void play_game() {
    printf("Welcome to the spell checking game!\n");
    printf("Please enter the number of players (max %d): ", MAX_PLAYERS);
    int num_players;
    scanf("%d", &num_players);
    getchar();

    struct Player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d name: ", i+1);
        fgets(players[i].name, 20, stdin);
        players[i].name[strlen(players[i].name)-1] = '\0';
        players[i].score = 0;
        players[i].num_words = 0;
    }

    char input[100];
    while (1) {
        printf("\nNew turn:\n");
        for (int i = 0; i < num_players; i++) {
            printf("%s, your turn:\n", players[i].name);
            fgets(input, 100, stdin);
            input[strlen(input)-1] = '\0';
        
            char* token = strtok(input, " ");
            while (token != NULL) {
                add_word(&players[i], token);
                token = strtok(NULL, " ");
            }
        }

        // Calculate winner
        int max_score = -1;
        int winners[MAX_PLAYERS];
        int num_winners = 0;
        for (int i = 0; i < num_players; i++) {
            printf("%s, your score: %d\n", players[i].name, players[i].score);
            if (players[i].score > max_score) {
                max_score = players[i].score;
                num_winners = 1;
                winners[0] = i;
            } else if (players[i].score == max_score) {
                winners[num_winners] = i;
                num_winners++;
            }
        }

        printf("Winner(s): ");
        for (int i = 0; i < num_winners; i++) {
            printf("%s ", players[winners[i]].name);
        }
        printf("\n\n");
    }
}

int main() {
    if (!read_dictionary("dictionary.txt")) {
        return 0;
    }
    play_game();
    return 0;
}