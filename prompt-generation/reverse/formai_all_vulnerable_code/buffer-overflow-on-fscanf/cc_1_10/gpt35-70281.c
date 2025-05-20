//FormAI DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>

// function to write data to a file
void writeToFile(char* filename) {
  FILE* fp;
  char input[50];
  
  fp = fopen(filename, "w"); // open file in write mode
  
  if(fp == NULL) { // error handling if file cannot be opened
    printf("Error opening file!\n");
    return;
  }
  
  printf("Please input data to be written to file:\n");
  fgets(input, 50, stdin); // get user input for data to be written
  
  fprintf(fp, "%s", input); // write data to file
  
  fclose(fp); // close file
  printf("Data has been written to file successfully!\n");
}

// function to read data from a file
void readFromFile(char* filename) {
  FILE* fp;
  char readData[50];
  
  fp = fopen(filename, "r"); // open file in read mode
  
  if(fp == NULL) { // error handling if file cannot be opened
    printf("Error opening file!\n");
    return;
  }
  
  fscanf(fp, "%s", readData); // read data from the file
  
  printf("Data from file:\n%s", readData); // print read data
  
  fclose(fp); // close file
}

int main() {
  char* filename = "example.txt"; // file name
  
  writeToFile(filename); // call function to write data to file
  readFromFile(filename); // call function to read data from file
  
  return 0;
}