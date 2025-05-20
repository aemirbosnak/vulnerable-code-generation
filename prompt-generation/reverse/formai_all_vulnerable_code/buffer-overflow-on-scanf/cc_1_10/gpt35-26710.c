//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_NAME_LENGTH 50
#define MAX_SKILLS 10
#define MAX_SKILL_LENGTH 20

typedef struct resume {
    char name[MAX_NAME_LENGTH];
    char skills[MAX_SKILLS][MAX_SKILL_LENGTH];
} Resume;

typedef struct player {
    char name[MAX_NAME_LENGTH];
    int score;
    Resume resumes[MAX_RESUMES];
} Player;

void print_menu();
void add_player(Player players[], int* num_players);
void parse_resume(Resume* resume);
void search_resumes(Player players[], int num_players);

int main() {
    Player players[10];
    int num_players = 0;
    int choice;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_player(players, &num_players);
                break;
            case 2:
                search_resumes(players, num_players);
                break;
            case 3:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void print_menu() {
    printf("\nResume Parsing System\n");
    printf("---------------------\n");
    printf("1. Add player\n");
    printf("2. Search resumes\n");
    printf("3. Exit\n");
}

void add_player(Player players[], int* num_players) {
    if (*num_players >= 10) {
        printf("Maximum number of players reached.\n");
        return;
    }

    printf("Enter player name: ");
    scanf("%s", players[*num_players].name);
    players[*num_players].score = 0;

    for (int i = 0; i < MAX_RESUMES; i++) {
        parse_resume(&players[*num_players].resumes[i]);
    }

    printf("Player added successfully!\n");
    (*num_players)++;
}

void parse_resume(Resume* resume) {
    printf("Enter resume name: ");
    scanf("%s", resume->name);

    printf("Enter skills (up to %d, enter 'done' to stop): \n", MAX_SKILLS);
    char input[MAX_SKILL_LENGTH];
    int i = 0;

    do {
        scanf("%s", input);
        if (strcmp(input, "done") == 0) break;
        strncpy(resume->skills[i++], input, MAX_SKILL_LENGTH);
    } while (i < MAX_SKILLS);

    printf("Resume added successfully!\n");
}

void search_resumes(Player players[], int num_players) {
    printf("Enter skill to search for: ");
    char skill[MAX_SKILL_LENGTH];
    scanf("%s", skill);

    printf("Results:\n");

    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < MAX_RESUMES; j++) {
            Resume* resume = &players[i].resumes[j];

            for (int k = 0; k < MAX_SKILLS; k++) {
                if (strcmp(resume->skills[k], skill) == 0) {
                    printf("Player: %s, Resume: %s, Skill: %s\n",
                        players[i].name, resume->name, skill);
                    players[i].score++;
                }
            }
        }
    }
}