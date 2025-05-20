//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define HEX_LENGTH 16

/* This struct contains the data passed to the thread */
typedef struct {
    char hex[HEX_LENGTH];
    int decimal;
} ConvertData;

/* This is the thread function that will execute the hexadecimal to decimal conversion */
void* convertHexToDecimal(void* data) {
    ConvertData* convertData = (ConvertData*) data;
    int decimal = 0;
    for (int i = 0; convertData->hex[i] != '\0'; i++) {
        char current = convertData->hex[i];
        if (current >= '0' && current <= '9') {
            decimal = decimal * 16 + (current - '0');
        } else if (current >= 'a' && current <= 'f') {
            decimal = decimal * 16 + (current - 'a' + 10);
        } else if (current >= 'A' && current <= 'F') {
            decimal = decimal * 16 + (current - 'A' + 10);
        }
    }
    convertData->decimal = decimal;
    pthread_exit(NULL);
}

/* This function creates a thread to convert the given hexadecimal string to decimal */
int convertHexadecimalToDecimal(char* hex) {
    ConvertData* convertData = (ConvertData*) malloc(sizeof(ConvertData));
    for (int i = 0; i < HEX_LENGTH; i++) {
        convertData->hex[i] = hex[i];
    }
    pthread_t thread;
    pthread_create(&thread, NULL, convertHexToDecimal, (void*) convertData);
    pthread_join(thread, NULL);
    int decimal = convertData->decimal;
    free(convertData);
    return decimal;
}

/* Main function */
int main() {
    char hex[HEX_LENGTH];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    int decimal = convertHexadecimalToDecimal(hex);
    printf("Decimal equivalent of %s is %d\n", hex, decimal);
    return 0;
}