//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PI 3.14159
#define INF 1000000

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point p1;
    Point p2;
} Line;

typedef struct {
    Line l1;
    Line l2;
} Polygon;

void drawPoint(Point p) {
    printf("(%d, %d)", p.x, p.y);
}

void drawLine(Line l) {
    printf("Line(%d, %d) -> (%d, %d)", l.p1.x, l.p1.y, l.p2.x, l.p2.y);
}

void drawPolygon(Polygon p) {
    int i;
    for (i = 0; i < p.l1.p2.x; i++) {
        drawLine(p.l1);
        drawLine(p.l2);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Polygon p;

    for (int i = 0; i < n; i++) {
        Point p1, p2;
        scanf("%d%d", &p1.x, &p1.y);
        scanf("%d%d", &p2.x, &p2.y);
        p.l1.p1 = p1;
        p.l1.p2 = p2;
        p.l2.p1 = p2;
        p.l2.p2 = p1;
        drawPolygon(p);
    }

    return 0;
}