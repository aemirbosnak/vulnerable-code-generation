//FormAI DATASET v1.0 Category: QR code generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define QR_CODE_SIZE 21

// Function to generate random alphanumeric characters
char genRandomAlphanumeric(){
    int ascii_value = (rand() % 62) + 48;
    if (ascii_value > 57) ascii_value += 7;
    if (ascii_value > 90) ascii_value += 6;
    return (char)ascii_value;
}

// Function to check if QR code is already stored in database
bool isQRCodeExists(char* qr_code, char* database[], int size){
    for(int i = 0; i < size; i++){
        if(strcmp(qr_code, database[i]) == 0){
            return true;
        }
    }
    return false;
}

// Main function to generate C QR code
char* generateQRCode(char* database[], int size){
    char* qr_code = malloc(sizeof(char) * QR_CODE_SIZE);
    
    do {
        for(int i = 0; i < QR_CODE_SIZE - 1; i++){
            qr_code[i] = genRandomAlphanumeric();
        }
        qr_code[QR_CODE_SIZE - 1] = '\0';
    } while (isQRCodeExists(qr_code, database, size));
    
    // Store QR code in database
    database[size] = qr_code;
    return qr_code;
}

// Utility function to print QR codes in database
void printQRCodeDatabase(char* database[], int size){
    printf("\nQR Code Database:\n");
    for(int i = 0; i < size; i++){
        printf("%s\n", database[i]);
    }
}

int main(){
    int database_size = 0;
    char* database[100]; // Array to store QR codes
    
    printf("Welcome to C QR Code Generator! Enter the number of QR codes you want to generate: ");
    int n;
    scanf("%d", &n);
    
    // Generate QR codes
    printf("Generating QR codes...\n");
    for(int i = 0; i < n; i++){
        char* qr_code = generateQRCode(database, database_size);
        database_size++;
        printf("QR Code %d: %s\n", i+1, qr_code);
    }
    printQRCodeDatabase(database, database_size);
    
    // End program
    printf("Done. Press any key to exit...");
    getchar();
    getchar();
    return 0;
}