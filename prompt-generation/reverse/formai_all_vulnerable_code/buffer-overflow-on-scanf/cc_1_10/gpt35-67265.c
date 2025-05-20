//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

   printf("Welcome to the C Word Frequency Counter\n\n");

   // Get the file path from the user
   char file_path[1000];
   printf("Enter the path of the file you want to process:\n");
   scanf("%s", file_path);

   // Open the file
   FILE *fp;
   fp = fopen(file_path, "r");

   // Check if file exists
   if (fp == NULL) {
      printf("\nError: File not found or unable to open the file, please try again.\n");
      exit(EXIT_FAILURE);
   }

   // Initialize a linked list to store the words and their frequency
   typedef struct node {
      char word[100];
      int count;
      struct node *next;
   } node;

   node *head = NULL;

   // Loop through the file and count the frequency of each word
   char delimiter[] = " ,.\n\t";
   char *word;

   char line[1000];
   while (fgets(line, 1000, fp) != NULL) {

      word = strtok(line, delimiter);

      while (word != NULL) {

         // Convert the word to lowercase
         for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
         }

         // Check if the word is already in the linked list
         node *current_node = head;
         while (current_node != NULL && strcmp(current_node->word, word) != 0) {
            current_node = current_node->next;
         }

         // If the word is not already in the linked list, add it
         if (current_node == NULL) {
            node *new_node = malloc(sizeof(node));
            strcpy(new_node->word, word);
            new_node->count = 1;
            new_node->next = head;
            head = new_node;
         }

         // If the word is already in the linked list, increment its count
         else {
            current_node->count++;
         }

         word = strtok(NULL, delimiter);
      }
   }

   fclose(fp);

   // Print the word frequency list
   printf("\nWORD\tFREQUENCY\n");
   printf("--------------------\n");
   node *current_node = head;
   while (current_node != NULL) {
      printf("%s\t%d\n", current_node->word, current_node->count);
      current_node = current_node->next;
   }

   // Free the linked list
   current_node = head;
   while (current_node != NULL) {
      node *next_node = current_node->next;
      free(current_node);
      current_node = next_node;
   }

   return 0;
}