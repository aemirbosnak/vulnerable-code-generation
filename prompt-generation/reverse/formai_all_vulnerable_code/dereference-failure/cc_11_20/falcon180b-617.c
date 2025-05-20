//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

int main(){
    int m, n, i, j, k, l, c, d, s=0, t=0, u=0, v=0;
    int sum=0;
    char str[MAX];
    char ch;
    char *token;
    FILE *fp;
    char filename[20];

    printf("Enter the number of matrices: ");
    scanf("%d", &m);

    for(i=0; i<m; i++){
        printf("Enter the filename for matrix %d: ", i+1);
        scanf("%s", filename);

        fp=fopen(filename, "r");
        if(fp==NULL){
            printf("Error: File not found.\n");
            exit(0);
        }

        printf("Enter the number of rows and columns for matrix %s: ", filename);
        scanf("%d%d", &n, &k);

        int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

        printf("Enter the elements of matrix %s:\n", filename);
        for(j=0; j<n; j++){
            for(l=0; l<k; l++){
                fscanf(fp, "%d", &A[j][l]);
            }
        }

        fclose(fp);

        printf("Enter the number of rows and columns for matrix B:\n");
        scanf("%d%d", &n, &k);

        printf("Enter the elements of matrix B:\n");
        for(j=0; j<n; j++){
            for(l=0; l<k; l++){
                fscanf(fp, "%d", &B[j][l]);
            }
        }

        fclose(fp);

        for(j=0; j<n; j++){
            for(l=0; l<k; l++){
                C[j][l]=A[j][l]+B[j][l];
            }
        }

        printf("The sum of matrices A and B is:\n");
        for(j=0; j<n; j++){
            for(l=0; l<k; l++){
                printf("%d\t", C[j][l]);
            }
            printf("\n");
        }

        printf("Enter the name for the output file: ");
        scanf("%s", filename);

        fp=fopen(filename, "w");
        if(fp==NULL){
            printf("Error: File not found.\n");
            exit(0);
        }

        for(j=0; j<n; j++){
            for(l=0; l<k; l++){
                fprintf(fp, "%d\t", C[j][l]);
            }
            fprintf(fp, "\n");
        }

        fclose(fp);
    }

    return 0;
}