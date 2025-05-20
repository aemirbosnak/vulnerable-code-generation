//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main(int argc, char** argv) {
  regex_t regex; // declare the regex object
  int reti; // declare the return value of regex functions
  char* pattern = "([A-Za-z]+)([ ]{0,1})((([A-Za-z]+(([ ]{0,1})-([ ]{0,1})[A-Za-z]+){0,1}){0,1})){1,3}[ ]{0,1}(\\r{0,1}\\n){0,1}[ ]{0,1}\\|([ ]{0,1})([A-Za-z]+(([ ]{0,1})[A-Za-z]+){0,1})(([ ]{0,1})\\r{0,1}\\n){0,1}[ ]{0,1}\\|([ ]{0,1})[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}"; // regular expression for name, job title, and email

  if (argc != 2) { // check if a resume was provided as an argument
    printf("Please provide a resume file as an argument\n");
    return 1;
  }

  FILE* fp = fopen(argv[1], "r"); // open the resume file
  if (fp == NULL) {
    printf("Unable to open file\n");
    return 2;
  }

  fseek(fp, 0, SEEK_END); // move the file pointer to the end of the file
  long size = ftell(fp); // determine the size of the file
  fseek(fp, 0, SEEK_SET); // move the file pointer back to the beginning of the file

  char* buffer = malloc(size); // allocate memory for reading the file
  fread(buffer, 1, size, fp); // read the file into the buffer

  reti = regcomp(&regex, pattern, REG_EXTENDED|REG_NEWLINE); // compile the regular expression pattern
  if (reti) {
    printf("Could not compile regex\n");
    return 3;
  }

  regmatch_t matches[10]; // declare an array of regmatch_t objects to hold the matches
  int num_matches = 0; // declare variable to hold the number of matches found

  // loop through the buffer and look for matches
  while ((reti = regexec(&regex, buffer, 10, matches, 0)) == 0) {
    num_matches++; // increment the number of matches found
    printf("Match %d:\nName: ", num_matches);
    for (int i = matches[1].rm_so; i < matches[1].rm_eo; i++)
      printf("%c", buffer[i]);
    if (matches[3].rm_so != -1) {
      printf(" ");
      for (int i = matches[3].rm_so; i < matches[3].rm_eo; i++)
        printf("%c", buffer[i]);
    }
    if (matches[5].rm_so != -1) {
      printf(" ");
      for (int i = matches[5].rm_so; i < matches[5].rm_eo; i++)
        printf("%c", buffer[i]);
    }
    printf("\nJob Title: ");
    for (int i = matches[9].rm_so; i < matches[9].rm_eo; i++)
      printf("%c", buffer[i]);
    printf("\nEmail: ");
    for (int i = matches[14].rm_so; i < matches[14].rm_eo; i++)
      printf("%c", buffer[i]);
    printf("\n");
    buffer += matches[0].rm_eo; // move the buffer pointer to the end of the match
  }

  if (num_matches == 0) {
    printf("No matches found\n");
    return 4;
  }

  regfree(&regex); // free the regex object

  free(buffer); // free the buffer
  fclose(fp); // close the file

  return 0;
}