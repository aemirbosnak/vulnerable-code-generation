//FormAI DATASET v1.0 Category: QR code reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program is a unique C QR code reader. 
 * It utilizes the knowledge of Sherlock Holmes in solving intricate problems in order to decode QR codes.
 */

int main() {
    printf("Greetings! I am your trusty QR code reader.\n");
    printf("Please input the code you would like me to decode: ");

    char str[1000], decoded[1000];
    scanf("%s",str);
    
    // We will use Sherlock's intuition to determine the QR code's encoding scheme
    int length = strlen(str);
    int scheme = 0;
    for(int i=0; i<length; i++) {
        if(str[i] == 'Q' || str[i] == 'R') {
            scheme = 1;
            break;
        } else if(str[i] == 'c' && str[i+1] == 'o' && str[i+2] == 'd' && str[i+3] == 'e') {
            scheme = 2;
            break;
        }
    }

    if(scheme == 0) {
        printf("Sorry, I could not determine the encoding scheme of your QR code.\n");
    } else if(scheme == 1) {
        // The QR code is encoded using base64
        printf("Ah, I recognize this encoding scheme! It's base64.\n");
        // Let's use some of Holmes' code-breaking skills to decode it
        for(int i=0; i<length; i+=4) {
            int num_bits = 0;
            int bit_24 = 0;
            for(int j=0; j<4; j++) {
                int value = 0;
                if(str[i+j] >= 'A' && str[i+j] <= 'Z') {
                    value = str[i+j] - 'A';
                } else if(str[i+j] >= 'a' && str[i+j] <= 'z') {
                    value = str[i+j] - 'a' + 26;
                } else if(str[i+j] >= '0' && str[i+j] <= '9') {
                    value = str[i+j] - '0' + 52;
                } else if(str[i+j] == '+') {
                    value = 62;
                } else if(str[i+j] == '/') {
                    value = 63;
                }
                
                bit_24 = (bit_24 << 6) | value;
                num_bits += 6;
            }
            for(int j=0; j<num_bits/8; j++) {
                decoded[(i*3/4)+j] = (bit_24 >> (8*(num_bits/8-j-1))) & 0xFF;
            }
        }
        printf("Your decoded message is: %s\n", decoded);
    } else if(scheme == 2) {
        // The QR code is encoded using ASCII
        printf("Aha, this encoding scheme is ASCII.\n");
        // Let's use some of Holmes' linguistic skills to decipher it
        for(int i=0; i<length; i+=5) {
            int letter = 0;
            for(int j=0; j<5; j++) {
                if(str[i+j] == ' ') continue;
                letter |= (1 << (4-j));
            }
            decoded[i/5] = letter + 'a';
        }
        printf("Your decoded message is: %s\n", decoded);
    }

    return 0;
}