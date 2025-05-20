//FormAI DATASET v1.0 Category: Pattern printing ; Style: statistical
#include<stdio.h>

int main()
{
   int rows, i, j, k, l;
   printf("Enter the number of rows: ");
   scanf("%d",&rows);
   
   if(rows < 5){
      printf("Error! Please enter a value greater than or equal to 5.");
      return 0;
   }
   
   int A = rows/2 + 1, B = rows/2;
   
   for(i=1;i<=rows;i++){
        
        if(i==A){
            for(j=1;j<=i;j++){
                printf("* ");
            }
        }
        else if(i>=1 && i<A){
            for(j=1;j<=i;j++){
                printf("* ");
            }
            for(k=1;k<=((rows-2*i)/2);k++){
                printf("C ");
            }
            for(l=1;l<=i;l++){
                printf("* ");
            }
        }
        else{
            for(j=i;j<=rows;j++){
                printf("* ");
            }
            for(k=1;k<=((2*B-rows+2*i)/2);k++){
                printf("C ");
            }
            for(l=i;l<=rows;l++){
                printf("* ");
            }
        }
        
        printf("\n");
   }

   return 0;
}