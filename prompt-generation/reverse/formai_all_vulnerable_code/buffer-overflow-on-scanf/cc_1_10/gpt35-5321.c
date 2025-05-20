//FormAI DATASET v1.0 Category: Smart home light control ; Style: standalone
#include <stdio.h>

int main(){
  
  int numLights;
  int option;
  int lightIndex;
  int brightnessLevel;
  
  printf("How many lights do you want to control? ");
  scanf("%d", &numLights);
  
  // initialize light array to all turn off (0 brightness)
  int lightArray[numLights];
  for(int i=0; i<numLights; i++){
    lightArray[i] = 0;
  }
  
  while(1){
    printf("Which light do you want to control? (Enter -1 to exit) ");
    scanf("%d", &lightIndex);
    
    if(lightIndex == -1){
      break;
    }
    
    printf("Options:\n1. Turn On\n2. Turn Off\n3. Set Brightness\n");
    scanf("%d", &option);
    
    switch(option){
      
      case 1:
        lightArray[lightIndex] = 100;
        printf("Light %d turned on.\n", lightIndex);
        break;
        
      case 2:
        lightArray[lightIndex] = 0;
        printf("Light %d turned off.\n", lightIndex);
        break;
        
      case 3:
        printf("Enter brightness level (0-100): ");
        scanf("%d", &brightnessLevel);
        lightArray[lightIndex] = brightnessLevel;
        printf("Light %d brightness set to %d.\n", lightIndex, brightnessLevel);
        break;
        
      default:
        printf("Invalid option.\n");
        break;
    }
  }
  
  printf("Final light status:\n");
  for(int i=0; i<numLights; i++){
    printf("Light %d brightness: %d\n", i, lightArray[i]);
  }
  
  return 0;
}