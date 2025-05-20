//FormAI DATASET v1.0 Category: Online Examination System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 20
#define MAX_CHOICES 4
#define MAX_NAME_LEN 20

typedef struct {
    char question[100];
    char choices[MAX_CHOICES][100];
    int correct_choice;
} Question;

typedef struct {
    char name[MAX_NAME_LEN];
    int score;
} Player;

Question questions[MAX_QUESTIONS];
Player players[100];
int num_players = 0;

void load_questions() {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file for reading.\n");
        exit(1);
    }
    int num_questions;
    fscanf(fp, "%d", &num_questions);
    for (int i = 0; i < num_questions; i++) {
        fgets(questions[i].question, 100, fp);
        fgets(questions[i].question, 100, fp);
        for (int j = 0; j < MAX_CHOICES; j++) {
            fgets(questions[i].choices[j], 100, fp);
        }
        fscanf(fp, "%d", &questions[i].correct_choice);
    }
    fclose(fp);
}

void save_scores() {
    FILE *fp = fopen("scores.txt", "w");
    if (fp == NULL) {
        printf("Error: Unable to open file for writing.\n");
        exit(1);
    }
    fprintf(fp, "%d\n", num_players);
    for (int i = 0; i < num_players; i++) {
        fprintf(fp, "%s %d\n", players[i].name, players[i].score);
    }
    fclose(fp);
}

void load_scores() {
    FILE *fp = fopen("scores.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file for reading.\n");
        return;
    }
    fscanf(fp, "%d", &num_players);
    for (int i = 0; i < num_players; i++) {
        fscanf(fp, "%s %d", players[i].name, &players[i].score);
    }
    fclose(fp);
}

void start_quiz(Player *player) {
    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nQuestion %d:\n\n%s\n", i+1, questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("%d) %s", j+1, questions[i].choices[j]);
        }
        int choice;
        printf("\nEnter your answer (1-%d): ", MAX_CHOICES);
        scanf("%d", &choice);
        if (choice == questions[i].correct_choice) {
            score++;
        }
    }
    player->score = score;
    printf("\n\n===== Quiz Results =====\n\n");
    printf("Player Name: %s\n", player->name);
    printf("Score: %d/%d\n", score, MAX_QUESTIONS);
}

void display_scores() {
    printf("\n\n===== Quiz High Scores =====\n\n");
    if (num_players == 0) {
        printf("No high scores yet.\n");
    }
    for (int i = 0; i < num_players; i++) {
        printf("%s - %d\n", players[i].name, players[i].score);
    }
}

int main() {
    load_questions();
    load_scores();

    char choice = ' ';
    do {
        printf("\n\n===== Online Quiz Menu =====\n\n");
        printf("1. Start Quiz\n");
        printf("2. High Scores\n");
        printf("3. Exit\n");
        printf("\nEnter your choice (1-3): ");
        scanf(" %c", &choice);
        switch(choice) {
            case '1': {
                Player player;
                printf("\nEnter your name: ");
                scanf("%s", player.name);
                start_quiz(&player);
                players[num_players] = player;
                num_players++;
                save_scores();
                break;
            }
            case '2':
                display_scores();
                break;
            case '3':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    } while (choice != '3');
    return 0;
}