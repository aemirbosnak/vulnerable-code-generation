//Falcon2-11B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PADDLE_SPEED 5
#define BALL_SPEED 10
#define WIDTH 80
#define HEIGHT 24
#define SCORE_WIDTH 6
#define SCORE_HEIGHT 2

// Define the paddle structure
typedef struct {
    int x;
    int y;
    int width;
    int height;
    int score;
} paddle;

// Define the ball structure
typedef struct {
    int x;
    int y;
    int width;
    int height;
    int speed;
} ball;

// Define the score structure
typedef struct {
    int score1;
    int score2;
} score;

// Define the main game structure
typedef struct {
    paddle paddle1;
    paddle paddle2;
    ball ball;
    score score;
} game;

// Function to initialize the game
void init_game(game* game) {
    // Initialize the paddle positions
    game->paddle1.x = WIDTH / 2 - 3;
    game->paddle1.y = HEIGHT / 2 - 5;
    game->paddle1.width = 3;
    game->paddle1.height = 15;
    game->paddle1.score = 0;

    game->paddle2.x = WIDTH / 2 + 3;
    game->paddle2.y = HEIGHT / 2 - 5;
    game->paddle2.width = 3;
    game->paddle2.height = 15;
    game->paddle2.score = 0;

    // Initialize the ball position and speed
    game->ball.x = WIDTH / 2;
    game->ball.y = HEIGHT / 2;
    game->ball.width = 1;
    game->ball.height = 1;
    game->ball.speed = BALL_SPEED;

    // Initialize the score
    game->score.score1 = 0;
    game->score.score2 = 0;
}

// Function to update the game state
void update_game(game* game) {
    // Update the paddle positions based on user input
    if (game->paddle1.y < 0 || game->paddle1.y > HEIGHT - game->paddle1.height) {
        game->paddle1.y = HEIGHT / 2 - 5;
    }
    if (game->paddle2.y < 0 || game->paddle2.y > HEIGHT - game->paddle2.height) {
        game->paddle2.y = HEIGHT / 2 - 5;
    }

    // Move the paddle up or down based on user input
    if (game->paddle1.y > HEIGHT - game->paddle1.height) {
        game->paddle1.y -= PADDLE_SPEED;
    } else if (game->paddle1.y < 0) {
        game->paddle1.y += PADDLE_SPEED;
    }
    if (game->paddle2.y > HEIGHT - game->paddle2.height) {
        game->paddle2.y -= PADDLE_SPEED;
    } else if (game->paddle2.y < 0) {
        game->paddle2.y += PADDLE_SPEED;
    }

    // Move the ball based on its speed and direction
    if (game->ball.x < 0) {
        game->ball.x = WIDTH / 2;
    }
    if (game->ball.x > WIDTH) {
        game->ball.x = WIDTH / 2;
    }
    if (game->ball.y < 0) {
        game->ball.y = HEIGHT / 2;
    }
    if (game->ball.y > HEIGHT) {
        game->ball.y = HEIGHT / 2;
    }
    game->ball.x += game->ball.speed;
    game->ball.y += game->ball.speed;
}

// Function to draw the game state
void draw_game(game* game) {
    // Draw the paddle
    printf(" ");
    for (int i = 0; i < game->paddle1.width; i++) {
        printf("_");
    }
    printf(" ");

    // Draw the ball
    printf(" ");
    for (int i = 0; i < game->ball.width; i++) {
        printf("|");
    }
    printf(" ");

    // Draw the score
    printf("  ");
    for (int i = 0; i < SCORE_WIDTH; i++) {
        printf(" ");
    }
    printf("%d ", game->score.score1);
    printf("  ");
    for (int i = 0; i < SCORE_WIDTH; i++) {
        printf(" ");
    }
    printf("%d ", game->score.score2);
    printf("\n");
}

// Function to handle user input
void handle_input(game* game) {
    int key;

    // Get the user input
    printf("Press a key to start the game: ");
    scanf("%c", &key);

    // Start the game
    while (key!= 'q') {
        // Update the game state
        update_game(game);

        // Draw the game state
        draw_game(game);

        // Get the user input again
        printf("Press a key to continue: ");
        scanf("%c", &key);
    }
}

// Function to generate a random direction for the ball
void generate_random_direction(game* game) {
    int random_x = rand() % 2;
    int random_y = rand() % 2;

    if (random_x == 0) {
        game->ball.speed = BALL_SPEED;
        if (random_y == 0) {
            game->ball.x = WIDTH / 2;
            game->ball.y = HEIGHT / 2;
        } else {
            game->ball.y = HEIGHT / 2;
            game->ball.x = WIDTH / 2;
        }
    } else {
        game->ball.speed = -BALL_SPEED;
        if (random_y == 0) {
            game->ball.x = WIDTH / 2;
            game->ball.y = HEIGHT / 2;
        } else {
            game->ball.y = HEIGHT / 2;
            game->ball.x = WIDTH / 2;
        }
    }
}

// Function to generate a random direction for the paddle
void generate_random_paddle(game* game) {
    int random_x = rand() % 2;
    int random_y = rand() % 2;

    if (random_x == 0) {
        game->paddle1.x = WIDTH / 2 - 3;
        game->paddle1.y = HEIGHT / 2 - 5;
    } else {
        game->paddle1.x = WIDTH / 2 + 3;
        game->paddle1.y = HEIGHT / 2 - 5;
    }

    if (random_y == 0) {
        game->paddle1.y = HEIGHT / 2 - 5;
    } else {
        game->paddle1.y = HEIGHT / 2 - 5;
    }
}

// Function to generate a random direction for the score
void generate_random_score(game* game) {
    int random_score1 = rand() % 2;
    int random_score2 = rand() % 2;

    if (random_score1 == 0) {
        game->score.score1 = 0;
        game->score.score2 = 0;
    } else {
        game->score.score1 = 0;
        game->score.score2 = 0;
    }

    if (random_score2 == 0) {
        game->score.score1 = 0;
        game->score.score2 = 0;
    } else {
        game->score.score1 = 0;
        game->score.score2 = 0;
    }
}

// Main function
int main() {
    srand(time(NULL));

    // Initialize the game
    game game;
    init_game(&game);

    // Update the game state
    while (1) {
        // Update the game state
        update_game(&game);

        // Draw the game state
        draw_game(&game);

        // Generate a random direction for the ball
        generate_random_direction(&game);

        // Generate a random direction for the paddle
        generate_random_paddle(&game);

        // Generate a random direction for the score
        generate_random_score(&game);

        // Handle user input
        handle_input(&game);
    }

    return 0;
}