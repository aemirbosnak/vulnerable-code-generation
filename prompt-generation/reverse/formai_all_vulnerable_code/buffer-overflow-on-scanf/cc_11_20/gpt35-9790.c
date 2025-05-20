//FormAI DATASET v1.0 Category: Data validation ; Style: curious
#include <stdio.h>

int main(){
   int age; //User input
   int valid = 0; //Assuming data is invalid initially
   char gender; //User input
   float height; //User input
   char name[20]; //User input

   while(valid==0){ //Loop keeps running until data is valid
   
       printf("Enter name: ");
       scanf("%s", name);
       if(name[0] >= 'A' && name[0] <= 'Z'){ //Checks if first letter of name is capital
           valid = 1;
       } else {
           printf("Name should start with a capital letter.\n");
           valid = 0;
           continue; //Goes back to start of loop
       }
       
       printf("Enter age: ");
       if(scanf("%d", &age) == 0){ //If user inputs non-integer data
           printf("Age should be a number.\n"); 
           valid = 0;
           continue;  
       } else if(age < 0 || age > 120){ //If age is not in valid range
           printf("Age should be between 0 and 120.\n"); 
           valid = 0;
           continue;  
       } else {
           valid = 1;
       }
       
       printf("Enter gender (M/F): ");
       scanf(" %c", &gender);
       if(gender == 'M' || gender == 'F'){ //Checks if gender is M or F
           valid = 1;
       } else {
           printf("Gender should be either M or F.\n"); 
           valid = 0;
           continue; 
       }
       
       printf("Enter height (in meters): ");
       if(scanf("%f", &height) == 0){ //If user inputs non-float data
           printf("Height should be a number.\n"); 
           valid = 0;
           continue;  
       } else if(height < 0.5 || height > 2.5){ //If height is not in valid range
           printf("Height should be between 0.5 and 2.5 meters.\n"); 
           valid = 0;
           continue;  
       } else {
           valid = 1;
       }
   }
   
   printf("Name: %s\n", name);
   printf("Age: %d\n", age);
   printf("Gender: %c\n", gender);
   printf("Height: %.2f\n", height);

   return 0;
}