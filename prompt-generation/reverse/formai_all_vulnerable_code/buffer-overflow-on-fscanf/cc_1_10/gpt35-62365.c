//FormAI DATASET v1.0 Category: Password management ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function to generate a random password
char* generate_password() {
    char* password = malloc(10 * sizeof(char)); //allocating memory for password
    const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"; //characters to choose from
    
    srand(time(NULL));

    for (int i = 0; i < 10; ++i) {
        password[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    password[10] = '\0'; //terminating the string
    return password;
}

int main(int argc, char const *argv[]) {
    char *password = NULL; //pointer to store the password
    char filename[20],stored_password[20];
    FILE* fp;

    printf("Welcome to the Password Management System :)\n");

    while(1){
        int choice,verify;
        printf("\n1) Generate Password\n2) Store Password\n3) Retrieve Password\n4) Exit\nEnter your choice: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("\nGenerating password...\n");
                password = generate_password();
                printf("Your new password is: %s\n",password);
                break;
            case 2:
                if(password){
                    printf("\nEnter a filename to store your password: ");
                    scanf("%s",filename);
                    fp = fopen (filename, "w");
                    fputs (password, fp);
                    fclose (fp);
                    printf("Password stored successfully in %s\n",filename);
                    password = NULL;
                }
                else{
                    printf("\nNo password generated yet :(\n");
                }
                break;
            case 3:
                printf("\nEnter the filename to retrieve the password: ");
                scanf("%s",filename);
                fp = fopen (filename, "r");
                if (fp != NULL){
                    fscanf(fp, "%s", stored_password);
                    printf("Your password for %s is: %s\n",filename,stored_password);
                }
                else{
                    printf("\nInvalid filename\n");
                }
                fclose (fp);
                break;
            case 4:
                printf("\nExiting... Bye!\n");
                exit(0);
            default:
                printf("\nInvalid choice, try again!\n");
        }

    }
    return 0;
}