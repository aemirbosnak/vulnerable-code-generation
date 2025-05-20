//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 20
#define PADDLE_SIZE 3
#define BALL_SYMBOL 'o'
#define PADDLE_SYMBOL '|'
#define SERVER_PORT 8080

typedef struct {
    int x;
    int y;
} Coordinates;

typedef struct {
    Coordinates position;
    int directionX;
    int directionY;
} Ball;

typedef struct {
    int score;
    Coordinates position;
} Paddle;

void clearScreen() {
    printf("\033[2J\033[1;1H");
}

void display(char screen[][SCREEN_WIDTH], Ball ball, Paddle player, Paddle opponent) {
    clearScreen();

    for(int i=0; i<SCREEN_HEIGHT; i++) {
        for(int j=0; j<SCREEN_WIDTH; j++) {
            if(i == ball.position.x && j == ball.position.y) {
                printf(" %c ", BALL_SYMBOL);
            } else if(i == player.position.x || i == player.position.x+1 || i == player.position.x+2) {
                if(j == player.position.y) {
                    printf("%c", PADDLE_SYMBOL);
                } else {
                    printf(" ");
                }
            } else if(i == opponent.position.x || i == opponent.position.x+1 || i == opponent.position.x+2) {
                if(j == opponent.position.y) {
                    printf("%c", PADDLE_SYMBOL);
                } else {
                    printf(" ");
                }
            } else {
                printf("%c", screen[i][j]);
            }
        }
        printf("\n");
    }
    printf("Player Score: %d\n", player.score);
    printf("Opponent Score: %d\n", opponent.score);
}

Ball initializeBall() {
    Ball ball;
    ball.position.x = SCREEN_HEIGHT / 2;
    ball.position.y = SCREEN_WIDTH / 2;
    ball.directionX = -1;
    ball.directionY = -1;
    return ball;
}

Paddle initializePlayer() {
    Paddle player;
    player.score = 0;
    player.position.x = (SCREEN_HEIGHT - PADDLE_SIZE) / 2;
    player.position.y = 2;
    return player;
}

Paddle initializeOpponent() {
    Paddle opponent;
    opponent.score = 0;
    opponent.position.x = (SCREEN_HEIGHT - PADDLE_SIZE) / 2;
    opponent.position.y = SCREEN_WIDTH - 3;
    return opponent;
}

void moveBall(Ball *ball, Paddle player, Paddle opponent, bool *gameOver) {
    ball->position.x += ball->directionX;
    ball->position.y += ball->directionY;

    if(ball->position.x <= 0 || ball->position.x >= SCREEN_HEIGHT-1) {
        ball->directionX = -ball->directionX;
    }

    if(ball->position.y <= 0) {
        ball->position.y = SCREEN_WIDTH / 2;
        ball->directionY = -ball->directionY;
        player.score++;
    }

    if(ball->position.y >= SCREEN_WIDTH-1) {
        ball->position.y = SCREEN_WIDTH / 2;
        ball->directionY = -ball->directionY;
        opponent.score++;
    }

    if(ball->position.x >= player.position.x && ball->position.x <= player.position.x+2 &&
        ball->position.y <= player.position.y) {
        ball->directionY = -ball->directionY;
    }

    if(ball->position.x >= opponent.position.x && ball->position.x <= opponent.position.x+2 &&
        ball->position.y >= opponent.position.y) {
        ball->directionY = -ball->directionY;
    }

    if(player.score == 10 || opponent.score == 10) {
        *gameOver = true;
    }
}

void movePlayer(Paddle *player, char direction) {
    if(direction == 'w' && player->position.x > 0) {
        player->position.x--;
    }

    if(direction == 's' && player->position.x < SCREEN_HEIGHT-PADDLE_SIZE) {
        player->position.x++;
    }
}

void moveOpponent(Paddle *opponent, Ball ball) {
    if(opponent->position.x + PADDLE_SIZE / 2 > ball.position.x) {
        if(opponent->position.x > 0) {
            opponent->position.x--;
        } else {
            opponent->position.x++;
        }
    }

    if(opponent->position.x + PADDLE_SIZE / 2 < ball.position.x) {
        if(opponent->position.x < SCREEN_HEIGHT-PADDLE_SIZE) {
            opponent->position.x++;
        } else {
            opponent->position.x--;
        }
    }
}

void setupSocket(int *sockfd, struct sockaddr_in *server, int *serverlen) {
    *sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(*sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    bzero((char *) server, sizeof(*server));
    server->sin_family = AF_INET;
    server->sin_addr.s_addr = htonl(INADDR_ANY);
    server->sin_port = htons(SERVER_PORT);
    *serverlen = sizeof(*server);

    if (bind(*sockfd, (struct sockaddr *) server, *serverlen) < 0) {
        perror("Error on binding");
        exit(1);
    }
}

void communicateWithClient(int sockfd, struct sockaddr_in client, int clientlen, Paddle *player) {
    char buffer[256];
    bzero(buffer, 256);
    int n = recvfrom(sockfd, buffer, 255, 0, (struct sockaddr *)&client, &clientlen);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    movePlayer(player, buffer[0]);
    n = sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *) &client, clientlen);
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }
}

int main() {
    char screen[SCREEN_WIDTH][SCREEN_HEIGHT];
    Ball ball = initializeBall();
    Paddle player = initializePlayer();
    Paddle opponent = initializeOpponent();
    bool gameOver = false;

    // setup socket to communicate with client
    int sockfd, serverlen, clientlen;
    struct sockaddr_in server, client;
    setupSocket(&sockfd, &server, &serverlen);

    // seed the random number generator
    srand(time(NULL));

    // initialize the screen
    for(int i=0; i<SCREEN_HEIGHT; i++) {
        for(int j=0; j<SCREEN_WIDTH; j++) {
            if(i == 0 || i == SCREEN_HEIGHT-1) {
                screen[i][j] = '-';
            } else if(j == 0 || j == SCREEN_WIDTH-1) {
                screen[i][j] = '|';
            } else {
                screen[i][j] = ' ';
            }
        }
    }

    // game loop
    while(!gameOver) {
        // move player
        communicateWithClient(sockfd, client, clientlen, &player);

        // move opponent
        moveOpponent(&opponent, ball);

        // move ball
        moveBall(&ball, player, opponent, &gameOver);

        // display screen
        display(screen, ball, player, opponent);
        usleep(50000); // sleep for 50 milliseconds
    }

    printf("GAME OVER\n");
    close(sockfd);

    return 0;
}