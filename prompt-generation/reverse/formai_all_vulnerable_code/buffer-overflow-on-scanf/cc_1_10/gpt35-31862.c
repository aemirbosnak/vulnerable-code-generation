//FormAI DATASET v1.0 Category: Digital Diary ; Style: Dennis Ritchie
#include<stdio.h> // Standard Input Output Header File
#include<stdlib.h> //Standard Library Header File
#include<string.h> //String Manipulation Header File

int main(){

    FILE *fptr; //Declare a file pointer
    char filename[50],content[200];
    int choice,validation=0;
    char password[50];

    printf("Welcome to your Digital Diary\n");

    printf("Do you have a password for your diary?\n");
    printf("1. Yes\n");
    printf("2. No\n");

    scanf("%d",&choice);

    switch(choice){
        case 1: printf("Please enter your password:\n");
                scanf("%s",&password);
                validation = 1;
                break;
        case 2: printf("You did not choose to set a password.\n");
                break;
        default: printf("Invalid choice entered.Exit Program.\n");
                 exit(0);
    }

    printf("Please enter the name of the file you want to access:\n");
    scanf("%s",&filename);

    //Add .txt file extension
    strcat(filename,".txt");

    //Open file in write mode
    fptr=fopen(filename,"w");

    if(fptr==NULL){
        printf("File does not exist or could not be opened.");
    }
    else{
        printf("File created successfully.\n");  
        printf("Please enter your diary content:\n");

        //Read input from user and write it to file
        while(strcmp(content,"exit")!=0){
            fgets(content,200,stdin); //Read input from user

            if(validation){
                printf("Enter your password to continue:");
                scanf("%s",password);

                if(strcmp(password,"admin")==0){ //If password is correct
                    fprintf(fptr,"%s",content); //Write content to file
                }
                else{
                    printf("Password incorrect. Retry writing the content.\n");
                }
            }
            else{
                fprintf(fptr,"%s",content); //Write content to file
            }

        }
    }

    //Close the file
    fclose(fptr);

    return 0;
}