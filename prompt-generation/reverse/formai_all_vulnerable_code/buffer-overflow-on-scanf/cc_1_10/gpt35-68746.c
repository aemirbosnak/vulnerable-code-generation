//FormAI DATASET v1.0 Category: Color Code Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Function to convert a hexadecimal value to decimal
int hex_to_dec(char hex_num[]) {
    int len = strlen(hex_num);
    int base = 1;
    int dec_num = 0;
    
    for(int i=len-1; i>=0; i--) {
        if(hex_num[i] >= '0' && hex_num[i] <= '9') {
            dec_num += (hex_num[i] - '0') * base;
            base *= 16;
        } else if(hex_num[i] >= 'A' && hex_num[i] <= 'F') {
            dec_num += (hex_num[i] - 55) * base;
            base *= 16;
        } else if(hex_num[i] >= 'a' && hex_num[i] <= 'f') {
            dec_num += (hex_num[i] - 87) * base;
            base *= 16;
        }
    }
    
    return dec_num;
}

//Function to convert decimal value to binary
void dec_to_bin(int dec_num, char *bin_num) {
    char temp_bin[100];
    int i = 0;
    
    while(dec_num > 0) {
        if(dec_num % 2 == 0) {
            temp_bin[i++] = '0';
        } else {
            temp_bin[i++] = '1';
        }
        dec_num /= 2;
    }
    
    //reverse the binary string
    int j=0;
    for(int k=i-1; k>=0; k--) {
        bin_num[j++] = temp_bin[k];
    }
    
    bin_num[j] = '\0';
}

//Function to convert RGB color code to hexadecimal
void rgb_to_hex(char rgb_code[], char *hex_code) {
    char r[3], g[3], b[3];
    int r_dec, g_dec, b_dec;
    char r_hex[3], g_hex[3], b_hex[3];
    
    //extract RGB values
    sscanf(rgb_code, "#%2s%2s%2s", r, g, b);
    
    //convert RGB values to decimal
    r_dec = atoi(r);
    g_dec = atoi(g);
    b_dec = atoi(b);
    
    //convert decimal values to hexadecimal
    sprintf(r_hex, "%X", r_dec);
    sprintf(g_hex, "%X", g_dec);
    sprintf(b_hex, "%X", b_dec);
    
    //concatenate the hexadecimal values
    strcat(hex_code, r_hex);
    strcat(hex_code, g_hex);
    strcat(hex_code, b_hex);
}

int main() {
    char choice;
    bool running = true;
    
    while(running) {
        printf("***Color Code Converter***\n");
        printf("1. RGB to Hex\n");
        printf("2. Hex to RGB\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        switch(choice) {
            case '1': {
                char rgb_code[10], hex_code[10] = "#";
                printf("Enter RGB color code (ex: 255,255,255): ");
                scanf("%s", rgb_code);
                rgb_to_hex(rgb_code, hex_code);
                printf("Hex color code: %s", hex_code);
                break;
            }
            
            case '2': {
                char hex_code[10], r[3], g[3], b[3];
                int r_dec, g_dec, b_dec;
                
                printf("Enter Hex color code (ex: #FFFFFF): ");
                scanf("%s", hex_code);
                
                //convert each part of the hexadecimal code to decimal
                r_dec = hex_to_dec(strncpy(r, &hex_code[1], 2));
                g_dec = hex_to_dec(strncpy(g, &hex_code[3], 2));
                b_dec = hex_to_dec(strncpy(b, &hex_code[5], 2));
                
                printf("RGB color code: %d,%d,%d", r_dec, g_dec, b_dec);
                break;
            }
            
            case '3': {
                running = false;
                break;
            }
            
            default: {
                printf("Invalid choice. Please enter again.");
                break;
            }
        }
        
        printf("\n\n");
    }
    
    return 0;
}