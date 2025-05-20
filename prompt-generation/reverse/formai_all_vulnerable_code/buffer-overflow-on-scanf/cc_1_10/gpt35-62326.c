//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: systematic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LENGTH 1000 // Maximum length of the string 

void binary_conversion(int number, int* binary_array){
    int i = 0;
    while(number != 0){
      binary_array[i] = number%2;
      number = number/2;
      i++;
    }
}

void digital_watermark(char* message, char* watermark){
    int binary_array[MAX_LENGTH];
    int key;
    int watermark_length = strlen(watermark);
    int message_length = strlen(message);

    printf("Enter the Watermark Key (An Integer): ");
    scanf("%d", &key);

    binary_conversion(key, binary_array);

    for(int i=0; i<watermark_length; i++){
        int char_code = watermark[i];
        binary_conversion(char_code, binary_array);

        for(int j=0; j<8; j++){
            int message_index = i*8+j;

            if(message_index >= message_length){
                break;
            }

            if(binary_array[j]==1){
                if(message[message_index] == '0'){
                    message[message_index] = '1';
                }
            }
        }
    }
    printf("Digital Watermarking Successful: %s\n", message);
}

int main(){
    char message[MAX_LENGTH];
    char watermark[MAX_LENGTH];

    printf("Enter the Message String (Max %d Characters): ", MAX_LENGTH-1);
    fgets(message, MAX_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0; // Removing the newline character
 
    printf("Enter the Watermark String (Max %d Characters): ", MAX_LENGTH-1);
    fgets(watermark, MAX_LENGTH, stdin);
    watermark[strcspn(watermark, "\n")] = 0; // Removing the newline character
    
    digital_watermark(message, watermark);

    return 0;
}