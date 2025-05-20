//FormAI DATASET v1.0 Category: Data validation ; Style: complex
#include<stdio.h>
#include<ctype.h>

//function to check if input is alphabetic or not
int isAlphabetic(char input[]){
    int i=0;
    while(input[i]!='\0'){
        if(!isalpha(input[i])){ //if input[i] is not an alphabet
            return 0; //return 0 indicating invalid input
        }
        i++;
    }
    return 1; //return 1 indicating valid input
}

//function to check if input is numeric or not
int isNumeric(char input[]){
    int i=0;
    while(input[i]!='\0'){
        if(!isdigit(input[i])){ //if input[i] is not a digit
            return 0; //return 0 indicating invalid input
        }
        i++;
    }
    return 1; //return 1 indicating valid input
}

int main(){
    char name[30];
    char age[5];
    char phone[15];
    char email[50];
    int valid=0; //flag to check if input is valid or not
    printf("Enter your name: ");
    scanf("%s", name); 
    while(valid==0){ //iterate until valid input is found
        if(isAlphabetic(name)){ //if input contains only alphabets
            valid=1; 
        }
        else{ //if input contains other than alphabets
            printf("Invalid input! Enter your name again: ");
            scanf("%s", name);
        }
    }
    valid=0; //resetting flag for next input
    printf("Enter your age: ");
    scanf("%s", age);
    while(valid==0){
        if(isNumeric(age)){ //if input contains only digits
            if(atoi(age)>=18 && atoi(age)<=99){ //if age is within given range
                valid=1;
            }
            else{ //if age is not within given range
                printf("Invalid input! Age should be between 18 and 99. Enter your age again: ");
                scanf("%s", age);
            }
        }
        else{ //if input contains other than digits
            printf("Invalid input! Enter your age again: ");
            scanf("%s", age);
        }
    }
    valid=0; 
    printf("Enter your phone number: ");
    scanf("%s", phone);
    while(valid==0){
        if(isNumeric(phone)){ //if input contains only digits
            if(strlen(phone)>=9 && strlen(phone)<=14){ //if phone number length is within given range
                valid=1;
            }
            else{ //if phone number length is not within given range
                printf("Invalid input! Phone number should be between 9 and 14 digits long. Enter your phone number again: ");
                scanf("%s", phone);
            }
        }
        else{ //if input contains other than digits
            printf("Invalid input! Enter your phone number again: ");
            scanf("%s", phone);
        }
    }
    valid=0; 
    printf("Enter your email address: ");
    scanf("%s", email);
    while(valid==0){
        int i=0, dotCount=0, atCount=0;
        if(isalnum(email[0]) || email[0]=='_' || email[0]=='.'){ //if email starts with an alphnumeric character, underscore or dot
            while(email[i]!='\0'){
                if(email[i]=='.'){ //if a dot is encountered
                    dotCount++; //increment dot count
                }
                if(email[i]=='@'){ //if an at sign is encountered
                    atCount++; //increment at count
                    if(email[i+1]=='.' || email[i+1]=='@' || email[i-1]=='.'){ //if dot or at sign is present next to it
                        break; //invalid email address
                    }
                }
                i++;
            }
            if(dotCount>=1 && atCount==1){ //if there is at least one dot and one at sign
                valid=1;
            }
        }
        if(valid==0){ //if input is invalid
            printf("Invalid input! Enter your email address again: ");
            scanf("%s", email);
        }
    }
    //print user details
    printf("\nUser Details:\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", atoi(age));
    printf("Phone: %s\n", phone);
    printf("Email: %s\n", email);
    return 0;
}