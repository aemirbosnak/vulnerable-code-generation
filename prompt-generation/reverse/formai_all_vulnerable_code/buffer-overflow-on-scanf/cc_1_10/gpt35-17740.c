//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This program can encode and decode a digital watermark in a string

//Function to encode a digital watermark in a string
void encode(char *str, char *watermark){
    int len_str = strlen(str);
    int len_watermark = strlen(watermark);
    int i, j;

    char encoded_str[len_str + len_watermark + 1]; //create new string for encoded output

    encoded_str[0] = '\0'; //initialize first character as null

    for(i = 0, j = 0; i < len_str; i++){ //loop through input string
        if(i % len_watermark == 0){ //if index is a multiple of watermark length
            strncat(encoded_str, watermark, len_watermark); //add watermark to output string
            j += len_watermark; //increment output index
        }
        encoded_str[j] = str[i]; //add input character to output string
        j++; //increment output index
    }

    encoded_str[j] = '\0'; //add null character at end of output

    printf("Encoded string: %s\n", encoded_str); //print encoded string
}

//Function to decode a digital watermark from a string
void decode(char *str, char *watermark){
    int len_str = strlen(str);
    int len_watermark = strlen(watermark);
    int i, j;
    char decoded_str[len_str + 1]; //create new string for decoded output

    decoded_str[0] = '\0'; //initialize first character as null

    for(i = 0, j = 0; i < len_str; i++){ //loop through input string
        if(i % len_watermark == 0){ //if index is a multiple of watermark length
            if(strncmp(str + i, watermark, len_watermark) == 0){ //check if watermark matches
                i += len_watermark - 1; //if match, skip over watermark in input string
            }
        }else{
            decoded_str[j] = str[i]; //add input character to output string
            j++; //increment output index
        }
    }

    decoded_str[j] = '\0'; //add null character at end of output

    printf("Decoded string: %s\n", decoded_str); //print decoded string
}

int main(){
    char str[100], watermark[10]; //initialize input string and watermark
    int choice;

    printf("Enter a string: ");
    fgets(str, 100, stdin); //get input string from user
    printf("Enter a watermark: ");
    fgets(watermark, 10, stdin); //get watermark from user
    watermark[strcspn(watermark, "\n")] = '\0'; //remove newline character from watermark

    while(1){ //loop until user exits
        printf("Choose an option:\n1. Encode\n2. Decode\n3. Exit\n");
        scanf("%d", &choice); //get user choice

        switch(choice){ //perform action based on user choice
            case 1:
                encode(str, watermark);
                break;
            case 2:
                decode(str, watermark);
                break;
            case 3:
                exit(0); //exit program
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}