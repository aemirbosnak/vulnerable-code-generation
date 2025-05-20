//FormAI DATASET v1.0 Category: modern Encryption ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char key[27] = "XZNLWEBGJHQDYVTKFUOMPCIASR";
//substitution cipher key

void encrypt(char *input, char *output){
    int i;
    for(i=0; i<strlen(input); i++){
        if(isalpha(input[i])){
            if(islower(input[i])){
                output[i] = tolower(key[input[i]-'a']); //convert to lowercase
            }
            else{
                output[i] = toupper(key[input[i]-'A']); //convert to uppercase
            }
        }
        else{
            output[i] = input[i];
        }
    }
    output[strlen(input)] = '\0';
}

void decrypt(char *input, char *output){
    int i, j;
    for(i=0; i<strlen(input); i++){
        if(isalpha(input[i])){
            if(islower(input[i])){
                for(j=0; j<26; j++){
                    if(key[j] == tolower(input[i])){
                        output[i] = tolower(j + 'a'); //convert to lowercase
                        break;
                    }
                }
            }
            else{
                for(j=0; j<26; j++){
                    if(key[j] == toupper(input[i])){
                        output[i] = toupper(j + 'a'); //convert to uppercase
                        break;
                    }
                }
            }
        }
        else{
            output[i] = input[i];
        }
    }
    output[strlen(input)] = '\0';
}

int main(){

    char input[1000], output[1000], choice;
    printf("Enter a string to encrypt (max 1000 characters):\n");
    fgets(input, 1000, stdin);
    input[strcspn(input, "\n")] = 0;

    printf("Do you want to encrypt(e) or decrypt(d)?\n");
    scanf("%c", &choice);

    if(choice == 'e'){
        encrypt(input, output);
        printf("Encrypted string: %s\n", output);
    }
    else if(choice == 'd'){
        decrypt(input, output);
        printf("Decrypted string: %s\n", output);
    }
    else{
        printf("Invalid input\n");
    }

    return 0;
}