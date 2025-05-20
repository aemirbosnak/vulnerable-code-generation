//FormAI DATASET v1.0 Category: String manipulation ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main()
{
   char message[100] = "W3LC0M3 T0 TH3 N3ON JUNGLE!";
   int choice, length, i;
   
   printf("Enter an option:\n1. Convert to lowercase\n2. Convert to uppercase\n3. Encode message\n4. Decode message\n");
   scanf("%d", &choice);
   
   switch(choice){
       case 1:
           // convert to lowercase
           length = strlen(message);
           for(i=0;i<length;i++){
               if(message[i]>='A' && message[i]<='Z'){
                   message[i] += 32; // add 32 to convert to lowercase
               }
           }
           printf("Lowercase message: %s\n", message);
           break;
           
       case 2:
           // convert to uppercase
           length = strlen(message);
           for(i=0;i<length;i++){
               if(message[i]>='a' && message[i]<='z'){
                   message[i] -= 32; // subtract 32 to convert to uppercase
               }
           }
           printf("Uppercase message: %s\n", message);
           break;
       
       case 3:
           // encode message
           length = strlen(message);
           for(i=0;i<length;i++){
               message[i] += 3; // add 3 to each character's ASCII value
           }
           printf("Encoded message: %s\n", message);
           break;
           
       case 4:
           // decode message
           length = strlen(message);
           for(i=0;i<length;i++){
               message[i] -= 3; // subtract 3 from each character's ASCII value
           }
           printf("Decoded message: %s\n", message);
           break;
           
       default:
           printf("Invalid option!\n");
           break;
   }
   
   return 0;
}