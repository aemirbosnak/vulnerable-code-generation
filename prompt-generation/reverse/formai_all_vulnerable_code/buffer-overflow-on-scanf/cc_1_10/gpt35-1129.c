//FormAI DATASET v1.0 Category: Smart home automation ; Style: statistical
#include<stdio.h>

int main()
{
   int time;
   float temp_sensor1, temp_sensor2, temp_sensor3, avg_temp, humidity_sensor1, humidity_sensor2, avg_humidity;

   printf("Enter the current time (in 24 hour format): ");
   scanf("%d", &time);
   
   //if statement to check if lights should be turned on
   if(time > 18 || time < 6){
      printf("Turning on lights\n");
      //code to turn on lights
   }

   //code to read temperature sensor values
   printf("Enter temperature value from sensor 1: ");
   scanf("%f", &temp_sensor1);
   printf("Enter temperature value from sensor 2: ");
   scanf("%f", &temp_sensor2);
   printf("Enter temperature value from sensor 3: ");
   scanf("%f", &temp_sensor3);

   //calculating average temperature
   avg_temp = (temp_sensor1 + temp_sensor2 + temp_sensor3) / 3;

   //if statement to check if AC should be turned on
   if(avg_temp > 26){
      printf("Turning on AC\n");
      //code to turn on AC
   }
   
   //code to read humidity sensor values
   printf("Enter humidity value from sensor 1: ");
   scanf("%f", &humidity_sensor1);
   printf("Enter humidity value from sensor 2: ");
   scanf("%f", &humidity_sensor2);

   //calculating average humidity
   avg_humidity = (humidity_sensor1 + humidity_sensor2) / 2;

   //if statement to check if dehumidifier should be turned on
   if(avg_humidity > 70){
      printf("Turning on dehumidifier\n");
      //code to turn on dehumidifier
   }

   return 0;
}