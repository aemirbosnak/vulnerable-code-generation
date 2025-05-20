//FormAI DATASET v1.0 Category: System administration ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
 srand(time(0)); //seeding the random number generator with time value

 int choice;
 printf("\nWelcome to the curious C System Administration program!");
 printf("\nPlease choose an option:\n");
 printf("1. Shutdown System\n");
 printf("2. Restart System\n");
 printf("3. View Processor Information\n");
 printf("4. Clear Screen\n");
 printf("5. Generate Random Password\n");

 scanf("%d",&choice); //get user input for choice

 switch(choice){
  case 1: //shutdown system
   printf("\nAre you sure you want to shutdown the system? (y/n): ");
   char shutdown_choice;
   scanf(" %c",&shutdown_choice); //get user confirmation for shutdown
   if(shutdown_choice=='y' || shutdown_choice=='Y'){
     system("shutdown -P now"); //command to shutdown the system
   }else{
     printf("\nSystem Shutdown Aborted!\n");
   }
   break;
  case 2: //restart system
   printf("\nAre you sure you want to restart the system? (y/n): ");
   char restart_choice;
   scanf(" %c",&restart_choice); //get user confirmation for restart
   if(restart_choice=='y' || restart_choice=='Y'){
     system("shutdown -r now"); //command to restart the system
   }else{
     printf("\nSystem Restart Aborted!\n");
   }
   break;
  case 3: //view processor information
   printf("\nProcessor Information:\n");
   system("lscpu"); //command to print processor information
   break;
  case 4: //clear screen
   system("clear"); //command to clear screen
   printf("\nScreen Cleared!\n");
   break;
  case 5: //generate random password
   printf("\nRandom Password Generated: ");
   for(int i=0;i<8;i++){ //loop to generate 8 random characters for password
    int random_num = rand()%76;
    if(random_num<48){
     random_num+=48;
    }else if(random_num<65){
     random_num+=7;
    }else if(random_num<97){
     random_num+=6;
    }else{
     random_num+=13;
    }
    printf("%c",(char)random_num);
   }
   printf("\n");
   break;
  default:
   printf("\nInvalid Choice!\n");
 }

 printf("\nThank you for using the curious C System Administration program!\n");
 return 0;
}