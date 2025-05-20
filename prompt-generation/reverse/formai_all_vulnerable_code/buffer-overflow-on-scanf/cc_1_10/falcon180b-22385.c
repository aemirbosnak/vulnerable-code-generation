//Falcon-180B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100
#define INF 9999

int cluster[MAX];
int minDistance = INF;
int minIndex;

void initialize(int n) {
    int i;
    for (i = 0; i < n; i++) {
        cluster[i] = i;
    }
}

void mergeClusters(int a, int b) {
    int i;
    for (i = 0; i < MAX; i++) {
        if (cluster[i] == a) {
            cluster[i] = b;
        }
    }
}

int euclideanDistance(int i, int j) {
    int sum = 0;
    int x, y;
    for (x = 0; x < 3; x++) {
        for (y = 0; y < 3; y++) {
            sum += pow((i % 10 - j % 10), 2);
            i /= 10;
            j /= 10;
        }
    }
    return sum;
}

void kMeans(int n, int k) {
    int i, j, c;
    int count = 0;
    while (count < 10) {
        count = 0;
        for (i = 0; i < n; i++) {
            minDistance = INF;
            minIndex = -1;
            for (j = 0; j < k; j++) {
                if (euclideanDistance(i, j) < minDistance) {
                    minDistance = euclideanDistance(i, j);
                    minIndex = j;
                }
            }
            if (cluster[i]!= minIndex) {
                mergeClusters(i, minIndex);
                count++;
            }
        }
    }
}

void printClusters(int n, int k) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("%d ", cluster[i]);
    }
    printf("\n");
    for (i = 0; i < k; i++) {
        printf("Cluster %d: ", i);
        for (j = 0; j < n; j++) {
            if (cluster[j] == i) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int data[MAX];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    initialize(n);
    kMeans(n, k);
    printClusters(n, k);
    return 0;
}