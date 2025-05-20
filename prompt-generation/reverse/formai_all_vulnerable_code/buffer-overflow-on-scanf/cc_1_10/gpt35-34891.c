//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_POINTS 100

struct Point {
   int x, y;
};

int orientation(struct Point A, struct Point B, struct Point C){
    int val = (B.y - A.y)*(C.x - B.x) - (B.x - A.x)*(C.y - B.y);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

void convexHull(struct Point points[], int n){
    if (n < 3) return;

    int hull[MAX_POINTS], hullCount = 0;

    int leftmost = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[leftmost].x)
            leftmost = i;

    int curr = leftmost, next, prev;
    do {
        hull[hullCount++] = curr;

        next = (curr + 1) % n;
        for (int i = 0; i < n; i++)
        {
           if (orientation(points[curr], points[i], points[next]) == 2)
               next = i;
        }

        prev = curr;
        curr = next;
    } while (curr != leftmost);

    for (int i = 0; i < hullCount; i++)
        printf("(%d, %d)\n", points[hull[i]].x, points[hull[i]].y);
}

int main() {
    int n;
    struct Point points[MAX_POINTS];

    printf("Enter number of points: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
       printf("Enter x and y co-ordinates of point %d: ", i+1);
       scanf("%d %d", &points[i].x, &points[i].y);
    }

    printf("The convex hull of the given points is:\n");
    convexHull(points, n);

    return 0;
}