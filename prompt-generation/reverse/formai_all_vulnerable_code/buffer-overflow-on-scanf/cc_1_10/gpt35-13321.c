//FormAI DATASET v1.0 Category: Color Code Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

void clear(){
  system("clear");
}

void printTitle(){
  clear();
  printf("\n");
  printf(" ________     ___      __    __    __ __    _______   \n");
  printf("|        |   |   |    |  |  |  |  |  |  |  |       |  \n");
  printf("|___    |   |   |    |  |__|  |  |  |  |  |____   |  \n");
  printf(" ___|   |   |   |    |   __   |  |  |  |   ____|  |  \n");
  printf("|       |   |   |__  |  |  |  |  |  |  |  |_______|  \n");
  printf("|_______|   |______| |__|  |__|  |__|  |__________|  \n");
  printf("\n\n");
}

void printMenu(){
  printf("What do you want to do?\n");
  printf("[1] Convert RGB to Hex\n");
  printf("[2] Convert Hex to RGB\n");
  printf("[3] Exit\n");
}

int main(){
  int choice;
  do{
    printTitle();
    printMenu();
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1:{
        clear();
        printf("Enter the RGB values:\n");
        int r, g, b;

        printf("R: ");
        scanf("%d", &r);

        printf("G: ");
        scanf("%d", &g);

        printf("B: ");
        scanf("%d", &b);

        if(r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255){
          printf("\nInvalid RGB values! Please try again.\n");
          printf("\n\nPress Enter to Continue");
          scanf("%*c");
          scanf("%*c");
        } else{
          int hexCode = (r << 16) | (g << 8) | b;
          printf("\nHex Code: #%06X", hexCode);
          printf("\n\nPress Enter to Continue");
          scanf("%*c");
          scanf("%*c");
        }
        break;
      }
      case 2:{
        clear();
        char hex[7];

        printf("Enter the hex color code: ");
        fflush(stdin);
        scanf("%6[^\n]", hex);

        int r, g, b;
        if(sscanf(hex, "%2x%2x%2x", &r, &g, &b)!=3){
          printf("\nInvalid Hex code! Please try again.\n");
          printf("\n\nPress Enter to Continue");
          scanf("%*c");
          scanf("%*c");
        } else{
          printf("\nRGB Values: %d, %d, %d", r, g, b);
          printf("\n\nPress Enter to Continue");
          scanf("%*c");
          scanf("%*c");
        }
        break;
      }
      case 3:{
        clear();
        printf("Goodbye!\n");
        break;
      }
      default:{
        printf("\nInvalid Choice! Please try again.\n");
        printf("\n\nPress Enter to Continue");
        scanf("%*c");
        scanf("%*c");
        break;
      }
    }
  } while(choice != 3);

  return 0;
}