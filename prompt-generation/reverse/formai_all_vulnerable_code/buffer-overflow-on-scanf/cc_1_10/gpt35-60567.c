//FormAI DATASET v1.0 Category: Password management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_password(char* password){
    int i;
    char rand_char;
    srand(time(NULL));
    for(i = 0; i < 8; i++){
        rand_char = (char) (rand() % 94 + 33);
        password[i] = rand_char;
    }
    password[i] = '\0';
}

int main(){
    FILE *password_file;
    char password[8];
    char input[8];
    char option;
    
    //Open password file
    password_file = fopen("password.txt", "r");
    if(password_file == NULL){
        printf("Password file does not exist..creating new file\n");
        password_file = fopen("password.txt", "w");
        fclose(password_file);
        printf("New password file created\n");
    }else{
        //Read password from file
        if(fgets(password, 8, password_file) != NULL){
            printf("Password loaded from file\n");
        }else{
            printf("Password file empty..generating new password\n");
            generate_password(password);
            fputs(password, password_file);
            printf("Password generated and saved\n");
        }
        fclose(password_file);
    }
    
    //Password authentication
    do{
        printf("Enter password: ");
        scanf("%s", input);
        if(strcmp(input, password) != 0){
            printf("Incorrect password..try again? (y/n): ");
            scanf(" %c", &option);
            if(option != 'y'){
                printf("Password authentication failed..terminating program\n");
                return 0;
            }
        }
    }while(strcmp(input, password) != 0);
    
    //Password change
    printf("Password authentication successful..change password? (y/n): ");
    scanf(" %c", &option);
    if(option == 'y'){
        generate_password(password);
        password_file = fopen("password.txt", "w");
        fputs(password, password_file);
        fclose(password_file);
        printf("New password generated and saved\n");
    }
    printf("Password management program terminated\n");
    
    return 0;
}