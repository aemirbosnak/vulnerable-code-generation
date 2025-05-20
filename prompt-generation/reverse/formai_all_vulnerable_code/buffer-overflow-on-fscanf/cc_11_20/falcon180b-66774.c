//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: mind-bending
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define M 1024
#define PI 3.14159265358979323846

int main(){
    int N, i, j;
    double x[M], y[M], h[M], s[M], c[M];
    FILE *fp;
    char file[20];
    printf("Enter the filename: ");
    scanf("%s", file);
    fp = fopen(file, "r");
    fscanf(fp, "%d", &N);
    for(i=0; i<N; i++){
        fscanf(fp, "%lf", &x[i]);
        fscanf(fp, "%lf", &y[i]);
    }
    fclose(fp);
    for(i=0; i<M; i++){
        h[i] = 0;
        s[i] = 0;
        c[i] = 0;
    }
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            if(i==j){
                h[j] = 1;
            }
            else{
                h[j] = 0;
            }
        }
        for(j=0; j<M; j++){
            s[j] += x[i]*h[j];
            c[j] += y[i]*h[j];
        }
    }
    for(i=0; i<M; i++){
        s[i] /= M;
        c[i] /= M;
    }
    for(i=0; i<M; i++){
        h[i] = s[i]*c[i];
        h[i] /= (s[i]*s[i] + c[i]*c[i]) + 0.0000000001;
    }
    for(i=0; i<M; i++){
        s[i] = s[i]*(1 - h[i]);
        c[i] = c[i]*(1 - h[i]);
    }
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            y[i] += h[j]*x[i];
        }
    }
    for(i=0; i<N; i++){
        x[i] = x[i] + y[i];
    }
    for(i=0; i<N; i++){
        printf("%lf\n", x[i]);
    }
    return 0;
}