//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int menu(); //function to display menu
void generatePassword(int, int, int, int); //function to generate password
void addUser(char[], char[]); //function to add user
void deleteUser(char[]); //function to delete user
void viewUsers(); //function to view all users

int main(){
    srand(time(NULL)); //seed rand() function with time
    int choice, length, lower, upper, digits; //variables to to store user inputs
    char username[20], password[20]; //arrays to store username and password
    
    printf("\nWelcome to the Secure Password Generator!\n");
    
    do{
        choice = menu(); //call menu function to display options
        
        switch(choice){
            case 1:
                printf("\nEnter the username: ");
                scanf("%s", username);
                printf("Enter the password: ");
                scanf("%s", password);
                addUser(username, password); //call addUser function to add user
                break;
                
            case 2:
                printf("\nEnter the username: ");
                scanf("%s", username);
                deleteUser(username); //call deleteUser function to delete user
                break;
                
            case 3:
                viewUsers(); //call viewUsers function to view all users
                break;
                
            case 4:
                printf("\nEnter the length of the password (minimum 8): ");
                scanf("%d", &length);
                printf("Include lowercase letters? (1 for yes, 0 for no): ");
                scanf("%d", &lower);
                printf("Include uppercase letters? (1 for yes, 0 for no): ");
                scanf("%d", &upper);
                printf("Include digits? (1 for yes, 0 for no): ");
                scanf("%d", &digits);
                generatePassword(length, lower, upper, digits); //call generatePassword function to generate password
                break;
                
            case 5:
                printf("\nGoodbye!\n");
                break;
                
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5); //loop until user chooses to quit
    
    return 0;
}

int menu(){
    int choice;
    
    printf("\nPlease choose an option:\n");
    printf("1. Add user\n");
    printf("2. Delete user\n");
    printf("3. View all users\n");
    printf("4. Generate password\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    return choice;
}

void generatePassword(int length, int lower, int upper, int digits){
    //arrays to store characters that can be used in password
    char lowerChars[] = "abcdefghijklmnopqrstuvwxyz";
    char upperChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digitChars[] = "0123456789";
    
    char password[length+1]; //array to store generated password
    int numChars = 0; //variable to store number of characters included in password
    
    if(lower == 1) numChars += 26; //add number of lowercase letters to numChars
    if(upper == 1) numChars += 26; //add number of uppercase letters to numChars
    if(digits == 1) numChars += 10; //add number of digits to numChars
    
    if(length < 8) length = 8; //set minimum password length to 8
    
    //error message if no characters will be included in password
    if(numChars == 0){
        printf("\nError: password must include at least one type of character.\n");
        return;
    }
    
    //generate password
    for(int i = 0; i < length; i++){
        int type = rand() % 3; //choose type of character to use
        
        if(type == 0 && lower == 1){ //add lowercase character
            password[i] = lowerChars[rand() % 26];
        }
        else if(type == 1 && upper == 1){ //add uppercase character
            password[i] = upperChars[rand() % 26];
        }
        else if(type == 2 && digits == 1){ //add digit character
            password[i] = digitChars[rand() % 10];
        }
        else{ //if chosen type is not included, choose again
            i--;
            continue;
        }
        
        numChars--; //decrease numChars to keep track of characters included
        
        //if all required character types have been used, add any remaining random character types
        if(numChars == 0){
            for(int j = i+1; j < length; j++){
                int type2 = rand() % 3;
                
                if(type2 == 0){ //add lowercase character
                    password[j] = lowerChars[rand() % 26];
                }
                else if(type2 == 1){ //add uppercase character
                    password[j] = upperChars[rand() % 26];
                }
                else{ //add digit character
                    password[j] = digitChars[rand() % 10];
                }
            }
            
            break;
        }
    }
    
    password[length] = '\0'; //add null character to end of password array
    
    printf("\nGenerated password: %s\n", password);
}

void addUser(char username[], char password[]){
    //open file for appending
    FILE *file = fopen("users.txt", "a");
    
    if(file == NULL){
        printf("\nError: file could not be opened.\n");
        return;
    }
    
    //write username and password to file
    fprintf(file, "%s %s\n", username, password);
    fclose(file);
    
    printf("\nUser added successfully.\n");
}

void deleteUser(char username[]){
    //open files for reading and writing
    FILE *infile = fopen("users.txt", "r");
    FILE *outfile = fopen("temp.txt", "w");
    
    if(infile == NULL || outfile == NULL){
        printf("\nError: file could not be opened.\n");
        return;
    }
    
    char line[40];
    int deleted = 0; //variable to keep track of whether user is deleted
    
    //copy all lines except the one with the specified username to temp.txt
    while(fgets(line, sizeof(line), infile)){
        char name[20], password[20];
        sscanf(line, "%s %s", name, password);
        
        if(strcmp(name, username) == 0){
            deleted = 1;
        }
        else{
            fprintf(outfile, "%s %s", name, password);
        }
    }
    
    fclose(infile);
    fclose(outfile);
    
    remove("users.txt"); //delete original file
    rename("temp.txt", "users.txt"); //rename temp.txt to original name
    
    if(deleted == 1){
        printf("\nUser deleted successfully.\n");
    }
    else{
        printf("\nError: user not found.\n");
    }
}

void viewUsers(){
    //open file for reading
    FILE *file = fopen("users.txt", "r");
    
    if(file == NULL){
        printf("\nError: file could not be opened.\n");
        return;
    }
    
    printf("\nCurrent users:\n");
    
    //read each line of file and print username
    char line[40];
    while(fgets(line, sizeof(line), file)){
        char name[20], password[20];
        sscanf(line, "%s %s", name, password);
        
        printf("%s\n", name);
    }
    
    fclose(file);
}