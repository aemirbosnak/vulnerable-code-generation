//FormAI DATASET v1.0 Category: Text processing ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
   char input[100], output[100];
   int i, j, k;

   printf("Enter a string: ");
   scanf("%s",input);

   printf("Processing the string...\n");

   // Start of text processing
   for (i = 0, j = 0; input[i] != '\0'; i++) {
       if (input[i] == ' ') {
           continue;
       } else if (input[i] == 't') {
           output[j] = '7';
           j++;
       } else if (input[i] == 'e') {
            output[j] = '3';
            j++;
       } else if (input[i] == 's') {
            output[j] = '5';
            j++;
       } else if (input[i] == 'a') {
            output[j] = '@';
            j++;
       } else if (input[i] == 'i') {
            output[j] = '!';
            j++;
       } else if (input[i] == 'o') {
            output[j] = '0';
            j++;
       } else if (input[i] == 'y') {
            output[j] = '?';
            j++;
       } else {
            output[j] = input[i];
            j++;
       }
   }

   output[j] = '\0';
   // End of text processing

   printf("The processed string is: %s\n", output);

   return 0;
}