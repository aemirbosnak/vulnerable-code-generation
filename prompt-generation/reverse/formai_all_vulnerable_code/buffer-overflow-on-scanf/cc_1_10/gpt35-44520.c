//FormAI DATASET v1.0 Category: File Encyptor ; Style: creative
#include<stdio.h>
#include<string.h>

int main(){
    char password[50]; // initialize password 
    printf("Enter your password: "); // prints message to user
    scanf("%s", password); // takes user input as password
    int passLength = strlen(password); //calculates length of password
    
    //Converting password into numerical form
    int numPass[passLength]; //create an integer array that will store the numerical value of each character in password
    for(int i=0; i<passLength; i++){
        numPass[i] = password[i];
    }

    //Encrypting the numerical password
    for(int i=0; i<passLength; i++){
        numPass[i] = numPass[i] + 10; //adds 10 to each numerical value
    }

    //Writing the Encrypted password to the file
    FILE *filePointer; //initialize filePointer 
    filePointer = fopen("password.txt", "w"); //opening file to write
    fprintf(filePointer, "Encrypted Password: "); //writing message to file
    for(int i=0; i<passLength; i++){
        fprintf(filePointer, "%d", numPass[i]); //writing encrypted version of password to file
    }
    fclose(filePointer); //closing the file
    
    //Reading encrypted password from the file
    char filePassword[50]; //initialize filePassword
    int fileNumPassword[passLength]; //initialize fileNumPassword
    filePointer = fopen("password.txt", "r"); //opening file to read
    fgets(filePassword, 50, filePointer); //reading message from file
    fclose(filePointer); //closing the file
    
    //Converting Encrypted password back to numerical form
    for(int i=20,j=0; i<strlen(filePassword); i+=2,j++){
        fileNumPassword[j] = filePassword[i] - '0'; //changing char to int
    }

    //Decrypting the numerical password
    for(int i=0; i<passLength; i++){
        fileNumPassword[i] = fileNumPassword[i] - 10; //subtracts 10 from each numerical value
    }

    //Converting password back to char form 
    char newPass[50]; //initailize newPass
    for(int i=0; i<passLength; i++){
        newPass[i] = fileNumPassword[i];
    }
    newPass[passLength] = '\0'; //add null character to the end of the string

    printf("Your decrypted password is: %s", newPass); //prints message with decrypted password
    return 0; //end of program
}