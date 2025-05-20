//FormAI DATASET v1.0 Category: Physics simulation ; Style: irregular
#include <stdio.h>
#include <math.h>

int main()
{
   int i,j,k,n;
   float a[10][10],min,max,sum,avg;
   printf("\nEnter the value of n : ");
   scanf("%d",&n);
   printf("\nEnter the matrix A:\n");
   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
           scanf("%f",&a[i][j]);
       }
   }

   min=a[0][0]; //Initial minimum value.
   max=a[0][0]; //Initial maximum value.
   sum=0; //Initial sum value.
   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
           if(a[i][j]<min) //If current element is less than min, update min.
           {
               min=a[i][j];
           }
           if(a[i][j]>max) //If current element is greater than max, update max.
           {
               max=a[i][j];
           }
           sum=sum+a[i][j]; //Sum all elements of the matrix.
       }
   }

   avg=sum/(n*n); //Calculate average of the matrix.
   printf("\nMinimum value of A : %f",min);
   printf("\nMaximum value of A : %f",max);
   printf("\nSum of all elements of A : %f",sum);
   printf("\nAverage of all elements of A : %f",avg);

   //Calculate cross product of matrix A with itself.
   float cross[10][10];
   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
           cross[i][j]=0;
           for(k=0;k<n;k++)
           {
               cross[i][j]=cross[i][j]+a[i][k]*a[k][j];
           }
       }
   }

   printf("\n\nCross product of A with itself :\n");
   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
           printf("%f\t",cross[i][j]);
       }
       printf("\n");
   }

   return 0;
}