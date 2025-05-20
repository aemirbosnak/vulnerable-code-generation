//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

//Structure for point and line
typedef struct {
    int x;
    int y;
} point;
typedef struct {
    point p1;
    point p2;
} line;

//Function to calculate the slope of a line
float slope(line l) {
    return (float)(l.p2.y - l.p1.y)/(l.p2.x - l.p1.x);
}

//Function to calculate the length of a line
float length(line l) {
    return sqrt((l.p2.x-l.p1.x)*(l.p2.x-l.p1.x) + (l.p2.y-l.p1.y)*(l.p2.y-l.p1.y));
}

//Function to check if two lines are perpendicular
int isPerpendicular(line l1, line l2) {
    return (slope(l1)*slope(l2) == -1);
}

int main() {
    int n;
    printf("Enter the number of lines: ");
    scanf("%d", &n);

    //Dynamically allocate memory for an array of lines
    line* lines = (line*) malloc(sizeof(line)*n);

    for(int i=0; i<n; i++) {
        printf("Enter the coordinates of point 1 for line %d: ", i+1);
        scanf("%d %d", &lines[i].p1.x, &lines[i].p1.y);
        printf("Enter the coordinates of point 2 for line %d: ", i+1);
        scanf("%d %d", &lines[i].p2.x, &lines[i].p2.y);
    }

    //Check for perpendicular lines in the array
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(isPerpendicular(lines[i], lines[j])) {
                printf("\nLine %d and Line %d are perpendicular!", i+1, j+1);
                printf("\nLength of Line %d : %f", i+1, length(lines[i]));
                printf("\nLength of Line %d : %f", j+1, length(lines[j]));
            }
        }
    }

    //Free dynamically allocated memory
    free(lines);

    return 0;
}