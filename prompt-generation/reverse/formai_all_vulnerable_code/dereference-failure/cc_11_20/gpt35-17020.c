//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double distance(int *x, int *y, int i, int j) {
    double dx = pow((x[i] - x[j]), 2);
    double dy = pow((y[i] - y[j]), 2);
    return sqrt(dx + dy);
}

int main() {
    int n = 5, i, j, k, count, flag, index;
    int *x, *y, *labels;
    double **matrix, dist;
    x = (int*)malloc(n * sizeof(int));
    y = (int*)malloc(n * sizeof(int));
    labels = (int*)malloc(n * sizeof(int));
    matrix = (double**)malloc(n * sizeof(double*));
    for(i=0; i<n; i++){
        matrix[i] = (double*)malloc(n * sizeof(double));
    }
    printf("Enter the values of x and y coordinates:\n");
    for(i=0; i<n; i++){
        scanf("%d%d", &x[i], &y[i]);
        labels[i] = i;
    }
    //Compute distance matrix
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            matrix[i][j] = 0;
            if(i!=j){
                dist = distance(x, y, i, j);
                matrix[i][j] = dist;
            }
        }
    }
    //Do clustering
    count = n;
    while(count>1){
        flag = 0;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(matrix[i][j]>0 && matrix[i][j]<100){
                    flag = 1;
                    break;
                }
            }
            if(flag==1){
                break;
            }
        }
        dist = matrix[i][j];
        index = j;
        for(k=0; k<n; k++){
            if(matrix[i][k]<dist && matrix[i][k]>0){
                dist = matrix[i][k];
                index = k;
            }
        }
        for(k=0; k<n; k++){
            if(k!=i && k!=index){
                matrix[i][k] = (matrix[i][k] + matrix[index][k])/2;
                matrix[k][i] = matrix[i][k];
            }
        }
        //Update the labels
        for(k=0; k<n; k++){
            if(labels[k]==index){
                labels[k] = i;
            }
        }
        count--;
    }
    //Print the clusters
    printf("The clusters are:\n");
    int cluster_count = 0;
    for(i=0; i<n; i++){
        if(labels[i]==i){
            printf("\nCluster %d:\n", ++cluster_count);
        }
        printf("%d\t", i);
    }
    printf("\n");
    for(i=0; i<n; i++){
        printf("%d\t", labels[i]);
    }
    //Free allocated memory
    free(x);
    free(y);
    free(labels);
    for(i=0; i<n; i++){
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}