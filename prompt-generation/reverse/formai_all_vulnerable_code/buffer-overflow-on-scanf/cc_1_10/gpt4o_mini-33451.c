//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 100
#define NAME_LENGTH 50
#define SCORE_FILE "scores.txt"

typedef struct {
    char name[NAME_LENGTH];
    int score;
} Player;

void save_scores(Player players[], int count) {
    FILE *file = fopen(SCORE_FILE, "w");
    if (!file) {
        perror("Unable to open score file for writing");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d\n", players[i].name, players[i].score);
    }
    
    fclose(file);
}

void load_scores(Player players[], int *count) {
    FILE *file = fopen(SCORE_FILE, "r");
    if (file) {
        while (fscanf(file, "%s %d", players[*count].name, &players[*count].score) != EOF) {
            (*count)++;
        }
        fclose(file);
    }
}

void display_top_scores(Player players[], int count) {
    if (count == 0) {
        printf("No scores available.\n");
        return;
    }
    
    printf("Top Scores:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s: %d\n", i + 1, players[i].name, players[i].score);
    }
}

void sort_scores(Player players[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (players[i].score < players[j].score) {
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int count = 0;
    char input[100];
    
    load_scores(players, &count);
    sort_scores(players, count);
    
    while (1) {
        printf("Enter player name (or 'exit' to finish): ");
        scanf("%s", input);
        
        if (strcmp(input, "exit") == 0) {
            break;
        }
        
        strcpy(players[count].name, input);
        
        printf("Enter score for %s: ", input);
        scanf("%d", &players[count].score);
        count++;
        
        if (count >= MAX_PLAYERS) {
            printf("Maximum number of players reached.\n");
            break;
        }
    }

    save_scores(players, count);
    
    sort_scores(players, count);
    display_top_scores(players, count);
    
    return 0;
}