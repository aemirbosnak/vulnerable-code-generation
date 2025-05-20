//FormAI DATASET v1.0 Category: Smart home automation ; Style: systematic
#include <stdio.h>
#include <stdbool.h>

//Function to turn on/off appliances
void turnOnOff(char* appliance, bool state) {
  if(state){
    printf("%s turned ON.\n", appliance);
  }else{
    printf("%s turned OFF.\n", appliance);
  }
}

int main() {
  //Variables for appliances
  bool livingRoomLight = false;
  bool bedRoomLight = false;
  bool ac = false;
  
  printf("Welcome to the Smart Home Automation System!\n");
  
  while(true){
    printf("\nPlease select an option:\n");
    printf("1. Turn Living Room Light ON/OFF.\n");
    printf("2. Turn Bed Room Light ON/OFF.\n");
    printf("3. Turn AC ON/OFF.\n");
    printf("4. Exit Smart Home Automation System.\n");
    
    int option;
    scanf("%d", &option);
    
    //Turn living room light on/off
    if(option == 1){
      if(livingRoomLight){
        turnOnOff("Living Room Light", false);
        livingRoomLight = false;
      }else{
        turnOnOff("Living Room Light", true);
        livingRoomLight = true;
      }
    }
    
    //Turn bedroom light on/off
    else if(option == 2){
      if(bedRoomLight){
        turnOnOff("Bed Room Light", false);
        bedRoomLight = false;
      }else{
        turnOnOff("Bed Room Light", true);
        bedRoomLight = true;
      }
    }
    
    //Turn AC on/off
    else if(option == 3){
      if(ac){
        turnOnOff("AC", false);
        ac = false;
      }else{
        turnOnOff("AC", true);
        ac = true;
      }
    }
    
    //Exit program
    else if(option == 4){
      printf("Exiting Smart Home Automation System...\n");
      break;
    }
    
    else{
      printf("Invalid option. Please try again.\n");
    }
  }

  return 0;
}