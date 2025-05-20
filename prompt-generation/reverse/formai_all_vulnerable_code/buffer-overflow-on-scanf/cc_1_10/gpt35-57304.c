//FormAI DATASET v1.0 Category: Password management ; Style: excited
#include<stdio.h>
#include<string.h>

/*Let's create an extremely exciting Password Manager!
This program will allow you to store and retrieve all your passwords, securely encrypted and safe from prying eyes!*/

/*Step 1: Define the maximum length of the passwords that our program will support*/
#define MAX_PASSWORD_LENGTH 256

/*Step 2: Define a function to encrypt the passwords*/
void encryptPassword(char* password){
    /*Shhh! This is where all the magic happens.
      We are using a simple bitwise XOR operation to encrypt the passwords.*/
    char key = 'K'; //Our secret key, just for fun!
    for(int i=0; password[i]!='\0'; i++){
        password[i] = password[i] ^ key;
    }
}

/*Step 3: Define a function to decrypt the passwords*/
void decryptPassword(char* password){
    /*It's time to reveal the secrets!
      We just need to call the same function again with the encrypted password.*/
    encryptPassword(password);
}

/*Step 4: Define the main function*/
int main(){
    int choice;
    char password[MAX_PASSWORD_LENGTH], encryptedPassword[MAX_PASSWORD_LENGTH];
    FILE *fp;
    
    /*Let's display a nice Welcome Message to our users!*/
    printf("\n***** Welcome to our Exciting Password Manager! *****\n\n");
    
    /*Let's ask the user what they want to do*/
    printf("Please choose from the following options:\n");
    printf("1. Store a new password.\n");
    printf("2. Retrieve a password.\n");
    printf("3. Exit.\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            /*Let's ask the user to enter the new password*/
            printf("\nEnter the new password: ");
            scanf("%s", password);
            /*Let's encrypt the password*/
            encryptPassword(password);
            /*Let's open a file to store the password*/
            fp = fopen("passwords.txt", "a");
            fprintf(fp, "%s\n", password); //Write the encrypted password to the file
            fclose(fp); //Close the file
            printf("\nPassword stored successfully!\n");
            break;
        
        case 2:
            /*Let's ask the user which password they want to retrieve*/
            printf("\nEnter the password index (starting from 1): ");
            int index;
            scanf("%d", &index);
            /*Let's open the file to retrieve the password*/
            fp = fopen("passwords.txt", "r");
            int count=0;
            while(fgets(encryptedPassword, MAX_PASSWORD_LENGTH, fp)!=NULL){
                count++;
                if(count==index){
                    /*Let's decrypt the password*/
                    decryptPassword(encryptedPassword);
                    printf("\nThe password is: %s\n", encryptedPassword);
                    fclose(fp); //Close the file
                    return 0;
                }
            }
            printf("\nPassword not found!\n");
            fclose(fp); //Close the file
            break;
        
        case 3:
            printf("\nThank you for using our Exciting Password Manager!\n");
            return 0;
        
        default:
            printf("\nInvalid choice!\n");
            break;
    }
    
    /*Let's have some more fun!*/
    printf("\n\n*********************************************************\n");
    printf("***          Now go and secure your passwords!         ***\n");
    printf("***   Remember, with great power comes great security! ***\n");
    printf("*********************************************************\n");
    return 0;
}