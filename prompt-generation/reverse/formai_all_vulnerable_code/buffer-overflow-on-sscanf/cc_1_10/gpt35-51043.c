//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Metadata {
   char author[50];
   char date[20];
   char description[100];
};

void print_metadata(struct Metadata *metadata) {
   printf("Author: %s\n", metadata->author);
   printf("Date: %s\n", metadata->date);
   printf("Description: %s\n", metadata->description);
}

void extract_metadata(FILE *file, struct Metadata *metadata) {
   char line[256];

   while (fgets(line, sizeof(line), file)) {
      if (strstr(line, "author:")) {
         sscanf(line, "author: %s", metadata->author);
      } else if (strstr(line, "date:")) {
         sscanf(line, "date: %s", metadata->date);
      } else if (strstr(line, "description:")) {
         sscanf(line, "description: %[^\n]", metadata->description);
      }
   }
}

int main(int argc, char **argv) {
   struct Metadata metadata;
   FILE *file;

   if (argc < 2) {
      fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   file = fopen(argv[1], "r");

   if (file == NULL) {
      perror("fopen");
      exit(EXIT_FAILURE);
   }

   extract_metadata(file, &metadata);
   print_metadata(&metadata);

   fclose(file);

   return EXIT_SUCCESS;
}