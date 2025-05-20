//FormAI DATASET v1.0 Category: Matrix operations ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main() {
   int r1,c1,r2,c2,i,j,k,sum=0;
   printf("\n\n Hey there! I am a Matrix Bot!\n");

   printf("\n Let's do some Matrix operations!\n");
   printf("\n First, we need to create two matrices\n");

   printf(" Enter the no. of rows for Matrix 1 : ");
   scanf("%d",&r1);

   printf(" Enter the no. of columns for Matrix 1 : ");
   scanf("%d",&c1);

   printf(" Enter the no. of rows for Matrix 2 : ");
   scanf("%d",&r2);

   printf(" Enter the no. of columns for Matrix 2 : ");
   scanf("%d",&c2);

   if(c1!=r2) {
      printf("\n OOPS! Matrix multiplication cannot be performed.\n");
      exit(0);
   }

   int** mat1 = (int**)malloc(sizeof(int*)*r1);
   for(i=0 ; i<r1 ; i++) {
      mat1[i] = (int*)malloc(sizeof(int)*c1);
   }

   int** mat2 = (int**)malloc(sizeof(int*)*r2);
   for(i=0 ; i<r2 ; i++) {
      mat2[i] = (int*)malloc(sizeof(int)*c2);
   }

   int** result = (int**)malloc(sizeof(int*)*r1);
   for(i=0 ; i<r1 ; i++) {
      result[i] = (int*)malloc(sizeof(int)*c2);
   }

   printf("\n Enter the elements of Matrix 1 : ");
   for(i=0 ; i<r1 ; i++) {
      for(j=0 ; j<c1 ; j++) {
         scanf("%d",&mat1[i][j]);
      }
   }

   printf("\n Awesome! Now enter the elements of Matrix 2 : ");
   for(i=0 ; i<r2 ; i++) {
      for(j=0 ; j<c2 ; j++) {
         scanf("%d",&mat2[i][j]);
      }
   }

   printf("\n Woohoo! Let's multiply Matrix 1 and Matrix 2!\n");

   for(i=0 ; i<r1 ; i++) {
      for(j=0 ; j<c2 ; j++) {
         for(k=0 ; k<c1 ; k++) {
            sum += mat1[i][k]*mat2[k][j];
         }
         result[i][j] = sum;
         sum = 0;
      }
   }

   printf("\n The resulting matrix is : ");
   for(i=0 ; i<r1 ; i++) {
      printf("\n");
      for(j=0 ; j<c2 ; j++) {
         printf("%d\t",result[i][j]);
      }
   }

   printf("\n Yay! We did it!!\n");

   for(i=0 ; i<r1 ; i++) {
      free(mat1[i]);
      free(result[i]);
   }

   for(i=0 ; i<r2 ; i++) {
      free(mat2[i]);
   }
   free(mat1);
   free(mat2);
   free(result);

   return 0;
}