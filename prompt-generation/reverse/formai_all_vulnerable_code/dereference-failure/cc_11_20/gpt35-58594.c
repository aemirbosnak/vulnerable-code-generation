//FormAI DATASET v1.0 Category: Password management ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
    int option, num_passwords=0;
    char master_password[50];
    char** passwords = malloc(50 * sizeof(char*));

    while(1){
        printf("Welcome to Password Manager\n");
        printf("============================\n");
        printf("1. Set Master Password\n");
        printf("2. Add New Password\n");
        printf("3. View Saved Passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Enter Master Password: ");
                scanf("%s", &master_password);
                break;

            case 2:
                if(strcmp(master_password, "") == 0){
                    printf("Please set the Master Password first!\n");
                }
                else{
                    char new_password[50];
                    printf("Enter New Password: ");
                    scanf("%s", &new_password);
                    int strength=0;
                    int len=strlen(new_password);
                    for(int i=0; i<len; i++){
                        if(isdigit(new_password[i])){
                            strength += 10;
                        }
                        else if(isalpha(new_password[i])){
                            strength += 20;
                        }
                        else{
                            strength += 30;
                        }
                    }
                    if(strength < 50){
                        printf("Strength: Weak\n");
                    }
                    else if(strength < 70){
                        printf("Strength: Medium\n");
                    }
                    else{
                        printf("Strength: Strong\n");
                    }
                    passwords[num_passwords] = malloc(50 * sizeof(char));
                    strcpy(passwords[num_passwords], new_password);
                    num_passwords++;
                }
                break;

            case 3:
                if(strcmp(master_password, "") == 0){
                    printf("Please set the Master Password first!\n");
                }
                else{
                    printf("Saved Passwords:\n");
                    for(int i=0; i<num_passwords; i++){
                        printf("%s\n", passwords[i]);
                    }
                }
                break;

            case 4:
                for(int i=0; i<num_passwords; i++){
                    free(passwords[i]);
                }
                free(passwords);
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option!\n");
        }
        printf("\n");
    }
    return 0;
}