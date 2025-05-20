//GPT-4o-mini DATASET v1.0 Category: Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <termios.h>
#include <fcntl.h>

#define SCREEN_WIDTH 20
#define SCREEN_HEIGHT 20
#define NUM_PLAYERS 2
#define NUM_BLOCKS 5

typedef struct {
    int x, y;
    int score;
    char symbol;
} Player;

typedef struct {
    int x, y;
} Block;

Player players[NUM_PLAYERS];
Block blocks[NUM_BLOCKS];
int gameRunning = 1;

void setup() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].x = SCREEN_WIDTH / (NUM_PLAYERS + 1) * (i + 1);
        players[i].y = SCREEN_HEIGHT - 1;  // Bottom of the screen
        players[i].score = 0;
        players[i].symbol = 'A' + i;  // Player symbols 'A', 'B', etc.
    }
    for (int i = 0; i < NUM_BLOCKS; i++) {
        blocks[i].x = rand() % SCREEN_WIDTH;
        blocks[i].y = 0;  // Start at the top of the screen
    }
}

void draw() {
    system("clear");  // Clear the screen
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            int isPlayer = 0;
            for (int i = 0; i < NUM_PLAYERS; i++) {
                if (players[i].x == x && players[i].y == y) {
                    putchar(players[i].symbol);
                    isPlayer = 1;
                    break;
                }
            }
            if (isPlayer) continue;

            int isBlock = 0;
            for (int i = 0; i < NUM_BLOCKS; i++) {
                if (blocks[i].x == x && blocks[i].y == y) {
                    putchar('#');  // Block symbol
                    isBlock = 1;
                    break;
                }
            }
            if (isBlock) continue;

            putchar(' '); // Empty space
        }
        putchar('\n');
    }
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %c Score: %d\n", players[i].symbol, players[i].score);
    }
}

void *fallingBlocks(void *arg) {
    while (gameRunning) {
        for (int i = 0; i < NUM_BLOCKS; i++) {
            if (blocks[i].y < SCREEN_HEIGHT - 1) {
                blocks[i].y++;
            } else {
                blocks[i].x = rand() % SCREEN_WIDTH;  // Reset block
                blocks[i].y = 0;
                for (int j = 0; j < NUM_PLAYERS; j++) {
                    if (players[j].x == blocks[i].x && players[j].y == blocks[i].y) {
                        players[j].score -= 1;  // Lose a point on hit
                        printf("Player %c hit by block!\n", players[j].symbol);
                    }
                }
            }
        }
        usleep(100000);  // Sleep for a while to slow down falling
    }
    return NULL;
}

int kbhit(void) {
    struct termios oldt, newt;
    int oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    int c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if(c != EOF) {
        ungetc(c, stdin);
        return 1;
    }
    return 0;
}

void movePlayer(int playerIndex, char direction) {
    if (direction == 'a' && players[playerIndex].x > 0) players[playerIndex].x--;
    if (direction == 'd' && players[playerIndex].x < SCREEN_WIDTH - 1) players[playerIndex].x++;
}

void *playerInput(void *arg) {
    int playerIndex = *(int *)arg;
    while (gameRunning) {
        if (kbhit()) {
            char ch = getchar();
            if (ch == 'q') gameRunning = 0;  // Exit game
            movePlayer(playerIndex, ch);
        }
        usleep(100000);  // Polling delay
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    setup();

    pthread_t blockThread, inputThreads[NUM_PLAYERS];
    
    pthread_create(&blockThread, NULL, fallingBlocks, NULL);
    
    for (int i = 0; i < NUM_PLAYERS; i++) {
        pthread_create(&inputThreads[i], NULL, playerInput, &i);
    }

    while (gameRunning) {
        draw();
        usleep(500000);  // Frame delay
    }

    pthread_join(blockThread, NULL);
    for (int i = 0; i < NUM_PLAYERS; i++) {
        pthread_join(inputThreads[i], NULL);
    }

    printf("Game Over!\n");
    return 0;
}