//FormAI DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>

int main()
{
  int choice, value;

  printf("Greetings, noble user! Welcome to the Medieval Unit Converter.\n");
  
  while(1) {
    printf("\nPlease select the unit conversion type:\n");
    printf("1. Weight (ounces to pounds)\n");
    printf("2. Distance (feet to miles)\n");
    printf("3. Volume (gallons to barrels)\n");
    printf("4. Quit\n");

    scanf("%d", &choice);

    if(choice == 1) {
      printf("Enter the weight in ounces: ");
      scanf("%d", &value);
      
      int pounds = value / 16;
      int ounces = value % 16;
      
      printf("%d ounces convert to %d pounds and %d ounces.\n", value, pounds, ounces);
    }
    else if(choice == 2) {
      printf("Enter the distance in feet: ");
      scanf("%d", &value);
      
      float miles = (float)value / 5280;
      
      printf("%d feet convert to %.2f miles.\n", value, miles);
    }
    else if(choice == 3) {
      printf("Enter the volume in gallons: ");
      scanf("%d", &value);
      
      int barrels = value / 31;
      int gallons = value % 31;
      
      printf("%d gallons convert to %d barrels and %d gallons.\n", value, barrels, gallons);
    }
    else if(choice == 4) {
      printf("Thank you for using Medieval Unit Converter. Goodbye!\n");
      break;
    } else {
      printf("Invalid selection. Please try again.\n");
    }
  }

  return 0;
}