//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIMENSIONS 2
#define MAX_ITERATIONS 100
#define MIN_CHANGE 0.0001
#define NUM_CLUSTERS 3

struct cluster{
    float centroid[DIMENSIONS];
    int num_points;
    float points[DIMENSIONS][1000];
};

float euclidean_distance(float point1[], float point2[]){
    float sum = 0; 
    for(int i=0; i<DIMENSIONS; i++){
        sum += pow((point1[i]-point2[i]), 2.0);
    }
    return sqrt(sum);
}

void assign_points_to_clusters(struct cluster clusters[], float points[][DIMENSIONS], int num_points){
    for(int i=0; i<num_points; i++){
        float min_distance = INFINITY;
        int closest_cluster_index;
        for(int j=0; j<NUM_CLUSTERS; j++){
            float distance = euclidean_distance(clusters[j].centroid, points[i]);
            if(distance < min_distance){
                min_distance = distance;
                closest_cluster_index = j;
            }
        }
        for(int k=0; k<DIMENSIONS; k++){
            clusters[closest_cluster_index].points[k][clusters[closest_cluster_index].num_points] = points[i][k];
        }
        clusters[closest_cluster_index].num_points++;
    }
}

void update_centroids(struct cluster clusters[]){
    for(int i=0; i<NUM_CLUSTERS; i++){
        for(int j=0; j<DIMENSIONS; j++){
            float sum = 0;
            for(int k=0; k<clusters[i].num_points; k++){
                sum += clusters[i].points[j][k];
            }
            clusters[i].centroid[j] = sum / clusters[i].num_points;
        }
    }
}

float calculate_change_in_clusters(struct cluster clusters_old[], struct cluster clusters_new[]){
    float max_change = 0;
    for(int i=0; i<NUM_CLUSTERS; i++){
        float change = euclidean_distance(clusters_old[i].centroid, clusters_new[i].centroid);
        if(change > max_change){
            max_change = change;
        }
    }
    return max_change;
}

void run_k_means(float points[][DIMENSIONS], int num_points){
    struct cluster clusters[NUM_CLUSTERS];
    for(int i=0; i<NUM_CLUSTERS; i++){
        for(int j=0; j<DIMENSIONS; j++){
            clusters[i].centroid[j] = ((float)rand()/(float)(RAND_MAX)) * 10;
        }
        clusters[i].num_points = 0;
    }
    
    int iteration = 1;
    float change = INFINITY;
    while(iteration <= MAX_ITERATIONS && change >= MIN_CHANGE){
        for(int i=0; i<NUM_CLUSTERS; i++){
            clusters[i].num_points = 0;
        }
        assign_points_to_clusters(clusters, points, num_points);
        struct cluster clusters_old[NUM_CLUSTERS];
        for(int i=0; i<NUM_CLUSTERS; i++){
            for(int j=0; j<DIMENSIONS; j++){
                clusters_old[i].centroid[j] = clusters[i].centroid[j];
            }
            clusters_old[i].num_points = clusters[i].num_points;
        }
        update_centroids(clusters);
        change = calculate_change_in_clusters(clusters_old, clusters);
        printf("Iteration %d: Max Change: %f\n", iteration, change);
        iteration++;
    }
}

int main(){
    float points[1000][DIMENSIONS];
    int num_points = 0;
    char filename[50];
    printf("Enter the filename containing the points (CSV format): ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if(file){
        while(!feof(file)){
            fscanf(file, "%f,%f", &points[num_points][0], &points[num_points][1]);
            num_points++;
        }
        fclose(file);
    }
    else{
        printf("Error reading file.\n");
    }
    run_k_means(points, num_points);
    return 0;
}