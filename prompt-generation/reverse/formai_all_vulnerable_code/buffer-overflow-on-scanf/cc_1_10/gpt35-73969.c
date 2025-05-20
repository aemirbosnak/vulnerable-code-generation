//FormAI DATASET v1.0 Category: QR code reader ; Style: complete
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
  
// Function to check if input character is a number or not 
bool isNumericChar(char *str) 
{ 
    int i = 0; 
    
    // Check for '-' sign to allow negative numbers
    if (str[0] == '-')
        i = 1;
        
    while (str[i] != '\0') { 
        if (str[i] < '0' || str[i] > '9') 
            return false; 
        i++; 
    } 
    return true; 
} 
  
// Function to validate the QR code format 
bool validateQRCode(char *qrCode) 
{ 
    // QR code must start with "QR:" 
    if (strncmp(qrCode, "QR:", 3) != 0)
        return false;
        
    // QR code must have a numeric value after the colon
    if (!isNumericChar(qrCode + 3))
        return false;
        
    return true;
} 
  
int main() 
{ 
    char qrCode[20]; 
    
    printf("Please scan the QR code: ");
    scanf("%s", qrCode);
    
    if (validateQRCode(qrCode)) {
        printf("QR code scanned successfully!\n");
        printf("The numeric value is: %d\n", atoi(qrCode + 3));
    } else {
        printf("Invalid QR code format.\n");
    }
  
    return 0; 
}