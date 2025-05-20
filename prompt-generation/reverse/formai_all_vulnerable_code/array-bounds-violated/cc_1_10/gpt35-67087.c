//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: mathematical
/*
JSON Parser Example Program: Addition of two numbers.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to parse and add two numbers from JSON string
int addTwoNumbersFromJSON(char* jsonString){
  
  int len = strlen(jsonString);
  int num1=0,num2=0;
  int* nums[2] = {&num1,&num2};
  int curNumIndex = -1;
  int isNegative = 0;
  int i;
  
  for(i=0;i<len;i++){
    if(jsonString[i] == ':'){
      curNumIndex++;
      continue;
    }
    
    if(jsonString[i] == '-'){
      isNegative = 1;
      continue;
    }
    
    if(jsonString[i] >= '0' && jsonString[i] <= '9'){
      *nums[curNumIndex] = (*nums[curNumIndex])*10 + (jsonString[i]-'0');
    }
    
    if(jsonString[i] == ','){
      if(isNegative)
        *nums[curNumIndex] *= -1;
      isNegative = 0;
      curNumIndex = -1;
    }
  }
  
  if(isNegative)
    *nums[curNumIndex] *= -1;
  return num1+num2;
}

int main(){
  
  char* jsonString = "{\"num1\": 15, \"num2\": -10}";
  
  int result = addTwoNumbersFromJSON(jsonString);
  printf("Result: %d",result);
  
  return 0;
}