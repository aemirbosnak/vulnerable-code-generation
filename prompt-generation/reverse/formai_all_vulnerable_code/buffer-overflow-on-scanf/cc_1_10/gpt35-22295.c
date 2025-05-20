//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Function to compare strings */
int strCompare(char *str1, char *str2) {
   int i = 0, flag = 0;
   
   while(str1[i] != '\0' && str2[i] != '\0') {
      if(str1[i] != str2[i]) {
         flag = 1;
         break;
      }
      i++;
   }

   if(flag == 0 && str1[i] == '\0' && str2[i] == '\0') {
      return 0;
   } else {
      return 1;
   }
}

/* Function to scan the binary file */
void scanFile(char *fileName) {
   char virus[] = "Trojan";
   char buffer[100];
   int i=0;

   FILE *fp;

   fp = fopen(fileName, "rb");

   if(fp == NULL) {
      printf("%s File not found!\n",fileName);
      return;
   }

   while(fgets(buffer,sizeof(buffer),fp) != NULL) {
      i++;
      
      /* Comparing the buffer with malware code */
      if(strCompare(buffer, virus) == 0) {
         printf("Virus detected at Line %d\n",i);
         exit(0);
      }
   }

   printf("File is safe!\n");
   fclose(fp);
}

/* Main function */
int main() {
   char fileName[100];
   
   printf("Enter the name of the file to scan: ");
   scanf("%s", fileName);
   
   scanFile(fileName);
   
   return 0;
}