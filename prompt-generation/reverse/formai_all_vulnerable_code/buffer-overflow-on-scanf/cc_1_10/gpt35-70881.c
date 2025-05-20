//FormAI DATASET v1.0 Category: QR code reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValidQRCode(char* code){

    // QR code consists of alphanumeric characters
    int i;
    for(i = 0; i < strlen(code); i++){
        if((code[i] >= 'A' && code[i] <= 'Z') || (code[i] >= 'a' && code[i] <= 'z') || (code[i] >= '0' && code[i] <= '9')){
            continue;
        }
        else{
            return false;
        }
    }

    // QR code should start with "QR"
    if(strncmp(code, "QR", 2) != 0){
        return false;
    }

    // QR code should end with three digits 000
    if(strncmp(&code[strlen(code)-3], "000", 3) != 0){
        return false;
    }

    return true;
}

int main(){

    char code[256];
    printf("Enter a QR code: ");
    scanf("%s", code);

    if(isValidQRCode(code)){
        printf("Valid QR code!\n");

        // extract information from QR code
        char info[256];
        strncpy(info, &code[2], strlen(code)-5);
        info[strlen(code)-5] = '\0';

        printf("Information: %s\n", info);
    }
    else{
        printf("Invalid QR code!\n");
    }

    return 0;
}