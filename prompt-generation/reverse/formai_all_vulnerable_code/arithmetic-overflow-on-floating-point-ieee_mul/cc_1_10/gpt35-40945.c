//FormAI DATASET v1.0 Category: Image compression ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Compression function
void compression(int **img, int M, int N, float c_ratio)
{
    int i,j,k,l,c_rate;
    int **new_img;

    //Calculating the number of rows and columns in the compressed image
    int M_new = ceil(c_ratio*M);
    int N_new = ceil(c_ratio*N);

    //Allocating memory for the new compressed image
    new_img = (int **)calloc(M_new,sizeof(int *));
    for(i=0;i<M_new;i++) new_img[i] = (int *)calloc(N_new,sizeof(int));

    //Compressing the image
    for(i=0;i<M_new;i++)
    {
        for(j=0;j<N_new;j++)
        {
            float sum = 0;
            float p = (float)M/M_new;
            float q = (float)N/N_new;

            for(k = floor(i*p);k < ceil((i+1)*p);k++)
            {
                for(l = floor(j*q);l < ceil((j+1)*q);l++)
                {
                    sum += img[k][l];
                }
            }

            new_img[i][j] = round(sum/((ceil((i+1)*p)-floor(i*p))*(ceil((j+1)*q)-floor(j*q))));
        }
    }

    //Calculating compression ratio
    c_rate = ceil((1-c_ratio)*100);
    printf("\nPercentage Compression : %d%%",c_rate);

    //Printing the compressed image
    printf("\nCompressed Image :\n");
    for(i=0;i<M_new;i++)
    {
        for(j=0;j<N_new;j++)
        {
            printf("%d ",new_img[i][j]);
        }
        printf("\n");
    }

    //Freeing the allocated memory
    for(i=0;i<M_new;i++) free(new_img[i]);
    free(new_img);

    printf("\nImage Compression Successful\n");
}

int main()
{
    int **img;
    int M, N, i, j;
    float c_ratio;

    printf("Enter the number of rows of the image : ");
    scanf("%d",&M);
    printf("Enter the number of columns of the image : ");
    scanf("%d",&N);

    printf("\nEnter the elements of the image :\n");
    img = (int **)calloc(M,sizeof(int *));
    for(i=0;i<M;i++) img[i] = (int *)calloc(N,sizeof(int));

    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("img[%d][%d] : ",i,j);
            scanf("%d",&img[i][j]);
        }
    }

    printf("\nEnter the compression ratio(e.g. 0.5 for 50%% compression) : ");
    scanf("%f",&c_ratio);

    //Calling the compression function
    compression(img,M,N,c_ratio);

    //Freeing the allocated memory
    for(i=0;i<M;i++) free(img[i]);
    free(img);

    return 0;
}