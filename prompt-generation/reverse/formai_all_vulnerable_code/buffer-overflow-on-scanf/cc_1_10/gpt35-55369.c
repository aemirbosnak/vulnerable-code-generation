//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: ephemeral
#include <stdio.h>
#define MAX 100

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    Point vertices[3];
} Triangle;

int counter = 0;
Triangle triangles[MAX];

float area(Triangle t) {
    float x1 = t.vertices[0].x, y1 = t.vertices[0].y;
    float x2 = t.vertices[1].x, y2 = t.vertices[1].y;
    float x3 = t.vertices[2].x, y3 = t.vertices[2].y;

    float a = x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2);

    return a/2.0;
}

int intersect(Triangle a, Triangle b) {
    int i, j;

    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (a.vertices[i].x == b.vertices[j].x && a.vertices[i].y == b.vertices[j].y) {
                return 0;
            }
        }
    }

    float ta = area(a);
    float tb = area(b);

    if (ta > 0 && tb > 0) {
        return (ta + tb) > area((Triangle){{a.vertices[0], a.vertices[1], b.vertices[2]}}) + area((Triangle){{b.vertices[0], b.vertices[1], a.vertices[2]}});
    } else if (ta < 0 && tb < 0) {
        return (ta + tb) < area((Triangle){{a.vertices[0], a.vertices[1], b.vertices[2]}}) + area((Triangle){{b.vertices[0], b.vertices[1], a.vertices[2]}});
    } else {
        return 0;
    }
}

int main() {
    int i, j, k;

    for (i=0; i<10; i++) {
        printf("Enter the vertices of triangle %d:\n", i+1);

        Triangle t;
        for (j=0; j<3; j++) {
            printf("Vertex %d:\n", j+1);

            Point p;
            scanf("%f%f", &p.x, &p.y);
            t.vertices[j] = p;
        }

        int flag = 1;
        for (k=0; k<counter; k++) {
            if (intersect(t, triangles[k])) {
                printf("This triangle intersects with triangle %d.\n", k+1);
                flag = 0;
                break;
            }
        }

        if (flag) {
            triangles[counter++] = t;
            printf("This triangle does not intersect with any of the previous triangles.\n");
        }
    }

    return 0;
}