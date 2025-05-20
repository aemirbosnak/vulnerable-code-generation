//FormAI DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This is a unique compression algorithm that uses ASCII values to compress the input string. 

int main()
{
   char input[100], output[200];
   int count = 0, len, i, j, k=0;

   printf("Enter the string to compress: ");
   scanf("%s", input);

   len = strlen(input);

   for(i=0; i<len; i++)
   {
       j=i+1;
       count++;

       //If the current character is different than the next one, then add the ASCII value of the current character
       //to the output string and its count as well.
       while(input[j] == input[i])
       {
           count++;
           i++;
           j++;
       }

       output[k++] = input[i];
       sprintf(&output[k], "%d", count);
       k += strlen(&output[k]);
       count = 0;
   }

   printf("\n\nCompressed string: %s", output);

   //Decompression logic

   char decompressed[100];
   int output_len = strlen(output);
   k=0;

   for(i=0; i<output_len; i++)
   {
       decompressed[k++] = output[i];

       //if the current character is a digit, then we need to add it to a new string to extract the number.
       if(output[i+1] >= 48 && output[i+1] <= 57)
       {
           int digit;
           char str_num[10];
           j=0;

           while(output[i+1] >= 48 && output[i+1] <= 57)
           {
               str_num[j++] = output[i+1];
               i++;
           }
           str_num[j] = '\0';
           digit = atoi(str_num);
           for(int z=0; z<digit-1; z++)
           {
               decompressed[k++] = decompressed[k-2];
           }
       }
   }

   decompressed[k] = '\0';

   printf("\n\nDecompressed string: %s", decompressed);
     
   return 0;
}