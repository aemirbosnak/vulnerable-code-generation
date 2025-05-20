//FormAI DATASET v1.0 Category: Password management ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generate_password(char *password, int length){
    int i, random_number;
    time_t t;

    srand((unsigned) time(&t)); // To seed random generator with current time

    for(i=0; i<length; i++){
        random_number = rand()%94 + 33; // Generating a random number between 33 and 126 (ASCII table)
        password[i] = (char) random_number; // Converting the random number to its corresponding character
    }

    password[length] = '\0'; // Terminating the string with a null character
}

int main(){
    char password[21];
    int option, length;

    printf("\n**Welcome to Futuristic Password Manager**\n\n");

    do{
        printf("\nEnter your choice (1 or 2):\n");
        printf("1. Generate a new password\n");
        printf("2. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("\nEnter the length of the password (max 20 characters): ");
                scanf("%d", &length);
                while(length < 1 || length > 20){
                    printf("Invalid length! Enter again: ");
                    scanf("%d", &length);
                }
                generate_password(password, length);
                printf("\nYour new password is: %s\n", password);
                break;
            case 2:
                printf("\nThank you for using Futuristic Password Manager!\n");
                break;
            default:
                printf("\nInvalid option! Enter again.\n");
                break;
        }
    }while(option != 2);

    return 0;
}