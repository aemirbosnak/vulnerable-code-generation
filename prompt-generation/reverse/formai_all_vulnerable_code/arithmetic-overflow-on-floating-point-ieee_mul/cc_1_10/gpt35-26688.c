//FormAI DATASET v1.0 Category: Fractal Generation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_DEPTH 10

typedef struct {
    double x,y;
} point;

typedef struct {
    point p1, p2;
} line;

line make_line(point p1, point p2) {
    line l = {p1, p2};
    return l;
}

point midpoint(point p1, point p2) {
    point pm = {(p1.x+p2.x)/2, (p1.y+p2.y)/2};
    return pm;
}

void draw_line(line l, char* screen) {
    int x0 = (int)l.p1.x;
    int y0 = (int)l.p1.y;
    int x1 = (int)l.p2.x;
    int y1 = (int)l.p2.y;
    
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    
    int err = dx - dy;
    int e2;
 
    while (1) {
        if (x0 >= 0 && x0 < WIDTH && y0 >= 0 && y0 < HEIGHT) {
            screen[(y0*WIDTH) + x0] = 1;
        }
        if (x0 == x1 && y0 == y1) break;
        e2 = err * 2;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 <  dx) { err += dx; y0 += sy; }
    }
}

void generate_fractal(line l, int depth, char* screen) {
    if (depth >= MAX_DEPTH) {
        draw_line(l, screen);
        return;
    }
    
    point p1 = l.p1;
    point p2 = l.p2;
    
    double length = sqrt(pow(p2.x-p1.x, 2) + pow(p2.y-p1.y, 2));
    
    point pm = midpoint(p1, p2);
    
    double dx = ((double)rand()/(double)RAND_MAX) - 0.5;
    double dy = ((double)rand()/(double)RAND_MAX) - 0.5;
    
    pm.x += dx * length / 2;
    pm.y += dy * length / 2;
    
    line l1 = make_line(p1, pm);
    line l2 = make_line(pm, p2);
    
    generate_fractal(l1, depth+1, screen);
    generate_fractal(l2, depth+1, screen);
}

int main() {
    srand(time(NULL));
    
    char* screen = calloc(WIDTH*HEIGHT, sizeof(char));
    
    point p1 = {0, HEIGHT/2};
    point p2 = {WIDTH, HEIGHT/2};
    line l = make_line(p1, p2);
    
    generate_fractal(l, 0, screen);
    
    FILE* fptr = fopen("image.pgm", "w");
    fprintf(fptr, "P2\n%d %d\n1\n", WIDTH, HEIGHT);  
 
    for (int i = 0; i < WIDTH*HEIGHT; i++) {
        fprintf(fptr, "%d ", screen[i]);
        if ((i+1) % WIDTH == 0) fprintf(fptr, "\n");
    }
 
    fclose(fptr);
    free(screen);
 
    return 0;
}