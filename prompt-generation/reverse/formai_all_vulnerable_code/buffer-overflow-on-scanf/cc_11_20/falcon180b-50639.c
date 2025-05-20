//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
    int i,j,k,l;
    int **matrix;
    int n,m;
    char *filename = "weather.txt";
    FILE *fp;
    fp = fopen(filename,"w");
    if(fp==NULL){
        printf("Error in opening file\n");
        exit(0);
    }
    printf("Enter the number of rows and columns: ");
    scanf("%d %d",&n,&m);
    matrix = (int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++){
        matrix[i] = (int *)malloc(m*sizeof(int));
    }
    srand(time(NULL));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            matrix[i][j] = rand()%100;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            fprintf(fp,"%d ",matrix[i][j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    printf("Weather simulation starting...\n");
    system("sleep 1");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(matrix[i][j]<50){
                printf("\x1b[31m");
            }
            else if(matrix[i][j]<75){
                printf("\x1b[33m");
            }
            else{
                printf("\x1b[32m");
            }
            printf("%d ",matrix[i][j]);
            printf("\x1b[0m");
        }
        printf("\n");
    }
    return 0;
}