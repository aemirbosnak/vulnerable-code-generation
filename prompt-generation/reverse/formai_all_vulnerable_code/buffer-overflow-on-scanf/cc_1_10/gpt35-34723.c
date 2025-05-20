//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

pthread_mutex_t lock;

char* hexToBin(char hex[]) {
    int i = 0;
    char *binary = malloc(BUFFER_SIZE);
    while(hex[i]) {
        switch(hex[i]) {
            case '0':
                strcat(binary, "0000");
                break;
            case '1':
                strcat(binary, "0001");
                break;
            case '2':
                strcat(binary, "0010");
                break;
            case '3':
                strcat(binary, "0011");
                break;
            case '4':
                strcat(binary, "0100");
                break;
            case '5':
                strcat(binary, "0101");
                break;
            case '6':
                strcat(binary, "0110");
                break;
            case '7':
                strcat(binary, "0111");
                break;
            case '8':
                strcat(binary, "1000");
                break;
            case '9':
                strcat(binary, "1001");
                break;
            case 'A':
            case 'a':
                strcat(binary, "1010");
                break;
            case 'B':
            case 'b':
                strcat(binary, "1011");
                break;
            case 'C':
            case 'c':
                strcat(binary, "1100");
                break;
            case 'D':
            case 'd':
                strcat(binary, "1101");
                break;
            case 'E':
            case 'e':
                strcat(binary, "1110");
                break;
            case 'F':
            case 'f':
                strcat(binary, "1111");
                break;
            default:
                printf("\n Invalid Hexadecimal Digit %c ", hex[i]);
                exit(0);
        }
        i++;
    }
    return binary;
}

void* hexToBinThread(void *args) {
    pthread_mutex_lock(&lock);
    char *hex = (char*)args;
    char *binary = hexToBin(hex);
    printf("\n Hexadecimal: %s --> Binary: %s ", hex, binary);
    free(binary);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t threads[3];
    char hex1[BUFFER_SIZE];
    char hex2[BUFFER_SIZE];
    char hex3[BUFFER_SIZE];

    printf("\n Enter three hexadecimal numbers: ");
    scanf("%s %s %s", hex1, hex2, hex3);

    pthread_create(&threads[0], NULL, hexToBinThread, (void*)hex1);
    pthread_create(&threads[1], NULL, hexToBinThread, (void*)hex2);
    pthread_create(&threads[2], NULL, hexToBinThread, (void*)hex3);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);

    return 0;
}