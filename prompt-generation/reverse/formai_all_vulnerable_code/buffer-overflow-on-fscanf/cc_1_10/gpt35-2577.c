//FormAI DATASET v1.0 Category: Image Classification system ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 1000
#define M 784
#define K 10
#define BATCH_SIZE 100

double X[N][M], Y[N][K], W[M][K], b[K];
int label[N];
int train_idx[N];

void softmax(double *A, int n)
{
    double maxval = A[0];
    int i;
    for(i = 1; i < n; i++)
    {
        if(A[i] > maxval)
        {
            maxval = A[i];
        }
    }
    double sum = 0.0;
    for(i = 0; i < n; i++)
    {
        sum += exp(A[i] - maxval);
    }
    for(i = 0; i < n; i++)
    {
        A[i] = exp(A[i] - maxval) / sum;
    }
}

void forward(double *x, double *y)
{
    int i, j;
    for(i = 0; i < K; i++)
    {
        y[i] = 0.0;
        for(j = 0; j < M; j++)
        {
            y[i] += x[j] * W[j][i];
        }
        y[i] += b[i];
    }
    softmax(y, K);
}

void backward(double alpha)
{
    int i, j, k, t;
    double delta[K] = {0};
    double gw[M][K] = {{0}};
    double gb[K] = {0};
    for(t = 0; t < BATCH_SIZE; t++)
    {
        memcpy(delta, Y[t], sizeof(delta));
        delta[label[t]] -= 1.0;
        for(i = 0; i < K; i++)
        {
            gb[i] += delta[i];
            for(j = 0; j < M; j++)
            {
                gw[j][i] += X[train_idx[t]][j] * delta[i];
            }
        }
    }
    for(i = 0; i < K; i++)
    {
        b[i] -= gb[i] * alpha / BATCH_SIZE;
        for(j = 0; j < M; j++)
        {
            W[j][i] -= gw[j][i] * alpha / BATCH_SIZE;
        }
    }
}

int main(int argc, char **argv)
{
    int num_train, num_iter, i, j, k, idx;
    double accuracy;
    
    // read data
    FILE *fp = fopen("train_data.txt", "r");
    fscanf(fp, "%d", &num_train);
    for(i = 0; i < num_train; i++)
    {
        fscanf(fp, "%d", &label[i]);
        for(j = 0; j < M; j++)
        {
            fscanf(fp, "%lf", &X[i][j]);
        }
    }
    fclose(fp);
    
    // initialize parameters
    srand(0);
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < K; j++)
        {
            W[i][j] = rand() / (double)(RAND_MAX) * 0.02 - 0.01;
        }
    }
    for(i = 0; i < K; i++)
    {
        b[i] = 0.0;
    }
    
    // train
    num_iter = 1000;
    for(k = 0; k < num_iter; k++)
    {
        for(i = 0; i < BATCH_SIZE; i++)
        {
            train_idx[i] = rand() % num_train;
        }
        for(i = 0; i < BATCH_SIZE; i++)
        {
            forward(X[train_idx[i]], Y[i]);
        }
        backward(0.01);
    }
    
    // test
    fp = fopen("test_data.txt", "r");
    int num_test;
    fscanf(fp, "%d", &num_test);
    int correct_count = 0;
    for(i = 0; i < num_test; i++)
    {
        int true_label;
        double prediction[K] = {0};
        fscanf(fp, "%d", &true_label);
        for(j = 0; j < M; j++)
        {
            fscanf(fp, "%lf", &X[i][j]);
        }
        forward(X[i], prediction);
        double maxval = 0.0;
        int max_idx = 0;
        for(j = 0; j < K; j++)
        {
            if(prediction[j] > maxval)
            {
                maxval = prediction[j];
                max_idx = j;
            }
        }
        if(max_idx == true_label)
        {
            correct_count++;
        }
    }
    fclose(fp);
    
    accuracy = correct_count / (double)num_test;
    printf("Accuracy: %lf\n", accuracy);
    
    return 0;
}