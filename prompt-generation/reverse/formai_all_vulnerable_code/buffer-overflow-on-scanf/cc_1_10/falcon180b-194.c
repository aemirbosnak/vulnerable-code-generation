//Falcon-180B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 100
#define INF INT_MAX

typedef struct{
    int data;
    int x,y;
}point;

point createPoint(int x, int y){
    point p;
    p.data = rand()%100;
    p.x = x;
    p.y = y;
    return p;
}

int euclideanDistance(point p1, point p2){
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return (dx*dx + dy*dy);
}

void swap(point *a, point *b){
    point temp = *a;
    *a = *b;
    *b = temp;
}

void kMeans(point data[], int k, int numOfIterations){
    int i,j;
    point centroids[k];
    int assignments[MAX];
    for(i=0; i<k; i++){
        centroids[i] = createPoint(i%50, i/50);
    }
    for(i=0; i<numOfIterations; i++){
        for(j=0; j<MAX; j++){
            int minDistance = INF;
            int minIndex = -1;
            for(int c=0; c<k; c++){
                int distance = euclideanDistance(data[j], centroids[c]);
                if(distance < minDistance){
                    minDistance = distance;
                    minIndex = c;
                }
            }
            assignments[j] = minIndex;
        }
        for(j=0; j<k; j++){
            int sumX = 0;
            int sumY = 0;
            int count = 0;
            for(int c=0; c<MAX; c++){
                if(assignments[c] == j){
                    sumX += data[c].x;
                    sumY += data[c].y;
                    count++;
                }
            }
            if(count > 0){
                centroids[j].x = sumX / count;
                centroids[j].y = sumY / count;
            }
        }
    }
    for(i=0; i<k; i++){
        printf("Cluster %d: (%d, %d)\n", i+1, centroids[i].x, centroids[i].y);
    }
}

int main(){
    point data[MAX];
    int numOfClusters, numOfIterations;
    printf("Enter the number of clusters: ");
    scanf("%d", &numOfClusters);
    printf("Enter the number of iterations: ");
    scanf("%d", &numOfIterations);
    srand(time(NULL));
    for(int i=0; i<MAX; i++){
        data[i] = createPoint(i%50, i/50);
    }
    kMeans(data, numOfClusters, numOfIterations);
    return 0;
}