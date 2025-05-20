//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

// Function to generate random numbers
int randrange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to draw a line with given length and angle
void drawline(int length, float angle) {
    int x1, y1, x2, y2;
    x1 = 500 + 300 * cos(angle);
    y1 = 500 - 300 * sin(angle);
    x2 = x1 + length * cos(angle);
    y2 = y1 - length * sin(angle);

    printf("\033[%d;%dH", y1 + 20, x1 + 10);
    putchar(' ');
    printf("\033[%d;%dH", y2 + 20, x2 + 10);
    putchar('*');
}

// Function to draw a tree
void drawtree(int height, int trunklength, int branches) {
    int i;
    float angle;

    // Draw trunk
    for(i = 0; i <= trunklength; i++) {
        drawline(i * 2, atan(1) - atan(sqrt(2) / 2));
        printf("\033[%d;%dH", 500 + i * 2, 500);
        putchar('*');
    }

    // Draw main branch
    angle = atan(1) - atan(sqrt(2) / 2);
    drawline(trunklength * 2, angle);

    // Draw secondary branches
    for(i = 0; i < branches; i++) {
        angle += PI / 4;
        drawtree(height - trunklength / 2, trunklength / 3, branches / 2);
    }
}

int main() {
    int height, trunklength, branches;

    // Get user input for tree dimensions
    printf("Enter tree height: ");
    scanf("%d", &height);
    printf("Enter trunk length: ");
    scanf("%d", &trunklength);
    printf("Enter number of branches: ");
    scanf("%d", &branches);

    // Clear terminal screen
    system("clear");

    // Draw tree
    drawtree(height, trunklength, branches);

    return 0;
}