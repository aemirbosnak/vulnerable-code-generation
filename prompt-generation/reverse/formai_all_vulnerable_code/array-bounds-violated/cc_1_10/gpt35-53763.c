//FormAI DATASET v1.0 Category: Data mining ; Style: surprised
#include<stdio.h>
#include<math.h>

int main() {
   int noOfRows, noOfCols;
   
   //Get the size of the data set
   printf("Enter the number of rows: ");
   scanf("%d", &noOfRows);
   printf("Enter the number of columns: ");
   scanf("%d", &noOfCols);
   
   //Initialize the 2D array
   float data[noOfRows][noOfCols];
   
   printf("Enter the data:\n");
   for(int i=0; i<noOfRows; i++) {
      for(int j=0; j<noOfCols; j++) {
         scanf("%f", &data[i][j]);
      }
   }
   
   //Calculate the mean temperature
   float sum = 0.0, mean;
   for(int i=0; i<noOfRows; i++) {
      sum += data[i][1];
   }
   mean = sum / noOfRows;
   printf("The mean temperature is: %.2f\n", mean);
   
   //Determine the coldest day
   float coldest = data[0][1];
   int coldIndex;
   for(int i=0; i<noOfRows; i++) {
      if(data[i][1] < coldest) {
         coldest = data[i][1];
         coldIndex = i;
      }
   }
   printf("The coldest day was on %f, with a temperature of %.2f\n", data[coldIndex][0], coldest);
   
   //Find the trend in the temperature over time
   float trend;
   int period = noOfRows / 4;
   float x[period], y[period];
   for(int i=0; i<period; i++) {
      x[i] = data[i][0];
      y[i] = data[i][1];
   }
   float xySum = 0.0, xSum = 0.0, ySum = 0.0, xSquaredSum = 0.0;
   for(int i=0; i<period; i++) {
      xySum += x[i] * y[i];
      xSum += x[i];
      ySum += y[i];
      xSquaredSum += pow(x[i], 2);
   }
   trend = (period * xySum - xSum * ySum) / (period * xSquaredSum - pow(xSum, 2));
   printf("The temperature trend over the first quarter of the time period is %.2f\n", trend);
 
   return 0;
}