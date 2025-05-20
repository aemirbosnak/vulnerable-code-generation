//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 50
#define MAX_QUESTION_LENGTH 256
#define MAX_ANSWER_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

void initialize_players(Player players[], int count);
void sanitize_input(char* input, size_t size);
void get_player_names(Player players[], int count);
int ask_question(const char* question, const char* answer);
void play_game(Player players[], int player_count);
void display_scores(Player players[], int count);

int main() {
    int player_count;
    
    printf("Enter number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &player_count);

    if (player_count < 1 || player_count > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting.\n");
        return 1;
    }

    Player players[MAX_PLAYERS];
    initialize_players(players, player_count);
    play_game(players, player_count);
    display_scores(players, player_count);
    
    return 0;
}

void initialize_players(Player players[], int count) {
    get_player_names(players, count);
    for (int i = 0; i < count; i++) {
        players[i].score = 0;  // Initialize scores to 0
    }
}

void sanitize_input(char* input, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (input[i] == '\n') {
            input[i] = '\0'; // Replace newline with null terminator
            break;
        }
        if (!isalnum(input[i]) && !isspace(input[i])) {
            input[i] = '_'; // Replace invalid characters
        }
    }
}

void get_player_names(Player players[], int count) {
    char buffer[MAX_NAME_LENGTH];
    for (int i = 0; i < count; i++) {
        printf("Enter name for Player %d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        sanitize_input(buffer, sizeof(buffer));
        strncpy(players[i].name, buffer, MAX_NAME_LENGTH);
    }
}

int ask_question(const char* question, const char* answer) {
    char input[MAX_ANSWER_LENGTH];
    printf("%s\n", question);
    printf("Your answer: ");
    fgets(input, sizeof(input), stdin);
    sanitize_input(input, sizeof(input));
    
    return strcasecmp(input, answer) == 0; // Compare ignoring case
}

void play_game(Player players[], int player_count) {
    const char* questions[] = {
        "What is the capital of France? (hint: city) [Answer: Paris]",
        "What is 2 + 2? [Answer: 4]",
        "What programming language is known for its performance and systems programming? [Answer: C]",
    };
    const char* answers[] = {
        "Paris",
        "4",
        "C",
    };
    
    int total_questions = sizeof(questions) / sizeof(questions[0]);
    
    for (int i = 0; i < total_questions; i++) {
        for (int j = 0; j < player_count; j++) {
            printf("%s's turn:\n", players[j].name);
            if (ask_question(questions[i], answers[i])) {
                printf("Correct!\n");
                players[j].score++;
            } else {
                printf("Wrong! The correct answer was: %s\n", answers[i]);
            }
        }
    }
}

void display_scores(Player players[], int count) {
    printf("\nFinal Scores:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}