//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define MAX_POINTS 1000
#define DIMENSIONS 5
#define MAX_ITERATIONS 100

struct point{
    float coordinates[DIMENSIONS];
    int cluster;
};

int main(){
    srand(time(NULL));

    struct point points[MAX_POINTS];
    int k, n, i, j;
    float distance, min_distance;
    int iterations = 0;
    int cluster_changed;

    printf("Enter number of points: ");
    scanf("%d", &n);

    printf("Enter value of k: ");
    scanf("%d", &k);

    for(i=0;i<n;i++){
        for(j=0;j<DIMENSIONS;j++){
            points[i].coordinates[j] = (float)(rand()%10000)/100.0;
        }
        points[i].cluster = -1;
    }

    struct point centroids[k];
    for(i=0;i<k;i++){
        centroids[i] = points[rand()%n];
    }

    while(iterations<MAX_ITERATIONS){
        for(i=0;i<n;i++){
            min_distance = INFINITY;
            for(j=0;j<k;j++){
                distance = 0;
                for(int d=0;d<DIMENSIONS;d++){
                    distance += pow(points[i].coordinates[d] - centroids[j].coordinates[d], 2);
                }
                distance = sqrt(distance);
                if(distance<min_distance){
                    min_distance = distance;
                    points[i].cluster = j;
                }
            }
        }

        cluster_changed = 0;

        for(j=0;j<k;j++){
            float new_centroid[DIMENSIONS] = {0};
            int count = 0;
            for(i=0;i<n;i++){
                if(points[i].cluster==j){
                    for(int d=0;d<DIMENSIONS;d++){
                        new_centroid[d] += points[i].coordinates[d];
                    }
                    count++;
                }
            }
            for(int d=0;d<DIMENSIONS;d++){
                new_centroid[d] /= count;
            }
            if(memcmp(centroids[j].coordinates, new_centroid, DIMENSIONS*sizeof(float)) != 0){
                cluster_changed = 1;
                for(int d=0;d<DIMENSIONS;d++){
                    centroids[j].coordinates[d] = new_centroid[d];
                }
            }
        }

        if(!cluster_changed) break;

        iterations++;        
    }

    for(j=0;j<k;j++){
        printf("Centroid %d: ", j);
        for(int d=0;d<DIMENSIONS;d++){
            printf("%f ", centroids[j].coordinates[d]);
        }
        printf("\n");
    }

    return 0;
}