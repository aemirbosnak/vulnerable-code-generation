//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: happy
#include<stdio.h>

int main(){

//Welcome Message
printf("Hello and welcome to our happy Intrusion Detection System!\n");

//User Inputs
char password[20];
printf("Please enter your desired password for your IDS:\n");
scanf("%s", password);
int threshold;
printf("Please enter the threshold for the number of failed login attempts:\n");
scanf("%d", &threshold);

//Initializing Variables
int loginAttempts = 0;
int loggedIn = 0;

//Infinite While Loop
while(1){

//User Inputs  
char user[20];
printf("Please enter your username:\n");
scanf("%s", user);
char pass[20];
printf("Please enter your password:\n");
scanf("%s", pass);

//Checking Credentials
if(strcmp(user,"admin")==0 && strcmp(pass,password)==0){
    printf("Login Successful! Welcome admin!\n");
    loggedIn = 1;
    loginAttempts = 0;
}
else{
    printf("Invalid username or password. Please try again.\n");
    loginAttempts++;
}

//Checking Threshold
if(loginAttempts >= threshold){
    printf("Warning! There have been multiple failed login attempts.\n");
    printf("Please contact your administrator for assistance.\n");
    break;
}

//Successful Login Condition
if(loggedIn == 1){
    printf("You have successfully logged in!\n");
    //Some Happy Functionality
    printf("We have detected that you are happy! Here is a happy message for you:\n");
    printf("Happiness is a warm puppy! - Charles M Schulz\n");
    break;
}
}

return 0;
}