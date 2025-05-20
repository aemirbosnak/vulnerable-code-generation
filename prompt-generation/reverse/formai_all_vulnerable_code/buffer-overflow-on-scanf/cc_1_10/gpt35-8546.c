//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

//function to calculate average temperature
float calcAvg(float *arr, int len){
  float sum = 0.0, avg;
  for(int i=0;i<len;i++){
    sum += *(arr+i);
  }
  avg = sum/len;
  return avg;
}

//function to calculate maximum temperature
float calcMax(float *arr, int len){
  float max = *arr;
  for(int i=0;i<len;i++){
    if(*(arr+i)>max){
      max = *(arr+i);
    }
  }
  return max;
}

//function to calculate minimum temperature
float calcMin(float *arr, int len){
  float min = *arr;
  for(int i=0;i<len;i++){
    if(*(arr+i)<min){
      min = *(arr+i);
    }
  }
  return min;
}

int main(){
  int num, i;
  float *ptr, avg, max, min;
  
  //getting user input for number of temperatures to monitor
  printf("Enter the number of temperatures to monitor: ");
  scanf("%d", &num);
  
  //memory allocation for temperature values
  ptr = (float*) malloc(num * sizeof(float));
  
  //getting user input for temperature values
  for(i=0;i<num;i++){
    printf("Enter the temperature value for reading %d: ", i+1);
    scanf("%f", ptr+i);
  }
  
  //calculating average temperature
  avg = calcAvg(ptr, num);
  
  //calculating maximum temperature
  max = calcMax(ptr, num);
  
  //calculating minimum temperature
  min = calcMin(ptr, num);
  
  //displaying results
  printf("Total number of temperatures monitored: %d\n", num);
  printf("Average temperature: %.2f\n", avg);
  printf("Maximum temperature: %.2f\n", max);
  printf("Minimum temperature: %.2f\n", min);
  
  //freeing allocated memory
  free(ptr);
  
  return 0;
}