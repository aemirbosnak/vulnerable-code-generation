//FormAI DATASET v1.0 Category: Log analysis ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to get the number of occurrences
int get_occurrences(char* log_file,char* search_str){
  int count = 0;

  //Open the log file
  FILE *fp;
  fp = fopen(log_file,"r");

  //Check if the file opened successfully
  if(fp == NULL){
    printf("\nError: Unable to open file\n");
    exit(1);
  }

  //Read the file line by line
  char line[1024];
  while(fgets(line,sizeof(line),fp) != NULL){
    //Check if the search string is present in the line
    char* ptr = strstr(line,search_str);
    while(ptr != NULL){
      count++;
      ptr = strstr(ptr+1,search_str);      
    }
  }

  //Close the file
  fclose(fp);

  return count;
}

int main(){

  //Get the log file name
  char log_file[100];
  printf("Enter the name of log file: ");
  scanf("%s",log_file);

  //Get the search string
  char search_str[100];
  printf("Enter the string to search: ");
  scanf("%s",search_str);

  //Get the number of occurrences
  int count = get_occurrences(log_file,search_str);

  //Display the result
  printf("\nThe string \"%s\" occurred %d times in the log file \"%s\"",search_str,count,log_file);

  return 0;
}