//FormAI DATASET v1.0 Category: Weather simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

int main(){
   //initialize variables
   float temperature, humidity, windSpeed, airPressure;
   
   //get weather data from user input
   printf("Enter current temperature in Celsius: ");
   scanf("%f", &temperature);
   printf("Enter current Humidity: ");
   scanf("%f", &humidity);
   printf("Enter current windspeed in km/h: ");
   scanf("%f", &windSpeed);
   printf("Enter current air pressure in kPa: ");
   scanf("%f", &airPressure);
   
   //output weather summary
   printf("\nCurrent Weather Conditions:\n");
   printf("Temperature: %.2f°C\n", temperature);
   printf("Humidity: %.2f%%\n", humidity);
   printf("Wind Speed: %.2f km/h\n", windSpeed);
   printf("Air Pressure: %.2f kPa\n", airPressure);

   //calculate and output temperature comfort level
   if(temperature < 5){
      printf("Temperature is chilly\n");
   } else if(temperature >= 5 && temperature < 15){
      printf("Temperature is cool\n");
   } else if(temperature >= 15 && temperature < 25){
      printf("Temperature is moderate\n");
   } else if(temperature >= 25 && temperature < 35){
      printf("Temperature is warm\n");
   } else {
      printf("Temperature is hot\n");
   }

   //calculate and output humidity comfort level
   if(humidity < 30){
      printf("Humidity is dry\n");
   } else if(humidity >= 30 && humidity < 60){
      printf("Humidity is comfortable\n");
   } else {
      printf("Humidity is moist\n");
   }

   //calculate and output wind comfort level
   if(windSpeed < 5){
      printf("Wind is calm\n");
   } else if(windSpeed >= 5 && windSpeed < 15){
      printf("Wind is moderate\n");
   } else {
      printf("Wind is strong\n");
   }

   //calculate and output air pressure comfort level
   if(airPressure < 100){
      printf("Low air pressure\n");
   } else if(airPressure >= 100 && airPressure < 101){
      printf("Normal air pressure\n");
   } else {
      printf("High air pressure\n");
   }
   
   return 0; //exit program
}