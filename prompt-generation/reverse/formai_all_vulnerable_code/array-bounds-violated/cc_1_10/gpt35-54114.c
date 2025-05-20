//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100
#define SIZE 2

struct point{
    float x[SIZE];
    int group;
}data[MAX];

float euclidean(struct point p1, struct point p2) {
    float dist = 0;

    for(int i=0; i<SIZE; i++) {
        dist += pow(p1.x[i] - p2.x[i], 2);
    }

    return sqrt(dist);
}

void kmeans(int k, int n) {
    int i, j, index, min_dist;
    int count[k], flag = 0;
    float dist, min;
    struct point mean[k], prev_mean[k];

    for(i=0; i<k; i++) {
        index = rand() % n;
        for(j=0; j<SIZE; j++) {
            mean[i].x[j] = data[index].x[j];
        }
    }

    while(!flag) {
        for(i=0; i<k; i++) {
            count[i] = 0;
            prev_mean[i] = mean[i];
        }

        for(i=0; i<n; i++) {
            min = euclidean(data[i], mean[0]);
            min_dist = 0;
            for(j=1; j<k; j++) {
                dist = euclidean(data[i], mean[j]);
                if(dist < min) {
                    min = dist;
                    min_dist = j;
                }
            }
            data[i].group = min_dist;
            count[min_dist]++;
        }

        for(i=0; i<k; i++) {
            for(j=0; j<SIZE; j++) {
                mean[i].x[j] = 0;
            }
        }

        for(i=0; i<n; i++) {
            for(j=0; j<SIZE; j++) {
                mean[data[i].group].x[j] += data[i].x[j];
            }
        }

        for(i=0; i<k; i++) {
            for(j=0; j<SIZE; j++) {
                if(count[i]>0) {
                    mean[i].x[j] /= count[i];
                }
            }
        }

        flag = 1;
        for(i=0; i<k; i++) {
            if(euclidean(mean[i], prev_mean[i]) > 0.001) {
                flag = 0;
                break;
            }
        }
    }

    for(i=0; i<k; i++) {
       printf("Cluster %d: ", i+1);
       for(j=0; j<n; j++) {
           if(data[j].group == i) {
               printf("(%f, %f) ", data[j].x[0], data[j].x[1]);
           }
       }
       printf("\n\n");
    }
}

int main() {
    int n, k, i, j;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter the coordinates for point %d: ", i+1);
        for(j=0; j<SIZE; j++) {
            scanf("%f", &data[i].x[j]);
        }
    }

    printf("\nEnter the number of clusters: ");
    scanf("%d", &k);

    kmeans(k, n);

    return 0;
}