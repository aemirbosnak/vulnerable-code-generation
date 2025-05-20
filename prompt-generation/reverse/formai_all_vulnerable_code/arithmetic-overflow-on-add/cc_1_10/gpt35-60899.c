//FormAI DATASET v1.0 Category: Temperature monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds){
     int milli_seconds=1000*seconds;
     clock_t start_time=clock();
     while(clock()<start_time+milli_seconds);
}

int main(){

   int temp[5], sum, avg, max=0, min=100, i, j;
   
   srand(time(NULL));

   printf("Initializing temperature monitor. Please wait...\n");
   delay(3);
   
   printf("\nTemperature values for the last 5 seconds:\n");

   for(i=0; i<5; i++){
      temp[i]=rand()%32 + 25;
      printf("Second %d: %d°C\n", i+1, temp[i]);
      delay(1);
   }

   for(j=0; j<10; j++){
       sum=0;
       max=0;
       min=100;
       printf("\n\nReading temperature values for second %d:\n", j+6);
       delay(1);

      for(i=0; i<5; i++){
        temp[i]=rand()%32 + 25;
        printf(" Sensor %d: %d°C\n", i+1, temp[i]);
        sum+=temp[i];
        if(temp[i]>max) max=temp[i];
        if(temp[i]<min) min=temp[i];
        delay(1);
      }

      avg=sum/5;
      printf("\n\nReport for second %d:\n\n", j+6);
      printf("Maximum temperature: %d°C\n", max);
      printf("Minimum temperature: %d°C\n", min);
      printf("Average temperature: %d°C\n", avg);
    
   }
   printf("\n\nTemperature monitor ended successfully!\n");
   return 0;
}