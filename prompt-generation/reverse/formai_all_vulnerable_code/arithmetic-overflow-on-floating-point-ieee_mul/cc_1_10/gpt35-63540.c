//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 100
#define EPSILON 0.0001
#define N 5

//Function to find distance between two points
float distance(float x1, float y1, float x2, float y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main(){
    float x_points[N] = {1.1, 2.2, 3.5, 4.7, 5.9};
    float y_points[N] = {2.3, 3.6, 4.8, 5.7, 6.4};
    float cluster_x[N], cluster_y[N];
    int cluster_count = 0;
    int i, j, k, flag = 0;

    for(i = 0; i < N; i++){
        flag = 0;
        for (j = 0; j < cluster_count; j++){
            if (distance(x_points[i], y_points[i], cluster_x[j], cluster_y[j]) < EPSILON){
                flag = 1;
                break;
            }
        }
        if (!flag){
            cluster_x[cluster_count] = x_points[i];
            cluster_y[cluster_count] = y_points[i];
            cluster_count++;
        }
    }

    int iteration_count = 0;

    while(iteration_count < MAX_ITERATIONS){
        int cluster_group_count[N][N];
        float cluster_group_x[N][N], cluster_group_y[N][N];

        for(i = 0; i < N; i++){
            int min_distance_cluster = 0;
            float min_distance = distance(x_points[i], y_points[i], cluster_x[0], cluster_y[0]);

            for(j = 1; j < cluster_count; j++){
                float dist = distance(x_points[i], y_points[i], cluster_x[j], cluster_y[j]);

                if (dist < min_distance){
                    min_distance_cluster = j;
                    min_distance = dist;
                }
            }

            cluster_group_x[i][min_distance_cluster] = x_points[i];
            cluster_group_y[i][min_distance_cluster] = y_points[i];
            cluster_group_count[i][min_distance_cluster] = 1;
        }

        flag = 0;
        for(i = 0; i < cluster_count; i++){
            float new_x = 0, new_y = 0, count = 0;

            for(j = 0; j < N; j++){
                new_x += cluster_group_x[j][i];
                new_y += cluster_group_y[j][i];
                count += cluster_group_count[j][i];
            }

            if (count != 0){
                new_x /= count;
                new_y /= count;

                if (distance(new_x, new_y, cluster_x[i], cluster_y[i]) > EPSILON){
                    flag = 1;
                }
                cluster_x[i] = new_x;
                cluster_y[i] = new_y;
            }
        }
    
        if (!flag){
            break;
        }

        iteration_count++;
    }

    printf("Cluster points:\n");
    for(i = 0; i < cluster_count; i++){
        printf("(%f, %f)\n", cluster_x[i], cluster_y[i]);
    }

    return 0;
}