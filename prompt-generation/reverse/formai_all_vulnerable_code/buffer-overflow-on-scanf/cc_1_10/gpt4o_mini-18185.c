//GPT-4o-mini DATASET v1.0 Category: Pac-Man Game Clone ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 20
#define HEIGHT 10
#define GHOST_COUNT 2

char maze[HEIGHT][WIDTH + 1] = {
    "###################",
    "#.................#",
    "#.#####.###########",
    "#...............#.#",
    "###.####.#######.#.#",
    "#.........#.......#",
    "#.#######.#####.###",
    "#...............#.#",
    "#.#####.###########",
    "###################"
};

typedef struct {
    int x;
    int y;
} Position;

Position pacman;
Position ghosts[GHOST_COUNT];

void initGame() {
    pacman.x = 1;
    pacman.y = 1;
    for (int i = 0; i < GHOST_COUNT; i++) {
        ghosts[i].x = 15;
        ghosts[i].y = 5 + i;
    }
}

void drawMaze() {
    system("clear");
    for (int i = 0; i < HEIGHT; i++) {
        printf("%s\n", maze[i]);
    }
    printf("Pac-Man is at (%d, %d)\n", pacman.x, pacman.y);
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

void moveGhosts() {
    for (int i = 0; i < GHOST_COUNT; i++) {
        if (pacman.x < ghosts[i].x) {
            ghosts[i].x--;
        } else if (pacman.x > ghosts[i].x) {
            ghosts[i].x++;
        }

        if (pacman.y < ghosts[i].y) {
            ghosts[i].y--;
        } else if (pacman.y > ghosts[i].y) {
            ghosts[i].y++;
        }
    }
}

int checkCollision() {
    for (int i = 0; i < GHOST_COUNT; i++) {
        if (pacman.x == ghosts[i].x && pacman.y == ghosts[i].y) {
            return 1; // collision with ghost
        }
    }
    return 0;
}

void updatePosition(char input) {
    switch (input) {
        case 'w': // Move up
            if (maze[pacman.y - 1][pacman.x] != '#')
                pacman.y--;
            break;
        case 's': // Move down
            if (maze[pacman.y + 1][pacman.x] != '#')
                pacman.y++;
            break;
        case 'a': // Move left
            if (maze[pacman.y][pacman.x - 1] != '#')
                pacman.x--;
            break;
        case 'd': // Move right
            if (maze[pacman.y][pacman.x + 1] != '#')
                pacman.x++;
            break;
    }
}

int main() {
    initGame();
    
    while (1) {
        drawMaze();
        moveGhosts();
        if (checkCollision()) {
            printf("Game Over! You got caught!\n");
            break;
        }
        
        if (kbhit()) {
            char input;
            scanf(" %c", &input);
            updatePosition(input);
        }

        usleep(100000); // Sleep for 100ms
    }

    return 0;
}