//MISTRAL-7B DATASET v1.0 Category: Digital signal processing ; Style: Cryptic
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

char* obfuscate(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = (char)(((int)str[i] << 2) | ((int)str[i] >> 4));
    }
    return str;
}

void low_pass_filter(int signal[N], int filtered_signal[N]) {
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = i; j < N && j < i + 5; j++) {
            sum += signal[j];
        }
        filtered_signal[i] = sum / 5;
    }
}

int main() {
    int input_signal[N] = { 0 };
    int filtered_signal[N] = { 0 };

    printf("Enter signal values (separated by space): ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &input_signal[i]);
    }

    printf("Original signal: ");
    obfuscate(obfuscate((char*)&input_signal)); // Cryptic obfuscation
    for (int i = 0; i < N; i++) {
        printf("%d ", input_signal[i]);
    }
    printf("\n");

    low_pass_filter(input_signal, filtered_signal); // Digital signal processing

    printf("Filtered signal: ");
    obfuscate(obfuscate((char*)&filtered_signal)); // Cryptic obfuscation
    for (int i = 0; i < N; i++) {
        printf("%d ", filtered_signal[i]);
    }
    printf("\n");

    return 0;
}