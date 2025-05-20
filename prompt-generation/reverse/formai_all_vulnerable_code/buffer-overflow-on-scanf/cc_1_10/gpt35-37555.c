//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXCOORD 1000    //Maximum coordinate value for any point
#define MAXSIZE 100      //Maximum number of points in the set


typedef struct {
    double x, y;
} Point;

/*
 * Function to find the area of a polygon using shoelace formula
 */
double areaOfPolygon(Point polygon[], int n) {
    double area = 0.0;
    int j = n - 1;

    for (int i = 0; i < n; i++) {
        area += (polygon[j].x + polygon[i].x) * (polygon[j].y - polygon[i].y);
        j = i;  //Set j to previous vertex
    }
    
    return fabs(area / 2.0);   //fabs() is used to get the absolute value of area
}

/*
 * Function to find the distance between two points
 */
double distance(Point A, Point B) {
    return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}

/*
 * Function to find the convex hull of a set of points
 */
void convexHull(Point set[], int n, Point hull[], int *s) {
    //Check if number of points is greater than or equal to 3
    if (n < 3) {
        *s = 0;
        return;
    }
    
    //Initialization
    int k = 0;
    Point H[2 * MAXSIZE];
    
    //Sort points by x-coordinate
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (set[j].x > set[j+1].x) {
                Point temp = set[j];
                set[j] = set[j+1];
                set[j+1] = temp;
            }
        }
    }
    
    //Lower half of hull
    for (int i = 0; i < n; i++) {
        while (k >= 2 && ((H[k-1].y - H[k-2].y) * (set[i].x - H[k-1].x) <= (H[k-1].x - H[k-2].x) * (set[i].y - H[k-1].y))) {
            k--;
        }
        H[k++] = set[i];
    }
    
    //Upper half of hull
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && ((H[k-1].y - H[k-2].y) * (set[i].x - H[k-1].x) <= (H[k-1].x - H[k-2].x) * (set[i].y - H[k-1].y))) {
            k--;
        }
        H[k++] = set[i];
    }
    
    *s = k - 1; //Final size of hull
    for (int i = 0; i < *s; i++) {
        hull[i] = H[i];
    }
}

/*
 * Main Function
 */
int main() {
    Point set[MAXSIZE], hull[MAXSIZE];
    int n, s;
    
    printf("Enter the number of points: ");
    scanf("%d", &n);
    
    printf("Enter the coordinates of the points: \n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &set[i].x, &set[i].y);
    }
    
    convexHull(set, n, hull, &s);
    
    printf("\nConvex Hull:\n");
    for (int i = 0; i < s; i++) {
        printf("(%lf, %lf)\n", hull[i].x, hull[i].y);
    }
    
    printf("\nArea of Convex Hull: %lf\n", areaOfPolygon(hull, s));
    
    return 0;
}