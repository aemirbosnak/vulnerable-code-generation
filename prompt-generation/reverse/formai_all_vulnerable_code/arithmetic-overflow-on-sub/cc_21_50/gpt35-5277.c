//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: futuristic
#include<stdio.h>

int main(){
   int x=0,y=0,i,j,k;
   char direction;
   printf("Welcome to the Futuristic GPS Navigation System!");
   printf("\nPlease input your current coordinates (x,y): ");
   scanf("%d,%d",&x,&y);
   printf("\nPlease input the direction you are facing (N,E,S,W): ");
   scanf(" %c",&direction);
   printf("\nThe GPS navigation system is ready. You can start giving the commands now.");
   printf("\nInput 'F' for forward, 'R' for right, and 'L' for left.\n");
   char command;
   for(k=0;k<5;k++){ //5 commands limit to prevent overflow
       printf("\nEnter command %d: ",k+1);
       scanf(" %c",&command);
       if(command=='F'){
           if(direction=='N'){
               y++;
           }
           else if(direction=='E'){
               x++;
           }
           else if(direction=='S'){
               y--;
           }
           else if(direction=='W'){
               x--;
           }
       }
       else if(command=='R'){
           if(direction=='N'){
               direction='E';
           }
           else if(direction=='E'){
               direction='S';
           }
           else if(direction=='S'){
               direction='W';
           }
           else if(direction=='W'){
               direction='N';
           }
       }
       else if(command=='L'){
           if(direction=='N'){
               direction='W';
           }
           else if(direction=='E'){
               direction='N';
           }
           else if(direction=='S'){
               direction='E';
           }
           else if(direction=='W'){
               direction='S';
           }
       }
       else{
           printf("\nInvalid command. Please input 'F', 'R', or 'L'.");
           k--;
           continue;
       }
       printf("\nDistance from origin: %d",abs(x)+abs(y)); //distance from origin
       if(x>=0 && y>=0){
           for(i=1;i<=y;i++){
               for(j=1;j<=x;j++){
                   printf("-");
               }
               printf("|\n");
           }
       }
       else if(x>=0 && y<0){
           for(i=1;i<=x;i++){
               printf("-");
           }
           printf("|\n");
           for(i=1;i<=abs(y);i++){
               for(j=1;j<x+1;j++){
                   printf("-");
               }
               printf("|\n");
           }
       }
       else if(x<0 && y>=0){
           for(i=1;i<=y;i++){
               for(j=1;j<=abs(x);j++){
                   printf("-");
               }
               printf("|\n");
           }
           for(i=1;i<=y+1;i++){
               printf("|");
               for(j=1;j<=abs(x);j++){
                   printf(" ");
               }
               printf("|\n");
           }
       }
       else{
           for(i=1;i<=abs(y);i++){
               for(j=1;j<=abs(x);j++){
                   printf("-");
               }
               printf("|\n");
           }
           for(i=1;i<=abs(y);i++){
               printf("|");
               for(j=1;j<=abs(x);j++){
                   printf(" ");
               }
               printf("|\n");
           }
       }
   }
   printf("\nYou have reached the command limit. The GPS navigation system has been terminated.");
   return 0;
}