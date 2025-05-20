//FormAI DATASET v1.0 Category: Fractal Generation ; Style: shocked
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point_t;

void drawFractal(point_t p1, point_t p2, int depth){
    if(depth > 0){
        point_t p3, p4, p5;
        int dx = p2.x - p1.x;
        int dy = p2.y - p1.y;
        
        p3.x = p1.x + dx / 3;
        p3.y = p1.y + dy / 3;
        p5.x = p1.x + 2 * dx / 3;
        p5.y = p1.y + 2 * dy / 3;
        
        double phi = M_PI / 3.0;
        double cos_phi = cos(phi);
        double sin_phi = sin(phi);

        p4.x = p3.x + (int)((p5.x - p3.x) * cos_phi + (p5.y - p3.y) * sin_phi);
        p4.y = p3.y - (int)((p5.x - p3.x) * sin_phi - (p5.y - p3.y) * cos_phi);

        drawFractal(p1, p3, depth-1);
        drawFractal(p3, p4, depth-1);
        drawFractal(p4, p5, depth-1);
        drawFractal(p5, p2, depth-1);
    }
    else{
        printf("%d %d ", p1.x, p1.y);
        printf("%d %d ", p2.x, p2.y);
    }
}

int main(){

    int depth, size;
    printf("Enter the size of the fractal: ");
    scanf("%d", &size);
    printf("Enter the depth of the fractal: ");
    scanf("%d", &depth);

    point_t p1 = {size / 2 - size / 4, size / 2 + size / 4};
    point_t p2 = {size / 2 + size / 4, size / 2 + size / 4};
    point_t p3 = {size / 2, size / 2 - size / 2};
    
    drawFractal(p1, p2, depth);
    printf("\n");
    drawFractal(p2, p3, depth);
    printf("\n");
    drawFractal(p3, p1, depth);
    printf("\n");
    return 0;
}