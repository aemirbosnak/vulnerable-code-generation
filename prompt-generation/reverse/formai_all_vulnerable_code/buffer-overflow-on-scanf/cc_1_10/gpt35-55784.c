//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: calm
#include<stdio.h>

int main() {
    int n; //number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    //create arrays to store x and y coordinates of data points
    float x[n], y[n];
    printf("Enter the x and y coordinates of data points:\n");

    for(int i=0; i<n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }

    //initialize variables for cluster centers and their indices
    float c1x = x[0], c1y = y[0];
    float c2x = x[1], c2y = y[1];
    int c1idx = 0, c2idx = 1;

    //initialize variables for distance calculation
    float d1, d2, dx, dy;
    float newc1x = 0, newc1y = 0, newc2x = 0, newc2y = 0;
    int c1count = 0, c2count = 0;

    //initialize threshold for convergence
    float eps = 0.0001;

    //repeat clustering until convergence
    while(1) {
        //initialize variables for distance calculation each iteration
        newc1x = 0, newc1y = 0, newc2x = 0, newc2y = 0;
        c1count = 0, c2count = 0;

        for(int i=0; i<n; i++) {
            //calculate distance of each data point from the cluster centers
            dx = x[i] - c1x;
            dy = y[i] - c1y;
            d1 = sqrt(dx*dx + dy*dy);

            dx = x[i] - c2x;
            dy = y[i] - c2y;
            d2 = sqrt(dx*dx + dy*dy);

            //assign each data point to its closest center
            if(d1 < d2) {
                newc1x += x[i];
                newc1y += y[i];
                c1count++;
            } else {
                newc2x += x[i];
                newc2y += y[i];
                c2count++;
            }
        }

        //update cluster centers as centroid of assigned data points
        newc1x /= c1count;
        newc1y /= c1count;
        newc2x /= c2count;
        newc2y /= c2count;
        
        //check for convergence and update cluster centers
        if(fabs(c1x-newc1x)<=eps && fabs(c1y-newc1y)<=eps && fabs(c2x-newc2x)<=eps && fabs(c2y-newc2y)<=eps) {
            break;
        } else {
            c1x = newc1x;
            c1y = newc1y;
            c2x = newc2x;
            c2y = newc2y;
        }
    }

    printf("Cluster 1 center: (%f, %f)\n",c1x,c1y);
    printf("Cluster 2 center: (%f, %f)\n",c2x,c2y);

    return 0;
}