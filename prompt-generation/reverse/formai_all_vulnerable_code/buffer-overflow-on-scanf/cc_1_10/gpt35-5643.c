//FormAI DATASET v1.0 Category: Ebook reader ; Style: multiplayer
#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define MAX_FILE_NAME 100
#define MAX_EBOOK_SIZE 1000

struct player {
    char name[50];
    int score;
};

// Function to read ebook from file
int read_ebook(char* file_name, char* ebook) {
    FILE* fp;
    if ((fp = fopen(file_name, "r")) == NULL) {
        printf("Error opening the ebook file.\n");
        return 0;
    }

    int c, i = 0;
    while ((c = fgetc(fp)) != EOF) {
        ebook[i++] = c;
        if (i >= MAX_EBOOK_SIZE) break;
    }
    ebook[i] = '\0';

    fclose(fp);
    return 1;
}

// Function to print ebook
void print_ebook(char* ebook) {
    printf("%s", ebook);
}

// Function to update player score
void update_score(struct player* p, int points) {
    p->score += points;
}

// Function to compare players based on their scores
int compare_scores(const void* pa, const void* pb) {
    struct player* a = (struct player*)pa;
    struct player* b = (struct player*)pb;

    return b->score - a->score;
}

// Main function
int main() {
    char file_name[MAX_FILE_NAME], ebook[MAX_EBOOK_SIZE];
    struct player players[4];
    int num_players = 0, i;

    printf("********** Welcome to the EBOOK reader game **********\n");
    printf("Enter the file name of the ebook you want to read: ");
    scanf("%s", file_name);

    if (!read_ebook(file_name, ebook)) {
        printf("Exiting game...\n");
        return 0;
    }

    while (num_players < 4) {
        printf("\nEnter name for player %d: ", num_players+1);
        scanf("%s", players[num_players].name);
        players[num_players].score = 0;
        num_players++;

        char choice;
        printf("\nDo you want to add another player? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'N' || choice == 'n') break;
    }

    // Loop for each chapter of the ebook
    for (i = 1;; i++) {
        printf("\n********** Chapter %d **********\n", i);
        print_ebook(ebook);

        // Loop for each player
        for (int j = 0; j < num_players; j++) {
            char response;
            printf("\n%s, did you like the chapter? (Y/N): ", players[j].name);
            scanf(" %c", &response);

            if (response == 'Y' || response == 'y') {
                printf("Great! You earn 10 points.\n");
                update_score(&players[j], 10);
            }
            else {
                printf("Too bad. You earn 5 points.\n");
                update_score(&players[j], 5);
            }
        }

        // Sort the players based on their scores
        qsort(players, num_players, sizeof(struct player), compare_scores);

        printf("\n********** Leaderboard **********\n");
        for (int j = 0; j < num_players; j++) {
            printf("%d. %s (%d points)\n", j+1, players[j].name, players[j].score);
        }

        // Prompt to continue or exit game
        char choice;
        printf("Do you want to continue reading? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'N' || choice == 'n') break;
    }

    printf("Thanks for playing the EBOOK reader game.\n");
    return 0;
}