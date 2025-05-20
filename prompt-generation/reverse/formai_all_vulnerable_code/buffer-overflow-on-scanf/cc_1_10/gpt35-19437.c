//FormAI DATASET v1.0 Category: Computer Biology ; Style: excited
#include <stdio.h>

int main() {

printf("Wow! This is a scientific breakthrough! Our C program now allows us to analyze DNA sequences!\n");
printf("Enter the DNA sequence: \n");

char sequence[100];
scanf("%s", sequence);

int adenine_count = 0, cytosine_count = 0, guanine_count = 0, thymine_count = 0, length;

for (length = 0; sequence[length] != '\0'; ++length) {

switch(sequence[length]) {
   case 'A':
   case 'a':
       ++adenine_count;
       break;
   case 'C':
   case 'c':
       ++cytosine_count;
       break;
   case 'G':
   case 'g':
       ++guanine_count;
       break;
   case 'T':
   case 't':
       ++thymine_count;
       break;
   default:
       printf("Invalid DNA sequence!");
       return 0;
   }
}

printf("\nAnalysis complete!\n");
printf("Adenine count: %d\n", adenine_count);
printf("Cytosine count: %d\n", cytosine_count);
printf("Guanine count: %d\n", guanine_count);
printf("Thymine count: %d\n", thymine_count);

float adenine_percentage = (float) adenine_count / length;
float cytosine_percentage = (float) cytosine_count / length;
float guanine_percentage = (float) guanine_count / length;
float thymine_percentage = (float) thymine_count / length;

printf("Adenine percentage: %.2f%%\n", adenine_percentage * 100);
printf("Cytosine percentage: %.2f%%\n", cytosine_percentage * 100);
printf("Guanine percentage: %.2f%%\n", guanine_percentage * 100);
printf("Thymine percentage: %.2f%%\n", thymine_percentage * 100);

return 0;
}