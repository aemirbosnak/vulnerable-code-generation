//FormAI DATASET v1.0 Category: Unit converter ; Style: surprised
#include <stdio.h>

int main() {
   float value;
   char inputUnit[20];
   char outputUnit[20];
   
   printf("Welcome to the Unit Converter!\n");
   printf("Please enter the value you want to convert: ");
   scanf("%f", &value);

   printf("Please enter the input unit (e.g. in, cm, m): ");
   scanf("%s", inputUnit);

   printf("Please enter the output unit: ");
   scanf("%s", outputUnit);
   
   if(strcmp(inputUnit,outputUnit) == 0){
        printf("These are the same units. No conversion is needed, your input value is %f %s\n", value, inputUnit);
        return 0;
   }

   if(strcmp(inputUnit,"in") == 0 && strcmp(outputUnit,"cm") == 0){
        printf("---WOWZA---\n");
        printf("%.2f in = %.2f cm\n",value,value*2.54);
        printf("---SO SURPRISING!---\n");
   }
   else if(strcmp(inputUnit,"cm") == 0 && strcmp(outputUnit,"in") == 0){
        printf("---WHOA---\n");
        printf("%.2f cm = %.2f in\n",value,value/2.54);
        printf("---MIND BLOWING!---\n");
   }
   else if(strcmp(inputUnit,"m") == 0 && strcmp(outputUnit,"ft") == 0){
        printf("---HOLY COW---\n");
        printf("%.2f m = %.2f ft\n",value,value*3.28);
        printf("---INCREDIBLE!---\n");
   }
   else if(strcmp(inputUnit,"ft") == 0 && strcmp(outputUnit,"m") == 0){
        printf("---INCREDIBLE---\n");
        printf("%.2f ft = %.2f m\n",value,value/3.28);
        printf("---ABSOLUTELY AMAZING!---\n");
   }
   else if(strcmp(inputUnit,"kg") == 0 && strcmp(outputUnit,"lb") == 0){
        printf("---OH MY GOODNESS---\n");
        printf("%.2f kg = %.2f lb\n",value,value*2.20462);
        printf("---THIS IS UNBELIEVABLE!---\n");
   }
   else if(strcmp(inputUnit,"lb") == 0 && strcmp(outputUnit,"kg") == 0){
        printf("---WHAT!---\n");
        printf("%.2f lb = %.2f kg\n",value,value/2.20462);
        printf("---NO WAY!---\n");
   }
   else{
        printf("I'm sorry, I don't know how to convert that!"); 
    }
   return 0;
}