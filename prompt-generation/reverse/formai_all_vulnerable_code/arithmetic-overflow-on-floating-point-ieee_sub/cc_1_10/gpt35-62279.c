//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: relaxed
/* This program will take three points as input and check if they form a right angled triangle */

#include <stdio.h>
#include <math.h>

int main() {
    float a[2], b[2], c[2];
    float AB, BC, AC;
    
    // Asking the user to input the three points
    printf("Enter the coordinates of Point A: ");
    scanf("%f %f", &a[0], &a[1]);
    
    printf("Enter the coordinates of Point B: ");
    scanf("%f %f", &b[0], &b[1]);
    
    printf("Enter the coordinates of Point C: ");
    scanf("%f %f", &c[0], &c[1]);
    
    AB = sqrtf(powf(b[0] - a[0], 2) + powf(b[1] - a[1], 2)); // Distance between Point A and Point B
    BC = sqrtf(powf(c[0] - b[0], 2) + powf(c[1] - b[1], 2)); // Distance between Point B and Point C
    AC = sqrtf(powf(c[0] - a[0], 2) + powf(c[1] - a[1], 2)); // Distance between Point A and Point C
    
    // Checking if the triangle is a right angled triangle
    if (AB > BC && AB > AC) {
        if ((powf(AB, 2) - (powf(BC, 2) + powf(AC, 2))) == 0) {
            printf("These points form a right angled triangle.\n");
        }
        else {
            printf("These points do not form a right angled triangle.\n");
        }
    }
    else if (BC > AB && BC > AC) {
        if ((powf(BC, 2) - (powf(AB, 2) + powf(AC, 2))) == 0) {
            printf("These points form a right angled triangle.\n");
        }
        else {
            printf("These points do not form a right angled triangle.\n");
        }
    }
    else if (AC > AB && AC > BC) {
        if ((powf(AC, 2) - (powf(AB, 2) + powf(BC, 2))) == 0) {
            printf("These points form a right angled triangle.\n");
        }
        else {
            printf("These points do not form a right angled triangle.\n");
        }
    }
    else {
        printf("These points do not form a right angled triangle.\n");
    }
    
    return 0;
}