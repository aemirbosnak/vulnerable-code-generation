//FormAI DATASET v1.0 Category: Unit converter ; Style: artistic
#include<stdio.h>

int main(){

  printf("----------------------------------------\n");
  printf("|                                      |\n");
  printf("|      The Artistic Unit Converter     |\n");
  printf("|                                      |\n");
  printf("----------------------------------------\n\n");
  
  printf("Hello there! Welcome to our Artistic Unit Converter.\n");
  
  while(1){
    int choice;
    printf("\nWhat do you want to do?\n");
    printf("[1] Convert Length\n");
    printf("[2] Convert Mass\n");
    printf("[3] Convert Temperature\n");
    printf("[4] Exit\n\n");
    
    printf("Enter your Choice: ");
    scanf("%d", &choice);
    
    if(choice==1){
      float length;
      printf("\nEnter the Length: ");
      scanf("%f", &length);
      printf("\nWhat do you want to convert it into?\n");
      printf("[1] Feet to Inches\n");
      printf("[2] Inches to Feet\n");
      int ch1;
      printf("\nEnter Your Choice: ");
      scanf("%d", &ch1);
      
      if(ch1==1){
        float inches = length * 12;
        printf("\n%f feet is equal to %f inches.\n", length, inches);
      }else if(ch1==2){
        float feet = length / 12;
        printf("\n%f inches is equal to %f feet.\n", length, feet);
      }else{
        printf("\nInvalid Choice!\n");
      }
      
    }else if(choice==2){
      float mass;
      printf("\nEnter the Mass: ");
      scanf("%f", &mass);
      printf("\nWhat do you want to convert it into?\n");
      printf("[1] Kilograms to Pounds\n");
      printf("[2] Pounds to Kilograms\n");
      int ch2;
      printf("\nEnter Your Choice: ");
      scanf("%d", &ch2);
      
      if(ch2==1){
        float pounds = mass * 2.20462;
        printf("\n%f kilograms is equal to %f pounds.\n", mass, pounds);
      }else if(ch2==2){
        float kilograms = mass / 2.20462;
        printf("\n%f pounds is equal to %f kilograms.\n", mass, kilograms);
      }else{
        printf("\nInvalid Choice!\n");
      }
      
    }else if(choice==3){
      float temp;
      printf("\nEnter the Temperature: ");
      scanf("%f", &temp);
      printf("\nWhat do you want to convert it into?\n");
      printf("[1] Celsius to Fahrenheit\n");
      printf("[2] Fahrenheit to Celsius\n");
      int ch3;
      printf("\nEnter Your Choice: ");
      scanf("%d", &ch3);
      
      if(ch3==1){
        float fahrenheit = (temp * 9/5) + 32;
        printf("\n%f degrees Celsius is equal to %f degrees Fahrenheit.\n", temp, fahrenheit);
      }else if(ch3==2){
        float celsius = (temp - 32) * 5/9;
        printf("\n%f degrees Fahrenheit is equal to %f degrees Celsius.\n", temp, celsius);
      }else{
        printf("\nInvalid Choice!\n");
      }
      
    }else if(choice==4){
      printf("\nThank you for using our Artistic Unit Converter! Have a great day!\n");
      break;
    }else{
      printf("\nInvalid Choice! Please try again.\n");
    }
  }
  
  return 0;
}