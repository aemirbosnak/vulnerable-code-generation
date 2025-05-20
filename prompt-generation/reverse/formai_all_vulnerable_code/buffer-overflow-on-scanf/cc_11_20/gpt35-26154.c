//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: brave
#include<stdio.h>
#include<string.h>

int main(){

    char input[100];
    int code = 0;
    int i, j;

    printf("Welcome to the C Alien Language Translator!\n\n");
    printf("Please enter the code: ");
    scanf("%d", &code);

    //validating the code
    if(code < 1000 || code > 9999){
        printf("Invalid code! Please enter a 4 digit code.\n");
        return 0;
    }

    //conversion of the code to binary
    char binary[17] = "";
    int len = 0;
    int temp = code;

    while(temp != 0){
        if(temp % 2 == 0){
            strcat(binary, "0");
        }else{
            strcat(binary, "1");
        }
        temp /= 2;
        len++;
    }

    //padding if the length of binary is less than 16
    if(len < 16){
        int diff = 16 - len;
        char padding[diff+1];
        for(i=0;i<diff;i++){
            padding[i] = '0';
        }
        padding[diff] = '\0';
        strcat(padding, binary);
        strcpy(binary, padding);
    }

    //decoding the binary to the C Alien language
    char output[100] = "";
    len = strlen(binary);
    i = 0;
    j = 0;

    while(i < len){
        int count = 0;
        char temp[5] = "";

        while(binary[i] == binary[j]){
            count++;
            j++;
        }
        i = j;

        //detection of the pattern and conversion to the C Alien language
        if(count == 1){
            strcat(output, "-");
        }else if(count == 2){
            strcat(output, "--");
        }else{
            strcat(output, "-.");
        }
    }

    printf("The C Alien language translation of %d is: \n%s\n", code, output);

    return 0;
}