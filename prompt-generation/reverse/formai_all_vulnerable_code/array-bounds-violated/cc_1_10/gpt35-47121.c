//FormAI DATASET v1.0 Category: Data validation ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

/*
This program validates a set of data inputs and calculates basic statistical measures.
*/

int main()
{
  int n, i, min, max, sum=0;
  float mean, sd;

  printf("Enter the number of data points: ");
  scanf("%d", &n);

  int data[n]; //declare an array of size n

  printf("Enter the data points: ");
  
  for(i=0; i<n; i++) //loop to take input of data points
  {
      scanf("%d", &data[i]);
      sum += data[i]; //calculate sum of data
  }

  mean = (float)sum/n; //calculate mean of data

  //calculate minimum and maximum data points
  min = data[0];
  max = data[0];
  for(i=1; i<n; i++)
  {
      if(data[i] < min)
          min = data[i];
      else if(data[i] > max)
          max = data[i];
  }

  //calculate standard deviation of data
  sum = 0;
  for(i=0; i<n; i++)
      sum += (data[i]-mean)*(data[i]-mean);
  sd = sqrt(sum/n);

  //validate data points
  for(i=0; i<n; i++)
  {
      if(data[i] < min || data[i] > max)
      {
          printf("\nInvalid data point: %d", data[i]);
          printf("\nPlease enter valid data points within range [%d, %d]", min, max);
          exit(0); //exit program if invalid data found
      }
  }

  //print statistical measures of data
  printf("\n--------STATISTICAL SUMMARY--------\n");
  printf("Number of data points: %d\n", n);
  printf("Minimum value: %d\n", min);
  printf("Maximum value: %d\n", max);
  printf("Mean: %f\n", mean);
  printf("Standard Deviation: %f\n", sd);

  return 0;
}