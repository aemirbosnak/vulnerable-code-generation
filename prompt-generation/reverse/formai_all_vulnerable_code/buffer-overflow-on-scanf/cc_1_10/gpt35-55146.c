//FormAI DATASET v1.0 Category: Robot movement control ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// Robot structure
struct robot {
    int x; // x-coordinate
    int y; // y-coordinate
    int id; // ID of the robot
    char ch; // Character representation of the robot
    int score; // Score of the robot
};

// Function to create a robot
struct robot create_robot(int x, int y, char ch, int id) {
    struct robot r;
    r.x = x;
    r.y = y;
    r.ch = ch;
    r.id = id;
    r.score = 0;
    return r;
}

// Function to move the robot up
void move_up(struct robot* r) {
    r->x--;
}

// Function to move the robot down
void move_down(struct robot* r) {
    r->x++;
}

// Function to move the robot left
void move_left(struct robot* r) {
    r->y--;
}

// Function to move the robot right
void move_right(struct robot* r) {
    r->y++;
}

int main() {
    int i, j, n, moves = 0, winner;
    struct robot robots[MAX];
    char map[MAX][MAX];
    printf("Enter the number of robots: ");
    scanf("%d", &n);
    // Initialize the map
    for(i=0;i<MAX;i++) {
        for(j=0;j<MAX;j++) {
            map[i][j] = ' ';
        }
    }
    // Create the robots
    for(i=0;i<n;i++) {
        int x, y;
        char ch;
        printf("Enter the starting position and character for robot %d: ", i+1);
        scanf("%d %d %c", &x, &y, &ch);
        robots[i] = create_robot(x, y, ch, i+1);
        map[x][y] = ch;
    }
    // Print the map
    for(i=0;i<MAX;i++) {
        for(j=0;j<MAX;j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
    // Game loop
    while(1) {
        // Move each robot
        for(i=0;i<n;i++) {
            printf("Robot %d, make your move (u/d/l/r): ", i+1);
            char move;
            scanf(" %c", &move);
            switch(move) {
                case 'u':
                    move_up(&robots[i]);
                    break;
                case 'd':
                    move_down(&robots[i]);
                    break;
                case 'l':
                    move_left(&robots[i]);
                    break;
                case 'r':
                    move_right(&robots[i]);
                    break;
                default:
                    printf("Invalid move!\n");
            }
        }
        // Update the map
        for(i=0;i<MAX;i++) {
            for(j=0;j<MAX;j++) {
                map[i][j] = ' ';
            }
        }
        for(i=0;i<n;i++) {
            map[robots[i].x][robots[i].y] = robots[i].ch; 
        }
        // Print the map
        for(i=0;i<MAX;i++) {
            for(j=0;j<MAX;j++) {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }
        // Check for collisions and scoring
        for(i=0;i<n;i++) {
            for(j=i+1;j<n;j++) {
                if(robots[i].x == robots[j].x && robots[i].y == robots[j].y) {
                    printf("Robot %d collided with robot %d!\n", robots[i].id, robots[j].id);
                    robots[i].score--;
                    robots[j].score--;
                    if(robots[i].score < 0) robots[i].score = 0;
                    if(robots[j].score < 0) robots[j].score = 0;
                }
            }
        }
        // Check for winner
        winner = -1;
        for(i=0;i<n;i++) {
            if(robots[i].score == 5) {
                winner = i;
                break;
            }
        }
        if(winner != -1) {
            printf("Robot %d wins!\n", robots[winner].id);
            break;
        }
        moves++;
        printf("Number of moves made: %d\n", moves);
    }
    return 0;
}