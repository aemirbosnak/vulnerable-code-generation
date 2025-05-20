//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#define MIN_LEN 8
#define MAX_LEN 16

void generatePassword(char* password, int len);
int isPasswordValid(char* password, int len);

int main(){
    char password[MAX_LEN+1];
    int len;
    srand(time(NULL));
    printf("\n******************************************************************************************\n");
    printf("\t\t\t\tPASSWORD GENERATOR\n");
    printf("******************************************************************************************\n");
    do{
        printf("Enter the desired length of your password (minimum length: %d, maximum length: %d): ", MIN_LEN, MAX_LEN);
        scanf("%d", &len);
    }while(len<MIN_LEN || len>MAX_LEN);
    generatePassword(password, len);
    printf("\nYour password is: %s\n\n", password);

    return 0;
}

void generatePassword(char* password, int len){
    int i, type;
    char c;
    do{
        for(i=0;i<len;i++){
            type = rand()%4;
            if(type == 0){
                do{
                    c = rand()%26 + 'a';
                }while(!islower(c));
            }
            else if(type == 1){
                do{
                    c = rand()%26 + 'A';
                }while(!isupper(c));
            }
            else if(type == 2){
                do{
                    c = rand()%10 + '0';
                }while(!isdigit(c));
            }
            else{
                do{
                    c = rand()%15 + '!';
                }while(!ispunct(c));
            }
            password[i] = c;
        }
        password[i] = '\0';
    }while(!isPasswordValid(password, len));
}

int isPasswordValid(char* password, int len){
    int i, hasLower=0, hasUpper=0, hasDigit=0, hasSpecial=0;
    for(i=0;i<len;i++){
        if(islower(password[i])){
            hasLower = 1;
        }
        else if(isupper(password[i])){
            hasUpper = 1;
        }
        else if(isdigit(password[i])){
            hasDigit = 1;
        }
        else{
            hasSpecial = 1;
        }
    }
    if(hasLower && hasUpper && hasDigit && hasSpecial){
        return 1;
    }
    else{
        return 0;
    }
}