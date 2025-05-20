//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PLAYERS 5
#define BUFFER_SIZE 256

typedef struct {
    char text[BUFFER_SIZE];
    int player_id;
} Player;

Player players[MAX_PLAYERS];
pthread_mutex_t lock;

void* generate_ascii_art(void* arg) {
    Player* p = (Player*)arg;
    char* text = p->text;
    printf("Player %d's ASCII Art:\n", p->player_id);
    
    // Simple ASCII art algorithm
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == 'A') {
            printf("   /\\ \n  /  \\ \n /____\\ \n |    | \n");
        } else if (text[i] == 'B') {
            printf("|\\    | \n| |\\   | \n| | \\  | \n|_|  \\_| \n");
        } else if (text[i] == 'C') {
            printf("  _____ \n /     \\ \n|       |\n \\_____/\n");
        }
        // Add more letters as needed
        else {
            printf("%c ", text[i]); // print unhandled characters as is
        }
    }
    printf("\n");
    pthread_exit(NULL);
}

void prompt_player_input(int player_id) {
    printf("Player %d, enter your text (max %d characters): ", player_id, BUFFER_SIZE - 1);
    fflush(stdout);
    pthread_mutex_lock(&lock);
    fgets(players[player_id - 1].text, BUFFER_SIZE, stdin);
    players[player_id - 1].text[strcspn(players[player_id - 1].text, "\n")] = 0; // Remove newline
    players[player_id - 1].player_id = player_id;
    pthread_mutex_unlock(&lock);
}

int main() {
    pthread_t threads[MAX_PLAYERS];
    int player_count;

    pthread_mutex_init(&lock, NULL);

    printf("Welcome to the Multiplayer ASCII Art Generator!\n");
    printf("Enter number of players (up to %d): ", MAX_PLAYERS);
    scanf("%d", &player_count);
    if (player_count > MAX_PLAYERS) {
        player_count = MAX_PLAYERS;
    }

    while (1) {
        for (int i = 1; i <= player_count; i++) {
            getchar(); // To consume newline character after scanf
            prompt_player_input(i);
            pthread_create(&threads[i - 1], NULL, generate_ascii_art, (void*)&players[i - 1]);
        }

        for (int i = 0; i < player_count; i++) {
            pthread_join(threads[i], NULL);
        }

        char choice;
        printf("Do you want to continue? (y/n): ");
        getchar(); // To consume newline character after last input
        choice = getchar();
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    pthread_mutex_destroy(&lock);
    printf("Thank you for playing! Goodbye!\n");
    return 0;
}