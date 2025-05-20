//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    float x, y;
} Point;

typedef struct Stack {
    Point *points;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->points = (Point *)malloc(stack->capacity * sizeof(Point));
    return stack;
}

int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, Point point) {
    if (isFull(stack)) return;
    stack->points[++stack->top] = point;
}

Point pop(Stack *stack) {
    if (isEmpty(stack))
        return (Point){0, 0}; // Return a dummy point if stack is empty
    return stack->points[stack->top--];
}

Point peek(Stack *stack) {
    if (isEmpty(stack))
        return (Point){0, 0}; // Return a dummy point if stack is empty
    return stack->points[stack->top];
}

float crossProduct(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

void quickHull(Point *points, int n, Point p1, Point p2, int side, Stack *hull) {
    int index = -1;
    float maxDist = 0;

    for (int i = 0; i < n; i++) {
        float temp = crossProduct(p1, p2, points[i]);
        if (temp == side) {
            float distance = (points[i].x - p1.x) * (points[i].x - p1.x) +
                             (points[i].y - p1.y) * (points[i].y - p1.y);
            if (distance > maxDist) {
                maxDist = distance;
                index = i;
            }
        }
    }
  
    if (index == -1) {
        push(hull, p1);
        push(hull, p2);
        return;
    }

    quickHull(points, n, points[index], p1, -crossProduct(p1, p2, points[index]), hull);
    quickHull(points, n, points[index], p2, -crossProduct(p2, p1, points[index]), hull);
}

void convexHull(Point *points, int n) {
    if (n < 3) return;

    Stack *hull = createStack(n);
    int leftMost = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[leftMost].x)
            leftMost = i;

    int rightMost = leftMost;

    for (int i = 0; i < n; i++) {
        if (points[i].x > points[rightMost].x)
            rightMost = i;
    }

    quickHull(points, n, points[leftMost], points[rightMost], -1, hull);
    quickHull(points, n, points[leftMost], points[rightMost], 1, hull);

    printf("The points in the Convex Hull are:\n");
    for (int i = 0; i <= hull->top; i++) {
        printf("(%.2f, %.2f)\n", hull->points[i].x, hull->points[i].y);
    }

    free(hull->points);
    free(hull);
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    Point *points = (Point *)malloc(n * sizeof(Point));
  
    printf("Enter the points (x and y for each):\n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &points[i].x, &points[i].y);
    }

    convexHull(points, n);

    free(points);
    return 0;
}