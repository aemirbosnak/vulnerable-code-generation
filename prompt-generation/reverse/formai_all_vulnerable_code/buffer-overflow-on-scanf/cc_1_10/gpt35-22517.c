//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define K 3
#define N 100
#define ITER 10

struct cluster{
    float centroid[K];
    int count;
    float data[N][K];
};

struct dataset{
    int len;
    float points[N][K];
};

float distance(float *pt1, float *pt2){
    float dis = 0, diff;
    for(int i=0; i<K; i++){
        diff = pt1[i] - pt2[i];
        dis += diff*diff;
    }
    return sqrt(dis);
}

void k_means_clustering(struct dataset *data, struct cluster *c){
    int cluster_id, min_dist;
    float min_dis, dist;
    for(int iter=0; iter<ITER; iter++){
        // initialisation
        for(int i=0; i<K; i++){
            for(int j=0; j<K; j++){
                c[i].centroid[j] = data->points[rand()%data->len][j]; // random point from dataset
            }
            c[i].count = 0;
        }

        // assignment
        for(int i=0; i<data->len; i++){
            min_dis = INFINITY;
            for(int j=0; j<K; j++){
                dist = distance(data->points[i], c[j].centroid);
                if(dist<min_dis){
                    min_dis = dist;
                    cluster_id = j;
                }
            }
            c[cluster_id].data[c[cluster_id].count][0] = data->points[i][0];
            c[cluster_id].data[c[cluster_id].count][1] = data->points[i][1];
            c[cluster_id].count++;
        }

        // update centroid
        for(int i=0; i<K; i++){
            for(int j=0; j<c[i].count; j++){
                c[i].centroid[0] += c[i].data[j][0];
                c[i].centroid[1] += c[i].data[j][1];
            }
            c[i].centroid[0] /= c[i].count;
            c[i].centroid[1] /= c[i].count;
        }
    }
}

void print_clusters(struct cluster *c){
    printf("\nClustered data:\n");
    for(int i=0; i<K; i++){
        printf("Cluster %d:\n", i+1);
        for(int j=0; j<c[i].count; j++){
            printf("(%f,%f)\n", c[i].data[j][0], c[i].data[j][1]);
        }
        printf("\n");
    }
}

void main(){
    struct dataset data;
    struct cluster c[K];

    data.len = 10;
    data.points[0][0] = 1.0;  data.points[0][1] = 1.0;
    data.points[1][0] = 1.3;  data.points[1][1] = 1.1;
    data.points[2][0] = 1.1;  data.points[2][1] = 1.4;
    data.points[3][0] = 3.0;  data.points[3][1] = 3.2;
    data.points[4][0] = 3.1;  data.points[4][1] = 3.0;
    data.points[5][0] = 3.4;  data.points[5][1] = 3.1;
    data.points[6][0] = 8.1;  data.points[6][1] = 8.0;
    data.points[7][0] = 8.3;  data.points[7][1] = 8.1;
    data.points[8][0] = 7.9;  data.points[8][1] = 8.3;
    data.points[9][0] = 8.2;  data.points[9][1] = 7.9;

    for(int i=0; i<K; i++){
        printf("Enter initial centroid %d: ", i+1);
        scanf("%f %f", &c[i].centroid[0], &c[i].centroid[1]);
        c[i].count = 0;
    }

    k_means_clustering(&data, c);
    print_clusters(c);
}