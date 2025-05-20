//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: multiplayer
#include <stdio.h>
#include <stdbool.h>

#define MAX_PLAYERS 4
#define MAX_RESUMES 10

// Resume Parsing System data structure
struct Resume {
    char* name;
    int experience;
    char* skills;
};

// Multilayered game data structure
struct Game {
    int num_players;
    struct Resume resumes[MAX_RESUMES];
};

// Prints out all resumes in the game
void print_resumes(struct Game* game) {
    printf("Resumes:\n");
    for (int i = 0; i < MAX_RESUMES; i++) {
        if (game->resumes[i].name != NULL) {
            printf("%d. Name: %s\n", i+1, game->resumes[i].name);
            printf("   Experience: %d years\n", game->resumes[i].experience);
            printf("   Skills: %s\n", game->resumes[i].skills);
        }
    }
}

// Adds a new resume to the game
void add_resume(struct Game* game, char* name, int experience, char* skills) {
    for (int i = 0; i < MAX_RESUMES; i++) {
        if (game->resumes[i].name == NULL) {
            game->resumes[i].name = name;
            game->resumes[i].experience = experience;
            game->resumes[i].skills = skills;
            printf("%s's resume added to the game.\n", name);
            return;
        }
    }
    printf("Could not add %s's resume. Game is full.\n", name);
}

// Determines the winner of the game based on experience and skills
void determine_winner(struct Game* game) {
    int max_exp = 0;
    int max_index = -1;
    for (int i = 0; i < MAX_RESUMES; i++) {
        if (game->resumes[i].name != NULL && game->resumes[i].experience > max_exp) {
            max_exp = game->resumes[i].experience;
            max_index = i;
        }
    }
    printf("The winner is %s with %d years of experience and skills in %s!\n", 
            game->resumes[max_index].name, game->resumes[max_index].experience, game->resumes[max_index].skills);
}

int main() {
    struct Game game = {0};
    bool playing = true;
    while (playing) {
        printf("\nWhat do you want to do?\n");
        printf("1. Add a new resume (only %d players allowed).\n", MAX_PLAYERS);
        printf("2. View all resumes.\n");
        printf("3. Determine the winner (minimum %d players required).\n", 2);
        printf("4. Quit game.\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (game.num_players == MAX_PLAYERS) {
                    printf("Game is full. Cannot add more resumes.\n");
                    break;
                }
                char name[20];
                int experience;
                char skills[50];
                printf("Enter the name: ");
                scanf("%s", name);
                printf("Enter the years of experience: ");
                scanf("%d", &experience);
                printf("Enter the skills: ");
                scanf("%s", skills);
                add_resume(&game, name, experience, skills);
                game.num_players++;
                break;
            case 2:
                print_resumes(&game);
                break;
            case 3:
                if (game.num_players < 2) {
                    printf("Minimum %d players required to determine the winner.\n", 2);
                    break;
                }
                determine_winner(&game);
                playing = false;
                break;
            case 4:
                playing = false;
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    }
    printf("Game over.\n");
    return 0;
}