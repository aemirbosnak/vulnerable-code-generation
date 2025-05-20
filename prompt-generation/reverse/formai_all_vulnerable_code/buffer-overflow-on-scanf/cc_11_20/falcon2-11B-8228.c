//Falcon2-11B DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>

int main()
{
   int base_unit, convert_to_unit;
   
   printf("Enter the base unit: ");
   scanf("%d", &base_unit);
   
   printf("Enter the unit to convert to: ");
   scanf("%d", &convert_to_unit);
   
   switch(base_unit)
   {
      case 1:
         if(convert_to_unit == 1)
            printf("%.2f\n", 1);
         else if(convert_to_unit == 2)
            printf("%.2f\n", 1.60934);
         else if(convert_to_unit == 3)
            printf("%.2f\n", 3.28084);
         else
            printf("Invalid unit\n");
         break;
      case 2:
         if(convert_to_unit == 1)
            printf("%.2f\n", 1.60934);
         else if(convert_to_unit == 2)
            printf("%.2f\n", 1.60934);
         else if(convert_to_unit == 3)
            printf("%.2f\n", 1.60934);
         else
            printf("Invalid unit\n");
         break;
      case 3:
         if(convert_to_unit == 1)
            printf("%.2f\n", 3.28084);
         else if(convert_to_unit == 2)
            printf("%.2f\n", 3.28084);
         else if(convert_to_unit == 3)
            printf("%.2f\n", 3.28084);
         else
            printf("Invalid unit\n");
         break;
      default:
         printf("Invalid unit\n");
         break;
   }
   
   return 0;
}