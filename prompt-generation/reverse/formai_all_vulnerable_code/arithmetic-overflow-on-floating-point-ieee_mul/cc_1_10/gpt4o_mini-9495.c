//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define WIDTH 20
#define HEIGHT 10
#define GRAVITY 0.1
#define FRICTION 0.05
#define MAX_DISTANCE 100

typedef struct {
    float x;
    float y;
    float vx;
    float vy;
    char symbol;
} Character;

void initializeCharacter(Character *c, float x, float y, char symbol) {
    c->x = x;
    c->y = y;
    c->vx = 0;
    c->vy = 0;
    c->symbol = symbol;
}

void printScene(Character *romeo, Character *juliet) {
    char scene[HEIGHT][WIDTH];
    for(int i = 0; i < HEIGHT; i++)
        for(int j = 0; j < WIDTH; j++)
            scene[i][j] = '.';

    int rX = (int)(romeo->x);
    int rY = (int)(romeo->y);
    int jX = (int)(juliet->x);
    int jY = (int)(juliet->y);

    if (rX >= 0 && rX < WIDTH && rY >= 0 && rY < HEIGHT) {
        scene[rY][rX] = romeo->symbol;
    }
    
    if (jX >= 0 && jX < WIDTH && jY >= 0 && jY < HEIGHT) {
        scene[jY][jX] = juliet->symbol;
    }

    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%c ", scene[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void applyGravity(Character *c) {
    c->vy += GRAVITY;
}

void applyFriction(Character *c) {
    c->vx *= (1 - FRICTION);
    c->vy *= (1 - FRICTION);
}

float distance(Character *c1, Character *c2) {
    return sqrt(pow(c1->x - c2->x, 2) + pow(c1->y - c2->y, 2));
}

void updatePosition(Character *c, int targetX, int targetY) {
    if (c->x < targetX) c->vx += 0.1;
    else if (c->x > targetX) c->vx -= 0.1;

    if (c->y < targetY) c->vy += 0.1;
    else if (c->y > targetY) c->vy -= 0.1;

    c->x += c->vx;
    c->y += c->vy;

    applyGravity(c);
    applyFriction(c);
}

int main() {
    Character romeo, juliet;
    initializeCharacter(&romeo, 2.0, 2.0, 'R');
    initializeCharacter(&juliet, 15.0, 7.0, 'J');

    while (1) {
        system("clear");  // Use "clear" to clear the console screen
        
        float dist = distance(&romeo, &juliet);
        if (dist < 1.0) {
            printf("Oh, sweet love! Romeo and Juliet unite!\n");
            break;
        }

        updatePosition(&romeo, (int)juliet.x, (int)juliet.y);
        updatePosition(&juliet, (int)romeo.x, (int)romeo.y);

        printScene(&romeo, &juliet);
        usleep(200000);  // Sleep for 200 milliseconds
    }

    return 0;
}