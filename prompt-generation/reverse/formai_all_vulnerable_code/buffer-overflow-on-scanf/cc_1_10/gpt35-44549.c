//FormAI DATASET v1.0 Category: Smart home automation ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
  int temp, hum, motion;
  printf("Welcome to the Smart Home Automation App!\n");
  
  while(1){
    printf("Enter the current temperature (in Celsius): ");
    scanf("%d", &temp);
      
    printf("Enter the current humidity (in percentage): ");
    scanf("%d", &hum);
      
    printf("Is there any motion detected inside the room? (1 for Yes / 0 for No): ");
    scanf("%d", &motion);
      
    if(temp>25){
        printf("\nTemperature is high! Turning on the AC.\n");
        system("curl \"http://192.168.0.123/control?cmd=GPIO,12,1\"");
    }
    else{
        printf("\nTemperature is normal. AC remains off.\n");
        system("curl \"http://192.168.0.123/control?cmd=GPIO,12,0\"");
    }
      
    if(hum>50){
        printf("Humidity is high! Turning on the dehumidifier.\n");
        system("curl \"http://192.168.0.123/control?cmd=GPIO,15,1\"");
    }
    else{
        printf("Humidity is normal. Dehumidifier remains off.\n");
        system("curl \"http://192.168.0.123/control?cmd=GPIO,15,0\"");
    }
      
    if(motion==1){
        printf("Motion detected! Turning on the lights.\n");
        system("curl \"http://192.168.0.123/control?cmd=GPIO,2,1\"");
        sleep(5);
        printf("Lights turned off.\n");
        system("curl \"http://192.168.0.123/control?cmd=GPIO,2,0\"");
    }
    else{
        printf("No motion detected. Lights remain off.\n");
        system("curl \"http://192.168.0.123/control?cmd=GPIO,2,0\"");
    }
      
    printf("\nPress any key to continue...\n");
    getchar();
    system("clear");
  }

  return 0;
}