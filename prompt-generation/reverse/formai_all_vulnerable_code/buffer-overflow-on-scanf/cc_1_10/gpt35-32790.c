//FormAI DATASET v1.0 Category: Smart home automation ; Style: thoughtful
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int temperature = 0;
    int humidity = 0;
    int light = 0;
    int motion = 0;
    
    printf("Welcome to SmartHome Automation System\n");
    printf("Enter current temperature: ");
    scanf("%d", &temperature);
    printf("Enter current humidity: ");
    scanf("%d", &humidity);
    printf("Enter current light intensity: ");
    scanf("%d", &light);
    printf("Enter motion detection status (0 for no motion, 1 for motion): ");
    scanf("%d", &motion);
    printf("\n");
    
    if(temperature>30){
        printf("Temperature is too high! Turning on air conditioner.\n");
        // code to turn on air conditioner
        sleep(1);
        printf("Air conditioner turned on!\n");
    }
    
    if(humidity>80){
        printf("Humidity is too high! Turning on dehumidifier.\n");
        // code to turn on dehumidifier
        sleep(1);
        printf("Dehumidifier turned on!\n");
    }
    
    if(light<50){
        printf("Light is too low! Turning on lights.\n");
        // code to turn on lights
        sleep(1);
        printf("Lights turned on!\n");
    }
    
    if(motion==1){
        printf("Motion detected! Turning on security camera.\n");
        // code to turn on security camera
        sleep(1);
        printf("Security camera turned on!\n");
    }
    
    printf("\nSmartHome Automation process finished successfully!\n");
    
    return 0;
}