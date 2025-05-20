//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    // define variables 
    int length, num, spec;
    char c;
    int i, r;

    // seed random number generator
    srand(time(NULL));

    // ask user for password length
    printf("Enter the desired password length: ");
    scanf("%d", &length);

    // ask user how many numbers they want in their password
    printf("How many numbers would you like in your password? ");
    scanf("%d", &num);

    // ask user how many special characters they want in their password
    printf("How many special characters would you like in your password? ");
    scanf("%d", &spec);

    // calculate number of letters needed
    int letter = length - num - spec;

    // generate random password
    printf("Generating password...\n");
    for(i = 0; i < length; i++){
        // if there are still letters needed
        if(letter > 0){
            // 1 in 3 chance of generating uppercase letter
            r = rand() % 3;
            if(r == 0){
                c = 'a' + (rand() % 26);
            }
            else{
                c = 'A' + (rand() % 26);
            }
            letter--;
        }
        // if there are still numbers needed
        else if(num > 0){
            c = '0' + (rand() % 10);
            num--;
        }
        // if there are still special characters needed
        else{
            // generate random special character from set [!@#$%^&*()]
            r = rand() % 9;
            switch(r){
                case 0: c = '!'; break;
                case 1: c = '@'; break;
                case 2: c = '#'; break;
                case 3: c = '$'; break;
                case 4: c = '%'; break;
                case 5: c = '^'; break;
                case 6: c = '&'; break;
                case 7: c = '*'; break;
                case 8: c = '('; break;
                case 9: c = ')'; break;
            }
            spec--;
        }
        // print character
        printf("%c", c);
    }

    return 0;
}