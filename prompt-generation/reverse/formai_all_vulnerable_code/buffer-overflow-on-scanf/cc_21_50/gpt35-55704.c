//FormAI DATASET v1.0 Category: Data mining ; Style: random
#include<stdio.h>
#include<stdlib.h>

int main()
{
   int arr[50], temp[50], n, c, d, i, j, k;
   float minsupp;

   printf("Enter the number of items in the list: ");
   scanf("%d", &n);

   printf("Enter the items:\n");
   for (i = 0;i < n;i++)
   {
      scanf("%d", &arr[i]);
      temp[i] = arr[i];
   }

   printf("Enter the minimum support in percentage: ");
   scanf("%f", &minsupp);

   minsupp/=100.0;

   int freq[n];     
   int visited = -1;

   for(i=0; i<n; i++)
   {
        freq[i] = 1;
        for(j=i+1; j<n; j++)
        {
            if(temp[i] == temp[j])
            {
                freq[i]++;
                temp[j] = visited;  
            }
        }
   }

   printf("\nThe frequent items are:\n");
   for(i=0; i<n; i++)
   {
        if(temp[i] != visited)
            printf("%d occurs %d times\n", temp[i], freq[i]);
   }

   int l1[n], l2[n];
   j=0; k=0;
   for(i=0; i<n; i++)
   {
        if(freq[i] >= minsupp*n)
        {
            l1[j] = temp[i];
            j++;
        }
        else
        {
            l2[k] = temp[i];
            k++;
        }
   }

   if(j==0)
   {
       printf("\nNo frequent items available\n");
       return 0;
   }

   int comb[l1[j-1]][l1[j-1]][2];
   for(i=0;i<j;i++)
   {
       for(int p=i+1;p<j;p++)
       {
           comb[l1[i]][l1[p]][0] = 0;
           comb[l1[i]][l1[p]][1] = 0;
           for(int q=0;q<n;q++)
           {
               if((arr[q]==l1[i])||(arr[q]==l1[p]))
               {
                   if((arr[q]==l1[i])&&(comb[l1[i]][l1[p]][1]==0))
                   {
                       comb[l1[i]][l1[p]][1] = 1;
                   }
                   if((arr[q]==l1[p])&&(comb[l1[i]][l1[p]][0]==1))
                   {
                       comb[l1[i]][l1[p]][1] = 1;
                   }
                   if((arr[q]==l1[i])&&(comb[l1[i]][l1[p]][1]==1))
                   {
                       comb[l1[i]][l1[p]][0] = 1;
                   }
                   if((arr[q]==l1[p])&&(comb[l1[i]][l1[p]][0]==0))
                   {
                       comb[l1[i]][l1[p]][0] = 1;
                   }

               }
           }
       }
   }

   printf("\nThe frequent item pairs are:\n");
   for(i=0;i<j;i++)
   {
        for(int p=i+1;p<j;p++)
        {
            if(comb[l1[i]][l1[p]][0]==1&&comb[l1[i]][l1[p]][1]==1)
            {
                printf("%d, %d\n",l1[i],l1[p]);
            }
        }
   }

   return 0;
}